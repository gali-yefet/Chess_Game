#include "Rook.h"
Rook::Rook(const int x, const int y, const int color, const string type, GameStatus* board)
	:Piece(x, y, color, type, board)
{}

int Rook::valadateMove(const int newX, const int newY)
{
    if (getX() == newX) {//if path creates an vertical line
        int offsetY = (getY() < newY) ? 1 : -1;//moving forwards or backwards
        for (int y = getY() + offsetY; y != newY; y += offsetY) {//for evrey square in path

            for (int i = 0; i < getGame()->getBoard().size(); i++)
            {
                if (getGame()->getBoard()[i]->getY() == y && getGame()->getBoard()[i]->getX() == getX())//if there is a piece of any kind
                {
                    return INVALID_M;
                }
            }
        }
        return VALID_M;
    }
    else if (getY() == newY) {//if path creates an horizantal line
        int offsetX = (getX() < newX) ? 1 : -1;//moving forwards or backwards
        for (int x = getX() + offsetX; x != newX; x += offsetX) {//for evrey square in path

            for (int i = 0; i < getGame()->getBoard().size(); i++)//if there is a piece of any kind
            {
                if (getGame()->getBoard()[i]->getX() == x && getGame()->getBoard()[i]->getY() == getY())
                {
                    return INVALID_M;
                }
            }
        }
        return VALID_M;
    }
    else//if path dosent create a line
        return INVALID_M;
}
