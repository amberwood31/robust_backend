SORTED=$1
DEL0=$2
METHOD=$3

if [ "$METHOD" == "cbsc" ] 
then
    ../../slam++/bin/slam_incre_clustering -i $SORTED -cs 10 >&1 | tee clustering_output.txt

elif [ "$METHOD" == "cbsc50" ]
then
    ../../slam++/bin/slam_incre_clustering -i $SORTED -cs 50 >&1 | tee clustering_output.txt

elif [ "$METHOD" == "cbsc100" ]
then
    ../../slam++/bin/slam_incre_clustering -i $SORTED -cs 100 >&1 | tee clustering_output.txt


fi

./input_file.sh $SORTED $DEL0
./backend input.g2o >&1 | tee output.txt
./copy_to_analysis.sh
./clean.sh
