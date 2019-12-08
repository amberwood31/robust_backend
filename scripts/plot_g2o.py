#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import sys

# In[2]:


def plot_trajectory( file_name , examine_list):
    #file_name = "/home/amber/pose_dataset/test_rtabmap_backend/manhattan_test_gtsam_1000_outlier_switchsigmoid/output.g2o"
    print(file_name)
    df = pd.read_csv(file_name, delimiter = " ", header = None, names = range(12)) #
    
    vertex = df.loc[df[0] == "VERTEX_SE2"]
    
    edges = df.loc[df[0] == "EDGE_SE2"]
    od_edges = edges.loc[(edges[2] - edges[1]) == 1]
    lc_edges = edges.loc[(edges[2] - edges[1]) != 1]
    
    switch_edges = df.loc[df[0] == "EDGE_SE2_SWITCHABLE"]
    
    vertex = vertex.sort_values(by = 1) # sorting vertex indexes to be increasing sequencial
    trajectory_x = np.array(vertex[[2]]) # 2D_trajectory_x
    trajectory_y = np.array(vertex[[3]]) # 2D_trajectory_y
    
    fig, ax = plt.subplots()
    plt.plot(trajectory_x, trajectory_y, 'b')
    plt.axis('equal')
    
    # In[]:
    
    # using dictionary to convert specific columns 
    convert_dict = {2: int}   
    lc_edges = lc_edges.astype(convert_dict)  
    print(lc_edges)
    
    for index in lc_edges.index:
        plt.plot([trajectory_x[lc_edges.loc[index, 1]-1][0], trajectory_x[lc_edges.loc[index, 2]-1][0]], 
                 [trajectory_y[lc_edges.loc[index, 1]-1][0], trajectory_y[lc_edges.loc[index, 2]-1][0]], 'r')
    
    
    filename = file_name.split(".")
    plt.savefig(filename[0])
    plt.show()
    # In[]:
    fig, ax = plt.subplots()
    plt.plot(trajectory_x, trajectory_y, 'b')
    
    # using dictionary to convert specific columns 
    convert_dict = {2: int}   
    switch_edges = switch_edges.astype(convert_dict) 
    
    #examine_list = [6441, 6589]
    for edge_to_be_examined in examine_list:
        vertex_from = switch_edges.loc[switch_edges[3] == edge_to_be_examined][1]
        vertex_to = switch_edges.loc[switch_edges[3] == edge_to_be_examined][2]
        print("examining edge ", edge_to_be_examined, ": ", int(vertex_from), ", ", int(vertex_to))
        print("pose ", int(vertex_from), ": ", [trajectory_x[vertex_from-1][0], trajectory_y[vertex_from-1][0]])
        print("pose ", int(vertex_to), ": ", [trajectory_x[vertex_to-1][0], trajectory_y[vertex_to-1][0]])
        
        plt.plot([trajectory_x[vertex_from-1][0], trajectory_x[vertex_to-1][0]], 
                 [trajectory_y[vertex_from-1][0], trajectory_y[vertex_to-1][0]], 'r')
    
        vertex_num = trajectory_x.shape[0]
        for i in [int(vertex_from), int(vertex_to)]:
            row = vertex.loc[vertex[1] == i]
            ax.scatter(row[2], row[3])
            ax.annotate(str(i), (row[2], row[3]))
    plt.axis('equal')
    plt.savefig('with_number')
    plt.show()



# In[3]:

print ('READ g2o file: ' + str(sys.argv[1]))

edge_to_plot = []
for i in range(2, len(sys.argv)):
    edge_to_plot.append(int(sys.argv[i]))
    
print ('plotting edges: ')
print(edge_to_plot)
    
plot_trajectory(str(sys.argv[1]), edge_to_plot)




# In[ ]:





# In[ ]:




                                                       


# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:




