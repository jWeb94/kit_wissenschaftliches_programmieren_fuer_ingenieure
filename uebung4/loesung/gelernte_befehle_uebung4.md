### Gelernte Befehle in Übung 4

#### man-Pages

+ Fast alle Programme, die sich über die Linux-Shell öffnen lassen, habe eine MAN-Page
+ MAN steht für 'Manual', bzw General Commands Manual

#### Skript-Sprachen

+ Ziel: Mehrfach verwendete Zeichenketten, die normalerweise einzeln im Terminal eingetippt werden würden, zeitsparend einsetzen
  + Shell-Skript und gawk: schnelle Bearbeitung textbasierter Daten

+ Keine Variablendeklaration/keine Zuweisung der Datentypen
  + Spart Zeit (kompatibilitätsprobleme, etc treten nicht auf)
  + Birgt Risiken/kann zu Fehlern führen!

+ for-Schleife:

          $ for i in $(seq 0 2 6); do mkdir test_folder_$i; echo 'finished createing test_folder_'$i; done

      Erstellt Ordner mit dem Namen test_folder_0, test_folder_2, test_folder_6 und schreibt _finished createing test_folder_0, 2, 4, 6 __ ins Terminal

      Auffällig:
        + do öffnet den Schleifenkörper ohne ein ; und done endet ihn ebenfalls ohne ;
        + die eigentliche for-Anweisung wird mit einem ; abgeschlossen
        + '' für Strings sind nicht notwendig! -> beim echo-Befehl könnte ich die auch weg lassen und beim mkdir-Befehl könnte ich sie hinzufügen!
        + Übergabe von Parametern an Shell-Funktionen wird mit Leerzeichen getrennt.
          + Beispiel:

              for i in $(seq 0 2); do mkdir test_ $i

            Würde 3 mal versuchen einen Ordner test_ anzulegen, und den Ordner 0, 1, 2 anlegen.

              for i in $(seq 0 2); do mkdir test_$i

            legt die Ordner 'test_0', 'test_1', 'test_2' an.
          + Außerdem: echo 'test' $i schreibt 'test 0', ... ins Terminal, während echo 'test'$i:  'test0', ... ins Terminal schreibt. Das Leerzeichen wird also hier mit ausgewertet!

+ rm -rf: rm bedeutet remove; -rf ist die Flag für 'recursive force'; so lange keine Konflikte entstehen, würde die -r (recursive) Flag auch reichen. Die -f Force-Flag sagt nur, dass in jedem Fall ohne Meldung gelöscht werden soll!

+ $ touch test.txt erstellt ein leeres Dokument mit dem Namen test.txt, *ohne es zu öffnen*!
