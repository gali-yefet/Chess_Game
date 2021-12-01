#include "Bioshop.h"
Bioshop::Bioshop(const int x, const int y, const int color, const string type)
	:Piece(x,y,color,type)
{}
int Bioshop::valadateMove(const int newX, const int newY, GameStatus* board)
{
	if ((getX() - newX == getY() - newY) || (newX - getX() == newY - getY()))
	{

	}
	else
	{
		return 0;
	}
}