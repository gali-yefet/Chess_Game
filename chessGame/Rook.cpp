#include "Rook.h"
Rook::Rook(const int x, const int y, const int color, const string type, GameStatus* board)
	:Piece(x, y, color, type, board)
{}

int Rook::valadateMove(const int newX, const int newY)
{
    if (getX() == newX) {
        int offsetY = (getY() < newY) ? 1 : -1;
        for (int y = getY() + offsetY; y != newY; y += offsetY) {

            for (int i = 0; i < getGame()->getBoard().size(); i++)
            {
                if (getGame()->getBoard()[i]->getY() == y && getGame()->getBoard()[i]->getX() == getX())
                {
                    return 6;
                }
            }
        }
        return 0;
    }
    else if (getY() == newY) {
        int offsetX = (getX() < newX) ? 1 : -1;
        for (int x = getX() + offsetX; x != newX; x += offsetX) {

            for (int i = 0; i < getGame()->getBoard().size(); i++)
            {
                if (getGame()->getBoard()[i]->getX() == x && getGame()->getBoard()[i]->getY() == getY())
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
