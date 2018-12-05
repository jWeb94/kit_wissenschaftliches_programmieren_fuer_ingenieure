PROG=programm1  # name der zu-erstellenden executable

CFLAGS=-O2		# compiler optimierung level 2
				# -O1 performs only optimisations that don't effect the compile time much.
				# -O2 performs optimisations without trading space for speed
				# -O3 performs maximal speed optimisation
				# -Os tries to make the executable as small as possible

LDFLAGS=$(CFLAGS) # linker flags entspricht der compiler flag	

CC=g++   #hier kann der Name des C++ compilers festgelegt werden

SRCS= funktion2.cxx addiere.cxx # definiere variable mit den namen der source code dateien
OBJ= $(SRCS:.cxx=.o)			# erstelle aus den namen der source code dateien die namen der objekt dateien
# muesste OBJ= $(SRCS:%.cxx=%.o) entsprechen


all: $(SRCS) $(PROG) # definiere das erste target, welches auch zuerst aufgerufen wird, das von ALLEN anderen targets abhaengt. 
					 # Wird nun das target all aufgerufen, werden alle von ihm abhängigen targets ueberprueft und evt neu gebaut!
					 # all ist ein phony target
					 # wird das makefile ohne spezifiziertes target aufgerufen, so wird all gebaut, weil es zuerst steht!
					 
					 # Exkurs: will ich nur einen Teil der Abhaengigkeiten neu bauen kann ich auch einfach das Makefile mit dem entsprechenden Target in der Shell eingeben! 


$(PROG): $(OBJ)						# 
	$(CC)  $(CFLAGS) $(OBJ) -o $@

#Regel um aus Dateien mit .cxx Endung eine Objektdatei (mit .o Endung) zu erstellen

%.o:%.cxx
	$(CC)  $(CFLAGS) -c $<

clean:
	rm -rf *.o $(PROG)

## dependencies

funktion2.o: funktion2.cxx addiere.h  # Quelldatei  und eingebundene Kopfdatei

addiere.o: addiere.cxx addiere.h
