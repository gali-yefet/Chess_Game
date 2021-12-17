#include "Pawn.h"
Pawn::Pawn(const int x, const int y, const int color, const string type, GameStatus* board)
	:Piece(x, y, color, type, board)
{}




int Pawn::valadateMove(const int newX, const int newY)
{
	if (((getColor()==0 && newY-getY()==-1) || (getColor() != 0 && newY - getY() == 1))&& getX()==newX)
	{
		for (int i = 0; i < getGame()->getBoard().size(); i++)
		{
			if (getGame()->getBoard()[i]->getX() == newX && getGame()->getBoard()[i]->getY() == newY)
			{
				return 6;
			}
		}
		return 0;
	}
	if (((getColor() == 0 && newY - getY() == -2 && getY() == 7) || (getColor() != 0 && newY - getY() == 2 && getY() == 2)) && getX() == newX)
	{
		for (int i = 0; i < getGame()->getBoard().size(); i++)
		{
			if (getGame()->getBoard()[i]->getX() == newX && getGame()->getBoard()[i]->getY() == newY)
			{
				return 6;
			}
		}
		return 0;
	}
	if (((getColor() == 0 && newY - getY() == -1) || (getColor() != 0 && newY - getY() == 1)) && ((newX - getX() == -1)||(newX-getX()==1)))
	{
		for (int i = 0; i < getGame()->getBoard().size(); i++)
		{
			if (getGame()->getBoard()[i]->getX() == newX && getGame()->getBoard()[i]->getY() == newY)
			{
				return 0;
			}
		}
		return 6;
	}
	return 6;
}