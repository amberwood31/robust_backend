./input_file.sh $1
./backend input.g2o > output.txt
./copy_to_analysis.sh
./clean.sh
