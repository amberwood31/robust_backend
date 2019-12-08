grep 'iteration ' output.txt > iteration_error.txt
python plot_g2o_with_link.py poses_transition_10.g2o
python plot_g2o_with_link.py output.g2o 
#python plot_switch_variable.py input.g2o output.g2o output.txt >&1 precision_recall
python plot_error.py 

