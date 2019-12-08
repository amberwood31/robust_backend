cp output.* $1
cp input.g2o $1
cp poses_transition_* $1
#cp s* $1
#cp iteration_error* $1
#cp with_number.png precision_recall $1
cp clustering_results.txt clustering_output.txt sorted.g2o $1


cp plot_switch_variable.py plot2_switch_variable.py plot_g2o_with_link.py plot.py plot_error.py plot_clustering.py plot_ate_convergence.py plot_s_value.py $1
cp analyze_switch_variable.sh analyze_cbsc_switch_variable.sh analyze.sh analyze_clustering.sh examine_clustering_results.py analyze_ate_convergence.sh analyze_s_value.sh $1

#cp full_analysis.txt $1



rm output.*
rm poses_transition_* 
#rm s*
rm input.g2o
#rm iteration_error*
#rm with_number.png
#rm precision_recall
#rm outlier_variance.png inlier_variance.png
rm clustering_results.txt clustering_output.txt sorted.g2o
