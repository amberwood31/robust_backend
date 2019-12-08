#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Aug  5 16:52:31 2019

@author: amber
"""

# In[1]:


import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import sys

# In[2]:

df = pd.read_csv("iteration_error.txt", sep = "\x1b| |=", header = None, names = range(12), engine='python') #
print(df.iloc[0,3])
print(df.iloc[0,4])
print(df.iloc[0,5])
print(df.iloc[0,6])
if df.iloc[0,6]=='nodes,': # g2o output template
	error =np.array(df[10], dtype = float)
else: # gtsam output template
	error =np.array(df[9], dtype = float)
fig, ax = plt.subplots()

plt.plot(error, 'b')
plt.savefig('iteration_error')
plt.show()
