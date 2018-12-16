#!/bin/bash
MAXDATASET=3
for i in $(seq 1 3);
do
echo run start$i"A.dat"
NAMEFILE=start$i"B.dat"
if [ -e $NAMEFILE ];
#if [-e $NAMEFILE]; # funktioniert nicht!
#if [ -e $NAMEFILE]; # funktioniert nicht!
then
  echo File $NAMEFILE does not exists. Finished execution
else
  echo "finished run "$i"B"
fi
done

echo "finished all runs"
