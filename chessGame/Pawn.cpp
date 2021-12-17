#include "Pawn.h"
Pawn::Pawn(const int x, const int y, const int color, const string type, GameStatus* board)
	:Piece(x, y, color, type, board)
{}



/*valadates pawn moves
*/
int Pawn::valadateMove(const int newX, const int newY)
{
	if (((getColor() == 0 && newY - getY() == -1) || (getColor() != 0 && newY - getY() == 1)) && getX() == newX)//if moves one tile verticly
	{
		for (int i = 0; i < getGame()->getBoard().size(); i++)
		{
			if (getGame()->getBoard()[i]->getX() == newX && getGame()->getBoard()[i]->getY() == newY)//if tile is blocked
			{
				return INVALID_M;
			}
		}
		return VALID_M;
	}
	if (((getColor() == 0 && newY - getY() == -2 && getY() == 7) || (getColor() != 0 && newY - getY() == 2 && getY() == 2)) && getX() == newX)//if moves two tile verticly
	{
		for (int i = 0; i < getGame()->getBoard().size(); i++)
		{
			if (getGame()->getBoard()[i]->getX() == newX && getGame()->getBoard()[i]->getY() == newY)//if tile is blocked
			{
				return INVALID_M;
			}
		}
		return VALID_M;
	}
	if (((getColor() == 0 && newY - getY() == -1) || (getColor() != 0 && newY - getY() == 1)) && ((newX - getX() == -1) || (newX - getX() == 1)))//if eats diagonaly
	{
		for (int i = 0; i < getGame()->getBoard().size(); i++)
		{
			if (getGame()->getBoard()[i]->getX() == newX && getGame()->getBoard()[i]->getY() == newY)//if tile has a piece
			{
				return VALID_M;
			}
		}
		return INVALID_M;
	}
	return INVALID_M;
}