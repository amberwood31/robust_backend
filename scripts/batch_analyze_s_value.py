import os


dataset = ['csail']#['csail', 'manhattan', 'intel'] #, 'mit']
inliers_quantity = [127]#[127, 1952, 256] #, 20]
inliers_percentages = [0.5, 0.6, 0.7, 0.8, 0.9]
sample_size = 10
method = 'dcs'

outliers_quantity = []
for i in range(0, len(dataset)):
    outliers_quantity.append([])
    for inlier_percentage in inliers_percentages:
        inlier_n = inliers_quantity[i]
        outliers_quantity[-1].append(round(inlier_n / inlier_percentage - inlier_n))
#print(outliers_quantity)

os.chdir('/home/amber/stew/test_backend/'+dataset[0])

for i in range(0,len(dataset)):
    for j in range(0, len(inliers_percentages)):

        dataset_name = dataset[i]
        configuration_name = 'random' + str(outliers_quantity[i][j])
        file_list_string = ''
        for k in range(1, sample_size+1):
            
            os.chdir(method + '_' + dataset_name + '_' + configuration_name + '/' + dataset_name + '_seed_' + str(k) + '/')
            command = './analyze_s_value.sh ' + str(inliers_quantity[i]) + ' ' + str(outliers_quantity[i][j])
            print (command)
            os.system(command)
            os.system('mv s_value_analysis.txt s_value_analysis_' + str(k) + '.txt')
            os.system('cp s_value_analysis_' + str(k) + '.txt ../')
            file_list_string += ' s_value_analysis_' + str(k) + '.txt'
            os.chdir('../../')

        os.chdir(method + '_' + dataset_name + '_' + configuration_name)
        os.system('cat' + file_list_string + ' > s_value_analysis_' + configuration_name)
        os.system('cp s_value_analysis_' + configuration_name + ' ../')
        os.chdir('../')