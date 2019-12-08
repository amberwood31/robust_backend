#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Sep  5 16:21:40 2019

@author: amber
"""

# In[1]:


import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import sys

# In[2]:


def sort(file_name, output_name, dimension):
#file_name = '/home/amber/Downloads/input_INTEL_g2o(1).g2o'
    
    if int(dimension) == 2:
        df = pd.read_csv(file_name, delimiter = " ", header = None, names = range(12))
        vertex = df.loc[df[0] == "VERTEX_SE2"]
        edges = df.loc[df[0] == "EDGE_SE2"]
        edges.columns = ['name', 'vertex_from', 'vertex_to', 'x', 'y', 'the', 'i0', 'i1', 'i2', 'i3', 'i4', 'i5']
        edges = edges.astype({'vertex_to': int, 'x': float, 'y': float, 'the': float})
    elif int(dimension) == 3:
        df = pd.read_csv(file_name, delimiter = " ", header = None, names = range(31))
        vertex = df.loc[df[0] == "VERTEX_SE3:QUAT"]
        edges = df.loc[df[0] == "EDGE_SE3:QUAT"]
        edges.columns = ['name', 'vertex_from', 'vertex_to', 'x', 'y', 'z', 'qa', 'qb', 'qc', 'qd', 'i11', 'i12', 'i13', 'i14', 'i15', 'i16', 'i22', 'i23', 'i24', 'i25','i26','i33', 'i34', 'i35','i36', 'i44', 'i45', 'i46', 'i55', 'i56', 'i66']
        edges = edges.astype({'vertex_to': int, 'x': float, 'y': float, 'z': float})
    
    
    #edges['vertex_to']= edges['vertex_to'].astype(int)
    
    od_edges = edges.loc[(edges['vertex_to'] - edges['vertex_from']) == 1]
    lc_edges = edges.loc[(edges['vertex_to'] - edges['vertex_from']) != 1]
    
    if lc_edges.loc[lc_edges.index[-1], 'vertex_to']- lc_edges.loc[lc_edges.index[-1], 'vertex_from'] > 0:# if vertex_from < vertex_too
        #temp1 = edges.sort_values(by= 'vertex_to')
        sorted_edges = edges.sort_values(by= ['vertex_to', 'vertex_from'], ascending=[True, False])
    else:
        sorted_edges = edges.sort_values(by= ['vertex_from', 'vertex_to'], ascending=[True, True])
            
    sorted_edges.to_csv(output_name, header=None, index=None, sep=' ', float_format='%0.6f')
    #return sorted_edges

# In[3]:


#sort(str(sys.argv[1]))
print(sys.argv)
sort(str(sys.argv[1]), str(sys.argv[2]), str(sys.argv[3]))
