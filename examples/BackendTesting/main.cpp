//
// Created by amber on 25/06/19.
//

#include "rtabmap/core/Graph.h"
#include "rtabmap/core/Transform.h"
#include "rtabmap/core/optimizer/OptimizerGTSAM.h"
#include "rtabmap/core/Optimizer.h"
#include "rtabmap/core/Rtabmap.h"
#include <rtabmap/utilite/UStl.h>
#include "rtabmap/core/Link.h"
#include "rtabmap/core/Parameters.h"

int main(int argc, char *argv[]){ //

    /* Set logger type */
    ULogger::setType(ULogger::kTypeConsole);
    ULogger::setLevel(ULogger::kDebug);


    const std::string & path = argv[1];//"/home/amber/pose_dataset/test_rtabmap_backend/manhattanOlson3500.g2o"; //
    int format_local = 4; // 0=Raw, 1=RGBD-SLAM motion capture (10=without change of coordinate frame), 2=KITTI, 3=TORO, 4=g2o, 5=NewCollege(t,x,y), 6=Malaga Urban GPS, 7=St Lucia INS, 8=Karlsruhe
    std::map<int, rtabmap::Transform> poses;
    std::multimap<int, rtabmap::Link>  constraints;

    // Create RTAB-Map
    rtabmap::Rtabmap rtabmap;


    if (rtabmap::graph::importPoses(path, format_local, poses, &constraints , 0))
    {

        std::cout<<"load g2o file successfully"<< std::endl;
        cv::Mat covariance;

        //load parameters
        rtabmap::ParametersMap configParameters;
        const std::string ini_path = "/home/amber/.rtabmap/rtabmap.ini";
        rtabmap::Parameters::readINI(ini_path, configParameters);

        std::string workingDir = "/home/amber/pose_dataset/test_rtabmap_backend";
        rtabmap.parseParameters(configParameters);
        //log
        rtabmap.setWorkingDirectory(workingDir);

        //create gtsam optimizer
        rtabmap::Optimizer * optimizer = rtabmap::Optimizer::create(configParameters);

        //optimize
        std::map<int, rtabmap::Transform> posesOut;
        std::multimap<int, rtabmap::Link> linksOut;

        std::cout<<"Get connected graph"<<std::endl;
        optimizer->getConnectedGraph(poses.rbegin()->first, poses, constraints, posesOut, linksOut);

        std::map<int, rtabmap::Transform> finalPoses;
        std::list<std::map<int, rtabmap::Transform>> intermediateGraphes; // TODO_LOCAL: maybe write a visualization code using this variable


        finalPoses = optimizer->optimize(posesOut.rbegin()->first, posesOut, linksOut, &intermediateGraphes);

        //save the final poses to a file
        std::string export_path = "/home/amber/pose_dataset/output.g2o";
        std::map<int, double> stamps;
        if (rtabmap::graph::exportPoses(export_path, 4, finalPoses, linksOut, stamps, configParameters))
        {
            std::cout << "Export poses successfully"<< std::endl;
        } else
        {
            std::cout << "Export poses failed"<< std::endl;
        }


    } else
    {
        std::cout<<"load g2o file failed"<< std::endl;

    }

    return 0;

}

