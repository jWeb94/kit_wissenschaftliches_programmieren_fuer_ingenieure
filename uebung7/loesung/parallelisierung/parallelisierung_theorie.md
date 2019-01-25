## Parallelisierung

### Allgemeines

+ Der Pragma-Befehl:
	+ Wie alle anderen #-Befehle ist das eine Präprozessoranweisung!
	+ Pragma sagt so viel aus wie "checke, ob du die nachfolgende Präprozessoranweisung kennst und wenn nicht ignoriere sie einfach." 


### Openmp-Befehle

+ #pragma omp atomic:
  + Gilt nur für die folgende Zeile
  + Geht nur mit elemmentaren (atomaren) Operatoren. Die Anzahl atomarer Operatoren ist dabei aber beliebig. Auch die dort aufgerufenen Objekte können beliebiger Natur sein!
    + Achtung: verrechne ich den Rückgabewert einer Funktion, so ist nur die atomare Anweisung geschützt. Die Funktion wird dann im Paralleln normal ausgeführt!
  + Keine cout mehr nach Berechnungen zum Debugging geben, wenn Operationen mit gemeinsam von allen Threads verwendeten Variablen berechnet werden.
      + IdR wird zuerst alles gerechnet und dann die naechste (cout) Zeile in den Threads ausgefuehrt!
      + Laesst sich mit critical Sections ausgleichen!

+ #pragma omp critical:
  + Definition von critical Sections in Programmen. Das können Funktionsblöcke sein, die immer ohne unterbrechnung ausgefuehrt werden! Während der Zeit der critical Section kann kein anderen Programm die.
  + So lange eine critical Section ausgeführt wird, kann das Programm nicht in einem anderen Thread in die critical Section eintreten
    + Ich kann auch critical Sections benennen, dann kann das Programm in verschiedenen Threads in unterschiedlichen critical Sections sein.

+ clauses:
  + private(<Variable>):
    + Die Variable die ich übergebe ist nur lokal in jedem Thread einzeln. Sie wird mit 0 initialisiert/undefinierter Zustand.
    + Existiert eine Variable mit gleichem Namen im übergeordneten Scope oder global, so wird sie im Thread-Scope überschrieben.
    + Auch wenn in einem Thread die Variable verändert wird, sehen davon die anderen Threads nichts!
    + Wenn die übergebene Variable nicht definiert ist, mäckert der Compiler!
  + firstprivate(<Variable>):
    + Variablen werden mit dem Wert im übergeordneten Scrope initialisert, werden aber in jedem Thread als lokale 'Scopevariable' behandelt!
    + Ansonsten wie private
    + Wenn die übergebene Variable nicht existiert, mäckert der Compiler!
  + reduction(<operator>:<list>):
    + Macht nur Sinn bei kommutativen Algorithmen, da diese in Teilen berechenbar sind!
    + Erstellt für jeden Thread eine lokale Variable in der der jeweilige Thread rechnet und fügt die parallelen Ergebnisse dann am Ende zusammen.
    + Der übergebene Operator dient nur dazu zu sagen, wie der Comiler optimieren soll. Eine direkte rechnerische Bedeutung hat der Operator nicht, wobei der Compiler aber annimmt, dass Die übergebene Variable mit dem jeweiligen Operator IM THREAD verrechnet wird!
    + Nach durchlauf des parallelen Teils werden die reduzierten Teilvariablen additiv überlagert!
    + Zusammenfügen von Variablen eines Threads mit dem übergebenen Operator.
    + Geht nur für Skalare!
    + Der im globalen verhandene Wert und die Einzelwerte aus den Threads werden entsprechend des Operators zu einem Wert am Ende zusammen gefügt.

+ Paralleler for-Loop:
  +
