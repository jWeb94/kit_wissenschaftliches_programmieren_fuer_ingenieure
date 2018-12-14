### Anmerkungen und Hinweise zur Lösung der Abgabeaufgabe

#### Aufgabenstellung

***Aufgabe 1***
- _ToDo_:
        1: Klasse erstellen und Operatoren überladen
        2: Make-File erstellen
        3: *Testprogramm* verwenden (!), um die Richtigkeit des Codes zu überprüfen
        4: (Eigene Aufgabe) Gegenchecken mit Matlab
        5: Dokumentation in Lösungs-PDF in Operatorschreibweise

***Aufgabe 2***

- _ToDo_:
        1: Neue Main-Methoden-File erstellen, dass Eingabeparameter einliest und die Iterationsvorschriften berechnet
        2: Make-File schreiben, dass für Aufgabe 2 baut und von der Klasse aus Aufgabe 1 abhängt
        3: Programm aufrufen mit den entsprechenden Übergabeparametern. Diese sind in .dat-Dateien gegeben. Sinnvoller Weise kann man hier ein Shell-Skript einsetzen!
        4: Visualisierung mit Gnuplot entsprechend der Anleitung


#### Dokumentation

* Als PDF
* Erste Version mit Markdown, wenn noch Zeit ist mit LaTex



### Meine Anmerkungen beim Lösen der Aufgabenstellung

+ Am besten schaut man vor allem Anderen nach Referenzcode, an dem man sich orientieren kann.

+ Baue zu aller erst die Infrastruktur:
    1: Makefile, damit man automatisiert bauen kann. Das spart Zeit
    2: Dummy-Methoden ohne Funktion, damit der Code das erste mal baut und man ab da immer ausprobieren kann


    Das macht man am besten mit dem Terminal und dem lieblingseditor, da das ganze in der IDE nur unnötig kompliziert ist, wenn man weiß, wie die Infrastruktur aussehen muss/soll


***Code:***

+ die <Klasse>.cpp darf keines Falls in die .h eingebunden werden! Sonst baut er nicht/kann die Klasse nicht im .cpp - File finden!

+ Alle Operatoren oder Methoden, die das Objekt mit dem sie aufgerufen werden verändern geben eine Referenz als Rückgabeobjekt zurück. Alle Operatoren und Methoden, die dem Rechnen dienen, geben das entsprechende Objekt zurück.
  + Constant-Correctness: Schränke die Rückgabe so weit wie möglich ein! Also setze die zurück gelieferten Objekte auf _const_!

+ Schreibe ich einen Destruktor in der .hpp, lasse ich ihn also nicht generisch vom Compiler erstellen, so *MUSS* (!) ich ihn auch in der .cpp schreiben, ansonsten mäckert der Compiler!

+ Makefile-Dependencys: Alle Objektdateien haengen nur von der eigenen .cpp ab. Ansonsten sind sie nur von den .h Dateien der anderen SRCs abhaengig!
