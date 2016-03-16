

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class TicTacToe
{
private:
	char game[3][3];    //defining the game array
	bool shift(int, int);

public:
	TicTacToe();
	void Instructions();
	void displayGame();     //dispaying the game board 3 by 3
	void player1(int);
	void player2(int);
	bool Win();
	bool Draw();
	void RESET();
};


int main()
{
	int p;

	TicTacToe Tic;
	Tic.Instructions();


start:{
	string plyr1, plyr2;

	cout << "\n ============================" << endl << endl;
	cout << "   >>>>The Tic Tac Toe GAME <<<<" << endl;
	cout << " ----------------------------" << endl;

	cout << " First player name: "; cin >> plyr1;
	cout << " Second player name: "; cin >> plyr2;
	cout << endl << " ----------------------------";

	while (Tic.Win() != true || Tic.Draw() != true)
	{
		// Player One
		cout << endl << " " << plyr1 << " your Turn (X): "; cin >> p; Tic.player1(p);
		cout << " ----------------------------" << endl;

		if (Tic.Win() == true)
		{
			cout << " " << plyr1 << " WIN!" << endl; Tic.displayGame(); cout << endl << endl;
			break;
		}
		else if (Tic.Draw() == true)
		{
			cout << " Draw!" << endl; Tic.displayGame(); cout << endl << endl;
			break;
		}

		Tic.displayGame();
		cout << endl << " ----------------------------" << endl;

		// Player Two
		cout << " " << plyr2 << " your Turn (O): "; cin >> p; Tic.player2(p);
		cout << " ----------------------------" << endl;

		if (Tic.Win() == true)
		{
			cout << " " << plyr2 << " WIN!" << endl; Tic.displayGame(); cout << endl << endl;
			break;
		}
		else if (Tic.Draw() == true)
		{
			cout << " Draw!" << endl; Tic.displayGame(); cout << endl << endl;
			break;
		}

		Tic.displayGame();
		cout << endl << " ----------------------------";
	}
}
	  int choice;
	  cout << " ============================" << endl;
	  cout << " 1. New game." << endl << " 2. Exit." << endl << " > ";

  nwGmOrExt:{

	  cin >> choice;

	  switch (choice)
	  {
	  case 1:{
		  Tic.RESET();
		  cout << " ----------------------------" << endl;
		  Tic.displayGame();
		  goto start;
		  break;
	  }
	  case 2:{
		  break;
	  }
	  default:{
		  cout << " Invalid option. Please try again." << endl;
		  goto nwGmOrExt;
	  }
	  }
  }

			cout << endl << " ============================" << endl << endl;

			return 0;
}

// Constructor
TicTacToe::TicTacToe()   // assigning letter to the boxes
{

	game[0][0] = '1'; game[0][1] = '2'; game[0][2] = '3';
	game[1][0] = '4'; game[1][1] = '5'; game[1][2] = '6';
	game[2][0] = '7'; game[2][1] = '8'; game[2][2] = '9';

}
void TicTacToe::Instructions()
{

	cout << endl << " The gameboard TicTacToe" << endl;
	displayGame();

}
// Display the board
void TicTacToe::displayGame()  // game board
{
	cout << endl;
	cout << "+-----+-----+-----+" << endl;
	cout << "|     |     |     |" << endl;
	cout << "|  " << game[0][0] << "  |  " << game[0][1] << "  |  " << game[0][2] << "  |  " << endl;
	cout << "+-----+-----+-----+" << endl;
	cout << "|     |     |     |" << endl;
	cout << "|  " << game[1][0] << "  |  " << game[1][1] << "  |  " << game[1][2] << "  |  " << endl;
	cout << "+-----+-----+-----+" << endl;
	cout << "|     |     |     |" << endl;
	cout << "|  " << game[2][0] << "  |  " << game[2][1] << "  |  " << game[2][2] << "  |  " << endl;
	cout << "+-----+-----+-----+" << endl;
}

// Check Wins
bool TicTacToe::Win()
{

	if (game[0][0] == game[0][1] && game[0][0] == game[0][2])   // match row1
	{
		return true;
	}
	else if (game[1][0] == game[1][1] && game[1][0] == game[1][2])  // match row2
	{
		return true;
	}
	else if (game[2][0] == game[2][1] && game[2][0] == game[2][2])  // match row3 
	{
		return true;
	}
	else if (game[0][0] == game[1][0] && game[0][0] == game[2][0]) // match column1
	{
		return true;
	}
	else if (game[0][1] == game[1][1] && game[0][1] == game[2][1])  // match column2 
	{
		return true;
	}
	else if (game[0][2] == game[1][2] && game[0][2] == game[2][2]) // match column3
	{
		return true;
	}
	else if (game[0][0] == game[1][1] && game[0][0] == game[2][2])  // match right left diagonal 
	{
		return true;
	}
	else if (game[0][2] == game[1][1] && game[0][2] == game[2][0]) // match left right diagonal
	{
		return true;
	}
	else
	{
		return false;
	}

}

// Check if Draw
bool TicTacToe::Draw()
{
	int drw = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (game[i][j] == 'X' || game[i][j] == 'O')
			{
				drw += 1;
			}
		}
	}

	if (drw == 9) // if spaces are completed on the board
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Resetting the board
void TicTacToe::RESET()
{

	game[0][0] = '1'; game[0][1] = '2'; game[0][2] = '3';
	game[1][0] = '4'; game[1][1] = '5'; game[1][2] = '6';
	game[2][0] = '7'; game[2][1] = '8'; game[2][2] = '9';

}

// Player one's play
void TicTacToe::player1(int position)
{
	if (Win() != true)
	{
		switch (position)  // selecting spaces in the board
		{
		case 1:{
			if (shift(0, 0) == true)
			{
				game[0][0] = 'X';
			}
			else
			{
				cout << endl << " Invalid Play!!" << endl;
			}
			break;
		}
		case 2:{
			if (shift(0, 1) == true)
			{
				game[0][1] = 'X';
			}
			else
			{
				cout << endl << " Invalid Play!!" << endl;;
			}
			break;
		}
		case 3:{
			if (shift(0, 2) == true)
			{
				game[0][2] = 'X';
			}
			else
			{
				cout << endl << " Invalid Play!!" << endl;;
			}
			break;
		}
		case 4:{
			if (shift(1, 0) == true)
			{
				game[1][0] = 'X';
			}
			else
			{
				cout << endl << " Invalid Play!!" << endl;;
			}
			break;
		}
		case 5:{
			if (shift(1, 1) == true)
			{
				game[1][1] = 'X';
			}
			else
			{
				cout << endl << " Invalid Play!!" << endl;;
			}
			break;
		}
		case 6:{
			if (shift(1, 2) == true)
			{
				game[1][2] = 'X';
			}
			else
			{
				cout << endl << " Invalid Play!!" << endl;;
			}
			break;
		}
		case 7:{
			if (shift(2, 0) == true)
			{
				game[2][0] = 'X';
			}
			else
			{
				cout << endl << " Invalid Play!!" << endl;;
			}
			break;
		}
		case 8:{
			if (shift(2, 1) == true)
			{
				game[2][1] = 'X';
			}
			else
			{
				cout << endl << " Invalid Play!!" << endl;;
			}
			break;
		}
		case 9:{
			if (shift(2, 2) == true)
			{
				game[2][2] = 'X';
			}
			else
			{
				cout << endl << " Invalid Play!!" << endl;;
			}
			break;
		}
		default:{
			cout << endl << " Invalid Move!!!" << endl;  //out of box 
		}
		}
	}
}

// Player Two's play
void TicTacToe::player2(int position)
{
	if (Win() != true)
	{
		switch (position)
		{
		case 1:{
			if (shift(0, 0) == true)
			{
				game[0][0] = 'O';
			}
			else
			{
				cout << endl << " Invalid Play!!" << endl;
			}
			break;
		}
		case 2:{
			if (shift(0, 1) == true)
			{
				game[0][1] = 'O';
			}
			else
			{
				cout << endl << " Invalid Play!!" << endl;;
			}
			break;
		}
		case 3:{
			if (shift(0, 2) == true)
			{
				game[0][2] = 'O';
			}
			else
			{
				cout << endl << " Invalid Play!!" << endl;;
			}
			break;
		}
		case 4:{
			if (shift(1, 0) == true)
			{
				game[1][0] = 'O';
			}
			else
			{
				cout << endl << " Invalid Play!!" << endl;;
			}
			break;
		}
		case 5:{
			if (shift(1, 1) == true)
			{
				game[1][1] = 'O';
			}
			else
			{
				cout << endl << " Invalid Play!!" << endl;;
			}
			break;
		}
		case 6:{
			if (shift(1, 2) == true)
			{
				game[1][2] = 'O';
			}
			else
			{
				cout << endl << " Invalid Play!!" << endl;;
			}
			break;
		}
		case 7:{
			if (shift(2, 0) == true)
			{
				game[2][0] = 'O';
			}
			else
			{
				cout << endl << " Invalid Play!!" << endl;;
			}
			break;
		}
		case 8:{
			if (shift(2, 1) == true)
			{
				game[2][1] = 'O';
			}
			else
			{
				cout << endl << " Invalid Play!!" << endl;;
			}
			break;
		}
		case 9:{
			if (shift(2, 2) == true)
			{
				game[2][2] = 'O';
			}
			else
			{
				cout << endl << " Invalid Play!!" << endl;;
			}
			break;
		}
		default:{
			cout << endl << " Invalid Move!!!" << endl;
		}
		}
	}
}
bool TicTacToe::shift(int row, int column)
{
	if (game[row][column] == 'X' || game[row][column] == 'O') //if player selected the same position as the previous player
	{
		return false;
	}
	else
	{
		return true;
	}
}
