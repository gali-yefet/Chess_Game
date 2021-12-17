#include "Queen.h"
Queen::Queen(const int x, const int y, const int color, const string type, GameStatus* board)
    :Piece(x, y, color, type, board)
{}

int Queen::valadateMove(const int newX, const int newY)
{
    //vertical
    if (getX() == newX) {//if path creates an vertical line
        int offsetY = (getY() < newY) ? 1 : -1;//moving forwards or backwards
        for (int y = getY() + offsetY; y != newY; y += offsetY) {//for evrey square in path

            for (int i = 0; i < getGame()->getBoard().size(); i++)
            {
                if (getGame()->getBoard()[i]->getY() == y && getGame()->getBoard()[i]->getX() == getX())//if there is a piece of any kind
                {
                    return 6;
                }
            }
        }
        return 0;
    }
    //horizontal 
    else if (getY() == newY) {//if path creates an horizantal line
        int offsetX = (getX() < newX) ? 1 : -1;//moving forwards or backwards
        for (int x = getX() + offsetX; x != newX; x += offsetX) {//for evrey square in path

            for (int i = 0; i < getGame()->getBoard().size(); i++)//if there is a piece of any kind
            {
                if (getGame()->getBoard()[i]->getX() == x && getGame()->getBoard()[i]->getY() == getY())
                {
                    return 6;
                }
            }
        }
        return 0;
    }
    //diagonal
    else if ((getX() - newX == getY() - newY) || (newX - getX() == newY - getY()) || (getX() - newX == -1 * (getY() - newY)) || (newX - getX() == -1 * (newY - getY())))
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
