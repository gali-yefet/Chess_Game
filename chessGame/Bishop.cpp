#include "Bioshop.h"
Bioshop::Bioshop(const int x, const int y, const int color, const string type, GameStatus* board)
	:Piece(x,y,color,type,board)
{}




int Bioshop::valadateMove(const int newX, const int newY)
{
	if ((getX() - newX == getY() - newY) || (newX - getX() == newY - getY()))
	{
		int offsetX = (getX() > newX) ? 1 : -1;
		int offsetY = (getY() > newY) ? 1 : -1;
		int row = 0;
		int col = 0;
		for (row = getX() + offsetX, col = getY() + offsetY; row != newX; row += offsetX, col += offsetY)
		{
			for (int i = 0; i < getGame()->getBoard().size(); i++)
			{
				if (getGame()->getBoard()[i]->getX() == getX() && getGame()->getBoard()[i]->getY() == getY())
				{
					return 6;
				}
			}
			return 0;
		}
	}
	else
	{
		return 6;
	}
}