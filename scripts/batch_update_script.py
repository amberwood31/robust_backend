import os
import sys


dataset = ['csail', 'manhattan', 'intel', 'mit']
inliers_quantity = [127, 1952, 256, 20]
inliers_percentages = [0.5, 0.6, 0.7, 0.8, 0.9]
sample_size = 10
methods_list = ['vertigo', 'dcs', 'cbsc']
script_name = sys.argv[1]

outliers_quantity = []
for i in range(0, len(dataset)):
    outliers_quantity.append([])
    for inlier_percentage in inliers_percentages:
        inlier_n = inliers_quantity[i]
        outliers_quantity[-1].append(round(inlier_n / inlier_percentage - inlier_n))
#print(outliers_quantity)

os.chdir('/home/amber/stew/test_backend/')
for method in methods_list:
    for i in range(0,len(dataset)):
        for j in range(0, len(inliers_percentages)):

            dataset_name = dataset[i]
            configuration_name = 'random' + str(outliers_quantity[i][j])
            
            for k in range(1, sample_size+1):
                
                command = 'cp ' + script_name + ' ' + dataset_name + '/' + method + '_' + dataset_name + '_' + configuration_name + '/' + dataset_name + '_seed_' + str(k)
                print (command)
                os.system(command)