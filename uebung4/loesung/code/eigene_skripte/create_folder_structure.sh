#!/bin/bash


# Erstelle die notwendige Ordnerstruktur mit diesem Skript

# make base folder
mkdir runs
cd runs
# loop over sequences
for f in $(seq 0.3 0.2 0.7);
do
  mkdir frac$f
  cd frac$f
  # loop oder runs
  for r in $(seq 1 10);
  do
    mkdir config$r
  done
  # go back in previous folder
  cd ..
done

# go back to the initial folder
cd ..

echo 'finished creating folder structure'
