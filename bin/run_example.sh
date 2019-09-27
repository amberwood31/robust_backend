../../slam++/bin/intermediate_clustering.sh $1
./input_file.sh $2
./backend input.g2o >&1 | tee output.txt
./copy_to_analysis.sh
./clean.sh
