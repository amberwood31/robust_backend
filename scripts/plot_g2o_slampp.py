#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import sys
from mpl_toolkits import mplot3d

# In[2]:


def plot_trajectory( file_name , pose_end, options, examine_list):
#options = "2d"
#file_name = "/home/amber/stew/test_backend/manhattan_group10_outlier1000_vertigo/manhattan_seed_7/input.g2o"
#print(file_name)
    vertex = pd.read_csv(file_name, delimiter = " ", header = None, names = range(12)) #

    
    trajectory_x = np.array(vertex[0]) # 2D_trajectory_x
    trajectory_y = np.array(vertex[1]) # 2D_trajectory_y
    if options == "3d":
        trajectory_z = np.array(vertex[2])
    
    fig = plt.figure()
    if options == "2d":
        plt.plot(trajectory_x, trajectory_y, 'b')
    elif options == "3d":
        ax = plt.axes(projection='3d')
        ax.plot3D(trajectory_x, trajectory_y, trajectory_z, 'gray')
    
    plt.axis('equal')
    
    
    filename = file_name.split(".")
    plt.savefig(filename[0])
    plt.show()

    # In[]:
    fig, ax = plt.subplots()
    if options == "2d":
        plt.plot(trajectory_x, trajectory_y, 'b')
        #plt.plot(trajectory_x[0:int(pose_end)], trajectory_y[0:int(pose_end)], 'r')
    elif options == "3d":
        ax = plt.axes(projection='3d')
        ax.plot3D(trajectory_x, trajectory_y, trajectory_z, 'gray')
    
    
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
                row = vertex.loc[vertex[0] == trajectory_x[i-1]]  # Don't use vertex_id. vertex_id from the intermediate poses are wrong
                ax.scatter(row[2], row[3])
                ax.annotate(str(i), (row[2], row[3]))
        elif options == "3d":
            print("pose ", int(vertex_from), ": ", [trajectory_x[vertex_from-1], trajectory_y[vertex_from-1], trajectory_z[vertex_from-1]])
            print("pose ", int(vertex_to), ": ", [trajectory_x[vertex_to-1], trajectory_y[vertex_to-1], trajectory_z[vertex_to-1]])
            
            ax.plot3D([trajectory_x[vertex_from-1], trajectory_x[vertex_to-1]], 
                     [trajectory_y[vertex_from-1], trajectory_y[vertex_to-1]], 
                     [trajectory_z[vertex_from-1], trajectory_z[vertex_to-1]], 'r')
        
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
for i in range(2, len(sys.argv), 2):
    edge_to_plot.append([int(sys.argv[i]), int(sys.argv[i+1])])
    
print ('plotting edges: ')
print(edge_to_plot)
    
plot_trajectory(str(sys.argv[1]), sys.argv[2], "2d", edge_to_plot)




# In[ ]:





# In[ ]:




                                                       


# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:




