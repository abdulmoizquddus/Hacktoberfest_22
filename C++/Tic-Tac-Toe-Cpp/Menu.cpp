#include "Menu.h"
#include "Game.h"
#include "Color.h"
#include <conio.h>
#include <windows.h>

Menu::Menu()
{
    choice = '0';
}
char Menu::menu()
{
    system("cls");
    Game title;
    Color c;
    title.TitleDisplay();
    c.color(12);
    cout<<">>Menu\n"; c.color(15);
    cout<<" 1) Start Game\n"
	      " 2) Game Info\n"
		  " 3) How to Win\n"
		  " 4) Score\n"
		  " 0) Exit\n"; c.color(13);
    cout<<"    Choice : ";
	choice=getch();
	c.color(15);
	return choice;
}
