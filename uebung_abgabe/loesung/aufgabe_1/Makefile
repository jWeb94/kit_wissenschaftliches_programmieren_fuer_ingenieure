# Variablen
PROG = aufgabe_1

FLAGS = -O2 # Stage 2 Compiler-Optimierung

CC = g++

SRC = complex.cpp main_complex_beispiel.cpp

OBJ = $(SRC:.cpp=.o)

# Targets
all: $(SRC) $(PROG)

$(PROG): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@


%.o:%.cpp
	$(CC) $(FLAGS) -c $<

clean:
	 rm *.o $(PROG)

# deps
complex.o: complex.cpp complex.h
main_complex_beispiel.o: main_complex_beispiel.cpp complex.h
