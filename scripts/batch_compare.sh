#usage: ./batch_compare.sh csail_random64 csail sample_size dcs_kernel_width

FOLDER=$1 # csail_random64
DATASET_NAME=$2
END=$3
WIDTH=$4

mkdir dcs"$WIDTH"_"$FOLDER"

for ((SEED=1;SEED<=END;SEED++))
do
    #echo $INPUT

    # compare scs vs vertigo
    python compare.py /home/amber/stew/test_backend/groundtruth/"$DATASET_NAME".g2o /home/amber/stew/test_backend/"$FOLDER"/"$DATASET_NAME"_seed_"$SEED"/output.g2o /home/amber/stew/test_backend/"$FOLDER"_vertigo/"$DATASET_NAME"_seed_"$SEED"/output.g2o 1044 $SEED >&1 | tee DCS_"$SEED"

    # compare scs vs dcs
    #python compare.py /home/amber/stew/test_backend/groundtruth/"$DATASET_NAME".g2o /home/amber/stew/test_backend/"$FOLDER"/"$DATASET_NAME"_seed_"$SEED"/output.g2o /home/amber/stew/test_backend/"$FOLDER"_dcs"$WIDTH"/"$DATASET_NAME"_seed_"$SEED"/output.g2o 1044 $SEED >&1 | tee DCS_"$SEED"
    #python compare.py /home/amber/stew/test_backend/"$FOLDER"/"$DATASET_NAME"_seed_"$SEED"/output.g2o /home/amber/stew/test_backend/"$FOLDER"/"$DATASET_NAME"_seed_"$SEED"/output.g2o /home/amber/stew/test_backend/"$FOLDER"_dcs"$WIDTH"/"$DATASET_NAME"_seed_"$SEED"/output.g2o 807 $SEED >&1 | tee DCS_"$SEED"

    cp DCS* SCS* dcs"$WIDTH"_"$FOLDER"
    rm DCS* SCS*



done
