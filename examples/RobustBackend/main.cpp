//
// Created by amber on 25/06/19.
//

#include "rtabmap/core/Graph.h"
#include "rtabmap/core/Transform.h"
#include "rtabmap/core/Optimizer.h"
#include "rtabmap/core/Rtabmap.h"
#include <rtabmap/utilite/UStl.h>
#include "rtabmap/core/Link.h"
#include "rtabmap/core/Parameters.h"



int main(int argc, char *argv[]){ //

    /* Set logger type */
    ULogger::setType(ULogger::kTypeConsole);
    ULogger::setLevel(ULogger::kDebug);
    {

        FILE *p_fr;
        if((p_fr = fopen(argv[1], "rb")))
            fclose(p_fr);
        else {
            fprintf(stderr, "error: can't open input file \'%s\'\n", argv[1]);
            return -1;
        }

    }


    const std::string & path = argv[1];
    int format_local = 4; // g2o format
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
        const std::string ini_path = "../rtabmap.ini";
        rtabmap::Parameters::readINI(ini_path, configParameters);

        std::string workingDir = "../working_dir";
        rtabmap.parseParameters(configParameters);
        //log
        rtabmap.setWorkingDirectory(workingDir);

        //create optimizer
        rtabmap::Optimizer * optimizer = rtabmap::Optimizer::create(configParameters);

        //optimize
        std::map<int, rtabmap::Transform> finalPoses;
        std::list<std::map<int, rtabmap::Transform>> intermediateGraphes; // TODO_LOCAL: maybe write a visualization code using this variable


        finalPoses = optimizer->optimize(poses.begin()->first, poses, constraints, &intermediateGraphes);

        //save the final poses to a file
        // this is moved inside OptimizerGTSAM to access loops_after_clustering

    } else
    {
        std::cout<<"load g2o file failed"<< std::endl;

    }

    return 0;

}

