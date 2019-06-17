#ifndef PLAYER_H
#define PLAYER_H
//enum playerType, this enum makes the program easier to read by assigning specific types to player types;
enum playerType{AI, HUMAN, DRAW, NONE, DEFAULT};
//Class player, a class that holds player symbol and type attributes. Also used t report game status.
class Player
{
private:
	//player attributes [symbol and type]
	char symbol;
	playerType type;
public:
	/**
	Default constructor
	@Initilize to default values
	*/
	Player();
	/**
	Constructor
	@char s, initilize the player's symbol
	@playerType t, initilize the player's type
	*/
	Player(char s, playerType t);
	/**
	getter function for player's symbol
	@return (char) symbol
	*/
	char getSymbol()const;
	/**
	getter function for player's type
	@return (playerType) type;
	*/
	playerType getType()const;

};
#endif //PLAYER_H