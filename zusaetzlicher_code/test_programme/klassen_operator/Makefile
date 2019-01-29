#!/bin/bash

# Variablendefinition
PROG = myClass_operator_test

CC = g++

FLAGS = -O2

SRCS = klassen_operatoren_test.cpp myClass.cpp

OBJS = $(SRCS:.cpp=.o)

# Targets
all: $(SRCS) $(PROG)
	# Target, dass von allen Abhaengt. Es darf darin genau eine Abhaengigkeit vorkommen, die eine Executable erstellt.
	# Beim Aufruf werden alle Abhaengigkeiten auf aktualitaet ueberprueft

$(PROG): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@ 	# Linken aller Objektdateien (binary code) zur Executable
																# Das $@ gibt den Namen des Targets an der jeweiligen Stelle zurueck!
																# Erst ueber diese Anweisung kennt das Translation Unit mit dem Entrance Point (Main-Methode) die Abhaengigkeit zu allen anderen Translation Units (ohne Entrance Point)!

%.o:%.cpp
	$(CC) $(FLAGS) -c $< 					# Uebersetzungsvorschrift, um die Translationunits einzeln zu uebersetzen
																# $< heisst 'Name der (ersten) Abhaengigkeit'
																# Geht durch das %-Zeichen alle .o durch!
																# Die Abhaengigkeit sagt so viel wie 'Alle .o haengen von den gleichnamigen .cpp ab'
clean:
	rm -rf $(PROG) *.o

#dependencies
myClass.o: myClass.cpp myClass.h
klassen_operator_test.o: klassen_operatoren_test.cpp myClass.h
