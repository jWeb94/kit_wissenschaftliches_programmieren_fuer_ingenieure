# Variablen
PROG = aufgabe_1				# Name des Zielprogramms

FLAGS = -O2 						# Compiler-Flags: Stage 2 Compiler-Optimierung

CC = g++								# Compiler

SRC = complex.cpp main_complex_beispiel.cpp 		# Namen aller cpp Dateien

OBJ = $(SRC:.cpp=.o)														# generiere Namen aller Objektdateien, basierend auf den Namen der SRC-Dateien

# Targets
all: $(SRC) $(PROG)															# Erstes Target-definiert alle Abhaengigkeiten und erstellt durch eine Abhaengigkeit eine lauffaehige Executable
																								# wird beim argumentenlosen Aufruf von Make gebaut

$(PROG): $(OBJ)																	# Definiere das Target, welches die Executable baut
	$(CC) $(FLAGS) $(OBJ) -o $@										# Compileranweisung


%.o:%.cpp																				# alle Objektdateien haengen von den entsprechenden cpp Dateien ab
	$(CC) $(FLAGS) -c $<													# Vorschrift, um cpp in o umzuwandeln

clean:																					# clean-Target - das ist ein argumentenloses 'phony-target'
	 rm *.o $(PROG)																# Anweisung, wie aufgeraeumt werden soll

# deps
complex.o: complex.cpp complex.h
main_complex_beispiel.o: main_complex_beispiel.cpp complex.h
