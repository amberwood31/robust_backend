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
from os import path


# In[]:

option = "2d"
generate_figure = False

# In[]:



def read_pose(file_path, method_name):
    
    if option == "2d":
        pose = np.zeros([pose_quantity, 2])
    elif option == "3d":
        pose = np.zeros([pose_quantity, 3])
        
    if not path.exists(file_path):  
        
        return pose
        
    else:
        f = open(file_path, "r")
        
        
    if method_name == 'slampp': # slampp results have pose 0
        
        i = 0
        while i < pose_quantity +1:
            x = f.readline()
            x_stripped = x.strip('\n')
            x_splitted = x_stripped.split(' ')   
            if i != 0: # don't read pose 0            
                pose[i-1] = np.array([x_splitted[0], x_splitted[1]], dtype = float)
            i += 1
    else:
        
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
    #print(diff_groundtruth[:,])
    
    if generate_figure == True:
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
        return average
        #return [average, max_dif_x, max_dif_y, max_dif_z]
    else:
        return average
        #return [average, max_dif_x, max_dif_y]
        

# In[]:
# read compare pose

def process(dataset_name, sample_size, pose_groundtruth, method_folder):
    
    #pose_quantity = int(sys.argv[2]) # manhattan: 3449 CSAIL: 1044 garage: 1660


    ate_list = [None] * sample_size
    for seed_number in range(1, sample_size+1):
        
        ate_list[seed_number-1] = [None] * len(method_folder)
        
        method_i = 0
        for each_method in method_folder:       
            
            temp_list = each_method.split('/')
            tem_list = temp_list[-2].split('_')
            method_name = tem_list[0]
            configuration = tem_list[-1]
            if seed_number == 1:
                print('method_name: ', method_name)
                print('configuration: ', configuration)
            
            if method_name == 'slampp':
                file_name = 'output_' + str(seed_number) + '.txt'
                file_absolute_path = each_method + file_name
                
            else:
                sub_folder_path = each_method + dataset_name + '_seed_' + str(seed_number) + '/'
                file_name = 'output.g2o'
                file_absolute_path = sub_folder_path + file_name
                
            pose_temp = read_pose(file_absolute_path, method_name)
            ate_list[seed_number -1][method_i] = calculate_average_translation_error(pose_groundtruth, pose_temp, method_name)                
            method_i += 1
            
    return ate_list
            
            

    
    # compare
    
    #mtx1, mtx2, disparity = procrustes(pose_groundtruth, pose_a)
    #scaling = np.trace(pose_groundtruth.dot(pose_groundtruth.transpose()))
    #print( 'cbsc disparity: ', disparity*scaling)

    #mtx1, mtx2, disparity = procrustes(pose_groundtruth, pose_b)
    #scaling = np.trace(pose_groundtruth.dot(pose_groundtruth.transpose()))
    #print( 'DCS disparity: ', disparity*scaling)

    
# In[]: test inputs

dataset_name = 'manhattan'
pose_quantity = 3449 # manhattan: 3449 CSAIL: 1044 garage: 1660
sample_size = 10
configuration = 'random1000'

ground_truth_file = '/home/amber/stew/test_backend/groundtruth/'+dataset_name + '.g2o'
pose_groundtruth = read_pose(ground_truth_file, '')

dir_path = '/home/amber/stew/test_backend/'
method_list = ['vertigo', 'dcs', 'cbsc', 'slampp']
method_folder = []
for method in method_list:
    method_folder.append(dir_path+dataset_name+'/'+method+ '_'+dataset_name+'_'+configuration+'/' )
    
    
# In[]:
    
    
print(sys.argv)

dataset_name = sys.argv[1]
pose_quantity = int(sys.argv[2]) # manhattan: 3449 CSAIL: 1044 garage: 1660
sample_size = int(sys.argv[3])
configuration = sys.argv[4]
ground_truth_file = sys.argv[5]
pose_groundtruth = read_pose(ground_truth_file, '')
method_list = sys.argv[6:]

dir_path = '/home/amber/stew/test_backend/'
method_folder = []
for method in method_list:
    method_folder.append(dir_path+dataset_name+'/'+method+ '_'+dataset_name+'_'+configuration+'/' )
    
# In[]:
ate = process(dataset_name, sample_size, pose_groundtruth, method_folder)
for each_seed in ate:
	print(each_seed)


