#ifndef MOVES_H
#define MOVES_H
//Moves class is a data stracture that allows an index to carry a score with it.
class Moves
{
private:
	//two attributes of the move
	int index, score;
public:
	/**
	default constructor
	@Initilize both attributes to 0
	*/
	Moves();
	/**
	constructor that takes a custom score
	@int s, initilize score to s
	@initilize index to 0
	*/
	Moves(int s);
	/**
	a getter function for index
	@return the index of the instance
	*/
	int getIndex()const;
	/**
	a getter function for score
	@return the score of the instance
	*/
	int getScore()const;
	/**
	a setter function for index
	@int i, initilize index to i
	@return void.
	*/
	void setIndex(int i);
	/**
	a setter function for score
	@int s, initilize scire to s
	@return void.
	*/
	void setScore(int s);
};
#endif //MOVES_H

