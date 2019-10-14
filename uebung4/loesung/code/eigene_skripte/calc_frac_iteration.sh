#!/bin/bash

echo 'start evaluation'

for i in $(seq 1 10);
do
  cd config$i/
  ~/Schreibtisch/wissenschaftliches_progammieren_fuer_ingenieure/wissenschaftliches_programmieren_fuer_ingenieure_ws1819/uebung4/loesung/code/calc_frac.sh 0 100 1
  # 0 100 1 -> Von-Bis-Schrittweite
  # Schaue in das entsprechende Skript für mehr Klarheit!
  echo 'finished evaluation for config'$i
  cd ..
done

echo 'finished evaluation'


# Skript zur effizienten Auswertung mit dem gegebenen Skript calc_frac.sh
# Tipp beim Shell Skript schreiben:
#   Checke, ob die Working-Directory passt, wenn er einen Zugriffsfehler wirft!
#   Mit dem Befehl: pwd
