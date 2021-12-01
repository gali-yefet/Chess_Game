#pragma once
#include "Piece.h"
class Knight : public Piece
{
public:
	Knight(const int x, const int y, const int color, const string type, GameStatus* board);
	int valadateMove(const int newX, const int newY)override;
};