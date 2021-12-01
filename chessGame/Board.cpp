#include "Board.h"

enum errors{VALID, CHECK, NO_P, DES_P, };

Board::Board()
{
	game = GameStatus();
}

int Board::valadate(int x, int y, int newX, int newY)
{
	if (0)//the move made a check on the opponent
	{
		return 1;
	}
	if (0)// the player has no piece at the source point 
	{
		return 2;
	}
	if (0)// the player has piece at the destination point 
	{
		return 3;
	}
	if (0)// the move made a check on the currrent player
	{
		return 4;
	}
	if ((newX > 7 || newX < 0) || (newY > 7 || newY < 0))//the new point is out of the game board
	{
		return 5;
	}
	if (0)// invalid move of piece
	{
		return 6;
	}
	if (x == newX && y == newY) // the points are the same 
	{
		return 7;
	}
	if (0)// checkmate was made
	{
		return 8;
	}

	return 0;
}