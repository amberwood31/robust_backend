#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import sys
from mpl_toolkits import mplot3d

# In[2]:


def plot_single_g2o( file_name , fig_name, options, examine_list,  ax):
    #options = "3d"
    #file_name = "/home/amber/pose_dataset/test_rtabmap_backend/analysis_chamber/output.g2o"
    #if not ax:
    #    _, ax = plt.subplots()
    print(file_name)
    df = pd.read_csv(file_name, delimiter = " ", header = None, names = range(12)) #
    
    if options == "2d":
        vertex = df.loc[df[0] == "VERTEX_SE2"]
        edges = df.loc[df[0] == "EDGE_SE2"]
    elif options == "3d":
        vertex = df.loc[df[0] == "VERTEX_SE3:QUAT"]
        edges = df.loc[df[0] == "EDGE_SE3:QUAT"]
        
    
    od_edges = edges.loc[(edges[2] - edges[1]) == 1]
    lc_edges = edges.loc[(edges[2] - edges[1]) != 1]
    
    if options == "2d":
        switch_edges = df.loc[df[0] == "EDGE_SE2_SWITCHABLE"]
    elif options == "3d":
        switch_edges = df.loc[df[0] == "EDGE_SE3_SWITCHABLE"]
    
    vertex = vertex.sort_values(by = 1) # sorting vertex indexes to be increasing sequencial
    trajectory_x = np.array(vertex[2]) # 2D_trajectory_x
    trajectory_y = np.array(vertex[3]) # 2D_trajectory_y
    if options == "3d":
        trajectory_z = np.array(vertex[4])
    
    #fig = plt.figure()
    if options == "2d":

        ax.plot(trajectory_x, trajectory_y,  label=fig_name) #label=file_name.split("/")[-1]
    elif options == "3d":
        #ax = plt.axes(projection='3d')
        ax.plot3D(trajectory_x, trajectory_y, trajectory_z,  label=fig_name) #label=file_name.split("/")[-1]
        ax.set_zticks([-20,0,20])
    #plt.legend((file_name.split("/")[-2],))
    #plt.axis('equal')
    
    
    # In[]:
def plot_specific_edge():
    fig = plt.figure()
    if options == "2d":
        plt.plot(trajectory_x, trajectory_y, 'b')
    elif options == "3d":
        ax = plt.axes(projection='3d')
        ax.plot3D(trajectory_x, trajectory_y, trajectory_z, 'gray')
    
        
    # using dictionary to convert specific columns 
    convert_dict = {2: int}   
    switch_edges = switch_edges.astype(convert_dict) 
    
    #examine_list = [5873]
    for edge_to_be_examined in examine_list:
        vertex_from = switch_edges.loc[switch_edges[3] == edge_to_be_examined][1]
        vertex_to = switch_edges.loc[switch_edges[3] == edge_to_be_examined][2]
        print("examining edge ", edge_to_be_examined, ": ", int(vertex_from), ", ", int(vertex_to))
        if options == "2d":
            print("pose ", int(vertex_from), ": ", [trajectory_x[vertex_from-1], trajectory_y[vertex_from-1]])
            print("pose ", int(vertex_to), ": ", [trajectory_x[vertex_to-1], trajectory_y[vertex_to-1]])
            
            plt.plot([trajectory_x[vertex_from-1], trajectory_x[vertex_to-1]], 
                     [trajectory_y[vertex_from-1], trajectory_y[vertex_to-1]], 'r')
        
            vertex_num = trajectory_x.shape[0]
            for i in [int(vertex_from), int(vertex_to)]:
                row = vertex.loc[vertex[1] == i]
                ax.scatter(row[2], row[3])
                ax.annotate(str(i), (row[2], row[3]))
        elif options == "3d":
            print("pose ", int(vertex_from), ": ", [trajectory_x[vertex_from-1], trajectory_y[vertex_from-1], trajectory_z[vertex_from-1]])
            print("pose ", int(vertex_to), ": ", [trajectory_x[vertex_to-1], trajectory_y[vertex_to-1], trajectory_z[vertex_to-1]])
            
            ax.plot3D([trajectory_x[vertex_from-1][0], trajectory_x[vertex_to-1][0]], 
                     [trajectory_y[vertex_from-1][0], trajectory_y[vertex_to-1][0]], 
                     [trajectory_z[vertex_from-1][0], trajectory_z[vertex_to-1][0]], 'r')
        
            vertex_num = trajectory_x.shape[0]
            #for i in [int(vertex_from), int(vertex_to)]:
            #    row = vertex.loc[vertex[1] == i]
            #    ax.scatter(row[2], row[3])
            #    ax.annotate(str(i), (row[2], row[3]))
                
    #plt.axis('equal')
    plt.savefig('with_number')
    plt.show()



# In[3]:

def simple_plot():
    print ('READ g2o file: ' + str(sys.argv[1]))

    edge_to_plot = []
    for i in range(2, len(sys.argv)):
        edge_to_plot.append(int(sys.argv[i]))
        
    print ('plotting edges: ')
    print(edge_to_plot)
        
    plot_trajectory(str(sys.argv[1]), "3d", edge_to_plot)




# In[ ]:


g2o_path_a = sys.argv[1]
g2o_path_b = sys.argv[2]
#g2o_path_c = sys.argv[3]


fig, ax = plt.subplots()
#ax = plt.axes(projection='3d')

#for file in sys.argv[1:len(sys.argv)]:
#	plot_single_g2o(file, fig_name, "2d", [], ax = ax)

ground_truth = sys.argv[1]
initial_graph = sys.argv[2]

plot_single_g2o(ground_truth, "ground_truth", "2d", [], ax = ax)
plot_single_g2o(initial_graph, "initial_graph", "2d", [], ax = ax)

#plot_single_g2o(g2o_path_a, "3d", [], 'grey', ax = ax)
#plot_single_g2o(g2o_path_b, "3d", [], 'r', ax = ax)
plt.axis('equal')

handles, labels = ax.get_legend_handles_labels()
ax.legend(handles, labels, loc=4)
plt.savefig("comparison_plot",dpi=300)

plt.show()


# In[ ]:




                                                       


# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:




