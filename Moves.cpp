#include "Moves.h"
/**
default constructor
@Initilize both attributes to 0
*/
Moves::Moves()
{
	score = 0;
	index = 0;
}
/**
constructor that takes a custom score
@int s, initilize score to s
@initilize index to 0
*/
Moves::Moves(int s)
{
	score = s;
	index = 0;
}
/**
a getter function for index
@return the index of the instance
*/
int Moves::getIndex()const
{
	return index;
}
/**
a getter function for score
@return the score of the instance
*/
int Moves::getScore()const
{
	return score;
}
/**
a setter function for index
@int i, initilize index to i
@return void.
*/
void Moves::setIndex(int i)
{
	if (i >= 0 && i <= 8)
	{
		index = i;
	}
}
/**
a setter function for score
@int s, initilize scire to s
@return void.
*/
void Moves::setScore(int s)
{
	if (s >= -1 || s <= 1)
	{
		score = s;
	}
}
