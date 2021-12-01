#pragma once
#ifndef GAME_STATUS_H
#define GAME_STATUS_H
#include "Piece.h"
#include <stdio.h>
#include <string>

#define BOARD_LEN 8

using std::string;

class GameStatus
{
private:
	Piece board[BOARD_LEN][BOARD_LEN];
	bool isWhiteTurn;

public:
	GameStatus();
	string toString() const;
};


#endif