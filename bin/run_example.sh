./input_file.sh $1
./backend input.g2o >&1 | tee output.txt
./copy_to_analysis.sh
./clean.sh
