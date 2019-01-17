# Variablendeklarationen
PROG = simulation

CFLAGS = -O2

CC = g++

SRC = matrix_funcs.cpp vector_funcs.cpp main.cpp solver_funcs.cpp

OBJ = $(SRC:.cpp=.o) # ersetze alle Elemente der Variable SRC (Zugriff ueber $(<VarName>)) mit .cpp durch .o und schreibe in LHS des Zuweisungsoperators

# Targets - Syntax: Targetname: Abhaengigkeit des Targets und mit einem Tab eingerueckt in naechster Zeile kommt die Anweisung fuer das Target
all: $(SRC) $(PROG)							# all Target muss alle Abhaengigkeiten enthalten und als Abhaengigkeit ein anderes Target haben, dass die Ziel-Executable erstellt

$(PROG): $(OBJ)									# Executable Target
	$(CC) $(CFLAGS) $(OBJ) -o $@	# Anweisung fuer Target; -o heißt linken der Objektdateien
																# $@ heisst: Name des Targets

%.o:%.cpp												# Alle .o Dateien haengen von gleichnamigen .cpp Dateien ab
	$(CC) $(CFLAGS) -c $<					# Compileranweisung um aus .cpp .o Dateien zu machen, ohne zu linken
																# $< heisst: verwende Name der ersten Abhaengigkeit

clean:													# phony-target (Stilles Target)
	rm -rf *.o $(PROG)						# loesche alle Dateien

# dependencies der Objektdateien
matrix_funcs.o: matrix_funcs.cpp matrix_funcs.h
vector_funcs.o: vector_funcs.cpp vector_funcs.h
solver_funcs.o: solver_funcs.cpp solver_funcs.h
main.o: main.cpp matrix_funcs.h vector_funcs.h solver_funcs.h
