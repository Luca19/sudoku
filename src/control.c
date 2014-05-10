#include "util.h"
#include "control.h"
#include <conio.h>

/*
*  Funktionsname:  control
*  Input:             -
*  Output:        int iRueckgabe
*
*  Beschreibung:  Pr�ft ob Eingabe bzw. Taste die gedr�ckt wurde eine Zahl oder eine Pfeiltaste ist.
*                 Bei Pfeiltasten wird jeweils ein anderer Zahlenwert zur�ckgegeben. F�r eine Zahl nur einer. 
*/
void control() {
	char cAuswahl;
	int iRueckgabe = -1;

	/* Pfeiltasten abfangen
	*	iRueckgabe gibt zur�ck je nach Sonderzeichen zur�ck.
	*	LINKS	-	1
	*	HOCH	-	2
	*	RUNTER	-	3
	*	RECHTS	-	4
	*
	*  Zahlen abfangen
	*	iRueckgabe gibt zur�ck ob Eingabe eine Zahl ist.
	*	ZAHL	-	5
	*/
   cAuswahl = _getch();
   if (cAuswahl == 77)
   {
      iRueckgabe = 4;
   }
   else if (cAuswahl == 75)
   {
      iRueckgabe = 1;
   }
   else if (cAuswahl == 80)
   {
      iRueckgabe = 3;
   }
   else if (cAuswahl == 72)
   {
      iRueckgabe = 2;
   }
   else if (cAuswahl == 48 || cAuswahl == 49 || cAuswahl == 50 || cAuswahl == 51 || cAuswahl == 52 || cAuswahl == 53 || cAuswahl == 54 || cAuswahl == 55 || cAuswahl == 56 || cAuswahl == 57)
   {
      iRueckgabe = 5;
   }
	return iRueckgabe;
}

