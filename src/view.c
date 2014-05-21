/* ============================================================================
* Autoren:         Mark Houben
* Klasse:          FA13
* Uebung:          Sudoku - Raster
* Dateiname:       view.c
* Datum:           20.05.2014
*
* Beschreibung:    Erstellt das Sudoku Raster
*
* ============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "util.h"

#define HEADER 1
#define BODY 2
#define FOOTER 3

void raster();
void fieldConstructor(int field);

void feldHead(int newLine);
void feldMitte(int newLine);
void feldEnd(int newLine);

void wTrenner();
void hTrenner();
void tStueck(int Zahl);

void zeihlenHoehe();
void zeihleLaenge();

/**
* ==================================================
*	Raster Settings
*	
*	Beschreibung: Die Felder werden von 0 an gezaehlt
* ==================================================
**/
int hFelder = 2;
int wFelder = 2;

int zLaenge = 6;
int zHoehe = 3;

/* ============================================================================
* Funktion:        raster
* Input:           -
* Output:          -
*
* Beschreibung:    In dieser Funktion wird das Sudoku-raster erstellt.
* ============================================================================
*/
void raster() 
{
	int i = 0;

	for(i = 0; i <= hFelder; i++) 
	{
		fieldConstructor(HEADER);

		zeihlenHoehe();

		fieldConstructor(BODY);

		zeihlenHoehe();

		fieldConstructor(BODY);

		zeihlenHoehe();
	
		fieldConstructor(FOOTER);

		if(i != 2) {
			printf("\n"); 
			hTrenner(); 
			printf("\xCE"); 
			hTrenner(); 
			printf("\xCE"); 
			hTrenner();
		}
	}
}

/* ============================================================================
* Funktion:        fieldConstructor
* Input:           {Integer} field	bestimmt das Feld
* Output:          -
*
* Beschreibung:    Die Forschleife baut die Felder zusammen die 
*					benoetigt werden.
*					"wFelder" wird in den Settings eingestellt.
*					Es wird eine Interger reingereicht der bestimmt was
*					fuer ein Feld abschnitt ausgegeben werden soll.
* ============================================================================
*/
void fieldConstructor(int field) {
	int i = 0;

	for (i = 0; i <= wFelder; i++)
	{
		switch (field)
		{
		case 1:
				if(i == 0) {
					feldHead(1);
				} 
				else
				{
					feldHead(0);
				}
				if(i <= 1) {
					wTrenner();
				}

			break;
		case 2:
				if(i == 0) {
					feldMitte(1);
				} 
				else
				{
					feldMitte(0);
				}
				if(i <= 1) {
					wTrenner();
				}

			break;
		case 3:
				if(i == 0) {
					feldEnd(1);
				} 
				else
				{
					feldEnd(0);
				}
				if(i <= 1) {
					wTrenner();
				}
			break;
		}
	}
	

}

/* ============================================================================
* Funktion:        feldHead
* Input:           int newLine
* Output:          -
*
* Beschreibung:    Baut den Head eines Feldes zusammen.
* ============================================================================
*/
void feldHead(int newLine) 
{

	if(newLine == 1) {
		printf("\n\xDA");
	} 
	else
	{
		printf("\xDA");
	}

	zeihleLaenge(); 
	tStueck(2); 
	zeihleLaenge(); 
	tStueck(2); 
	zeihleLaenge(); 
	printf("\xBF");	
}

/* ============================================================================
* Funktion:        feldMitte
* Input:           int newLine
* Output:          -
*
* Beschreibung:    Baut den Body eines Feldes zusammen.
* ============================================================================
*/
void feldMitte(int newLine) 
{

	if(newLine == 1) {
		printf("\n\xC3");
	} 
	else
	{
		printf("\xC3");
	}
	 
	zeihleLaenge(); 
	printf("\xC5"); 
	zeihleLaenge(); 
	printf("\xC5"); 
	zeihleLaenge(); 
	printf("\xB4");
}

/* ============================================================================
* Funktion:        feldEnd
* Input:           int newLine
* Output:          -
*
* Beschreibung:    Baut den Footer eines Feldes zusammen.
* ============================================================================
*/
void feldEnd(int newLine) 
{

	if(newLine == 1) {
		printf("\n\xC0");
	} 
	else
	{
		printf("\xC0"); 
	}
	
	zeihleLaenge(); 
	tStueck(1); 
	zeihleLaenge(); 
	tStueck(1); 
	zeihleLaenge();  
	printf("\xD9");
}

/* ============================================================================
* Funktion:        wTrenner
* Input:           -
* Output:          -
*
* Beschreibung:    Gibt den Wagerechten trennstrich aus.
* ============================================================================
*/
void wTrenner() 
{
	printf("\xBA");
}

/* ============================================================================
* Funktion:        hTrenner
* Input:           -
* Output:          -
*
* Beschreibung:    Gibt die Horizentalen Trennstrich aus.
* ============================================================================
*/
void hTrenner() 
{
	int i = 0;

	for (i = 0; i <= 24; i++)
	{
		printf("\xCD");
	}
}

/* ============================================================================
* Funktion:        tStueck
* Input:           int Zahl
* Output:          -
*
* Beschreibung:    Gibt eine zwei verschieden T-Stuecke aus. 
*					Je nach zahl die reingereicht wird.
* ============================================================================
*/
void tStueck(int Zahl) 
{

	if(Zahl == 2) {
		printf("\xC2");
	}
	if(Zahl == 1) {
		printf("\xC1");
	}
	
}

/* ============================================================================
* Funktion:        zeihlenHoehe
* Input:           -
* Output:          -
*
* Beschreibung:    Gibt die einzelden Felder Hoehen aus. "zHoehe" wird in den
*					Setting gesetzt.
* ============================================================================
*/
void zeihlenHoehe() 
{
	int i = 0, j = 0, x = 0;

	// Verandwortliche f�r die Zeilen H�he
	for (i = 0; i <= zHoehe; i++)
	{
		printf("\n");

		for(x = 0; x < 12; x++) 
		{
			if(x % 4 && x != 0) 
			{
				// faelt die Felder aus.
				for(j = 0; j < 7; j++) 
				{
					printf(" ");
				}
			}
			printf("\xB3");
			if(x == 3 || x == 7) 
			{
				wTrenner();
			}
			
		}
		
	}

}
/* ============================================================================
* Funktion:        zeihleLaenge
* Input:           -
* Output:          -
*
* Beschreibung:    Gibt die L�nge der Einzelden Felder aus. "zLaenge" wird
*					bein den Setting einstellungen gesetzt.
* ============================================================================
*/
void zeihleLaenge() 
{
	int i = 0;

	for (i = 0; i <= zLaenge; i++)
	{
		printf("\xC4");
	}

}

void createBlockView( int width, int height )
{
    int i=0, n=0;
	 if(width==0) {
		 width = WINDOW_WIDTH;
	 }

	 for(i=0; i<=height; i++) {
        for(n=0; n<width; n++) {
            if(i==0 && n==0) {
                printf("%c", 218);
            } else if(i==0 && n == (width-1))  {
                printf("%c", 191);
            } else if(i==0) {
                printf("%c", 196);
            } else if( i != height ) {
                if(n==0 || n==(width-1))
                    printf("%c", 179);
                else
                    printf(" ");
            } else if( n==0) {
                printf("%c", 192);
            } else if( n==(width-1)) {
                printf("%c", 217);
            } else {
                printf("%c", 196);
            }
        }
    }
    return;
}