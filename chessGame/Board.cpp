#include "Board.h"

enum messages{VALID, CHECK, NO_P, DES_P, CHECK_C, RANGE, I_MOVE, SAME, CHECKMATE};

Board::Board()
{
	game = GameStatus();
}

int Board::valadate(int x, int y, int newX, int newY)
{
	int i = 0; //index of piece in the source point
	int j = 0;// index of piece in the destination point
	int k = 0;// index of the opponent's king piece
	int kCurrent = 0;// index of the current player's king 
	bool flag = true;

	//getting index of piece in the source point
	while (i < this->game.getBoard().size() && flag)
	{
		if (this->game.getBoard()[i]->getX() == x && this->game.getBoard()[i]->getY() == y && (this->game.getIsWhiteTurn() == false && this->game.getBoard()[k]->getColor() != 0) || (this->game.getIsWhiteTurn() == true && this->game.getBoard()[k]->getColor() == 0))
		{
			flag = false;// the index of the current piece found
		}
		if (flag)
		{
			i++;
		}
	}

	flag = true;
	//getting index of piece in the destination point
	while (j < this->game.getBoard().size() && flag)
	{
		if (this->game.getBoard()[j]->getX() == newX && this->game.getBoard()[j]->getY() == newY && (this->game.getIsWhiteTurn() == false && this->game.getBoard()[k]->getColor() != 0) || (this->game.getIsWhiteTurn() == true && this->game.getBoard()[k]->getColor() == 0))
		{
			flag = false;// the index of the destination piece found
		}
		if (flag)
		{
			j++;
		}
	}

	//getting the opponent's king coordinates 
	flag = true;
	while (k < this->game.getBoard().size() && flag)
	{
		if (this->game.getBoard()[k]->getType() == "king" && (this->game.getIsWhiteTurn() == false && this->game.getBoard()[k]->getColor() == 0) || (this->game.getIsWhiteTurn() == true && this->game.getBoard()[k]->getColor() != 0))
		{
			flag = false;// the index of the opponent's king found
		}
		if (flag)
		{
			k++;
		}
	}


	//getting the current player's king coordinates 
	flag = true;
	while (kCurrent < this->game.getBoard().size() && flag)
	{
		if (this->game.getBoard()[kCurrent]->getType() == "king" && (this->game.getIsWhiteTurn() == true && this->game.getBoard()[k]->getColor() == 0) || (this->game.getIsWhiteTurn() == false && this->game.getBoard()[k]->getColor() != 0))
		{
			flag = false;// the index of the current player's king found
		}
		if (flag)
		{
			kCurrent++;
		}
	}

	//check options
	if (this->game.getBoard()[i]->valadateMove(this->game.getBoard()[k]->getX(), this->game.getBoard()[k]->getY(), &this->game))//the move made a check on the opponent
	{
		return CHECK;
	}
	if (i == this->game.getBoard().size())// the player has no piece at the source point 
	{
		return NO_P;
	}
	if (j != this->game.getBoard().size())// the player has piece at the destination point 
	{
		return DES_P;
	}
	if (this->game.getBoard()[i]->valadateMove(this->game.getBoard()[kCurrent]->getX(), this->game.getBoard()[kCurrent]->getY(), &this->game))// the move made a check on the currrent player
	{
		return CHECK_C;
	}
	if ((newX > 7 || newX < 0) || (newY > 7 || newY < 0))//the new point is out of the game board
	{
		return RANGE;
	}
	if (!(this->game.getBoard()[i]->valadateMove(newX, newY, &this->game)))// invalid move of piece
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

	return VALID;
}