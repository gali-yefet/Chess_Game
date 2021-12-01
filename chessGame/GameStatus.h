#pragma once
#ifndef GAME_STATUS_H
#define GAME_STATUS_H
#include "Piece.h"
#include <stdio.h>
#include <string>
#include <vector>

class Piece;

using std::string;
using std::vector;



class GameStatus
{
private:
	vector<Piece*> _board;
	bool isWhiteTurn;

public:
	GameStatus();
	~GameStatus();
	string toString() const;
	vector<Piece*> getBoard() const;
	bool getIsWhiteTurn() const;
	void setIsWhiteTurn(bool isWhiteTurn);
};


#endif