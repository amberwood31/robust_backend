//
// Created by amber on 2019-07-29.
//

#ifndef RTABMAP_UTILS_H
#define RTABMAP_UTILS_H

#include "cluster.hpp"
#include "types.hpp"
bool getLoopClosures(const std::multimap<int, rtabmap::Link>& linksIn, IntPairSet& loops);


#endif //RTABMAP_UTILS_H
