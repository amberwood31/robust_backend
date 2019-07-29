//
// Created by amber on 2019-07-29.
//

#ifndef RTABMAP_UTILS_H
#define RTABMAP_UTILS_H

#include "rtabmap/core/Graph.h"
#include "rtabmap/core/Transform.h"
#include "rtabmap/core/optimizer/OptimizerGTSAM.h"
#include "rtabmap/core/Optimizer.h"
#include "rtabmap/core/Rtabmap.h"
#include <rtabmap/utilite/UStl.h>
#include "rtabmap/core/Link.h"
#include "rtabmap/core/Parameters.h"
#include "cluster.hpp"
#include "types.hpp"
bool getLoopClosures(const std::multimap<int, rtabmap::Link>& linksIn, IntPairSet& loops);


#endif //RTABMAP_UTILS_H
