#include "Game_info.h"
#include "Game.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool Game_info::game_info()
{
    	system("cls");
      Game Title;
      Title.TitleDisplay();

	 cout<<"\n\t\tRULES OF TIC-TAC-TOE\n\n";

	 cout<<" 1. The game is played on a grid that's 3 squares by 3 squares.\n\n";

	 cout<<" 2. You are X, your friend is O. Players take turns putting their"
           " \n    marks in any number squares.\n\n";

	 cout<<" 3. The player who get 3 of her marks in a row\n"
           "    (up, down, across, or diagonally) is the winner.\n\n";

   	 cout<<" 4. When all 9 squares are full, the game is over.\n"
          "    If no player has 3 marks in a row, the game ends in a tie.\n\n\n";
	cout<<"\n1) Main Menu"
	      "\n2) Exit\n"
		  "    Choice : ";
	choice=_getch();
	switch(choice)
	{
		case '1':
			return true;
		case '2':
			Choice=Title.ExitOption();
			if(Choice == false)
			return false;
			else
			game_info();
	}
}
