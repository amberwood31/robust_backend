#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Sep  5 19:02:39 2019

@author: amber
"""

#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import sys
from file_read_backwards import FileReadBackwards as readreverse


## In[]:

def process():
#folder_path = "/home/amber/stew/slam++/bin"
#
#inlier_quantity = 20 # manhattan: 2097 garage: 4615 mit: 20 intel: 256
#outlier_quantity = 20
    
    # read input file, find last N edges (where N=outlier_quantity+inlier_quantity)
    
    print(sys.argv)
    
    if len(sys.argv) > 1:
        posegraph_input_path = sys.argv[1]
        output_path = sys.argv[2]
        #rejected_loops_path = sys.argv[3]
        inlier_quantity = int(sys.argv[3])
        outlier_quantity = int(sys.argv[4])   


    #posegraph_input_path = "/home/amber/stew/slam++/bin/input.g2o"
    #output_path = "/home/amber/stew/slam++/bin/clustering_results.txt" 
    lc_edge_quantity = inlier_quantity + outlier_quantity 
    
    #df_full = pd.read_csv(output_path, delimiter = " ", header = None, names = ['vertex_from', 'vertex_to', 'ofc', 'score'])
    
    
    # In[]:
    
    i = 0
    lc_pair_search_phrases = []         # list of [str0, str1], each strpair represents one loop closure
    outlier_pair_search_phrases = []    # list of [str0, str1], each strpair represents one loop closure
    inlier_pair_search_phrases = []     # list of [str0, str1], each strpair represents one loop closure
    with readreverse(posegraph_input_path, encoding="utf-8") as obj:
        while i < lc_edge_quantity:
            line = obj.readline()
            line_stripped = line.strip('\n')
            line_splitted = line_stripped.split(' ')
            #if [line_splitted[1], line_splitted[2]] in lc_pair_search_phrases:
                #print('reduntant: '+ line_splitted[1] +' '+line_splitted[2] )
            lc_pair_search_phrases.append([line_splitted[1], line_splitted[2]])
            if i < outlier_quantity:
                outlier_pair_search_phrases.append([line_splitted[1], line_splitted[2]])
            else:
                inlier_pair_search_phrases.append([line_splitted[1], line_splitted[2]])
                
            i += 1
    
    edge_twice = []        # handle edges that are in both inlier list and outlier lise, consider as inlier
    for e in outlier_pair_search_phrases:
        if e in inlier_pair_search_phrases:
            edge_twice.append(e)
            
    outlier_pair_search_phrases = [i for i in outlier_pair_search_phrases if i not in edge_twice]
            
        
            
    # In[]:
            
    #read output file, find clusters
    
    clusters = [[]]
    edge_counter = 0 
    cluster_index = 0
            
    with open(output_path, encoding="utf-8") as obj:
        while edge_counter < lc_edge_quantity: # should always be true, since some edges will be deleted during the incremental clustering
            line = obj.readline()
            if line != '\n':
                edge_counter +=1
                line_stripped = line.strip('\n')
                line_splitted = line_stripped.split(' ')
                if line_splitted[0] == 'CLUSTER':
                    clusters[-1].append([int(line_splitted[1]), int(line_splitted[2])])
                #print('edge counter: ', edge_counter)
                
            else:
                #print('cluster', cluster_index, ' ended')
                if line_splitted[0] != 'CLUSTER_R':
	                clusters.append([])
	                cluster_index += 1
                
               
    
    clusters.remove([])
    
        # In[]:
            
    #read rejected_loops_file
    
    rejected_loops = []
    edge_counter = 0 
    cluster_index = 0
            
    content =open(output_path, 'r')
    lines = content.readlines()
    for line in lines:
       
        line_stripped = line.strip('\n')
        line_splitted = line_stripped.split(' ')
        #print(line_splitted)
        if line_splitted[0] == 'CLUSTER_R':
        	rejected_loops.append([line_splitted[1], line_splitted[2]])
                #print('edge counter: ', edge_counter)
                    
    rejected_outliers = []
    rejected_inliers = []

    for loop in rejected_loops:
        if loop in outlier_pair_search_phrases:
            rejected_outliers.append(loop)
        else:
            rejected_inliers.append(loop)
            
    # In[]:
           
    clusters_array_list = []
    for cluster in clusters:
        np_array = np.array(cluster)
        empty_column = np.zeros([len(cluster),1], dtype = int) # prepare space for later decisions
        np_array = np.append(np_array, empty_column, axis = 1)
        clusters_array_list.append(np_array)
        
            
            
    # In[]:

    for i in range(0, len(clusters_array_list)):
        for j in range(0, len(clusters_array_list[i])):
            if [str(clusters_array_list[i][j][0]), str(clusters[i][j][1])] in outlier_pair_search_phrases:
                
                clusters_array_list[i][j][2] = -1
            else:
                clusters_array_list[i][j][2] = 1
    
    # In[]:
    
    decision = []
    cluster_nature = []
    inconsistant_cluster = []  
    for i in range(0, len(clusters_array_list)):   
        if abs(sum(clusters_array_list[i][:,2])) == len(clusters_array_list[i]):
            
            decision.append(True)
            if sum(clusters_array_list[i][:,2]) >0:
                cluster_nature.append(1) # cluster full of inliers 
            else:
                cluster_nature.append(-1) # cluster full of outliers
            
        else:
            decision.append(False)
            inconsistant_cluster.append(clusters_array_list[i])
            
    wrong_clusters = []
    
    print('rejected outliers (', len(rejected_outliers), ') includes: ', rejected_outliers)
    print('rejected inliers (', len(rejected_inliers), ') includes: ', rejected_inliers)
    
            
    print('consistant clusters/all clusters: ', sum(decision), '/', len(decision))
    if sum(decision) != len(decision):
        for i in range(0, len(decision)):
            if decision[i] == False:
                print('wrong clusters: ', i)
                wrong_clusters.append(clusters_array_list[i])
                print('includes ', clusters_array_list[i])
    print('sum of all edges', sum([len(cluster) for cluster in clusters_array_list]))


# In[]:


    
process()
