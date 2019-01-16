# Variablen
PROG=test_parser

CC = g++

FLAGS = -O2

SRCS = main_test.cpp parser_universal.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(SRCS) $(PROG)

$(PROG): $(OBJS)									# die Executable haengt von allen Objektdateien ab
	$(CC) $(FLAGS) $(OBJS) -o $@		# Das ist die Compileranweisung zum Linken
																	# $@ sagt, dass der Name entsprechend des des Namens des Targets dort eingefuegt werden soll

%.o:%.cpp													# Vorschrift zum Erstellen der Objektdateien
	$(CC) $(FLAGS) $(SRCS) -c $< 		# -c : Compilieren ohne zu linken -> nur Objektdateien Erstellen
																	# $< : Name des Targets, wenn dieses implizit steht

clean:
	rm -rf *.o *.dat $(PROG)

# Abhaengigkeiten der einzelnen Dateien

main_test.o: main_test.cpp parser_universal.h									# hier werden nur die eingebundenen Header anderer Dateien eingebunden, nicht die cpps
parser_universal.o: parser_universal.cpp parser_universal.h
