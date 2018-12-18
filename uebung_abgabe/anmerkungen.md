### Anmerkungen und Hinweise zur Lösung der Abgabeaufgabe

#### Aufgabenstellung

***Aufgabe 1***
- _ToDo_:
        1: Klasse erstellen und Operatoren überladen                                  ***DONE***
        2: Make-File erstellen                                                        ***DONE***
        3: *Testprogramm* verwenden (!), um die Richtigkeit des Codes zu überprüfen   ***DONE***
        4: (Eigene Aufgabe) Gegenchecken mit Matlab                                   ***DONE***
        5: Dokumentation in Lösungs-PDF in Operatorschreibweise + Code aufräumen und rein kopieren                       ***TODO!!!***

***Aufgabe 2***

- _ToDo_:
        1: Neue Main-Methoden-File erstellen, dass Eingabeparameter einliest und die Iterationsvorschriften berechnet
        2: Make-File schreiben, dass für Aufgabe 2 baut und von der Klasse aus Aufgabe 1 abhängt
        3: Programm aufrufen mit den entsprechenden Übergabeparametern. Diese sind in .dat-Dateien gegeben. Sinnvoller Weise kann man hier ein Shell-Skript einsetzen!
        4: Visualisierung mit Gnuplot entsprechend der Anleitung

***[Aufgabe 3 - Dokumentation]***
+ Dokumentation anhand der Vorgaben!

#### Dokumentation

* Als PDF
* Erste Version mit Markdown, wenn noch Zeit ist mit LaTex



### Meine Anmerkungen beim Lösen der Aufgabenstellung

+ Am besten schaut man vor allem Anderen nach Referenzcode, an dem man sich orientieren kann.

+ Baue zu aller erst die Infrastruktur:
    1: Makefile, damit man automatisiert bauen kann. Das spart Zeit
    2: Dummy-Methoden ohne Funktion, damit der Code das erste mal baut und man ab da immer ausprobieren kann


    Das macht man am besten mit dem Terminal und dem lieblingseditor, da das ganze in der IDE nur unnötig kompliziert ist, wenn man weiß, wie die Infrastruktur aussehen muss/soll

+ Um zu verstehen, was überhaupt gefragt ist, sollte man sich anschauen, was als Ergebnis erwartet wird!
	+ Wir suchen: nx, ny (diskrete Schrittweite, relativ zur Grenze des Untersuchungsbereichs z_ll) & n_iter (Anzahl an Iterationen bis zur Divergenz oder n_max fuer Konvergenz)
	+ Dabei: genau auf den Wortlaut achten! Hier -> 'z0=nx*delta_x+i*ny*delta_y liegt im Definitionsbereich', also ist die Formel nur das Offset auf z_ll -> z0 = z_ll + (nx*delta_x+i*ny*delta_y)



***Code:***

+ const MyComplex MyComplex::operator+(double a) const{}
	+ das nachgestellte const hinter dem (double a) sagt aus, dass das aufrufende Objekt der Methode nicht verändert werden kann. 
	+ Dem entsprechend wird das const nicht bei Methoden/Operatoren nachgestellt, die das Objekt selbst verändern, wie bspw setter-Methoden, Zuweisungsoperatoren oder Konstruktoren
	+ das const MyComplex sagt aus, dass die Rückgabe der Methode vom Typ MyComplex ist und das zurück gegebene Objekt nicht mehr verändert werden kann. 

+ die <Klasse>.cpp darf keines Falls in die .h eingebunden werden! Sonst baut er nicht/kann die Klasse nicht im .cpp - File finden!

+ Alle Operatoren oder Methoden, die das Objekt mit dem sie aufgerufen werden verändern geben eine Referenz als Rückgabeobjekt zurück. Alle Operatoren und Methoden, die dem Rechnen dienen, geben das entsprechende Objekt zurück.
  + Constant-Correctness: Schränke die Rückgabe so weit wie möglich ein! Also setze die zurück gelieferten Objekte auf _const_!

+ Schreibe ich einen Destruktor in der .hpp, lasse ich ihn also nicht generisch vom Compiler erstellen, so *MUSS* (!) ich ihn auch in der .cpp schreiben, ansonsten mäckert der Compiler!

+ Makefile-Dependencys: Alle Objektdateien haengen nur von der eigenen .cpp ab. Ansonsten sind sie nur von den .h Dateien der anderen SRCs abhaengig!

+ Ergebnisse in Datei schreiben: 
	+ In C++ wird ein geöffnetes File innerhalb des Programms als "Stream" bezeichnet. Ich muss also in den Stream rein schreiben! Alles was ich schreiben will muss ich mit dem Stream-OBJEKT machen!
	+ Es gibt 3 Klassen in C++-Standart-Library, um File-Streams und zugehörige, physikalische Files zu erstellen: ofstream, ifstream und fstream. Diese erben von istream und ostream (input-/output-Stream). istream und ostream sind auch das Elternobjekt von std::cin/std::cerr und std::cout. Die Verwendung ist also analog!!! Der Unterschied liegt nur darin, dass die drei zuletzt genannten Stream einen virtuellen Kanal haben, ofstream, ifstream und fstream aber ein reales File referenzieren und darin schreiben/lesen
	+ Wenn ich mit einem Streamobjekt eine Datei öffne und damit referenziere, kann/muss ich sagen, welchen Modus der Stream haben soll. Also wie er in die Datei schreiben soll (normal oder binär, ..). Die drei beschriebenen Streams haben jeweils default-Modi. Bei ofstream ist das ios::out. (Für mehr Details: http://www.cplusplus.com/doc/tutorial/files/)
	+ Wenn ich ein Stream-Objekt erstelle ist diesem erstmal kein File zugeordnet. Erst wenn ich <Objektinstanz>.open(<path/to/filename>) [bzw nur Filename übergaben, wenn das File sich im aktuellen Ordner befindet/befinden soll nach der Erstellung] sage, wird das entsprechende File dem Stream zugeordnet. 
	+ Schließe ich das File mit <Objektinstanz>.close(), so wird das File im Programm geschlossen und es ist für andere Programme (wieder) verfügbar. (Das istream/ostream-Objekt hat eine Zugriffsverwalung integriert!) Das Stream-Objekt bleibt allerdings erhalten bis zum Ende des Scopes! Es kann dann wiederverwendet werden, um andere Objekte zu öffnen (mit erneuter Verwendung von <Objektname>.open(<Dateiname>))!
	+ Innerhalb des Stream-Objekt gelten die selben Codierungen wie bei cout, also '<<' für unten anfügen, \n für Zeilenumbruch

+ Ich kann Operatoren miteinander verketten, wenn die Rückgabetypen entsprechend passen!
	z_1.operator-().operator+(5) funktioniert! -> z_1.operator-() ist das unäre Minus!

***Debugging***
+ Mit der Compilerdirektive #define und #ifdef <Anweisungen, wenn definiert> #endif lassen sich alle Debug-Teile des Codes für das Compilieren ausschalten
	+ Möchte ich den Debug-Modus, muss ich nur eine Zeile aus-/einkommentieren und neu compilieren
	+ Das macht, im Gegensatz zu einer Debug-Flag keinen Overhead bei der Laufzeit und beim Compilieren wenn ich des Code nicht verwenden will 
	+ Dafür muss ich eine Debug-Executable und eine 'Finished Code'-Executable erstellen



#### Allgemeines

+ TIPP beim Implementieren von Klassen (insbesondere beim Rechnen): 
	+ Alle Fälle abdecken! Nicht nur die benötigten Rechenregeln implementieren, sondern alle
	+ Achtung bei Berechnungen wie ^x: Es müssen alle Fällle abgedeckt sein, nicht nur ^2!

+ Variablen _Definition_ :
	+ Anforderung des Speicherplatz, falls nicht geüegend Platz alloziert werden kann, wird eine Exception ausgelöst!
	+ Beiispiel: int i; 
+ Variablen _Initialisierung_: 
	+ Initialen Wert zuweisen
	+ Beispiel: 
			
			int i; // Definiton
			i = 5; // Initialisierung

+ Definiton und Initialisierung kann auch in einem Schritt statt finden! (über den Konstruktor oder Zuweisungsoperator)

+ cin mehrerer Terminaleingaben: 
	+ cin >> a >> b; 
	+ Das liest a und b nacheinander ein
	+ Das kann man im Terminal dann entweder als 
			
			2, 3 <Enter>
	
	 umsetzen, oder die Eingabe wartet bis die zweite Eingabe erfolgt

		
			2
			3

	+ Liest man über ein Eingabefile Daten ein, so wird jedes Leerzeichen, Tab und Zeilenumbruch als neue Eingabe gewertet



***Shell-Skript***

+ Unheimlich sensitiv auf Leerzeichen. 
	+ Beispiel in den Test-Dateien -> if [ bla -bli blub ] funktioniert nur wenn rechts und links Leerzeichen sind
+ $(blabla) führt Kommando in der Klammer aus
+ $bla ist ein Variablenzugriff
+ Variablen schreiben:
	+ Keine Leerzeichen im Zuweisungsoperator verwenden, ansonsten wird nur das erste Element, welches ein Leerzeichen ist, zugewiesen!
		
		A=5
	NICHT
		A = 5 

***GNU-Plot***

+ Ich kann befehle statt mit ; zu trennen und in einer Zeile auch ohne ; in Skript schreiben und mit load 'datei.gp' starten

+ Möchte ich zur Kontrolle etwas im GNU-Plot Terminal ausgeben, so kann ich einfach print <Variable> schreiben

+ for-Schleifen und If-Statements sind ebenfalls möglich!

+ plotten mit 3d maps: 
	+ set pm3d map
	+ bei x y z - Koordinaten: splot 'abc.dat' u ($1):($2):($3), statt nur u 1:2:3 
	+ für weitere Details siehe Aufgabe 2


