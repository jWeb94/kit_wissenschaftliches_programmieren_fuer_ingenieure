#!/bin/bash

# die Zeile 1 ist ein 'Shebang' -> Sagt dem Terminal, dass alle im File vorkommenden Befehle ausgeführt werden sollen und welcher Interpreter verwendet werden soll/wo dieser zu finden ist
NX=100
NY=100

frac=$1

echo $1

MAXSTEP=100
NWRITE=1

# die {} beschreiben einen Block. Dieser wird in die (temporäre) Datei 'conf_start' geschrieben (vgl > - Operator der Shell!)
# es
{
    echo $NX $NY
    echo $frac
    echo $MAXSTEP
    echo $NWRITE
} > "conf_start"
# conf_start wird in jeder Iteration überschrieben.

# ausführen der unter dem Pfad gespeicherten Executable, mit den Übergabeparametern in conf_start
/home/jens/Schreibtisch/wissenschaftliches_progammieren_fuer_ingenieure/wissenschaftliches_programmieren_fuer_ingenieure_ws1819/uebung4/loesung/code/game_of_life_lsg_WS1819/game < conf_start

# vgl: Jede Zeile eines Shell-Skripts wird wie eine Eingabe in die Shell ausgewertet!
