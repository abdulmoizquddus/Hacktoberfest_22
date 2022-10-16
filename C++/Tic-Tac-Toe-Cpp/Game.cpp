#include "Game.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Color.h"
using namespace std;
Game::Game()
{
    for(int i=0 ; i<20 ; i++)
    {

        selection[i]='F';
    }
   win1=0,win2=0,loss1=0,loss2=0,sdraw=0;
   draw= false,undo=false,redo=false;
   Quit=false,backtoexit=true,Exit=true;
   turn='X';
   k=0,temp=0;
}
Color c;
void Game::InitializeBoard()
{
	int n=49;    //   49 is the ASCII code of 1 and Onward Numbers 50-57 are ASCII Code of 2-9 Respectively
	for( int i=0 ; i<3 ; i++ )
	for( int j=0 ; j<3 ; j++ )
	{
		board[i][j]=n; // Setting Board To its Initial Position
		n++;
	}
}
void Game::TitleDisplay()
{

    c.color(11);
	cout<<"\n\t\t\t    "<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178);
	cout<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<endl;
	cout<<"\t\t\t    "<<char(178); c.color(911); cout<<"  Tic Tac Toe Game  "; c.color(14); cout<<char(178);
	cout<<"\n\t\t\t    "<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178);
	cout<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<char(178)<<endl<<endl;
	c.color(15);
}

bool Game::ExitOption()
{
	char ExitChoice;
	cout<<"\nAre You Sure You Want to Exit\n"
	      "    ( Yes(Y) or No(N) )\n";
	ExitChoice=_getch();
	if( ExitChoice=='Y' || ExitChoice=='y' )
	return false;
	else if( ExitChoice=='N' || ExitChoice=='n' )
	return true;
	else
	ExitOption();
}

void Game::startgame()
{

	Players_Names();
	do         //                                           Outer Do While Starting To Chech Either user want to Play Again or Not
	{
	InitializeBoard();
	////////////////////////////Game Body////////////////////////////////
	do{
	Display();
	Move();
    }while(win_check());
    ////////////////////////////Game Body////////////////////////////////
    system("pause");
    system("cls");
    Result();
    line:
    	cout<<"\n\nSelect AnyOne\n";

	    cout<<"\n1) Play Again"
	          "\n2) Main Menu"
	          "\n3) Exit\n Choice : ";
        PlayAgain_choice=_getch();
        //                                                Switch Start
	    switch(PlayAgain_choice)
        {
		   case '1':  Quit = false;  continue;
		   case '2':  Exit = false;  break;
		   case '3':  cout<<"\n\n";
		              backtoexit=ExitOption();
                      if(backtoexit==true){ system("cls");	goto line; }
		              break;
		   default:   system("cls");	TitleDisplay();
			          cout<<"Invalid Choice\nPlease Select Valid one\n";
			           goto line;
	}  //                                               Switch End
    }while(Exit && backtoexit);   //                                         Outer Do While
}

void Game::Players_Names()
{
	system("cls");
	TitleDisplay();
	c.color(14); cout<<"\n>>Players Names\n"; c.color(7);
	cout<<"\n  Enter Player 1 Name : "; c.color(15);   cin>>Player1; c.color(7);
	cout<<"\n  Enter Player 2 Name : "; c.color(15);   cin>>Player2;
}

void Game::Display()
{
	system("cls");
	TitleDisplay();
	cout<<endl;c.color(9);
	cout<<" Player 1 :"; c.color(15); cout<<" X\t\t\t\t\t\t  Press z to Undo\n";
	cout<<" Player 2 :"; c.color(15); cout<<" O\t\t\t\t\t\t  Press y to Redo\n";
	cout<<"\t\t\t           "; c.color(11); cout<<char(219); c.color(11);cout<<"     "; c.color(11); cout<<char(219)<<"     \n"; c.color(15);
	cout<<"\t\t\t        "<<board[0][0]<<"  "; c.color(11); cout<<char(219)<<"  "; c.color(15);cout<<board[0][1]<<"  "; c.color(11);
	cout<<char(219)<<"  "; c.color(15);cout<<board[0][2]<<"  \n";; c.color(11);
	cout<<"\t\t\t      _____"<<char(219)<<"_____"<<char(219)<<"_____\n";
	cout<<"\t\t\t           "<<char(219)<<"     "<<char(219)<<"     \n";
    cout<<"\t\t\t        "; c.color(15);cout<<board[1][0]<<"  ";  c.color(11);
    cout<<char(219)<<"  "; c.color(15);cout<<board[1][1]<<"  ";   c.color(11);
    cout<<char(219)<<"  "; c.color(15);cout<<board[1][2]<<"  \n"; c.color(11);
    cout<<"\t\t\t      _____"<<char(219)<<"_____"<<char(219)<<"_____\n";
	cout<<"\t\t\t           "<<char(219)<<"     "<<char(219)<<"     \n";
	cout<<"\t\t\t        "; c.color(15);cout<<board[2][0]<<"  "; c.color(11); cout<<char(219)<<"  "; c.color(15);
	cout<<board[2][1]<<"  "; c.color(11); cout<<char(219)<<"  "; c.color(15);cout<<board[2][2]<<"  \n"; c.color(11);
    cout<<"\t\t\t           "<<char(219)<<"     "<<char(219)<<"     \n\n";
    c.color(15);
    cout<<" Press 0 To Quit\n";
}

void Game::Move()
{

	if(turn == 'X')
	    cout<<"\n "<<Player1<<" [X] Turns :- ";
	else
	if(turn == 'O')
	    cout<<"\n "<<Player2<<"[O] Turns :- ";
	turnchoice=_getch();  // User Will Select Any Number on The Board

	switch(turnchoice)
	{//      Setting Row and Column According to User Choice To Replace with 'X' or 'O'
		case '1':  	row=0;  column=0; No[0]=49; a[k]=0; if(turn=='O'){achar[k]='O';}else{achar[k]='X';} selection[k]='T'; k++; /* k=0 */ break;

		case '2':  	row=0;  column=1; No[1]=50; a[k]=1; if(turn=='O'){achar[k]='O';}else{achar[k]='X';} selection[k]='T'; k++; /* k=1 */ break;

		case '3':		row=0;  column=2; No[2]=51; a[k]=2; if(turn=='O'){achar[k]='O';}else{achar[k]='X';} selection[k]='T'; k++; /* k=2 */ break;

		case '4':		row=1;  column=0; No[3]=52; a[k]=3; if(turn=='O'){achar[k]='O';}else{achar[k]='X';} selection[k]='T'; k++; /* k=3 */ break;

		case '5':		row=1;  column=1; No[4]=53; a[k]=4; if(turn=='O'){achar[k]='O';}else{achar[k]='X';} selection[k]='T'; k++; /* k=4 */ break;

		case '6':		row=1;  column=2; No[5]=54; a[k]=5; if(turn=='O'){achar[k]='O';}else{achar[k]='X';} selection[k]='T'; k++; /* k=5 */ break;

		case '7':		row=2;  column=0; No[6]=55; a[k]=6; if(turn=='O'){achar[k]='O';}else{achar[k]='X';} selection[k]='T'; k++; /* k=6 */ break;

		case '8':		row=2;  column=1; No[7]=56; a[k]=7; if(turn=='O'){achar[k]='O';}else{achar[k]='X';} selection[k]='T'; k++; /* k=7 */ break;

		case '9':		row=2;  column=2; No[8]=57; a[k]=8; if(turn=='O'){achar[k]='O';}else{achar[k]='X';} selection[k]='T'; k++; /* k=8 */ break;

		case 'z':     undo=true;                 break;

		case 'y':    redo=true;                 break;

		case '0':    Quit=true;                 break;
		default:
			cout<<"Invalid Choice\nPlease select Valid One ";
			Move();
	}
    if(Quit == true)
     goto line;
    if ( redo==false && undo==false && turn == 'X' &&  board[row][column] != 'X'  &&  board[row][column] != 'O' )
    {
	  board[row][column] = 'X' ;    // Converting User Selected Number With X
	  turn = 'O' ;                  // Converting Turn to O
	}else
	if ( redo==false && undo==false &&  turn == 'O' &&  board[row][column] != 'X'  &&  board[row][column] != 'O' )
	{
	  board[row][column] = 'O';   	// Converting User Selected Number With O
	  turn = 'X';                   // Converting Turn to O
	}else
	if(undo==true && redo==false)
	{
	   Undo();
	}else if(redo==true && undo==false)
	{
	    Redo();
	}
	line:
	Display();
}
void Game::Redo()
{
    char t;
     temp=a[k];t=achar[k];
     switch(temp)
        {
            case 0:  row=0;  column=0; break;
            case 1:  row=0;  column=1; break;
            case 2:  row=0;  column=2; break;
            case 3:  row=1;  column=0; break;
            case 4:  row=1;  column=1; break;
            case 5:  row=1;  column=2; break;
            case 6:  row=2;  column=0; break;
            case 7:  row=2;  column=1; break;
            case 8:  row=2;  column=2; break;
        }
        if(selection[k]=='F')
        goto line;
        else if(turn == 'X' && selection[k-1]=='T')
        {
        board[row][column]=t;
            turn = 'O';
            selection[k]=='F';
        }
		else if(turn == 'O' && selection[k]=='T')
		{
		    board[row][column]=t;
		    turn = 'X';
		    selection[k]=='F';
        }
          k++;
	    line:
		redo=false;

}
void Game::Undo()
{
        k--;
        temp=a[k];
        switch(temp)
        {
            case 0:  row=0;  column=0; break;
            case 1:  row=0;  column=1; break;
            case 2:  row=0;  column=2; break;
            case 3:  row=1;  column=0; break;
            case 4:  row=1;  column=1; break;
            case 5:  row=1;  column=2; break;
            case 6:  row=2;  column=0; break;
            case 7:  row=2;  column=1; break;
            case 8:  row=2;  column=2; break;
        }
		if(board[row][column]!='O' && board[row][column]!='X')
		{
		goto line;
		}
			board[row][column] = No[temp];
		if(turn == 'X')
        turn = 'O';
		else if(turn == 'O')
		turn = 'X';

	    line:
		undo=false;
}

bool Game::win_check()
{
     if( Quit==true )
        return false;

  	 ////////////////////////////////////// Rows check ///////////////////////////////////////////

  	 if (( board [1][0] == board [1][1] && board [1][0]  == board [1][2] )  || ( board [0][0] == board [0][1] &&
	       board [0][1]  == board [0][2] ) || (board [2][0] == board [2][1] && board [2][0]  == board [2][2]))
  	 return false;

  	 //////////////////////////////////// Diagonals Check ////////////////////////////////////////

  	 if (( board [0][0] == board [1][1] && board [1][1]  == board [2][2] ) || ( board [2][0] == board [1][1] &&
	     board [1][1]  == board [0][2] ) )
  	 return false;

  	 //////////////////////////////////// Column Check ///////////////////////////////////////////

  	 if (( board [0][0] == board [1][0] && board [1][0]  == board [2][0] ) || ( board [0][1] == board [1][1] &&
	    board [1][1]  == board [2][1] )  || ( board [0][2] == board [1][2] && board [1][2]  == board [2][2] ))
  	 return false;

     /////////////////////////////////// unfilled Box Check //////////////////////////////////////

     for ( int i=0 ; i<3 ; i++ )
     for ( int j=0 ; j<3 ; j++ )
     if ( board [i][j] != 'X' && board [i][j] != 'O' )
     return true;   // If There Is Any Box Unfilled Game will Continue

     //////////////////////////// When all Boxes Filled and No one wins //////////////////////////
     draw = true;  // If There is No winner And All the Box Are Filled Then Match Draw will Be Draw
     return false;
}

void Game::Result()
{

	TitleDisplay();
	cout<<"Result :\n";

	if(Quit==true)
    cout<<"\n\t\t<<<<Game Interepted>>>>";
	else if(draw== true)
    {
    	cout<<"\n\t\t<<<<<<Game Draw>>>>>>";
    	sdraw++;
	}
    else if(turn == 'O')
    {
    	cout<<"\n\t\t>>>>>>Congratulations<<<<<<\n\t\t\t"<<Player1<<" wins";
    	win1++;
    	loss2++;
	}else if(turn == 'X')
    {
    	cout<<"\n\t\t>>>>>>Congratulations<<<<<<\n\t\t\t"<<Player2<<" wins";
    	win2++;
    	loss1++;
	}
}

bool Game::Score()
{
	line:
    system("cls");
	TitleDisplay();
 	cout<<">>>Scores\n\n";

	cout<<"  >>Player 1 \n";
	 cout<<"\n      >>wins :- "<<win1<<endl;
     cout<<"\n      >>Loses :- "<<loss1<<endl;

 	////////////////////  Player 2 Win and Lose Number  ///////////////////

	 cout<<"\n  >>Player 2 \n\n";
	 cout<<"      >>wins :- "<<win2;
 	 cout<<"\n\n      >>loses :- "<<loss2<<endl;

 	/////////////////////   Number of Draws  //////////////////////////////
	int choice;
    cout<<"\n  >>Games Draw \n\n";
	cout<<"      >>Draws :- "<<sdraw<<endl<<endl;
	cout<<"\n1) Main Menu"
	      "\n2) Reset Scores"
	      "\n3) Exit\n"
		  "    Choice : ";
	choice=_getch();
	switch(choice)
	{
		case '1':
		   return true;
		case '2':
			loss1=0,loss2=0,sdraw=0,win1=0,win2=0;
		    goto line;
		case '3':
		   char ExitChoice;
	        cout<<"\nAre You Sure You Want to Exit\n"
	              "    ( Yes(Y) or No(N) )\n";
	        ExitChoice=_getch();
	       if( ExitChoice=='Y' || ExitChoice=='y' )
	        return false;
	       else if( ExitChoice=='N' || ExitChoice=='n' )
	         goto line;
		default:
			Score();
    }
}
