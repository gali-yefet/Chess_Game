#include "Board.h"

enum messages{VALID, CHECK, NO_P, DES_P, CHECK_C, RANGE, I_MOVE, SAME, CHECKMATE};

Board::Board()
{
	game = new GameStatus();
}

int Board::valadate(int x, int y, int newX, int newY)
{
	int i = 0; //index of piece in the source point
	int j = 0;// index of piece in the destination point
	int k = 0;// index of the opponent's king piece
	int kCurrent = 0;// index of the current player's king 
	bool flag = true;// for the loops to stop when piece found
	int res = VALID; //return value

	//getting index of piece in the source point
	//if the piece is of the current player i == board.size
	while (i < this->game->getBoard().size() && flag)
	{
		if (this->game->getBoard()[i]->getX() == x && this->game->getBoard()[i]->getY() == y && (this->game->getIsWhiteTurn() == false && this->game->getBoard()[i]->getColor() != 0) || (this->game->getIsWhiteTurn() == true && this->game->getBoard()[i]->getColor() == 0))
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
	//if the dest is empty j == board.size
	while (j < this->game->getBoard().size() && flag)
	{
		if (this->game->getBoard()[j]->getX() == newX && this->game->getBoard()[j]->getY() == newY)
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
	while (k < this->game->getBoard().size() && flag)
	{
		if (this->game->getBoard()[k]->getType() == "king" && (this->game->getIsWhiteTurn() == false && this->game->getBoard()[k]->getColor() == 0) || (this->game->getIsWhiteTurn() == true && this->game->getBoard()[k]->getColor() != 0))
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
	while (kCurrent < this->game->getBoard().size() && flag)
	{
		if (this->game->getBoard()[kCurrent]->getType() == "king" && (this->game->getIsWhiteTurn() == true && this->game->getBoard()[kCurrent]->getColor() == 0) || (this->game->getIsWhiteTurn() == false && this->game->getBoard()[kCurrent]->getColor() != 0))
		{
			flag = false;// the index of the current player's king found
		}
		if (flag)
		{
			kCurrent++;
		}
	}

	//check options

	if ((newX > 8 || newX < 1) || (newY > 8 || newY < 1))//the new point is out of the game board
	{
		res =  RANGE;
	}
	if ((this->game->getBoard()[i]->valadateMove(newX, newY)) != CHECK)// invalid move of piece
	{
		res = I_MOVE;
	}
	if (x == newX && y == newY) // the points are the same 
	{
		res = SAME;
	}
	if (i == this->game->getBoard().size())// the player has no piece at the source point 
	{
		res = NO_P;
	}
	if (this->game->getBoard()[j]->getColor() == this->game->getBoard()[i]->getColor())// the player has piece at the destination point 
	{
		res = DES_P;
	}
	
	this->game->getBoard()[i]->move(newX, newY);// moving the current piece to the destination

	for (int x = 0; x < this->game->getBoard().size(); x++)
	{
		if (this->game->getBoard()[x]->valadateMove(this->game->getBoard()[kCurrent]->getX(), this->game->getBoard()[kCurrent]->getY()) == VALID && this->game->getBoard()[kCurrent]->getColor() != this->game->getBoard()[x]->getColor())// the move made a check on the currrent player
		{
			res = CHECK_C;
		}
	}
	if (res == CHECK_C)
	{
		this->game->getBoard()[i]->move(x, y);// moving the current piece back to the source - invalid move 
	}

	for (int x = 0; x < this->game->getBoard().size(); x++)
	{
		if (this->game->getBoard()[x]->valadateMove(this->game->getBoard()[k]->getX(), this->game->getBoard()[k]->getY()) == VALID && this->game->getBoard()[x]->getColor() != this->game->getBoard()[k]->getColor())//the move made a check on the opponent
		{
			res = CHECK;
		}
	}
	if (0)// checkmate was made
	{
		res = CHECKMATE;
	}

	if (res == CHECK_C || res == CHECK || res == CHECKMATE || res == VALID)
	{
		if (this->game->getBoard()[j]->getColor() != this->game->getBoard()[i]->getColor())// there is a piece of the opponent in the destination
		{
			delete this->game->getBoard()[j];
			this->game->getBoard().erase(this->game->getBoard().begin() + j);
		}
		this->game->setIsWhiteTurn(!this->game->getIsWhiteTurn());// setting the turn to the other player
	}
	
	return res;
}
GameStatus* Board::getGame() const
{
	return game;
}