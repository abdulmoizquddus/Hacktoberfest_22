#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Color.h"
using namespace std;

class Game
{
    private:
        bool draw,undo,redo,Quit;
      char turn,No[9];
      int turnchoice,PlayAgain_choice;
	  int row,column,Exit,a[20];
	  string Player1,Player2;
	  char selection[20];
	  char achar[20];
	  int temp,k;
	  int win1,win2,loss1,loss2,sdraw;
    public:
        char board[3][3];
        Game();
        void Redo();
        void Undo();
		bool backtoexit;
		void TitleDisplay();
		void startgame();
		void Players_Names();
		void Display();
		void Move();
		bool win_check();
		void Result();
		bool Score();
		void InitializeBoard();
		bool ExitOption();
};

#endif // GAME_H
