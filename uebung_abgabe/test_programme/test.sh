#!/bin/bash
MAXDATASET=3
for i in $(seq 1 3);
do
echo run start$i"A.dat"
NAMEFILE=start$i"B.dat"
#if [ "$MAXDATASET" -eq "$i" ]; # funktioniert! Die "" dienen dazu klar zu machen, dass es sich um Variablen handelt!
if [ $MAXDATASET -eq $i ];      # funktioniert!
#if [ "$MAXDATASET" -eq "$i"];  # funktioniert nicht
#if ["$MAXDATASET" -eq "$i" ];  # funktioniert nicht
then
  echo File $NAMEFILE does not exists. Finished execution
else
  echo "finished run "$i"B"
fi
done

echo "finished all runs"
