#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import sys
from file_read_backwards import FileReadBackwards as readreverse
import math


examine_edge_option = 1
iteration = 30
threshold = 0.5  # to determine whether it's switched on or off after optimization

generate_figure = False


#pose_quantity = 808 # manhattan: 3499 garage: 1660 csail: 1044 mit: 808
#inlier_quantity = 20 # manhattan: 2097 garage: 4615 csail: 128 mit: 20
#outlier_quantity = 5

# In[]:

def process( options ):
    
#folder_path = "/home/amber/stew/test_backend/analysis_chamber"
#pose_quantity = 808
#inlier_quantity = 20
#outlier_quantity = 20
#options = "2d"

    print(sys.argv)
    
    if len(sys.argv) > 1:
        folder_path = sys.argv[1]
        pose_quantity = int(sys.argv[2])
        inlier_quantity = int(sys.argv[3])
        outlier_quantity = int(sys.argv[4])        
    
    
    posegraph_input_path = folder_path+"/input.g2o"
    output_path = folder_path+"/output.g2o"
    text_output_path = folder_path+"/output.txt" 
    clustering_results_path = folder_path+"/clustering_results.txt"   
    lc_edge_quantity = inlier_quantity + outlier_quantity 
    
    # In[]:
       
    # read input file, find last N edges
    #find all edge ID-pair and outlier ID-pair
    f = open(posegraph_input_path, "r")
    i = 0
    all_lc_edge_pair_search_phrases = []    # list of [str0, str1], each strpair represents one loop closure
    outlier_pair_search_phrases = []        # list of [str0, str1], each strpair represents one loop closure
    with readreverse(posegraph_input_path, encoding="utf-8") as obj:
        while i < outlier_quantity + inlier_quantity:
            line = obj.readline()
            line_stripped = line.strip('\n')
            line_splitted = line_stripped.split(' ')
            if i < outlier_quantity:
                outlier_pair_search_phrases.append([line_splitted[1], line_splitted[2]])
            if abs(int(line_splitted[1]) - int(float(line_splitted[2]))) != 1: # deals with garage dataset, where edges are already sorted
                all_lc_edge_pair_search_phrases.append([line_splitted[1], str(int(float(line_splitted[2])))])
                i += 1 # only increment when it's nonsequential edge
            
                
            
    # In[]:
    
    # read clustering_results.txt, find already deleted edges
    
    f = open(clustering_results_path, "r")
    deleted_quantity = 0
    rejected_loops = []
    lines = f.readlines()
    for line in lines:
        line_stripped = line.strip('\n')
        line_splitted = line_stripped.split(' ')
        if line_splitted[0]== "CLUSTER_R":
            deleted_quantity += 1 
            rejected_loops.append([line_splitted[1], line_splitted[2]])
            
    rejected_outliers = []
    rejected_inliers = []

    for loop in rejected_loops:
        if loop in outlier_pair_search_phrases:
            rejected_outliers.append(loop)
        else:
            rejected_inliers.append(loop)
            
    # In[]:
            
    #read output.g2o, find outlier ID-pair 
            
    f = open(output_path, "r")
    outlier_id_pair = np.zeros((outlier_quantity - len(rejected_outliers), 3), dtype = int)      ## deleted edges are not in output.g2o
    #   array of [int0, int1, int2], int0: switchcounter, int1: vertex_from, int2: vertex_to
    
    
    i = 0
    lines = f.readlines()
    for x in lines:
        x_stripped = x.strip('\n')
        x_splitted = x_stripped.split(' ')
        if options == "2d":
            prefix = "EDGE_SE2_SWITCHABLE"
        elif options == "3d":
            prefix = "EDGE_SE3_SWITCHABLE"
        if x_splitted[0]==prefix:
            if [x_splitted[1], x_splitted[2]] in outlier_pair_search_phrases:
                outlier_id_pair[i] = np.array([int(x_splitted[3]), int(x_splitted[1]), int(x_splitted[2])])
                #print(all_switch_edge[i])
                i += 1
    
    outlier_pair_df = pd.DataFrame(columns = outlier_id_pair[:,0], index=[0]) 
    # put data in dataframe for easier access
    # DF column names: int (switch counter)
    #        0th row: [int0, int1], int0: vertex_from, int1: vertex_to
           
    
    # In[]:
    for i in range(0, outlier_quantity - len(rejected_outliers)):
        outlier_id=outlier_id_pair[i,0]
        outlier_pair_df.loc[0, outlier_id]=outlier_id_pair[i,1:3]
    
    outlier_id_search_phrases = [] # list of ['s<switch counter>:'] for searching in the output.txt
    
    for rows in outlier_id_pair:
        outlier_id_search_phrases.append("s"+str(rows[0])+":")
    
    # In[]:
    #find all_edge ID-pair
        
    f = open(output_path, "r")
    all_edge_id_pair = np.zeros((lc_edge_quantity - deleted_quantity, 3), dtype = int) ## deleted edges are not in output.g2o
    #   array of [int0, int1, int2], int0: switchcounter, int1: vertex_from, int2: vertex_to
    
    i = 0
    while i < lc_edge_quantity - deleted_quantity:
        x = f.readline()
        x_stripped = x.strip('\n')
        x_splitted = x_stripped.split(' ')
        if options == "2d":
            prefix = "EDGE_SE2_SWITCHABLE"
        elif options == "3d":
            prefix = "EDGE_SE3_SWITCHABLE"
        if x_splitted[0]==prefix:
            if [x_splitted[1], x_splitted[2]] in all_lc_edge_pair_search_phrases:
                all_edge_id_pair[i] = np.array([int(x_splitted[3]), int(x_splitted[1]), int(x_splitted[2])])
                #print(all_switch_edge[i])
                i += 1
              
    
    ## In[]:
    all_edge_pair_df = pd.DataFrame(columns = all_edge_id_pair[:,0], index=[0]) 
    # put data in dataframe for easier access
    # DF column names: int (switch counter)
    #        0th row: [int0, int1], int0: vertex_from, int1: vertex_to
    
    
    for i in range(0, lc_edge_quantity - deleted_quantity):
        e_id=all_edge_id_pair[:,0][i]
        all_edge_pair_df[e_id].iloc[0]=all_edge_id_pair[i,1:3]
    
    
    
    # In[2]:
            
    # read output.txt, find the value of all LC edges after the last iteration
        
    lc_edge_search_phrases = [] # list of ['s<switch counter>:'] for searching in the output.txt
    for i in range(pose_quantity, pose_quantity + lc_edge_quantity - deleted_quantity): 
        # pose zero  will be drop in rtabmap
        lc_edge_search_phrases.append("s"+str(i)+":")
    
    
    all_lc_edge_value = pd.DataFrame(columns = lc_edge_search_phrases, index=[0, 1, 2])
    #   column names:   's<switch counter>:'
    #   0th row:        switch variable value
    #   1st row:        [vertex_from, vertex_to]
    #   2nd row:        bool, indicating whether is switched on or off, depends on threshold
    
    i = 0
    with readreverse(text_output_path, encoding="utf-8") as obj:
        while i < lc_edge_quantity - deleted_quantity: # only get the last iteration
            line = obj.readline()
            
            line_stripped = line.strip('\n')
            line_splitted = line_stripped.split(' ')
            if len(line_splitted) > 1:
                if str(line_splitted[1]) in lc_edge_search_phrases:
                    all_lc_edge_value[str(line_splitted[1])][0] = float(line_splitted[4])
                    temp_s = str(line_splitted[1])
                    temp_str=temp_s.strip('s')
                    temp_string=temp_str.strip(':')
                    id_number_only= int(temp_string)
                    all_lc_edge_value[str(line_splitted[1])][1] = all_edge_pair_df[id_number_only].iloc[0]
                    i += 1
        
        
    # In[]:
        
    # calculate precision/recall rate of outlier/inlier
    
                    
    for column in all_lc_edge_value:
        all_lc_edge_value[column][2] = (all_lc_edge_value[column][0] > threshold)
        
    outlier_analysis = all_lc_edge_value[outlier_id_search_phrases]
    #outlier_analysis = outlier_analysis.drop('s5644:',1)
    
    if generate_figure == True:
        fig, ax = plt.subplots()
        plt.plot(range(0,outlier_quantity - len(rejected_outliers)), (outlier_analysis.iloc[0]), 'ro-')
        plt.legend(("outlier value",))
        plt.savefig("outlier_variance")
        plt.show()
    
    pd.set_option('display.max_columns', None)  # or 1000
    pd.set_option('display.max_rows', None)  # or 1000
    pd.set_option('display.max_colwidth', -1)  # or 199
    print("threshold: ", threshold)
    print("outliers acceptted: ", sum(outlier_analysis.iloc[2]), "/", outlier_quantity - len(rejected_outliers))
    print("accepted outliers: ", outlier_analysis.loc[:,outlier_analysis.iloc[2] == True].columns)
    print("accepted outlier: ")
    print(outlier_analysis.loc[:,outlier_analysis.iloc[2] == True])
        
    inlier_analysis = all_lc_edge_value.drop(outlier_id_search_phrases, 1)
    
    if generate_figure == True:
        fig, ax = plt.subplots()
        plt.plot(range(0,inlier_quantity - len(rejected_inliers)), (inlier_analysis.iloc[0]), 'o-')
        plt.legend(("inlier value",))
        plt.savefig("inlier_variance")
        plt.show()
    
    
    print("inliers acceptted: ", sum(inlier_analysis.iloc[2]), "/", lc_edge_quantity- len(rejected_inliers) -outlier_quantity)
    print("rejected inlier: ")
    print(inlier_analysis.loc[:,inlier_analysis.iloc[2] == False])
    print()
    
    
    # In[]:
    
    # get the convergence curve of all lc edge value:
    if examine_edge_option == 1:
                  
        f = open(text_output_path, "r")
        
        lc_edge_value_convergence = pd.DataFrame(columns = lc_edge_search_phrases, index=[0])
        #   column names:   's<switch counter>:'
        #       0st row:    list of values over all iterations
        # 
        
        i = 0
        while i < (lc_edge_quantity - deleted_quantity) *(iteration+1): # including initial estimate
            line = f.readline()
            line_stripped = line.strip('\n')
            line_splitted = line_stripped.split(' ')
            if len(line_splitted) > 1:
                if  str(line_splitted[1]) in lc_edge_search_phrases:
                    if type(lc_edge_value_convergence[str(line_splitted[1])][0]) != list:
                        lc_edge_value_convergence[str(line_splitted[1])][0] = []
                    
                    lc_edge_value_convergence[str(line_splitted[1])][0].append(float(line_splitted[4]))
                    i += 1
                    #print(i)
        # In[]:
        
        # examine a specified edge value convergence
        
        examine_edge = []      #3625, 3781, 4139, 4291, 6441
        new_search_phases = []
        if len(sys.argv) > 5:
            for i in range(5, len(sys.argv)):
                examine_edge.append(sys.argv[i]) 
                
        for edge in examine_edge:
            new_search_phases.append("s"+str(edge)+":")
    
    
        for j in new_search_phases:
            
            plt.plot(lc_edge_value_convergence[j][0])
            plt.title(j+str(all_lc_edge_value[j][1][0])+','+str(all_lc_edge_value[j][1][1]))
            plt.savefig(j)
            plt.show()
    


# In[]:
        

def sigmoid(x):
    type(x)
    sig = []
    for i in x:
        sig.append(1.0/(1.0+math.exp(-i)))
        
    return sig
# In[]:
    
        
process("2d")
