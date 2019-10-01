#/home/amber/stew/slam++/bin/slam_incre_clustering -i $1 -cs 10 >&1 | tee clustering_output.txt
./input_file.sh $1 $2
./backend input.g2o >&1 | tee output.txt
./copy_to_analysis.sh
./clean.sh
