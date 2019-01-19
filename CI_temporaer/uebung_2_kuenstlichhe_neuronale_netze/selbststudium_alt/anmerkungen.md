## Anmerkungen zu Neuronalen Netzen mit Matlab

### Matlab für Neuronale Netzen

+ Eine gute Einführung findet sich auf
  https://de.mathworks.com/help/deeplearning/ug/workflow-for-neural-network-design.html

+ Gute Übersicht, wie man ein Netz Konstruiert findet sich hier:
    https://stackoverflow.com/questions/35074646/how-to-create-a-multi-layer-perceptron-in-matlab-for-a-multi-class-dataset

  hier sind alle Eigenschaften eines mit Matlab generisch erstellten MLP aufgelistet.

+ Mehrere Inputs:

      Für hochdimensionale Input Daten -> Gemeinsame Gewichtung

  1. Setze Anzahl der Inputs hoch:

        net.numInputs = 2; % fuer 2 Inputs

  2. Verlinke die Inputs in das Netz:

        net.inputConnect = [1 1; 0 0; 0 0]; % Verbinde die zwei Inputs mit dem Ersten Layer eines Netzes mit insgesamt 3 Layern. Die uebergebene Matrix entspricht eine Bool-Matrix (1 = true, 0 = false) für die Verlinkung der Layer mit dem Input.

  3. Gebe Eingabedaten auf die Inputs

        configuratedNet = configure(net, inputCellArray, outputArray)
        % Die Größen müssen zueinander passen!

          ALTERNATIV

          Für mehrere, unabhängige Inputs -> Werden eigens gewichtet!

    Baue nur einen Input und lasse die Inputdimension über configure bestimmen!




+ Mehrere Outputs:

  net.outputConnect

### Beispiele für MPL-Netze

+ newff(P):
  + Das ist ein alter Befehl, der durch feedforwardnet ab matlab 2010 ersetzt wurde
  + Erstellt ein Objekt dass ein ensprechend der Konfiguration definiertes Neuronales Netz beinhaltet. Über Membervariablen können Trainingsparameter (Hyperparameter) verändert werden.
  + newff(P,T,S,TF,BTF,BLF,PF,IPF,OPF,DDF)
    + P: [min, max] -> Werte, die das Netz abdecken soll. 'Arbeitsintervall des Netzes' (MLP wird für Regressionsaufgaben idR verwendet!) Man kann auch die Eingabedaten direkt eingeben
    + R: [S1, S2, ...] -> Größe des i-ten Layers. Ohne Betrachung des Input-Layers. Dieser wird automatisch generiert, basierend auf den Eingabedaten! - Ich kann auch die Zieldaten eingeben, dann wird ein 1 Layer Netz erstellt, dessen Ausgabedimension den Eingabedaten entspricht.
    + Effektiv machen die ersten zwei Eingaben das, was feedforwardnet und configure separat machen. Mit den letzeren Befehlen habe ich mehr kontrolle über das Netz 
    + Alle weiteren siehe doku ~ einfach nach der Bezeichnung des Übergabeparameters für Matlab googeln. Das sind systemweite Eigenschaften!
    + Optionale Parameter beschreiben:

            (..., parameterName, parameterValue, ...)


+ feedforwardnet(.):
  + Ist ein neuerer Befehl, der einen Wrapper um newff bildet. Er initialisiert und schreibt das Netz  
