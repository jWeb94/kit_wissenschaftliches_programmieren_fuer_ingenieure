## Lambda-Funktionen

### Function Pointers

+ Weise eine Funkion zu einer Variable
+ Normale Funktionen:
  + Aufrufbar -> Ich kann keine Logik mit einer Funktion machen. Ich kann sie nur aufrufe, was rein geben und ein Ergebnis erhalten
  + Ich kann auch Funktionen als Übergabeparameter einer Funktion übergeben. Dann verwendet die Funktion den Rückgabewert der Funktion als Übergabeparameter. Das kann ich beliebig oft machen, wird aber schnell sehr unübersichtlich.
  + Function Pointers vereinfachen das und machen den Code wesentlich übersichtlicher!
+ Funktionen sind im Endeffekt nur CPU-Anweisungen. Man kann also die Adresse, in der die Funktion steht auch direkt ansprechen
+ ***Ich kann über Funktionspointer eine Funktion schreiben, die an eine andere Funktion (mittels Funktionspointer als Übergabeparameter) übergeben wird. So kann ich verschiedene Funktionalitäten in einer Grundfunktionaliät umsetzen! vgl in zusaetzliche_programme den Beispielcode 'function_pointers.cpp'***
+ Wichtig bei Funktionspointern ist, dass ich Funktion(pointer) an Funktionen als Übergabeparameter weiter geben kann!


### Lambda-Funktionen:

+ Lambda-Funktionen sind:
  + Namenlose Funktionsobjekte
  + Werden an der Stelle ihrer Verwendung definiert
  + Sind Bestandteil der ***funktionalen Programmierung***

+ Machen immer dann Sinn, wenn ich eine Funktion mit einem Function-Pointer als Übergabe verwenden möchte. Dann muss ich mir nicht extra eine Funktion sschreiben, die aufrufen will, sondern kann das direkt im Funktionsaufruf schreiben.
  + Das macht natürlich nur dann Sinn, wenn ich die Funktion nur genau einmal an der Stelle, an der die Funktion als Übergabeparameter übergeben werden soll verwendet wird. Bei häufigerem Verwenden bietet sich eine normale Funktionsdefinition an, die ich dann an die Funktion übergebe!

+ Lambda-Funktionen sind wie folgt aufgebaut:


          [<Captures>] (<Parameter Spezifikationen>) <Spezifikationen> -> <Rueckgabetyp> {Lambda; Body} (<tatsaechliche Parameter>)

    + captures: 'Fangen' von Umgebungsvariablen ~ Falls ich bereits vorhandene Variablen in der Lambda veraendern will.  
          + []: fange nichts
          + [=]: Alles bei Wert
          + [&]: Alles bei Referenz
          + [<Variable>]: Nur die <Variable> wird aus dem Speicher weiter verwendet. (Bei Wert)
          + [&<Variable>]: ..
          + [y = x]: Initialisiert lokale Variable y mit globalen Wert von x

     + Parameter Spezifikationen: Sagt, wie viele und von welchen Typ die Lambda-Funktion Parameter übernimmt
          + Beispiel:

                [](int a, float b, string c)...

             Lamdbda nimmt 3 Parameter entegegen mit den entsprechenden Datentypen, die über ihre Namen (a, b, c) im Körper der Lambda-Funktion angesprochen werden können!

      + Spezifikationen: const oder mutable ~> mutable sagt, dass die lokalen Kopien (!) der 'passed-by-value' Variablen verändert werden dürfen
      + Rückgabetyp: Nur notwendig, wenn kein return in der Lambda-Funktion steht! Ansonsten kann das notfalls (!) der Compiler auch deduzieren.    

+ Achtung bei der Parameterübergabe:
  + Wenn ich den Parameterübergabetyp angebe muss ich mir gedanken machen, wie die Funktion mit den Parametern umgehen soll!
    + Will ich das übergebene Objekt global verändern, so muss ich es per Referenz übergeben, sofern ich kein return habe
    + Übergebe ich per Wert, so erstellt sich die Lambdafunktion zur Laufzeit eine Variable, die den entsprechenden, übergebenen Wert hat, aber nur im Scope der Lambdafunktion lebt!
