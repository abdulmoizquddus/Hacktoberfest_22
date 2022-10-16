#include "How_to_win.h"
#include "Game.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool How_to_win::how_to_win()
{
    system("cls");
    Game title;
    title.TitleDisplay();
    cout<<"\t\t\t |-------------------------|\n"
          "\t\t\t | How To Play Tic Tac Toe |\n"
          "\t\t\t |-------------------------|\n\n"
 	      "  To beat the Opponent, you need to make use of a little bit of strategy. Strategy means\n"
	      "  figuring out what you need to do to win.Part of your strategy is trying to figure out\n"
		  "  how to get three Xs or Os in a row,column or Diagonal.The other part is trying to figure\n"
		  "  out how to stop the Opponent from getting three Os or Xs in a row,column or Diagonal.\n"
          "  After you put an X or O in a square, you start looking ahead. Where's the best place for\n"
		  "  your next X or O? You look at the empty squares and decide which ones are good choices-\n"
		  "  which ones might let you make three Xs or Os in a row,column or Diagonal. You also have\n"
		  "  to watch where the Opponent puts its O or X.That could change what you do next.If the\n"
		  "  Opponent gets two Os or Xs in a row, you have to put your next X or O in the last empty\n"
		  "  square in that row,column or Diagonal otherwise the Opponent will win.You are forced to\n"
		  "  play in a particular square or lose the game.If you always pay attention and look ahead,\n"
		  "  you'll never lose a game of Tic-Tac-Toe.you may not win, but at least you'll tie.\n\n"
		  "  1) Main Menu\n"
		  "  0) Exit\n"
		  "    Choice : ";
    choice=_getch();
      switch(choice)
      {
	   case '1':
		 return true;
       case '2':
	      Choice=title.ExitOption();
	    	if(Choice == false)
              return false;
            else
	     	   How_to_win();
     }
	}
