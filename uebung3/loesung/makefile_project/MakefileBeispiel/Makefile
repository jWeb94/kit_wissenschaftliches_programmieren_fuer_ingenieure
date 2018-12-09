PROG=programmTerminal  # name der zu-erstellenden executable

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


all: $(SRCS) $(PROG) 	# definiere das erste target, welches auch zuerst aufgerufen wird, das von ALLEN anderen targets abhaengt.
					 						# Wird nun das target all aufgerufen, werden alle von ihm abhängigen targets ueberprueft und evt neu gebaut!
					 						# wird das makefile ohne spezifiziertes target aufgerufen, so wird all gebaut, weil es zuerst steht!

					 						# Das Makefile wird komplett durch gegangen, damit Make alle Dependencys kennt. Allerdings wird nur das erste Target als Executable erstellt
					 						# Ziel des Make-Files mit einem ersten Target 'all' ist, ein ausführbares exec bei einem argumentenlosem Aufruf von Make zu erstellen!
											# Deshalb darf nur eine Dependency mit einer Compileranweisung zur Erstellung einer Executable vorkommen

					 						# Exkurs: will ich nur einen Teil der Abhaengigkeiten neu bauen kann ich auch einfach das Makefile mit dem entsprechenden Target in der Shell eingeben!
											# zB beim Clean - Target: $ make clean

$(PROG): $(OBJ)										# Aufruf des Targets, das in der Variable PROG gepeichert, das von den Dateien in der Variable OBJ (-> alle Objektdateien) abhängt
	$(CC)  $(CFLAGS) $(OBJ) -o $@		# Regel, wie es mit den Abhängigkeiten umgehen soll
																	# Dabei wird geprüft, ob die Anhängigkeiten neuer als das Target sind
																	#
																	# Hier: Die Zieldatei hängt von allen Objektdateien ab

#Regel um aus Dateien mit .cxx Endung eine Objektdatei (mit .o Endung) zu erstellen

%.o:%.cxx 									# Jede Objektdatei (Target) hängt von der gleichnamigen cxx Datei ab 
	$(CC)  $(CFLAGS) -c $<		# So soll mit den Objektdateien umgegangen werden, wenn der Quellcode neuer ist als die Objektdatei

clean:							# Phony Target Clean -> keine Abhängigkeit
	rm -rf *.o $(PROG)			# Anweisung: Lösche alle erzeugten Objektdateien UND die erzeugte Executable
	#rm -rf *.o					# Anweisung: Lösche nur die Objektdateien

## dependencies

funktion2.o: funktion2.cxx addiere.h  # Quelldatei  und eingebundene Kopfdatei

addiere.o: addiere.cxx addiere.h
