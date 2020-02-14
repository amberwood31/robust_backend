
import os


dataset = ['manhattan']                #['csail', 'manhattan', 'intel'] #, 'mit']
inliers_quantity = [1952]              #[127, 1952, 256] #, 20]
inliers_percentages = [0.5, 0.6, 0.7, 0.8, 0.9]
sample_size = 10
methods = ['cbsc50', 'cbsc100']

outliers_quantity = []
for i in range(0, len(dataset)):
    outliers_quantity.append([])
    for inlier_percentage in inliers_percentages:
        inlier_n = inliers_quantity[i]
        outliers_quantity[-1].append(round(inlier_n / inlier_percentage - inlier_n))
#print(outliers_quantity)

#os.chdir('/home/amber/stew/rtabmap/bin/')

for method in methods:
    for i in range(0,len(dataset)):
        for j in range(0, len(inliers_percentages)):
            dataset_name = dataset[i]
            configuration_name = 'random' + str(int(outliers_quantity[i][j]))
            print("configuration_name: " + configuration_name)
            command = './batch_experiment.sh /media/amber/www/devel/stew/pose_dataset/' + dataset_name + '_' + configuration_name + '/ ' + dataset_name \
                        + ' ' + str(sample_size) + ' ' + method
            print (command)
            os.system(command)
            os.chdir('../../test_backend/')
            os.system('mkdir ' + method + '_' + dataset_name + '_' + configuration_name)
            os.system('cp -r ' + dataset_name + '_seed_* ' + method + '_' + dataset_name + '_' + configuration_name)
            os.system('rm -r ' + dataset_name + '_seed_* ')
            os.chdir('../rtabmap/bin/')