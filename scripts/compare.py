#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Aug  8 12:33:08 2019

@author: amber
"""

# In[1]:


import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import sys
from scipy.spatial import procrustes
from scipy.linalg import orthogonal_procrustes


# In[]:

pose_quantity = int(sys.argv[5]) # manhattan: 3449 CSAIL: 1044 garage: 1660
option = "2d"
#seed = sys.argv[5] # only used for figure names

#dir_path = "/home/amber/stew/"
#file_name = "/output.g2o"


#ground_truth_path = "test_backend/ground_truth_CSAIL_iter40/output.g2o"
#compare_path_a = "test_backend/csail_random64/csail_seed_1/output.g2o"
#compare_path_b = "pose_dataset/dcs10_csail_random64/csail.g2o_seed_1_dcs.g2o"

# In[]:



def read_pose(path):
    f = open(path, "r")
    if option == "2d":
        pose = np.zeros([pose_quantity, 2])
    elif option == "3d":
        pose = np.zeros([pose_quantity, 3])
        
    i = 0
    while i < pose_quantity:
        x = f.readline()
        x_stripped = x.strip('\n')
        x_splitted = x_stripped.split(' ')
        if option == "2d":
            if x_splitted[0]=="VERTEX_SE2":

                pose[i] = np.array([x_splitted[2], x_splitted[3]], dtype = float)
                #print(i)
                i += 1
        elif option == "3d":
            if x_splitted[0]=="VERTEX_SE3:QUAT":

                pose[i] = np.array([x_splitted[2], x_splitted[3], x_splitted[4]], dtype = float)
                #print(all_switch_edge[i])
                i += 1


    return pose

# In[]:

def calculate_average_translation_error(pose_groundtruth, pose_tocompare, fig_name):
    R, scale = orthogonal_procrustes(pose_groundtruth, pose_tocompare)
    rotated_groundtruth = pose_groundtruth.dot(R)
    diff_groundtruth = rotated_groundtruth - pose_tocompare
    print(diff_groundtruth[:,])
    
    fig, ax = plt.subplots() # plot comparisons
    if option == "2d":
        plt.plot(rotated_groundtruth[:,0], rotated_groundtruth[:,1], 'green')
        plt.plot(pose_tocompare[:,0], pose_tocompare[:,1], 'r')
        plt.axis('equal')
        plt.savefig(fig_name+'_trajectory')
        plt.show()
     
        
    
    fig, ax = plt.subplots()
    plt.plot(diff_groundtruth[:, 0], label='x')
    plt.plot(diff_groundtruth[:,1], label='y')
    
    
    if option == "3d":
        plt.plot(diff_groundtruth[:, 2], label='z')
    handles, labels = ax.get_legend_handles_labels()
    ax.legend(handles, labels)
    plt.savefig(fig_name+'_error')
    plt.show()
    
    if option == "2d":
        translation_diff = np.sqrt(np.square(diff_groundtruth[:,0]) + np.square(diff_groundtruth[:,1]))
    elif option == "3d":
        translation_diff = np.sqrt(np.square(diff_groundtruth[:,0]) + np.square(diff_groundtruth[:,1]) + np.square(diff_groundtruth[:,2]))
    #print(translation_diff)
    average = np.mean(translation_diff)
    max_dif_x = np.max(diff_groundtruth[:, 0])
    max_dif_y = np.max(diff_groundtruth[:, 1])
    if option == "3d":
        max_dif_z = np.max(diff_groundtruth[:, 2])

    if option == "3d":
        return [average, max_dif_x, max_dif_y, max_dif_z]
    else:
        return [average, max_dif_x, max_dif_y]
        

# In[]:
# read compare pose

def process():
    print(sys.argv)
    
    pose_groundtruth = read_pose(sys.argv[1])
    pose_a = read_pose(sys.argv[2])
    pose_b = read_pose(sys.argv[3])
    pose_c = read_pose(sys.argv[4])
    
    # compare
    
    #mtx1, mtx2, disparity = procrustes(pose_groundtruth, pose_a)
    #scaling = np.trace(pose_groundtruth.dot(pose_groundtruth.transpose()))
    #print( 'cbsc disparity: ', disparity*scaling)

    #mtx1, mtx2, disparity = procrustes(pose_groundtruth, pose_b)
    #scaling = np.trace(pose_groundtruth.dot(pose_groundtruth.transpose()))
    #print( 'DCS disparity: ', disparity*scaling)
    
    average_a = calculate_average_translation_error(pose_groundtruth, pose_a, 'cbsc')
    print("average translation error ", "(cbsc)", ": ", average_a)
    
    average_b = calculate_average_translation_error(pose_groundtruth, pose_b, 'dcs')
    print("average translation error ", "(dcs)", ": ", average_b)
    
    average_c = calculate_average_translation_error(pose_groundtruth, pose_c, 'vertigo')
    print("average translation error ", "(vertigo)", ": ", average_c)
    
# In[]:

process()


