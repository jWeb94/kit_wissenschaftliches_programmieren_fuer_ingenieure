PROG = vec_mat_test

FLAGS = -O2

CC = g++

SRCS = vector_funcs.cpp matrix_funcs.cpp vec_mat_test.cpp

OBJ = $(SRCS:.cpp=.o) 	# ersetze alle .cpp, in der Variable SRC ($ ist der Variablenzugriff), durch .o -> erstelle Variable mit den Nanem der Objektdateien 

all: $(SRCS) $(PROG)	# erstelle Target mit allen Abhängigkeiten der .cpps und dem PROG-Target (das Makefile wird komplett durch gegangen und das in Zeile 13 definierten PROG-Target wird gefunden, da zuvor nur die Variable (nicht gleich Target, welche 
						# gekennzeichnet durch : sind) deklariert wurde.) In PROG steht ein Target, dass compuiliert wird.

$(PROG): $(OBJ)			# resulting executable 
	$(CC) $(FLAGS) $(OBJ) -o $@	# Kompiliervorschrift
								# $@ ist der Name des Targets für das die Regel gelten soll

%.o:%.cpp				# Alle (%) .o-Dateien sind von allen (%) .cpp-Dateien abhängig
	$(CC)  $(FLAGS) -c $<		# Compiliervorschrift zur Erstellung derObjektdateien
								# $< ist der Name der ersten Abhängigkeit

clean:					# Clean-Target -> das ist ein Phony-Target ohne abhängigkeit
	rm -rf *.o $(PROG)

## dependencies

vector_funcs.o: vector_funcs.cpp vector_funcs.h matrix_funcs.h

matrix_funcs.o: matrix_funcs.cpp matrix_funcs.h

vec_mat_test.o: vec_mat_test.cpp vector_funcs.h matrix_funcs.h