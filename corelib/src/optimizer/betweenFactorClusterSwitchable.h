//
// Created by amber on 2019-07-30.
//

#ifndef RTABMAP_BETWEENFACTORCLUSTERSWITCHABLE_H
#define RTABMAP_BETWEENFACTORCLUSTERSWITCHABLE_H

#include <gtsam/nonlinear/NonlinearFactor.h>

#include <iostream>

#include "vertigo/gtsam/switchVariableLinear.h"
#include "vertigo/gtsam/switchVariableSigmoid.h"

namespace vertigo {
    class BetweenFactorClusterSwitchableLinear : public gtsam::NoiseModelFactor2<SwitchVariableLinear, SwitchVariableLinear>
    {
    public:
        BetweenFactorClusterSwitchableLinear() {};
        BetweenFactorClusterSwitchableLinear(gtsam::Key key1, gtsam::Key key2, const gtsam::SharedNoiseModel& model)
            : gtsam::NoiseModelFactor2<SwitchVariableLinear, SwitchVariableLinear>(model, key1, key2) {};

        gtsam::Vector evaluateError(const SwitchVariableLinear& s1, const SwitchVariableLinear& s2,
                                    boost::optional<gtsam::Matrix&> H1 = boost::none,
                                    boost::optional<gtsam::Matrix&> H2 = boost::none) const
        {

            if (H1) (*H1) = Matrix::Identity(traits<SwitchVariableLinear>::GetDimension(s1),traits<SwitchVariableLinear>::GetDimension(s1));
            if (H2) (*H2) = -1.0 * Matrix::Identity(traits<SwitchVariableLinear>::GetDimension(s2),traits<SwitchVariableLinear>::GetDimension(s2));


            //gtsam::Vector error = gtsam::Vector1(1.0);
            //error *= s1.value()-s2.value() ;
            //return error;

            // manifold equivalent of z-x -> Local(x,z)
            return -traits<SwitchVariableLinear>::Local(s1, s2);

        };



    };

    class BetweenFactorClusterSwitchableSigmoid : public gtsam::NoiseModelFactor2<SwitchVariableSigmoid, SwitchVariableSigmoid>
    {
    public:
        BetweenFactorClusterSwitchableSigmoid() {};
        BetweenFactorClusterSwitchableSigmoid(gtsam::Key key1, gtsam::Key key2, const gtsam::SharedNoiseModel& model)
            : gtsam::NoiseModelFactor2<SwitchVariableSigmoid, SwitchVariableSigmoid>(model, key1, key2) {};

        gtsam::Vector evaluateError(const SwitchVariableSigmoid& s1, const SwitchVariableSigmoid& s2,
                                    boost::optional<gtsam::Matrix&> H1 = boost::none,
                                    boost::optional<gtsam::Matrix&> H2 = boost::none) const
        {
            double w1 = sigmoid(s1.value());
            double w2 = sigmoid(s2.value());
            /* (w*(1.0-w))*/;  // sig(x)*(1-sig(x)) is the derivative of sig(x) wrt. x

            if (H1) (*H1) = (w1*(1.0-w1)) * Matrix::Identity(traits<SwitchVariableSigmoid>::GetDimension(s1),traits<SwitchVariableSigmoid>::GetDimension(s1));//(w1*(1.0-w1)) *
            if (H2) (*H2) = (w2*(1.0-w2)) * -1.0 * Matrix::Identity(traits<SwitchVariableSigmoid>::GetDimension(s2),traits<SwitchVariableSigmoid>::GetDimension(s2));//* (w2*(1.0-w2))

            // manifold equivalent of z-x -> Local(x,z)

            //return -traits<SwitchVariableSigmoid>::Local(s1, s2);

            gtsam::Vector error = gtsam::Vector1(1.0);
            error *= w1- w2 ;
            return error;

        };

    private:

        double sigmoid(double x) const {
            return 1.0/(1.0+exp(-x));
        }



    };

}

#endif //RTABMAP_BETWEENFACTORCLUSTERSWITCHABLE_H
