#!/bin/bash

# loesche alle alten Dateien
rm ergebnis*

# Berechnung aller 5 Datensaetze
for i in $(seq 1 3);
do
    NAMECURRENTFILEA=start$i"A.dat"
    NAMECURRENTFILEB=start$i"B.dat"
    ./aufgabe_2 < $NAMECURRENTFILEA
    echo "finished run "$i"A"

    if [ -e $NAMECURRENTFILEB ]  
    then
      ./aufgabe_2 < "start"$i"B.dat"
      echo "finished run "$i"B"
    else
      echo "File start"$i"B.dat does not exists"
    fi
done

echo "finished all runs"
