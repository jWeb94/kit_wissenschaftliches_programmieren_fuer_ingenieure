PROG=test_eigen3 				# Name des Programms

CFLAGS=-O2 -I/home/jens/Schreibtisch/wissenschaftliches_progammieren_fuer_ingenieure/wissenschaftliches_programmieren_fuer_ingenieure_ws1819/uebung3/loesung/eigen3_einfuehrung/eigen3
		 						# Pfad zu Eigen3 Bibliothek

LDFLAGS=$(CFLAGS)				# Linker Flags als Variable

CC=g++ 							# Compiler festlegen

SRCS= test_eigen.cxx			# Sourcecode Dateien benennen und als Variable speichern
OBJ= $(SRCS:.cxx=.o)			# Objektdateien aus SRCS-Variable erstellen -> ersetze .cxx durch .o; $() ~> Variablenzugriff


all: $(SRCS) $(PROG)			# Erstes Target ~> das wird als Executable gebaut, falls kein anderes Target an Make übergeben wird
								# Teste/Baue alles neu -> Abhängig von allen anderen, im Makefile definierten, Targets
								# Da beim Bauen des Targets all eine Executable entstehen soll, darf hier nur eine Abhängigkeit drin sein, die als Anweisung des Targets einen
								# Compiliervorgang hat

$(PROG): $(OBJ)					# Definiere Zielprogramm und seine Abhängigkeiten
	$(CC)  $(CFLAGS) $(OBJ) -o $@		# Compiliervorschrift

#Regel um aus Dateien mit .cxx Endung eine Objektdatei (mit .o Endung) zu erstellen

%.o:%.cxx						# Alle Objektdateien hängen von den gleichnamigen cxx Dateien ab
	$(CC)  $(CFLAGS) -c $<		# Compilervorschrift für das Erstellen der Objektdateien

clean:							# Clean Target
	rm -rf *.o $(PROG)

## dependencies

