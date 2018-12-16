#!/bin/bash

# raeaume auf - loesche alle alten Ergebnisse
rm ergebnis*

# fuehre alle 5 Berechnungen durch
for i in $(seq 1 3);
do
    NAMECURRENTFILEA=start$i"A.dat"
    NAMECURRENTFILEB=start$i"B.dat"
    ./aufgabe_2 < $NAMECURRENTFILEA
    echo "finished run "$i"A"

    if [ -e $NAMECURRENTFILEB ]   # Berechne fuer jede Iterationsvorschrift Datensatz A und B, nur der 3. Datensatz hat keinen Datensatz B
    then
      ./aufgabe_2 < "start"$i"B.dat"
      echo "finished run "$i"B"
    else
      echo "File start"$i"B.dat does not exists"
    fi
done

echo "finished all runs"
