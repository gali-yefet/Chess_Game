#include "Bioshop.h"
Bioshop::Bioshop(const int x, const int y, const int color, const string type, GameStatus* board)
	:Piece(x,y,color,type,board)
{}



/*valadates bioshop moves
*/
int Bioshop::valadateMove(const int newX, const int newY)
{
    if ((getX() - newX == getY() - newY) || (newX - getX() == newY - getY()) || (getX() - newX == -1*(getY() - newY)) || (newX - getX() == -1 * (newY - getY())))//if new x,y creates a diagonal line from start
    {
        int offsetX = (getX() < newX) ? 1 : -1;//moving forwards or backwards
        int offsetY = (getY() < newY) ? 1 : -1;
        for (int x = getX() + offsetX,  y = getY() + offsetY; x != newX; x += offsetX, y += offsetY)//for evrey square in path
        {
            for (int i = 0; i < getGame()->getBoard().size(); i++)//if there is a piece of any kind in said line
            {
                if (getGame()->getBoard()[i]->getX() == x && getGame()->getBoard()[i]->getY() == y)
                {
                    return INVALID_M;
                }
            }
        }
        return VALID_M;
    }
    else
        return INVALID_M;
}