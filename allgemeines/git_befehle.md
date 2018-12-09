### Einige wichitige GIT-Befehle

#### Branch basierend auf anderem Branch erstellen
git checkout -b myfeature dev

#### Merge Branch A in Branch B

          $ cd /path/to/local/branch
          $ git checkout B
          $ git merge B -m "merge commit message"

+ Grundsätzlich sollte man niemals das Online-Tool von GIT zum mergen verwenden!
  + So lange der merge nur lokal ist, habe ich online nichts kaput gemacht und kann einfach $ git stash und nochmal versuchen
  + Ich muss ausprobieren, ob der gemergte Code überhaupt (fehlerfrei) lauffähig ist, bevor ich ihn pushen sollte. Evt ist durch den (fast-forward oder gelösten merge Konflikt) der Code nicht mehr lauffähig!

+ Online lassen sich alte Branches einfach löschen, sofern ich die Rechte dazu habe!

+ Falls es merge Fehler gibt, können diese von zwei Arten sein:
  + Allgemein: Es gibt einige Plug-Ins, bspw für Atom, die mit das mergen von Line-Changes erleichtern, in dem sie die konfliktären Zeilen gegenüberstellen und mich auswählen lassen!
  + Line-Changes:
      1. Generiere Liste mit allen betroffenen Files mit, denn alle confliktären Dateien werden verändert!

              $ git status

      2. Öffne die veränderten Dateien in Atom (oder einem anderen Editor) und suche nach '<<<<<<<'. Das schreibt GIT an die stellen, die in den beiden Branches unterschiedlich sind!
          + Was vor '<<<<<<< HEAD' steht, ist der aktuelle Branch A
          + '=======' trennt das, was im akuellen Branch steht von dem was im Branch B steht.
          + '>>>>>>> BRANCH-NAME' beendet den Merge Konflikt in den jeweiligen Zeilen!

      3. Entscheide, für welche Version man sich entscheidet und lösche die Konflikmarker. Es ist möglich, eine eigene Zeile zu schreiben, in der man beide, unterschiedlichen Zeilen Code miteinander vereinigt!

      4. $ git add . && git commit -m "solved merge conflicts"

  + Removed Files:
      Wenn an zwei Branches auf Branch B an einer Datei gearbeitet wird und auf Branch A gelöscht wird, muss man den Merge Konfikt mit einem zusätzlichen Commit lösen, und kann erst danach mergen.

      1. $ git checkout A && git merge B -m "try to merge" - dabei entsteht eine Fehlermeldung, die die Dateien anzeigt, die konfliktär sind.

      2. Betrachte die Dateien und entscheide ob sie behalten werden sollen oder gelöscht werden sollen:
          + löschen: $ git rm <Datei>
          + übernehmen/move: $ git add <Datei>

      3. $ git commit -m "resolved merge conflict caused by the removed file <Datei>"

      4. Versuche erneut zu mergen
