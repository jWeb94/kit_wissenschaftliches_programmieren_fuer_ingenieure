## Linux Cheat Sheet

+ mv oldName newName-> 'move' auch mit Pfad möglich, dann entspricht das einer Verschieben Operation

+ cp /von /nach

+ more /Dateiname 	-> Zeigt Teile des Inhalts der Datei in der Console an; mit :q  lässt sich die Anzeige abbrechen
+ less /Dateiname 	-> Zeigt Teile des Inhalts der Datei in der Console an; mit :q lässt sich die Anzeige abbrechen
+ cat /Dateiname		-> Zeigt Inhalt der Datei an (cat steht für concatinate files)

+ man <Befehl> 		-> Zeigt Optionen des Befehls an

+ head -n <AnzahlZeilen> /Dateiname -> Zeigt die ERSTEN Zeilen der Datei an
+ tail -n <AnzahlZeilen> /Dateiname -> Zeigt die LETZTEN Zeilen der Datei an

+ "?" in Dateinamen 	-> Ersetzt eine Ziffer; Wie "*" (Wildcat), nur für ein Zeichen

+ chmod u+rwx		-> ändere Rechte an Datei

+ ls -l 			-> Erweiterte Dateiinformationen

+ \> -, bzw < - Operator			-> Ein-/Ausgabeoperatoren

	\>> - , bzw << - Operator

	Beispiel:
		cat /Datei1 > /Datei2 -> (Über-)Schreibt Inhalt von Datei 1 in Datei 2
		cat /Datei1 /Datei3 >> /Datei2 -> Fügt Inhalt von Datei 1 & 3 an Datei 2 an

  2> Ist der Error-Kanal aus einem Programm (std::cerr)
	> Ist der Standart-Output-Kanal (std::cout)

	Formatierung entsprechend den String/Char Regeln (zB Zeilenumbruch /r ist Zeilenumbruch) im std::... - Befehl.

	Bei Programmeingaben mit std::cin >> x; und einer Eingabe durch ein eingabeDaten.dat, wird für jede Eingabe mit cin ein Leerzeichen weiter eingelesen. Sollten keine Leerzeichen vorhanden sein, so wird nach Spalten eingelesen.

		Beispiel:
			./sinus_test<inputSinus.dat 2> sinusData_test.dat # liest Daten aus inputSinus.dat für die Terminaleingaben ein und schreibt die cerr-Ausgabe in sinusData_test.dat.

			# Sollte sinusData_test.dat vorhanden sein, wird die Datei überschrieben.
			# Sollte sinusData_test.dat nicht existieren, wird eine solche Datei erstellt und die Daten entsprechend dort geschrieben.
			# std::cerr << xStep << " " << yValue << std::endl;  schreibt dann in sinusData_test.dat den xStep mit einem Leerzeichen und dann yValue zeilenweise (durch std::endl; am Ende).
