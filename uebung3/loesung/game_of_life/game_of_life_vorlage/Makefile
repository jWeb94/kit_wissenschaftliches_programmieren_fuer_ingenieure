PROG = game_of_life_test 					# Variable für Namen des Zielprogramms

FLAGS = -O2 -I /home/jens/Schreibtisch/wissenschaftliches_progammieren_fuer_ingenieure/wissenschaftliches_programmieren_fuer_ingenieure_ws1819/uebung3/loesung/eigen3_einfuehrung/eigen3 
											# Pfad zu Eigen3 als Compiler-Flag, um den Search-Path zu erweitern

CC = g++									# Variable mit Compiler

SRCS = main_game.cpp functions_game.cpp		# Definiere Variable mit Namen der Quellcode Dateien

OBJ = $(SRCS:.cpp=.o)						# Definiere Variable mit Namen der Objektdateien
											# Dafür ersetze alle .cpp aus der Variable 
											# SRC mit .o für Objektdateien

all: $(SRCS) $(PROG)						# Definiere erstes Target
											# Mit einziger Compiler-Aktion in $(PROG)

$(PROG): $(OBJ)								# Dependency von $(PROG) mit entsprechender Compiler-Anweisung
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o:%.cpp									# Alle Objektdateien hängen von den gleichnamigen .cpp Dateien ab
	$(CC)  $(FLAGS) -c $<

clean:										# clean-Target
	rm -rf *.o *.dat $(PROG)

## dependencies der einzelnen Objektdateien

functions_game.o: functions_game.cpp functions_game.h		

main_game.o: main_game.cpp functions_game.h   # Quelldatei  und eingebundene Kopfdatei

