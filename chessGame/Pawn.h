#pragma once
#include "Piece.h"
class Pawn : public Piece
{
	Pawn(const int x, const int y, const int color, const string type, GameStatus* board);
	int valadateMove(const int newX, const int newY)override;
};