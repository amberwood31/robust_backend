

import os


dataset = ['csail', 'manhattan', 'intel', 'mit']
inliers_quantity = [127, 1952, 256, 20]
inliers_percentages = [0.5, 0.6, 0.7, 0.8, 0.9]
sample_size = 10

outliers_quantity = []
for i in range(0, len(dataset)):
    outliers_quantity.append([])
    for inlier_percentage in inliers_percentages:
        inlier_n = inliers_quantity[i]
        outliers_quantity[-1].append(round(inlier_n / inlier_percentage - inlier_n))
#print(outliers_quantity)

os.chdir('/home/amber/stew/pose_dataset/')

for i in range(0,len(dataset)):
    for j in range(0, len(inliers_percentages)):
        os.system('./create_new_dataset_folder.sh '+ dataset[i]+ ' random'+str(outliers_quantity[i][j]))
        print('adding new dataset folder: '+dataset[i]+'_'+'random'+str(outliers_quantity[i][j]))

for i in range(0, len(dataset)):
    for j in range(0, len(inliers_percentages)):
        dataset_name = dataset[i]
        configuration_name = 'random'+str(outliers_quantity[i][j])
        os.chdir(dataset_name + '_'+ configuration_name)
        os.system('python uniquify.py ' + dataset_name + '.g2o' + ' ' + dataset_name + '.g2o_unique.g2o')
        if dataset_name == 'mit':
            os.system('./generate_dataset.sh ' + dataset_name + '.g2o_unique.g2o ' + str(sample_size) + ' ' + str(outliers_quantity[i][j]) + ' ' + str(0))
        else:
            os.system('./generate_dataset.sh ' + dataset_name + '.g2o_unique.g2o ' + str(sample_size) + ' ' + str(outliers_quantity[i][j]))
        os.chdir('..')


