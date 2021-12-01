#include "Board.h"


Board::Board()
{
	game = GameStatus();
}

int Board::valadate(int x, int y, int newX, int newY)
{
	if (x == newX && y == newY)
	{
		return 1;
	}
}