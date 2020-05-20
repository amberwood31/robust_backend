
import os


dataset = ['csail', 'manhattan', 'intel']
inliers_quantity = [128, 1952, 256] # 127 not dividable, changed to 128 for group experiment
inliers_percentages = [0.5]
sample_size = 10
method = 'cbsc'

outliers_quantity = []
for i in range(0, len(dataset)):
    outliers_quantity.append([])
    for inlier_percentage in inliers_percentages:
        inlier_n = inliers_quantity[i]
        outliers_quantity[-1].append(round(inlier_n / inlier_percentage - inlier_n))
#print(outliers_quantity)

os.chdir('/home/amber/stew/rtabmap/bin/')

for i in range(0,len(dataset)):
    for j in range(0, len(inliers_percentages)):
        dataset_name = dataset[i]
        configuration_name = 'group' + str(outliers_quantity[i][j])
        command = './batch_experiment.sh /home/amber/stew/pose_dataset/' + dataset_name + '_' + configuration_name + '/ ' + dataset_name + ' ' + str(sample_size)
        print (command)
        os.system(command)
        os.chdir('../../test_backend/')
        os.system('mkdir ' + method + '_' + dataset_name + '_' + configuration_name)
        os.system('cp -r ' + dataset_name + '_seed_* ' + method + '_' + dataset_name + '_' + configuration_name)
        os.system('rm -r ' + dataset_name + '_seed_* ')
        os.chdir('../rtabmap/bin/')