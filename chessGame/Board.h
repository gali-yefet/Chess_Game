#pragma once
#ifndef BOARD_H
#define BOARD_H
#include "GameStatus.h"

class Board 
{
private:
	GameStatus game;

public:
	Board();
	int valadate(int x, int y, int newX, int newY);
	GameStatus getGame() const ;
};


#endif