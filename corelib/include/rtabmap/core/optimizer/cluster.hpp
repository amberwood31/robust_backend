

#ifndef CLUSTER_HPP_
#define CLUSTER_HPP_

#include <iostream>
#include <vector>
#include <cstdlib>
#include "types.hpp"
#include <stdio.h>
#include <rtabmap/utilite/UStl.h>


struct cluster
{

	int size;
	double last_score;
	double std_score;
	double mean_score;

	cluster():size(0), last_score(-1), std_score(-1), mean_score(-1){}
    cluster(double score) : size(1), last_score(score), std_score(0), mean_score(score){}

};

class Clusterizer
{
	//typedef IntPairIDMap 			LoopwScoreToClusterIDMap;
	//typedef IDintPairSetMap 		ClusterIDtoLoopsMap;
	typedef IntPairDoubleMap        LoopToScoreMap;
	typedef IDintPairDoubleMapMap       ClusterIDtoLoopsMap;
	typedef IntPairDoubleMapIDMap       LoopwScoreToClusterIDMap;
	typedef IntPairIDMap                LoopToClusterIDMap;

	std::vector<cluster>                _clustersFound;
	ClusterIDtoLoopsMap	                clusterIDtoLoopsMap;
	LoopwScoreToClusterIDMap            loopwScoreToClusterIDMap;
	LoopToClusterIDMap                  loopToClusterIDMap;

public:

	void clusterize( FILE* clustering_results,  const double threshold)
	{
	    double alpha = 0.95;

		if(!clustering_results)
		{
			std::cerr<<"clusterize(): "<<__LINE__<<" no clustering results to load"<<std::endl;
			return;
		}
		_clustersFound.clear();
        char line[400];
        while ( fgets (line , 400 , clustering_results) != NULL )
		{
            std::vector<std::string> strList = uListToVector(uSplit(uReplaceChar(line, '\n', ' '), ' '));
            double new_score = uStr2Double(strList[3]);
            if (new_score < alpha)
            {
                new_score = 0;  //zero the score of all good measurements
            }
            IntPair lc_edge(atoi(strList[0].c_str()), atoi(strList[1].c_str()));
            IntPairDoubleMap lc_edge_with_score;
            lc_edge_with_score[lc_edge] = new_score;

			if(_clustersFound.empty())
			{
				cluster s(new_score); //initialize cluster with the new score
				_clustersFound.push_back(s);

                clusterIDtoLoopsMap[_clustersFound.size()-1][lc_edge] = new_score;;
                loopwScoreToClusterIDMap[lc_edge_with_score] = _clustersFound.size()-1;
                loopToClusterIDMap[lc_edge] = _clustersFound.size()-1;
                std::cout<<"cluster begins: " << lc_edge.first << " " << lc_edge.second << std::endl;
			}
			else
			{
				cluster* currentCluster = NULL;
				//check for the last score of last cluster

                if (fabs(_clustersFound.back().last_score - new_score) < threshold)
                {
                    currentCluster = &_clustersFound.back();
                    currentCluster->size++;
                    currentCluster->last_score = new_score;

                    clusterIDtoLoopsMap[_clustersFound.size()-1][lc_edge] = new_score;;
                    loopwScoreToClusterIDMap[lc_edge_with_score] = _clustersFound.size()-1;
                    loopToClusterIDMap[lc_edge] = _clustersFound.size()-1;
                    IntPairDoubleMap current_cluster_map = clusterIDtoLoopsMap[_clustersFound.size()-1];
                    double sum = 0;
                    for (IntPairDoubleMap::iterator it= current_cluster_map.begin();
                        it != current_cluster_map.end(); it++)
                    {
                        sum += it->second;
                    }
                    currentCluster->mean_score = sum / current_cluster_map.size();


                }
                else	    // variation in scores exceed the threshold
				{
					cluster s(new_score);
					_clustersFound.push_back(s);

                    clusterIDtoLoopsMap[_clustersFound.size()-1][lc_edge] = new_score;;
                    loopwScoreToClusterIDMap[lc_edge_with_score] = _clustersFound.size()-1;
                    loopToClusterIDMap[lc_edge] = _clustersFound.size()-1;
                    std::cout<<"cluster begins: " << lc_edge.first << " " << lc_edge.second << std::endl;

				}

			}

		}

	}

    int getClusterID(const IntPair& loop)
    {
        return loopToClusterIDMap.at(loop);
    }

    double getScoreByID(int id){
	    return _clustersFound.at(id).mean_score;
	}


	IntPairDoubleMap& getClusterByID(int id){
		return clusterIDtoLoopsMap.at(id);
	}

	size_t clusterCount()
	{
		return _clustersFound.size();
	}

	bool deleteCluster(int clusterID)
	{
		clusterIDtoLoopsMap.erase(clusterID);

		for(IntPairDoubleMapIDMap::iterator it= loopwScoreToClusterIDMap.begin();
				it!=loopwScoreToClusterIDMap.end(); it++)
		{
			if(it->second == clusterID)
				loopwScoreToClusterIDMap.erase(it->first);
		}

		return true;
	}

};

#endif /* CLUSTER_HPP_ */
