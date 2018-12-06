#ifndef _ADDITION   // Praeprozessoranweisung

#define _ADDITION

int addiere(int,int);

#endif


/*
 * Ziel ist es, eine Mehrfacheinbindung der Funktion zu verhindern!
 * Checke, ob _ADDITION schon vom Präprozessor definiert wurde
 * Ist das der Fall, wird die Header-Datei nicht noch einmal eingebunden.
 * Ansonsten wird die Header-Datei eingebunden und _ADITTION als Name definiert
 *
 * In diesem Fall wird _ADITTION nur als Flag verwendet, um Mehrfacheinbindung zu verhindern, richtig?
 *
 * Das macht den Compiliervorgang nur schneller, oder?
 */
