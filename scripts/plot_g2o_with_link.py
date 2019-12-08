#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import sys
from mpl_toolkits import mplot3d

# In[2]:
plot_node_degree = False
plot_all_lc = True

def plot_trajectory( file_name , options, examine_list):
#options = "2d"
#file_name = "/home/amber/stew/test_backend/manhattan_group10_outlier1000_vertigo/manhattan_seed_7/input.g2o"
#print(file_name)
    df = pd.read_csv(file_name, delimiter = " ", header = None, names = range(12)) #
    
    if options == "2d":
        vertex = df.loc[df[0] == "VERTEX_SE2"]
        edges = df.loc[df[0] == "EDGE_SE2"]
    elif options == "3d":
        vertex = df.loc[df[0] == "VERTEX_SE3:QUAT"]
        edges = df.loc[df[0] == "EDGE_SE3:QUAT"]
        
    
    print('Number of poses: ', vertex.shape[0])
    print('Number of edges: ', edges.shape[0])
    od_edges = edges.loc[(edges[2] - edges[1]) == 1]
    lc_edges = edges.loc[(edges[2] - edges[1]) != 1]
    
    if options == "2d":
        switch_edges = df.loc[df[0] == "EDGE_SE2_SWITCHABLE"]
    elif options == "3d":
        switch_edges = df.loc[df[0] == "EDGE_SE3_SWITCHABLE"]
        
    
    if plot_node_degree == True: # only generate this for input.g2o
        vertex_from_array = edges[1]
        vertex_to_array = edges[2]
        vertex_from_array.index = range(0,len(vertex_from_array))
        vertex_to_array.index = range(0,len(vertex_to_array))
        node_degree = []
        for j in range(1,len(vertex)+1):
            a = sum(vertex_from_array == j)
            b = sum(vertex_to_array == j)
            node_degree.append(a+b)
            #print(j)
            
        #vertex[5] = pd.Series(node_degree) # cause warning message
        # In[]:
        fig = plt.figure()
        plt.plot(range(1,len(vertex)+1), node_degree, 'b')
        plt.savefig('node_degree')
        plt.show()
        print('minimum_node_degree: ', min(node_degree))
        print('how many of degree_2 edges: ', sum([n == 2 for n in node_degree]))
    
                
        
    
    # In[]:
        # Don't do sorting here. Intermediate pose graph outputs from rtabmap had the reversed vertex_id
        # but the actual poses are in increasing sequencial. Just ignore the vertex_id
    #vertex = vertex.sort_values(by = 1) # sorting vertex indexes to be increasing sequencial
    #vertex = vertex.reset_index(drop=True) # refresh the index
    
    trajectory_x = np.array(vertex[2]) # 2D_trajectory_x
    trajectory_y = np.array(vertex[3]) # 2D_trajectory_y
    if options == "3d":
        trajectory_z = np.array(vertex[4])
    
    fig = plt.figure()
    if options == "2d":
        plt.plot(trajectory_x, trajectory_y, 'b')
    elif options == "3d":
        ax = plt.axes(projection='3d')
        ax.plot3D(trajectory_x, trajectory_y, trajectory_z, 'gray')
    
    plt.axis('equal')
    
    
    # using dictionary to convert specific columns 
    convert_dict = {2: int}   
    lc_edges = lc_edges.astype(convert_dict)
    
    if plot_all_lc == True:
	    for index in lc_edges.index:
	        from_vertex = lc_edges.loc[index, 1]
	        to_vertex = lc_edges.loc[index, 2]
	        if options == "2d":
	            plt.plot([trajectory_x[from_vertex-1], trajectory_x[to_vertex-1]], 
	                     [trajectory_y[from_vertex-1], trajectory_y[to_vertex-1]], 'r')
	        elif options == "3d":
	            ax.plot3D([trajectory_x[from_vertex-1], trajectory_x[to_vertex-1]], 
	                     [trajectory_y[from_vertex-1], trajectory_y[to_vertex-1]],
	                     [trajectory_z[from_vertex-1], trajectory_z[to_vertex-1]], 'r')
    
    
    filename = file_name.split(".")
    plt.savefig(filename[0])
    plt.show()
    # In[]:
    fig, ax = plt.subplots()
    if options == "2d":
        plt.plot(trajectory_x, trajectory_y, 'b')
        if len(sys.argv) > 2:
            pose_start = sys.argv[2]
            pose_end = sys.argv[3]
            plt.plot(trajectory_x[int(pose_start)-1:int(pose_end)], trajectory_y[int(pose_start)-1:int(pose_end)], 'r')
    elif options == "3d":
        ax = plt.axes(projection='3d')
        ax.plot3D(trajectory_x, trajectory_y, trajectory_z, 'gray')
        if len(sys.argv) > 2:
            pose_start = sys.argv[2]
            pose_end = sys.argv[3]
            ax.plot3D(trajectory_x[int(pose_start)-1:int(pose_end)], trajectory_y[int(pose_start)-1:int(pose_end)], trajectory_z[int(pose_start)-1:int(pose_end)], 'r')
    
        
    # using dictionary to convert specific columns 
    convert_dict = {2: int}   
    switch_edges = switch_edges.astype(convert_dict) 
    
    #examine_list = []
    for edge_to_be_examined in examine_list:
        vertex_from = edge_to_be_examined[0]
        vertex_to = edge_to_be_examined[1]
        print("examining edge ", edge_to_be_examined, ": ", int(vertex_from), ", ", int(vertex_to))
        if options == "2d":
            print("pose ", int(vertex_from), ": ", [trajectory_x[vertex_from-1], trajectory_y[vertex_from-1]])
            print("pose ", int(vertex_to), ": ", [trajectory_x[vertex_to-1], trajectory_y[vertex_to-1]])
            
            plt.plot([trajectory_x[vertex_from-1], trajectory_x[vertex_to-1]], 
                     [trajectory_y[vertex_from-1], trajectory_y[vertex_to-1]], 'r')
        
            vertex_num = trajectory_x.shape[0]
            for i in [int(vertex_from), int(vertex_to)]:
                row = vertex.loc[vertex[2] == trajectory_x[i-1]]  # Don't use vertex_id. vertex_id from the intermediate poses are wrong
                ax.scatter(row[2], row[3])
                ax.annotate(str(i), (row[2], row[3]))
        elif options == "3d":
            print("pose ", int(vertex_from), ": ", [trajectory_x[vertex_from-1], trajectory_y[vertex_from-1], trajectory_z[vertex_from-1]])
            print("pose ", int(vertex_to), ": ", [trajectory_x[vertex_to-1], trajectory_y[vertex_to-1], trajectory_z[vertex_to-1]])
            
            ax.plot3D([trajectory_x[vertex_from-1], trajectory_x[vertex_to-1]], 
                     [trajectory_y[vertex_from-1], trajectory_y[vertex_to-1]], 
                     [trajectory_z[vertex_from-1], trajectory_z[vertex_to-1]], 'b')
        
            vertex_num = trajectory_x.shape[0]
            #for i in [int(vertex_from), int(vertex_to)]:
            #    row = vertex.loc[vertex[1] == i]
            #    ax.scatter(row[2], row[3])
            #    ax.annotate(str(i), (row[2], row[3]))
                
    plt.axis('equal')
    plt.savefig('with_specific_link')
    plt.show()



# In[3]:

print ('READ g2o file: ' + str(sys.argv[1]))

edge_to_plot = []
for i in range(4, len(sys.argv), 2):
    edge_to_plot.append([int(sys.argv[i]), int(sys.argv[i+1])])
    
print ('plotting edges: ')
print(edge_to_plot)
    
plot_trajectory(str(sys.argv[1]), "2d", edge_to_plot)




# In[ ]:





# In[ ]:




                                                       


# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:




