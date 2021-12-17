#include "Bioshop.h"
Bioshop::Bioshop(const int x, const int y, const int color, const string type, GameStatus* board)
	:Piece(x,y,color,type,board)
{}




int Bioshop::valadateMove(const int newX, const int newY)
{    
    if ((getX() - newX == getY() - newY) || (newX - getX() == newY - getY()) || (getX() - newX == -1*(getY() - newY)) || (newX - getX() == -1 * (newY - getY())))
    {
        int offsetX = (getX() < newX) ? 1 : -1;
        int offsetY = (getY() < newY) ? 1 : -1;
        int x = 0;
        int y = 0;
        for (x = getX() + offsetX, y = getY() + offsetY; x != newX; x += offsetX, y += offsetY)
        {
            for (int i = 0; i < getGame()->getBoard().size(); i++)
            {
                if (getGame()->getBoard()[i]->getX() == x && getGame()->getBoard()[i]->getY() == y)
                {
                    return 6;
                }
            }
        }
        return 0;
    }
    else
        return 6;
}