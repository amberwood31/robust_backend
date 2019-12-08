#!/usr/bin/env python
# coding: utf-8

# In[1]:


import matplotlib.pyplot as plt
import pandas as pd
import numpy as np


# In[5]:

inlier_path = "/home/amber/SLAM_plus_plus_v2.30/slam/bin/inlier_analysis.txt"
outlier_path = "/home/amber/SLAM_plus_plus_v2.30/slam/bin/outlier_analysis.txt"

df_inlier = pd.read_csv(inlier_path, delimiter = " ", header = None, names = ['vertex_from', 'vertex_to', 'transform', 'infor', 'ofc', 'mi'])
df_inlier = df_inlier.sort_values(by=['vertex_from'])
df_inlier = df_inlier.reset_index(drop=True)
inlier_list = []
for i in df_inlier.index:
    inlier_list.append([df_inlier['vertex_from'].iloc[i], df_inlier['vertex_to'].iloc[i]])

df_outlier = pd.read_csv(outlier_path, delimiter = " ", header = None, names = ['vertex_from', 'vertex_to', 'transform', 'infor', 'ofc', 'mi'])
df_outlier = df_outlier.sort_values(by=['vertex_from'])
df_outlier = df_outlier.reset_index(drop=True)
outlier_list = []
for i in df_outlier.index:
    outlier_list.append([df_outlier['vertex_from'].iloc[i], df_outlier['vertex_to'].iloc[i]])



#real_ofc_path = "/home/amber/SLAM_plus_plus_v2.30/slam/bin/real_ofc.txt"
#df_rofc = pd.read_csv(real_ofc_path, delimiter = " ", header = None, names = ['vertex_from', 'vertex_to', 'ofc'])
#df_rofc = df_rofc.sort_values(by=['vertex_from'])
#df_rofc = df_rofc.reset_index(drop=True)

df_outlier['status'] = 1
df_inlier['status'] = 0


for i in df_full.index:
    if [df_full['vertex_from'].iloc[i], df_full['vertex_to'].iloc[i]] in inlier_list:
        df_full.loc[i, 'status'] = 0
    elif [df_full['vertex_from'].iloc[i], df_full['vertex_to'].iloc[i]] in outlier_list:
        df_full.loc[i, 'status'] = 1
# In[]:

#fig = plt.figure()
#plt.plot(df_inlier['ofc'])
#file_path_example = "full_analysis_MIT_group10_no_outlier_rejection"
full_analysis_path = "/home/amber/stew/slam++/bin/full_analysis.txt"
df_full = pd.read_csv(full_analysis_path, delimiter = " ", header = None, names = ['vertex_from', 'vertex_to', 'ofc', 'score'])
df_full = df_full.sort_values(by=['vertex_from'])
df_full = df_full.reset_index(drop=True)


fig = plt.figure()
plt.plot(df_full['ofc'], 'ro-')

fig = plt.figure()
plt.plot(df_full['score'], 'o-')





# In[4]:


print('outlier_ofc_minimum: ', df_outlier['ofc'].min())
print('outlier_ofc_maximum: ', df_outlier['ofc'].max())
print('inlier_ofc_minimum: ', df_inlier['ofc'].min())
print('inlier_ofc_maximum: ', df_inlier['ofc'].max())
print(' ')
print('outlier_mi_minimum: ', df_outlier['mi'].min())
print('outlier_mi_maximum: ', df_outlier['mi'].max())
print('inlier_mi_minimum: ', df_inlier['mi'].min())
print('inlier_mi_maximum: ', df_inlier['mi'].max())



# In[ ]:

def clustering_ofc(threshold, df_full):
    #threshold = 0.2
    cluster = []
    for i in df_full.index:
        if len(cluster) == 0:
            cluster.append([df_full.iloc[i]])
        else:            
            if abs(df_full.iloc[i]['ofc'] - df_full.iloc[i-1]['ofc']) > threshold: # starting new cluster
                cluster.append([df_full.iloc[i]])
            else:
                cluster[-1].append(df_full.iloc[i])
                
    #print('generated ', len(cluster), ' cluster')
    
    cluster_list = []  
    
    for individual_cluster in cluster:
        df_cluster = pd.concat(individual_cluster, axis=1)   
        cluster_list.append(df_cluster) # transfer list into dataframe for each cluster
    
    cluster_length = np.array([])
    for i in cluster_list:
        cluster_length = np.append(cluster_length,i.shape[1]) # check the size of cluster_length

    return cluster_list, cluster_length

def evaluation_status(cluster_list):
    cluster_length = np.array([])
    for i in cluster_list:
        cluster_length = np.append(cluster_length,i.shape[1]) # check the size of cluster_length
    
    cluster_status = np.array([])
    for i in cluster_list:
        cluster_status = np.append(cluster_status, sum(i.loc['status'])) # check the status of individual cluster
        
    evaluation = (cluster_length != cluster_status) & (cluster_status != 0.0) # if true, mixed group; if negative, homogeneous group 
    
    print('heterogeneous cluster/ all cluster: ', sum(evaluation), ',', len(cluster_list))
    return cluster_status, evaluation

# In[ ]:
cluster_ofc, cluster_length_ofc = clustering_ofc(10, df_full)
cluster_ofc_status, evaluation_ofc = evaluation_status(cluster_ofc)


def mi_gain_std( cluster_list):
    mi_gain_cluster = []
    for i in cluster_list:
        if i.shape[1] == 1:
            mi_gain_cluster.append(1000)
        else:
            mi_gain_cluster.append( i.loc['mi'].std() )
    
    return mi_gain_cluster

def ofc_std( cluster_list):
    ofc_cluster = []
    for i in cluster_list:
        if i.shape[1] == 1:
            ofc_cluster.append(1000)
        else:
            ofc_cluster.append( i.loc['ofc'].std() )
    
    return ofc_cluster

# In[]:

mi_gain_cluster = mi_gain_std(cluster_ofc)
while min(mi_gain_cluster) < 1.0:
    todel_index = []
    for j in range(0, len(mi_gain_cluster)):
        if mi_gain_cluster[j] < 1.0 and mi_gain_cluster[j] != 0:
            print(j)
            temp = [cluster_ofc[j-1], cluster_ofc[j]]
            cluster_ofc[j-1] = pd.concat(temp, axis=1)
            todel_index.append(j)
    
    for k in todel_index:
        del cluster_ofc[k]
        
    mi_gain_cluster = []
    for i in cluster_ofc:
        if i.shape[1] == 1:
            mi_gain_cluster.append(1000)
        else:
            mi_gain_cluster.append( i.loc['mi'].std() )

evaluation_status(cluster_ofc)
# In[]:

zoomin_cluster_ofc = []
zoomin_cluster_length = np.array([])
for cluster_i in cluster_ofc:
    temp_cluster = cluster_i.T.reset_index(drop=True)
    temp_clu, temp_len = clustering_ofc(0.001, temp_cluster)
    zoomin_cluster_ofc += temp_clu
    zoomin_cluster_length = np.append(zoomin_cluster_length, temp_len)

zoomin_cluster_ofc_status, zoomin_evaluation_ofc = evaluation_status(zoomin_cluster_ofc, zoomin_cluster_length)
    

# In[]:

import time
start_time = time.time()

threshold = 50
cluster = []

cluster_vertex_limit = np.array([[-1,-1,-1,-1]]) # [from_high, from_low, to_high, to_low]
for i in df_full.index:
    #print(i)
    set = 0 # 0 indicates edge is free, 1 indicates edge has been set to a cluster
    if len(cluster) == 0:
        cluster.append([df_full.iloc[i]])
        cluster_vertex_limit = np.array([[df_full.iloc[i]['vertex_from'] , df_full.iloc[i]['vertex_from'], \
                                         df_full.iloc[i]['vertex_to'] , df_full.iloc[i]['vertex_to']]])
    else:            
        for j in range(0, len(cluster)): # check all existing cluster
            if (abs(df_full.iloc[i]['vertex_from'] - cluster_vertex_limit[j][0]) < threshold \
            or abs(df_full.iloc[i]['vertex_from'] - cluster_vertex_limit[j][1]) < threshold) \
            and (abs(df_full.iloc[i]['vertex_to'] - cluster_vertex_limit[j][2]) < threshold \
            or abs(df_full.iloc[i]['vertex_to'] - cluster_vertex_limit[j][3]) < threshold): 
                
                cluster[j].append(df_full.iloc[i])
                set = 1
                
                if df_full.iloc[i]['vertex_from'] > cluster_vertex_limit[j][0]:
                    cluster_vertex_limit[j][0] = df_full.iloc[i]['vertex_from']
                if df_full.iloc[i]['vertex_from'] < cluster_vertex_limit[j][1]:
                    cluster_vertex_limit[j][1] = df_full.iloc[i]['vertex_from']
                if df_full.iloc[i]['vertex_to'] > cluster_vertex_limit[j][2]:
                    cluster_vertex_limit[j][2] = df_full.iloc[i]['vertex_to']
                if df_full.iloc[i]['vertex_to'] < cluster_vertex_limit[j][3]:
                    cluster_vertex_limit[j][3] = df_full.iloc[i]['vertex_to']
                break 
                
        if set == 0:
            cluster.append([df_full.iloc[i]]) # starting new cluster if edge is free after looping through all clusters
            cluster_vertex_limit = np.append(cluster_vertex_limit, [[df_full.iloc[i]['vertex_from'], \
                                                                     df_full.iloc[i]['vertex_from'], \
                                                                     df_full.iloc[i]['vertex_to'], \
                                                                     df_full.iloc[i]['vertex_to']]], axis=0)
        
                
            
print('generated ', len(cluster), ' cluster')

print ('----%s seconds ----' % (time.time()-start_time))
# In[]:
cluster_list = []  
for individual_cluster in cluster:
    df_cluster = pd.concat(individual_cluster, axis=1)   
    cluster_list.append(df_cluster) # transfer list into dataframe for each cluster



cluster_status, evaluation = evaluation_status(cluster_list)


# In[]:

def scale(array):
    minimum = array.min()
    maximum = array.max()
    scaled_array = np.array([])
    for i in range(0, len(array)):
        scaled_array = np.append(scaled_array,  (array[i] - minimum) / (maximum - minimum))
    
    return scaled_array
        
    
# In[]:
    

ofc_scaled = scale(df_full['ofc'])
mi_scaled = scale(df_full['transform'])
points = np.column_stack((ofc_scaled, mi_scaled))
#metrics = [df_full['ofc'], df_full['mi']]
#points = pd.concat(metrics, axis = 1)
from sklearn.cluster import KMeans as km
kmeans = km(n_clusters=3)
# fit kmeans object to data
kmeans.fit(points)
# print location of clusters learned by kmeans object
print(kmeans.cluster_centers_)
# save new clusters for chart
y_km = kmeans.fit_predict(points)

#plt.scatter(points[y_km ==0,0], points[y_km == 0,1], s=100, c='red')
#plt.scatter(points[y_km ==1,0], points[y_km == 1,1], s=100, c='black')


