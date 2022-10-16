#include "Game.h"
#include "Game_info.h"
#include "How_to_win.h"
#include "Menu.h"

int main()
{
	Game game;
    Game_info G;
	How_to_win h;
	Menu m;
	do{
	switch(m.menu())
	{
	case '1':  game.startgame();                        break;
	case '2':  game.backtoexit = G.game_info();         break;
	case '3':  game.backtoexit = h.how_to_win();	    break;
	case '4':  game.backtoexit = game.Score();          break;
	case '0':  game.backtoexit = game.ExitOption();  	break;
	default:   m.menu();                             	break;
	}
    }while(game.backtoexit);
    return 0;
}
