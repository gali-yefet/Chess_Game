#pragma once
#include "Piece.h"
class King : public Piece
{
	King(const int x, const int y, const int color, const string type, GameStatus* board);
	int valadateMove(const int newX, const int newY)override;
};