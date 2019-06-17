#include "GameMaster.h"
/**
GameMaster constructor
@char c, the symbol for computer, used to call Player constructor for computer
@char p, the symbol for player, used to call Player constructor for human
*/
GameMaster::GameMaster(char c, char p):
	computer(Player(c,AI)), human(Player(p, HUMAN)),
	tie(Player(' ', DRAW)), none(Player(' ', NONE)) //construct the appropriate players/statuses
{
	moveCount = 0; //initilize moveCount
	winner = NONE; //initilize winner value
	//initilize the emoty board
	for (int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++)
	{
		board.push_back(' ');
	}
}
/**
Cleans a single spot on the board. This allows the computer to test all moves
@int index, the spot to clean
@return void
*/
void GameMaster::cleanBoardSpot(int index)
{
	board[index] = ' ';
	moveCount--;
}
/**
gets the Board value. This cannot change the value only read it
@int index, which spot we want to read from
@return char, the sumbol in the corresponding index
*/
char GameMaster::getBoardVal(int index) const
{
	return board[index];
}
/**
Player Move, checks for a valid input and calls move
@int index, the spot the player wants to perform a move in
@return bool, status of whether the move was successful or not
@return void
*/
bool GameMaster::playerMove(int index)
{
	//check for valid input
	if (index >= 0 && index <= 8)
	{
		if (board[index] == ' ')
		{
			move(human, index);
			winner = getWinner();
			//after the user performs a move automatically call the computerMove if the game is not over
			if (winner == NONE)
			{
				computerMove();
			}
			printBoard();
			//return the status of the move
			return true;
		}
		else
		{
			//if the provided board[index] is not empty
			std::cout << "That spot is occupied..." << std::endl;
			return false;
		}
	}
	else
	{
		//if user put a wrong number
		std::cout << "Only numbers from 0-8..." << std::endl;
		return false;
	}
}
/**
Performs a computer move by calling the recursive function to get the best possible move
@return void
*/
void GameMaster::computerMove()
{
	//check for a special base case. 
	//recursion takes couple of seconds so we can hardcode the best move at the very beginning.
	if (moveCount == 0)
	{
		move(computer, 0);
		winner = getWinner();
	}
	else
	{
		move(computer, playMinMax(computer).getIndex());
		winner = getWinner();
	}
}
/**
Move, an IMPORTANT function that performs a move on the board,
this code does not check for validations and can only be accessed inside the class
@plyr, takes the player that wants to perform a move(determines the symbol)
@int index, where the move is going to go
@return void(this function is supposed to never fail)
*/
void GameMaster::move(const Player &plyr, int index)
{
	board[index] = plyr.getSymbol();
	moveCount++;
}
/**
Prints the board
@return void
*/
void GameMaster::printBoard() const
{
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	std::cout << std::endl << "|---|---|---|" << std::endl;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		std::cout << "|";
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			//fill the empty spots with their corresponding numbers for easier play
			if ((board[i * BOARD_SIZE + j] == ' '))
			{
				std::cout << " " << i * BOARD_SIZE + j << " |";
			}
			else
			{
				std::cout << " " << board[i * BOARD_SIZE + j] << " |";
			}

		}
		std::cout << std::endl << "|---|---|---|" << std::endl;
	}
	std::cout << std::endl;
}
/**
gets winner value, simply a game status
@return playerType, returns the current value in winner variable
*/
playerType GameMaster::getWinnerValue()const
{
	return winner;
}
/**
Returns the game status or the playerType in case there is a winner.
@Return playerType, if winner found returns player type, otherwise two game statuses, tie or none(game still continues)
*/
playerType GameMaster::getWinner()const
{

	//Check all the rows
	for (int i = 0; i < BOARD_SIZE*BOARD_SIZE; i += 3)
	{
		if (board[i] == board[i + 1] && board[i + 1] == board[i + 2] && board[i] != ' ')
		{
			if (human.getSymbol() == board[i])
			{
				return human.getType();
			}
			else
			{
				return computer.getType();
			}
		}
	}
	//check all the columns
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (board[i] == board[i + 3] && board[i + 3] == board[i + 6] && board[i] != ' ')
		{
			if (human.getSymbol() == board[i])
			{
				return human.getType();
			}
			else
			{
				return computer.getType();
			}
		}
	}
	//check the 2 diagonals
	for (int i = 0; i < BOARD_SIZE; i += 2)
	{
		if (board[i] == board[4] && board[4] == board[8 - i] && board[i] != ' ')
		{
			if (human.getSymbol() == board[i])
			{
				return human.getType();
			}
			else
			{
				return computer.getType();
			}
		}
	}
	//if we didn't return so far, that means there is no winner, check for an empty spot, if found, let the game continue
	for (int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++)
	{
		if (board[i] == ' ')
		{
			return none.getType();
		}
	}
	//no winner and no empty spots, it is a tie
	return tie.getType();
}
/**
Recursively called in order to perform every possible move in the game, this stops when the game reaches a terminal state
@plyr, Allows the computer to play against an imagenary pefect human.
@return Moves goldenMove, returns the final move for the computer to perform once recursion is done.
*/
Moves GameMaster::playMinMax(const Player &plyr)
{
	//get the winner value, and check the game status
	playerType winner = getWinner();
	//base cases, 
	switch (winner)
	{
	//if human wins, return -1 to minimize the score
	case HUMAN:
		return Moves(-1);
		break;
	//if ai wins, return +1 to maximize the score
	case AI:
		return Moves(1);
		break;
	//in case of a draw no need to alter the score.
	case DRAW:
		return Moves(0);
		break;
	//if the game continues, keep calling recursively
	default:
		break;
	}
	//Define a goldenMove which will initially have the worst score possible for the specific player
	Moves goldenMove;
	if (plyr.getType() == AI)
	{
		//AI's worst score
		goldenMove.setScore(-1);
	}
	else
	{
		//Human's worst score
		goldenMove.setScore(1);
	}
	//for each board element 
	for (int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++)
	{
		//if board element is empty, 
		//computer will create a fake scenario and play with itself as if it is playing against a human
		if (board[i] == ' ')
		{
			//create a move to perform in that empty spot
			Moves possibleMove;
			possibleMove.setIndex(i);
			//perform the move behind the scenes
			move(plyr, i);
			//see who performed the move and call the recursion for the other player
			switch (plyr.getType())
			{
			case AI:
				possibleMove.setScore(playMinMax(human).getScore());
				//once a score is returned see if it is better than the old "goldenScore" and if it is change it
				if (possibleMove.getScore() >= goldenMove.getScore())
				{
					goldenMove.setIndex(possibleMove.getIndex());
					goldenMove.setScore(possibleMove.getScore());
				}
				break;
			case HUMAN:
				possibleMove.setScore(playMinMax(computer).getScore());
				//once a score is returned see if it is better than the old "goldenScore" and if it is change it
				if (possibleMove.getScore() <= goldenMove.getScore())
				{
					goldenMove.setIndex(possibleMove.getIndex());
					goldenMove.setScore(possibleMove.getScore());
				}
				break;
			default:
				break;
			}
			//we must clean up the move that we performed
			cleanBoardSpot(i);
		}
	}
	return goldenMove;
}