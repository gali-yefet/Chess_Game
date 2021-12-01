#include "GameStatus.h"


//constructor
GameStatus::GameStatus()
{
	this->isWhiteTurn = 0;
	//0- white
	//else- black
}
string GameStatus::toString() const
{
	if (this->isWhiteTurn == 0)
		return "RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr1";
	return "RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr0";
}

void GameStatus::getBoard() const
{
	return this->board;
}