### Overview GNUPlot

#### Installation

          $ sudo apt-get install gnuplot

#### Verwendung und Bedienung

+ Starten von gnuplot über

              $ gnuplot

+ Daten aus Datei plotten:
  * Ich muss im jeweiligen Verzeichnis mit dem Terminal sein, in dem sich die Daten befinden.
  * Gebe an, welche Spalten als Punkte nebeneinander geplottet werden sollen!

        gnuplot > plot 'daten.dat' using 1:2 w lp

        Erklärung:
          plot ist der plot-befehl
          die zu plottenden daten in '' setzen!
          using gibt an, dass gewisse Spalten aus der Datei entnommen werden sollen
          1:2 bedeutet in dem Fall 1 und 2 Spalte, DIE BESCHRIEBEN IST ! (vgl waveTest.dat und der Befehl plot 'waveTest.dat' using 1:2 w lp)

+ gnuplot beenden:

            gnuplot > exit

              ODER

            gnuplot q

+ Funktion definieren und plotten:

          gnuplot > f(x) = sin(x); # definiere Funktion f(x)
          gnuplot > pl f(x) w lp   # w lp bedeutet with linepoints, also dass alle ausgewerteten Punkte mit einem Punkt versehen werden

  Dabei entsteht ein Plot mit generisch eingesetzten x-Werten.

+ Bestimmte Anzahl an x-Range:

          gnuplot > set xrange [0:2*pi];
          gnuplot > replot                # plotfenster bleibt offen und plottet mit neu gesetzten Parametern wie xrange

+ Weitere Befehle:

    + clear -> Resettet Plot-Fenster, NICHT den Arbeitsspeicher, was eingetragene Funktionen angeht!

    + ; Trennt Befehle, ich kann also in einer Zeile mehrere Komandos umsetzen!

    + werden Dateien eingelesen, so werden Zeilen, denen ein # vorrangesetellt ist als Kommentare interpretiert

+ Funktionen mit Parametern plotten:

          gnuplot > a=5; b=3;
          gnuplot > g(x) = a*x+b;
          gnuplot > pl g(x) w lp
