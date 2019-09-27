FILENAME=$1
POSE_QUANTITY=$2
INLIER_QUANTITY=$3
OUTLIER_QUANTITY=$4
END=$5

for ((SEED=1;SEED<=END;SEED++))
do
    #echo $INPUT

    
    cd ../../test_backend/"$FILENAME"_seed_"$SEED"
    ./analyze.sh

    #grep "Scale: " output.txt > s_value_seed_"$SEED".txt
    #python plot_s_value.py $INLIER_QUANTITY $OUTLIER_QUANTITY $SEED


    ./analyze clustering and switch variables
    ./analyze_clustering.sh $INLIER_QUANTITY $OUTLIER_QUANTITY 0.25 0 >&1 | tee clustering_results.txt
    ./analyze_switch_variable.sh $POSE_QUANTITY $INLIER_QUANTITY $OUTLIER_QUANTITY >&1 | tee switch_variable_results.txt
 

    # move back
    #cd ../../rtabmap/bin  



done
