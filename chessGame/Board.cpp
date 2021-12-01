#include "Board.h"

enum messages{VALID, CHECK, NO_P, DES_P, CHECK_C, RANGE, I_MOVE, SAME, CHECKMATE};

Board::Board()
{
	game = GameStatus();
}

int Board::valadate(int x, int y, int newX, int newY)
{
	if (0)//the move made a check on the opponent
	{
		return CHECK;
	}
	if (this->game.getBoard()[this->game.] == this->game.getBoard()->getColor())// the player has no piece at the source point 
	{
		return NO_P;
	}
	if (0)// the player has piece at the destination point 
	{
		return DES_P;
	}
	if (0)// the move made a check on the currrent player
	{
		return CHECK_C;
	}
	if ((newX > 7 || newX < 0) || (newY > 7 || newY < 0))//the new point is out of the game board
	{
		return RANGE;
	}
	if (0)// invalid move of piece
	{
		return I_MOVE;
	}
	if (x == newX && y == newY) // the points are the same 
	{
		return SAME;
	}
	if (0)// checkmate was made
	{
		return CHECKMATE;
	}
	int i = 0;
	while (this->game.getBoard()[i].getX() == x && this->game.getBoard()[i].getY() == y)
	{

	}
	return VALID;
}