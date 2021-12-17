#include "Knight.h"
Knight::Knight(const int x, const int y, const int color, const string type, GameStatus* board)
    :Piece(x, y, color, type, board)
{}

/*valadates Knight moves
*/
int Knight::valadateMove(const int newX, const int newY)
{
    if (((getX() == newX + 1) || (getX() == newX - 1))&& ((getY() == newY + 2) || (getY() == newY - 2)))//1 vertical and 2 horizantal
    {
        return VALID_M;
    }
    else if (((getX() == newX + 2) || (getX() == newX - 2))&&((getY() == newY + 1) || (getY() == newY - 1)))//2 vertical and 1 horizantal
    {
        return VALID_M;
    }
    else 
        return INVALID_M;
}