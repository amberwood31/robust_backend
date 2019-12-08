INPUT_QUANTITY=$1
OUTLIER_QUANTITY=$2

grep 'Scale: ' output.txt >&1 | tee s_value.txt
python plot_s_value.py $INPUT_QUANTITY $OUTLIER_QUANTITY $3 $4 $5 $6 $7 $8 >&1 | tee s_value_analysis.txt

