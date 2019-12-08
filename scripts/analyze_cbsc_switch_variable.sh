echo "$(pwd)"
SCRIPT_DIR="$(pwd)"
python plot2_switch_variable.py $SCRIPT_DIR $1 $2 $3 $4 $5 $6 $7 $8 $9 >&1 | tee switch_variable_analysis.txt
