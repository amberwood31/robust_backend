DATASET_NAME=$1 #csail
OUTLIER_STRATERY=$2 #random128
END=$3


for ((SEED=1;SEED<=END;SEED++))
do
 
    cp plot_switch_variable.py plot_g2o_with_link.py plot.py plot_error.py plot_clustering.py plot_ate_convergence.py plot_s_value.py ../"$DATASET_NAME"_"$OUTLIER_STRATERY"/"$DATASET_NAME"_seed_"$SEED"
    cp analyze_switch_variable.sh analyze.sh analyze_clustering.sh analyze_ate_convergence.sh ../"$DATASET_NAME"_"$OUTLIER_STRATERY"/"$DATASET_NAME"_seed_"$SEED"

done
