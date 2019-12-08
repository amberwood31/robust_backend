DATASET_NAME=$1 #csail
OUTLIER_STRATEGY=$2 #random128
END=$3


for ((SEED=1;SEED<=END;SEED++))
do

    cd ../"$DATASET_NAME"_"$OUTLIER_STRATEGY"/"$DATASET_NAME"_seed_"$SEED"

    #python plot_ate_convergence.py /home/amber/stew/test_backend/groundtruth/"$1".g2o 1044 30
    grep "Scale: " output.txt > s_value_seed_"$SEED".txt
    python plot_s_value.py 128 128  $SEED

    cd ../../analysis_chamber
 
done
