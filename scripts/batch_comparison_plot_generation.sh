#!/bin/bash
# Input: a list of dataset names
# Output: generate comparison plots between ground truth and initial graph for all datasets and move to documentation folder
for dataset in $1 $2 $3 $4 $5 $6
do
    python compare_plot_g2o.py groundtruth/"$dataset".g2o ../pose_dataset/"$dataset".g2o
    cp comparison_plot.png ../../Documents/outlier_rejection_documentation/comparison_plot_"$dataset".png
done

