#  this is for clustering based on score only
#echo "$(pwd)"
#SCRIPT_DIR="$(pwd)"
#python plot_clustering.py $SCRIPT_DIR $1 $2 $3 $4 $5 $6 $7 $8 $9 

python examine_clustering_results.py input.g2o clustering_results.txt $1 $2 >&1 | tee clustering_analysis.txt

