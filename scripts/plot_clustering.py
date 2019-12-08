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
#folder_path = "/home/amber/stew/test_backend/analysis_chamber"
#threshold = 0.01
#outlier_quantity = 10
#
#pose_quantity = 808 # manhattan: 3499 garage: 1660 mit: 808 intel: 1228
#inlier_quantity = 20 # manhattan: 2097 garage: 4615 mit: 20 intel: 256
    
    # read input file, find last N edges (where N=outlier_quantity+inlier_quantity)
    
    print(sys.argv)
    
    if len(sys.argv) > 1:
        folder_path = sys.argv[1]
        #pose_quantity = int(sys.argv[2])
        inlier_quantity = int(sys.argv[2])
        outlier_quantity = int(sys.argv[3])   
        threshold = float(sys.argv[4])
        zero_out_threshold = float(sys.argv[5])
        print('threshold value: ', threshold)


    posegraph_input_path = folder_path+"/input.g2o"
    output_path = folder_path+"/full_analysis.txt" 
    lc_edge_quantity = inlier_quantity + outlier_quantity 
    
    df_full = pd.read_csv(output_path, delimiter = " ", header = None, names = ['vertex_from', 'vertex_to', 'ofc', 'score'])
    #df_full = df_full.sort_values(by=['vertex_to'])
    #df_full = df_full.reset_index(drop=True)
    
    
    #fig = plt.figure()
    #plt.plot(df_full['ofc'], 'ro')
    #plt.legend(("ofc",))
    #plt.savefig("ofc_incremental")
    #plt.show()
    
    #fig = plt.figure()
    #plt.plot(df_full['score'], 'o')
    #plt.savefig("score_incremental")
    #plt.show()
    
    #df_full
    
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
            
    #read output file, find ID-value-pair 
            
    
    lc_id_score_pair = np.zeros((lc_edge_quantity, 4), dtype = float)
    lc_id_ofc_pair = np.zeros((lc_edge_quantity, 4), dtype = float)
    #   array of [float0, float1, float2, float3], f0: vertex_from, f1: vertex_to, f2: ofc or score, f3: incremental step
    
    
    for i in df_full.index:
        
        if [str(df_full['vertex_from'].iloc[i]), str(df_full['vertex_to'].iloc[i])] in lc_pair_search_phrases:
            
            lc_id_ofc_pair[i] = np.array([df_full['vertex_from'].iloc[i], df_full['vertex_to'].iloc[i], df_full['ofc'].iloc[i], float(i)])
            if float(df_full['score'].iloc[i]) > zero_out_threshold:            
                
                lc_id_score_pair[i] = np.array([df_full['vertex_from'].iloc[i], df_full['vertex_to'].iloc[i], df_full['score'].iloc[i], float(i)])
            else:
            
                lc_id_score_pair[i] = np.array([df_full['vertex_from'].iloc[i], df_full['vertex_to'].iloc[i], 0, float(i)])
            #print(all_switch_edge[i])
           
    print('std_score of all edges: ', lc_id_score_pair[:,2].std())
          
    # In[]:
    inlier_id_ofc_pair = np.zeros((inlier_quantity+len(edge_twice), 4), dtype = float) # change the quantity based on overlap
    outlier_id_ofc_pair = np.zeros((outlier_quantity-len(edge_twice), 4), dtype = float) # change the quantity based on overlap
    #   array of [float0, float1, float2, float3], f0: vertex_from, f1: vertex_to, f2: ofc or score, f3: incremental step
    
    
    j=0
    k=0
    for i in range(0, lc_id_ofc_pair.shape[0]):
        if [str(int(lc_id_ofc_pair[i, 0])), str(int(lc_id_ofc_pair[i,1]))] in outlier_pair_search_phrases:
            outlier_id_ofc_pair[j] = lc_id_ofc_pair[i]
            j+=1
        elif [str(int(lc_id_ofc_pair[i, 0])), str(int(lc_id_ofc_pair[i,1]))] in inlier_pair_search_phrases:
            inlier_id_ofc_pair[k] = lc_id_ofc_pair[i]
            k+=1
            
    # In[]:
    print('outlier_ofc_minimum: ', outlier_id_ofc_pair[:,2].min())
    print('outlier_ofc_maximum: ', outlier_id_ofc_pair[:,2].max())
    print('inlier_ofc_minimum: ', inlier_id_ofc_pair[:,2].min())
    print('inlier_ofc_maximum: ', inlier_id_ofc_pair[:,2].max())
    print(' ')
    
    #    fig = plt.figure()
    #    plt.plot(outlier_id_ofc_pair[:,2], 'ro-')
    #    plt.savefig("ofc_outlier")
    #    plt.show()
    
    #    fig = plt.figure()
    #    plt.plot(inlier_id_ofc_pair[:,2], 'o-')
    #    plt.savefig("ofc_inlier")
    #    plt.show()
    
    #fig = plt.figure()
    #plt.plot(outlier_id_ofc_pair[:,3], outlier_id_ofc_pair[:,2], 'ro')
    #plt.plot(inlier_id_ofc_pair[:,3], inlier_id_ofc_pair[:,2], 'o')
    #plt.savefig("combined_ofc_plot")
    #plt.show()
    
    
    
    # In[]:
    inlier_id_score_pair = np.zeros((inlier_quantity+len(edge_twice), 4), dtype = float) # change the quantity based on overlap
    outlier_id_score_pair = np.zeros((outlier_quantity-len(edge_twice), 4), dtype = float) # change the quantity based on overlap
    j=0
    k=0
    for i in range(0, lc_id_score_pair.shape[0]):
        if [str(int(lc_id_score_pair[i, 0])), str(int(lc_id_score_pair[i,1]))] in outlier_pair_search_phrases:
            outlier_id_score_pair[j] = lc_id_score_pair[i]
            j+=1
        elif [str(int(lc_id_score_pair[i, 0])), str(int(lc_id_score_pair[i,1]))] in inlier_pair_search_phrases:
            inlier_id_score_pair[k] = lc_id_score_pair[i]
            k+=1
            
    print('outlier_score_minimum: ', outlier_id_score_pair[:,2].min())
    print('outlier_score_maximum: ', outlier_id_score_pair[:,2].max())
    print('inlier_score_minimum: ', inlier_id_score_pair[:,2].min())
    print('inlier_score_maximum: ', inlier_id_score_pair[:,2].max())
    
    #    fig = plt.figure()
    #    plt.plot(outlier_id_score_pair[:,2], 'ro-')
    #    plt.savefig("score_outlier")
    #    plt.show()
    
    
    #    fig = plt.figure()
    #    plt.plot(inlier_id_score_pair[:,2], 'o-')
    #    plt.savefig("score_inlier")
    #    plt.show()
    
    fig = plt.figure()
    plt.plot(outlier_id_score_pair[:,3], outlier_id_score_pair[:,2], 'ro')
    plt.plot(inlier_id_score_pair[:,3], inlier_id_score_pair[:,2], 'o')
    plt.savefig("combined_score_plot")
    plt.show()
    
    # In[]:
                
    clusters = [[lc_id_score_pair[0]]]
    for i in range(0, len(lc_id_score_pair)-1):
        last_cluster = clusters[-1]
        sumsup = 0
        for j in last_cluster:
            sumsup += j[2]
        ave = sumsup / len(last_cluster)
        #print('ave: ', ave)
        #print('new score: ', lc_id_score_pair[i+1, 2])
        if abs(ave - lc_id_score_pair[i+1, 2]) > threshold or ((lc_id_score_pair[i+1, 2] > 0.99) != (ave > 0.99)):
            clusters.append([lc_id_score_pair[i+1]]) 

        else:
            clusters[-1].append(lc_id_score_pair[i+1])
    
    for i in range(0, len(clusters)):
        print('cluster begins: ', clusters[i][0][0], ' ', clusters[i][0][1])
            
    # In[]:
    for i in range(0, len(clusters)):
        for j in range(0, len(clusters[i])):
            if [str(int(clusters[i][j][0])), str(int(clusters[i][j][1]))] in outlier_pair_search_phrases:
                clusters[i][j] = np.append(clusters[i][j], -1)  # append one value for decision status
            else:
                clusters[i][j] = np.append(clusters[i][j], 1)
    
    decision = []
    inconsistant_cluster = []  
    for i in range(0, len(clusters)):   
        if abs(sum(np.array(clusters[i])[:,4])) == len(clusters[i]):
            
            decision.append(True)
        else:
            decision.append(False)
            inconsistant_cluster.append(clusters[i])
            
    print('consistant clusters/all clusters: ', sum(decision), '/', len(decision))
    if sum(decision) != len(decision):
        for i in range(0, len(decision)):
            if decision[i] == False:
                print('wrong clusters: ', i)
                print('includes ', clusters[i])
    print('sum of all edges', sum([len(cluster) for cluster in clusters]))


# In[]:


    
process()
