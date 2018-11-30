PROG=programm1

CFLAGS=-O2

LDFLAGS=$(CFLAGS)

CC=g++   #hier kann der Name des C++ compilers festgelegt werden

SRCS= funktion2.cxx addiere.cxx
OBJ= $(SRCS:.cxx=.o)


all: $(SRCS) $(PROG)


$(PROG): $(OBJ)
	$(CC)  $(CFLAGS) $(OBJ) -o $@

#Regel um aus Dateien mit .cxx Endung eine Objektdatei (mit .o Endung) zu erstellen

%.o:%.cxx
	$(CC)  $(CFLAGS) -c $<

clean:
	rm -rf *.o $(PROG)

## dependencies

funktion2.o: funktion2.cxx addiere.h  # Quelldatei  und eingebundene Kopfdatei

addiere.o: addiere.cxx addiere.h
