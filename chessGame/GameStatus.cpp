#include "GameStatus.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "Bioshop.h"

#define PAWNS 8

//constructor
GameStatus::GameStatus()
{
	this->isWhiteTurn = false;
	//0- white
	//else- black
	//add rook
	this->_board.push_back(new Rook(1, 1, 0, "rook", this));
	this->_board.push_back(new Knight(2, 1, 0, "knight", this));
	this->_board.push_back(new Bioshop(3, 1, 0, "bioshop", this));
	this->_board.push_back(new King(4, 1, 0, "king", this));
	this->_board.push_back(new Queen(5, 1, 0, "queen", this));
	this->_board.push_back(new Bioshop(6, 1, 0, "bioshop", this));
	this->_board.push_back(new Knight(7, 1, 0, "knight", this));
	this->_board.push_back(new Rook(8, 1, 0, "rook", this));

	for (int i = 1; i <= PAWNS; i++)
	{
		this->_board.push_back(new Pawn(i, 2, 0, "pawn", this));
	}

	for (int i = 1; i <= PAWNS; i++)
	{
		this->_board.push_back(new Pawn(i, 7, 1, "pawn", this));
	}

	this->_board.push_back(new Rook(1, 8, 1, "rook", this));
	this->_board.push_back(new Knight(2, 8, 1, "knight", this));
	this->_board.push_back(new Bioshop(3, 8, 1, "bioshop", this));
	this->_board.push_back(new Queen(4, 8, 1, "queen", this));
	this->_board.push_back(new King(5, 8, 1, "king", this));
	this->_board.push_back(new Bioshop(6, 8, 1, "bioshop", this));
	this->_board.push_back(new Knight(7, 8, 1, "knight", this));
	this->_board.push_back(new Rook(8, 8, 1, "rook", this));

}

GameStatus::~GameStatus()
{
	for (int i = 0; i < this->_board.size(); i++)
	{
		delete this->_board[i];
	}
	//delete to _board?
}
string GameStatus::toString() const
{
	if (this->isWhiteTurn == false)
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

void GameStatus::setIsWhiteTurn(bool isWhiteTurn)
{
	this->isWhiteTurn  = isWhiteTurn;
}