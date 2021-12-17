#include "King.h"
King::King(const int x, const int y, const int color, const string type, GameStatus* board)
    :Piece(x, y, color, type, board)
{}
/*valadates king moves
*/
int King::valadateMove(const int newX, const int newY)
{
    if (((newY - getY() >= -1) && (newY - getY() <= 1)) && ((newX - getX() >= -1) && (newX - getX() <= 1)))//if range of both x and y is -1<=x<=1 -1<=y<=1
    {
        return VALID_M;
    }
    return INVALID_M;
}