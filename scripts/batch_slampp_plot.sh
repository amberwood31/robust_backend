POSE_QUANTITY=$1
END=$2


for ((SEED=1;SEED<=END;SEED++))
do

	python plot_g2o_slampp.py output_"$SEED".txt $POSE_QUANTITY


done
