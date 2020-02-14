#!/bin/bash

INPUT=$1 # folder path
FILENAME=$2
END=$3
METHOD=$4

for ((SEED=1;SEED<=END;SEED++))
do
    #echo $INPUT

    #run experiment
    cp "$INPUT""$FILENAME".g2o_unique.g2o_seed_"$SEED"_sorted.g2o sorted.g2o
    cp "$INPUT""$FILENAME".g2o_unique.g2o_seed_"$SEED"_del0.g2o del0.g2o
    sleep 1
    ./run_example.sh sorted.g2o del0.g2o "$METHOD"

   
    #move to analysis chamber
    cd ../../test_backend/analysis_chamber/
    mkdir ../"$FILENAME"_seed_"$SEED"
    ./move_to_results_folder.sh ../"$FILENAME"_seed_"$SEED"


    #move back
    cd ../../rtabmap/bin  
    rm sorted.g2o del0.g2o





done
