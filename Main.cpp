/*
=====================================================================Arman Arakelyan========================================================================

Welcome to the unbeatable tic tac toe.

This program uses an algorithm called minimax. --> https://en.wikipedia.org/wiki/Minimax

You can find more on how minimax is applied to tic tac toe --> here https://neverstopbuilding-dropblog.herokuapp.com/minimax

The computer essentially calls itself recursively and "plays" every possible move given the board arrangment.
Each move is assigned a score based on the outcome and stored in a vector. 
After the recursion terminates the vector of moves is run through a loop to determine the best score and the index of that move is returned as the "goldenMove".
This is done for every possible empty spot on the board to ensure the best overall move.

*/
#include <iostream>
#include "GameMaster.h"
int main()
{
	//Declare Variables
	int index=0;
	char sel=' ';
	char plyrSide=' ';
	//Pointer to be able to construct games as many times as user wants.
	GameMaster *myGame=NULL;
	do
	{
		std::cout << "Choose your side (X or O)" << std::endl;
		std::cin >> plyrSide;
		plyrSide = toupper(plyrSide);
		if (plyrSide == 'X')
		{
			//contruct a game where player goes first
			myGame = new GameMaster('O', 'X');
			myGame->printBoard();
		}
		else if (plyrSide == 'O')
		{
			//construct a game where player goes second, perform a computer move
			myGame = new GameMaster('X', 'O');
			myGame->computerMove();
			myGame->printBoard();
		}
		else
		{
			//in case the user does an invalid input, default game will allow user to go first.
			myGame = new GameMaster('O', 'X');
			myGame->printBoard();
			std::cout << "That was not a valid option..." << std::endl;
			std::cout << "Default Game chosen...\nYou go first!" << std::endl;
		}
		//do loop to make sure user enters a valid position
		do
		{
			std::cout << "Choose position 0-8\n" << std::endl;
			std::cin >> index;
			//check for non-numbers
			if (!(std::cin.fail()))
			{
				//if move fails
				if (!myGame->playerMove(index))
				{
					std::cout << "Oops...\nThat move did not go through :/" << std::endl;
				}
			}
			else
			{
				//if user enters a non-number
				std::cout << "Please enter numbers..." << std::endl;
				std::cin.clear();
				std::cin.ignore(1);
				std::cin.fill(0);
			}
		} while (myGame->getWinnerValue() == NONE); //end of user input loop

		//once the game is in termination state check the status.
		if (myGame->getWinnerValue() == AI)
		{
			std::cout << "COMPUTER WON!" << std::endl;
		}
		else if (myGame->getWinnerValue() == HUMAN)
		{
			std::cout << "HUMAN WON!" << std::endl;
		}
		else if (myGame->getWinnerValue() == DRAW)
		{
			std::cout << "DRAW!" << std::endl;
		}
		//delete the game and offer the user to play again.
		delete myGame;
		std::cout << "Again? (y/n)" << std::endl;
		std::cin >> sel;
		sel = tolower(sel);
		if (sel != 'y' && sel!='n')
		{
			std::cout << "Invalid Selection... \nExiting...\n";
			sel = 'n';
		}
	} while (sel != 'n'); //end of the game loop
	return 0;
}
