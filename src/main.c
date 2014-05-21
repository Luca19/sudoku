#define _CRT_SECURE_NO_WARNINGS 1

#include "util.h"
#include "register.h"
#include "login.h"
#include "toplist.h"
#include "sudoku_gen.h"
#include "view.h"

#define MAIN_MENUE_SIZE 3
#define GAME_MENUE_SIZE 5

int LoadMainMenue(void);
void LoadGameMenue(ACCOUNT user);

/* ============================================================================
* Funktion:        main
* Input:           -
* Output:          int
*
* Beschreibung:    Funktionsaufrufe für Registrierung.
* ============================================================================
*/
int main(void)
{
	int m_Exit = 0;
	do
	{
	  resizeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
	  m_Exit = LoadMainMenue( );
	} while(!m_Exit);
   
	system("cls");
   printf("\n\n\n\t\tWe hope you enjoyed your time. Visit us again!");
	printf("\n\n\n\n\n\n\n\n\n\n\n\nPress a key to exit");
	getchar();
   return 0;
}

int LoadMainMenue(void) {
	int iStatus = 0, iTemp = 1, i, m_Exit=0;
   char *cMenu[MAIN_MENUE_SIZE] = { "Register", "Login", "Exit"},highLight[2];
   ACCOUNT user;
   
	sprintf(highLight, "%c", 16);
	system("cls");
	createBlockView(WINDOW_WIDTH, 37);
	createBlockView(WINDOW_WIDTH, 10);
	loadMainLogo();
	printTo(((WINDOW_WIDTH-9)/2), 40, "M E N U E");
	printTo(((WINDOW_WIDTH-9)/2), 41, "= = = = =");
	for (i = 0; i < MAIN_MENUE_SIZE; i++)
	{
			printTo((WINDOW_WIDTH-9)/2, 43+i, cMenu[i]);
	}
	printTo(((WINDOW_WIDTH-9)/2)-5, 43, highLight);
	gotoxy(WINDOW_WIDTH-1,0);
   do
   {
		iStatus = control();
		printTo(((WINDOW_WIDTH-9)/2)-5, 42+iTemp, " ");
		if (iStatus == 2) 
		{
			if (iTemp > 1) 
			{
				iTemp--;
			}
		}
		else if (iStatus == 3) 
		{
			if (iTemp < MAIN_MENUE_SIZE && iTemp > 0)
			{
				iTemp++;
			}
		}
		printTo(((WINDOW_WIDTH-9)/2)-5, 42+iTemp, highLight);
		gotoxy(WINDOW_WIDTH-1,0);
   } while (iStatus != 6);

   system("cls");

   switch(iTemp) 
   {
		case 1:
			registrierung();
			system("cls");
		break;
		case 2:
			user = login();
			system("cls");
			if( user.FirstName=="" )
			{
				printf("\n\n\n\nError, couldn't log in, the game will shut down automatically now.");
				m_Exit = 1;
				getchar( );
			}
			else
			{
				LoadGameMenue(user);
			}
		break;
		default:
			m_Exit=1;
			break;
   }
	return m_Exit;
}

void LoadGameMenue(ACCOUNT user) {
	int iStatus = 0, iTemp = 1, iLength = 0, i, m_Exit = 0;
   char *cMenu[GAME_MENUE_SIZE] = { "Play Sudoku", 
												"How To Play", 
												"Top List",
												"Settings",
												"Log Out"}
			,highLight[2];
	
	sprintf(highLight, "%c", 16);

	if(user.WindowHeight!=0 && user.WindowWidth!=0) {
	  resizeWindow(user.WindowWidth, user.WindowHeight);
	} else {
		user.WindowWidth = WINDOW_WIDTH;
		user.WindowHeight = WINDOW_HEIGHT;
	}

	createBlockView(user.WindowWidth, ((user.WindowHeight/3)*2)-4);
	createBlockView(user.WindowWidth, ((user.WindowHeight/3)*1)+1);
	printTo(((user.WindowWidth-17)/2), ((user.WindowHeight/3)*2)-2, "G A M E M E N U E");
	printTo(((user.WindowWidth-17)/2), ((user.WindowHeight/3)*2)-1, "= = = = = = = = =");
	for (i = 0; i < GAME_MENUE_SIZE; i++)
	{
			printTo((user.WindowWidth-17)/2, ((user.WindowHeight/3)*2)+1+i, cMenu[i]);
	}
	printTo(((user.WindowWidth-17)/2)-5, ((user.WindowHeight/3)*2)+1, highLight);
	gotoxy(user.WindowWidth-1,0);

   do
   {
		iStatus = control();
		printTo(((user.WindowWidth-17)/2)-5, ((user.WindowHeight/3)*2)+iTemp, " ");

		if (iStatus == 2) 
		{
			if (iTemp > 1) 
			{
				iTemp--;
			}
		}
		else if (iStatus == 3) 
		{
			if (iTemp < GAME_MENUE_SIZE && iTemp > 0)
			{
				iTemp++;
			}
		}
		
		printTo(((user.WindowWidth-17)/2)-5, ((user.WindowHeight/3)*2)+iTemp, highLight);
		gotoxy(user.WindowWidth-1,0);
   } while (iStatus != 6);

	switch(iTemp) 
   {
		case 1:
			system("cls");
			createBlockView(user.WindowWidth, 20 );
			getchar( );
			//LoadDifficultyMenue();
		break;
		case 2:
			//HowToPlay();
		break;
		case 3:
			toplist();
		break;
		case 4:
			//loadSettings();
		break;
		default:
			m_Exit = 1;
		break;
   }
}