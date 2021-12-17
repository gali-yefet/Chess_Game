#include "King.h"
King::King(const int x, const int y, const int color, const string type, GameStatus* board)
    :Piece(x, y, color, type, board)
{}

int King::valadateMove(const int newX, const int newY)
{
    if (((newY - getY() >= -1) && (newY - getY() <= 1)) && ((newX - getX() >= -1) && (newX - getX() <= 1)))
    {
        return VALID_M;
    }
    return INVALID_M;
}