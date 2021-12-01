#pragma once
#ifndef GAME_STATUS_H
#define GAME_STATUS_H
#include "Piece.h"
#include <stdio.h>
#include <string>
#include <vector>

using std::string;

class GameStatus
{
private:
	std::vector<Piece*> _board;
	bool isWhiteTurn;

public:
	GameStatus();
	string toString() const;
	std::vector<Piece*> getBoard() const;
};


#endif