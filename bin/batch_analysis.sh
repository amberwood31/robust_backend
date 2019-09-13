FILENAME=$1
END=$2

for ((SEED=1;SEED<=END;SEED++))
do
    #echo $INPUT

    
    cd ../../test_backend/"$FILENAME"_seed_"$SEED"
    ./analyze.sh
    ./analyze_clustering.sh 128 64 0.25 0 >&1 | tee clustering_results.txt
    ./analyze_switch_variable.sh 1045 128 64 >&1 | tee switch_variable_results.txt
 

    #move back
    #cd ../../rtabmap/bin  



done
cd ../../rtabmap/bin
