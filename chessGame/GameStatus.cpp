#include "GameStatus.h"


//constructor
GameStatus::GameStatus()
{
	this->isWhiteTurn = 0;
	//0- white
	//else- black
	//add rook

}
string GameStatus::toString() const
{
	if (this->isWhiteTurn == 0)
		return "RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr1";
	return "RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr0";
}

vector<Piece*> GameStatus::getBoard() const
{
	return this->_board;
}

bool GameStatus::getIsWhiteTurn() const
{
	return this->isWhiteTurn;
}