#ifndef GAMEMASTER_H
#define GAMEMASTER_H
#include <vector>
#include <iostream>
//Used for private inheritance
#include "Player.h"
#include "Moves.h"
//A constant board size of 3. Can be used later to modify into a 4x4 game
const int BOARD_SIZE = 3;
//Class GameMaster, inherits Player and Moves, declares them as private for security purposes.
class GameMaster: private Player, private Moves
{
private:
	//Declare different players/statuses
	Player computer,human,tie,none;
	//This holds the winner value. Used for optimization purposes
	playerType winner;
	//Used for optimization purposes. Counts the number of moves done so far
	int moveCount;
	//Declare a 1 dimensional board vector for tic tac toe interface.
	std::vector < char > board;
	//Some internal private functions that are not allowed to be used outside of this class.
	/**
	Cleans a single spot on the board. This allows the computer to test all moves
	@int index, the spot to clean
	@return void
	*/
	void cleanBoardSpot(int index);
	/**
	Returns the game status or the playerType in case there is a winner.
	@Return playerType, if winner found returns player type, otherwise two game statuses, tie or none(game still continues)
	*/
	playerType getWinner()const;
	/**
	Recursively called in order to perform every possible move in the game, this stops when the game reaches a terminated state
	@plyr, Allows the computer to play against an imagenary pefect human. 
	@return Moves goldenMove, returns the final move for the computer to perform once recursion is done.
	*/
	Moves playMinMax(const Player &plyr);
	/**
	Move, a IMPORTANT function that performs a move on the board, 
	this code does not check for validations and can only be accessed inside the class
	@plyr, takes the player that wants to perform a move(determines the symbol)
	@int index, where the move is going to go
	@return void(this function is supposed to never fail)
	*/
	void move(const Player &plyr, int index);

public:
	/**
	GameMaster constructor
	@char c, the symbol for computer, used to call Player constructor for computer
	@char p, the symbol for player, used to call Player constructor for human
	*/
	GameMaster(char c, char p);
	/**
	gets winner value, simply a game status
	@return playerType, returns the current value in winner variable
	*/
	playerType getWinnerValue()const;
	/**
	gets the Board value. This cannot change the value only read it
	@int index, which spot we want to read from
	@return char, the sumbol in the corresponding index
	*/
	char getBoardVal(int index)const;
	/**
	Prints the board
	@return void
	*/
	void printBoard()const;
	/**
	Player Move, checks for a valid input and calls move
	@int index, the spot the player wants to perform a move in
	@return bool, status of whether the move was successful or not
	@return void
	*/
	bool playerMove(int index);
	/**
	Performs a computer move by calling the recursive function to get the best possible move
	@return void
	*/
	void computerMove();

};
#endif //GAMEMASTER_H