#include "Player.h"
/**
Default constructor
@Initilize to default values
*/
Player::Player()
{
	type = DEFAULT;
	symbol = 'D';
}
/**
Constructor
@char s, initilize the player's symbol
@playerType t, initilize the player's type
*/
Player::Player(char s, playerType t)
{
	symbol = s;
	type = t;
}
/**
getter function for player's symbol
@return (char) symbol
*/
char Player::getSymbol()const
{
	return symbol;
}
/**
getter function for player's type
@return (playerType) type;
*/
playerType Player::getType()const
{
	return type;
}