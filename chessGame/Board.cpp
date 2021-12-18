#include "Board.h"

enum messages{VALID, CHECK, NO_P, DES_P, CHECK_C, RANGE, I_MOVE, SAME, CHECKMATE};
#define OUTSIDE_X -10
#define OUTSIDE_Y 18

Board::Board()
{
	game = new GameStatus();
}


int Board::valadate(int x, int y, int newX, int newY)
{
	int selected_piece = 0; //index of piece in the source point
	int dest_piece = 0;// index of piece in the destination point
	int opponent_king = 0;// index of the opponent's king piece
	int ally_king = 0;// index of the current player's king 
	bool flag = true;// for the loops to stop when piece found
	int res = VALID; //return value

	//getting index of piece in the source point
	//if the piece is of the current player selected_piece == board.size
	while (selected_piece < this->game->getBoard().size() && flag)
	{
		if (((this->game->getBoard()[selected_piece]->getX() == x) && (this->game->getBoard()[selected_piece]->getY() == y)) && ((this->game->getIsWhiteTurn() == false && this->game->getBoard()[selected_piece]->getColor() != 0) || (this->game->getIsWhiteTurn() == true && this->game->getBoard()[selected_piece]->getColor() == 0)))
		{
			flag = false;// the index of the current piece found
		}
		if (flag)
		{
			selected_piece++;
		}
	}
	if (selected_piece == this->game->getBoard().size())// the player has no piece at the source point 
	{
		return NO_P;
	}
	flag = true;

	//getting index of piece in the destination point
	//if the dest is empty dest_piece == board.size
	while (dest_piece < this->game->getBoard().size() && flag)
	{
		if (this->game->getBoard()[dest_piece]->getX() == newX && this->game->getBoard()[dest_piece]->getY() == newY)
		{
			flag = false;// the index of the destination piece found
		}
		if (flag)
		{
			dest_piece++;
		}
	}

	//getting the opponent's king coordinates 
	flag = true;
	while (opponent_king < this->game->getBoard().size() && flag)
	{
		if (this->game->getBoard()[opponent_king]->getType() == "king" && (this->game->getBoard()[opponent_king]->getColor() != this->game->getBoard()[selected_piece]->getColor()))
		{
			flag = false;// the index of the opponent's king found
		}
		if (flag)
		{
			opponent_king++;
		}
	}


	//getting the current player's king coordinates 
	flag = true;
	while (ally_king < this->game->getBoard().size() && flag)
	{
		if (this->game->getBoard()[ally_king]->getType() == "king" && (this->game->getBoard()[ally_king]->getColor() == this->game->getBoard()[selected_piece]->getColor()))
		{
			flag = false;// the index of the current player's king found
		}
		if (flag)
		{
			ally_king++;
		}
	}

	//check options

	
	if (dest_piece != this->game->getBoard().size() && this->game->getBoard()[dest_piece]->getColor() == this->game->getBoard()[selected_piece]->getColor())// the player has piece at the destination point 
	{
		return DES_P;
	}
	if ((newX > 8 || newX < 1) || (newY > 8 || newY < 1))//the new point is out of the game board
	{
		return RANGE;
	}
	if ((this->game->getBoard()[selected_piece]->valadateMove(newX, newY)) != VALID)// invalid move of piece
	{
		return I_MOVE;
	}
	if (x == newX && y == newY) // the points are the same 
	{
		return  SAME;
	}
	
	this->game->getBoard()[selected_piece]->move(newX, newY);// moving the current piece to the destination

	for (int a = 0; a < this->game->getBoard().size(); a++)
	{
		if (this->game->getBoard()[a]->valadateMove(this->game->getBoard()[ally_king]->getX(), this->game->getBoard()[ally_king]->getY()) == VALID && this->game->getBoard()[ally_king]->getColor() != this->game->getBoard()[a]->getColor())// the move made a check on the currrent player
		{
			res = CHECK_C;
			this->game->getBoard()[selected_piece]->move(x, y);// moving the current piece back to the source - invalid move 
		}
	}

	for (int kc = 0; kc < this->game->getBoard().size(); kc++)
	{
		if (this->game->getBoard()[kc]->valadateMove(this->game->getBoard()[opponent_king]->getX(), this->game->getBoard()[opponent_king]->getY()) == VALID && this->game->getBoard()[kc]->getColor() != this->game->getBoard()[opponent_king]->getColor())//the move made a check on the opponent
		{
			res = CHECK;
		}
	}
	/*
	bool is_checkmate = true;
	for (int p = 0; p < game->getBoard().size() && is_checkmate; p++)//checks every possible nove of opponent
	{
		if (game->getBoard()[p]->getColor() != game->getBoard()[selected_piece]->getColor())//for every oppoonent piece
		{
			for (int i = 1; i <= 8 && is_checkmate; i++)//for every tile
			{
				for (int j = 1; j <= 8 && is_checkmate; j++)
				{
					//checks if tile is clear
					int dp = 0;
					bool f = true;
					while (dp < game->getBoard().size() && f)
					{
						if (game->getBoard()[dp]->getX() == i && game->getBoard()[dp]->getY() == j)
						{
							f = false;// the index of the destination piece found
						}
						if (f)
						{
							dp++;
						}
					}
					if (!(i == game->getBoard()[p]->getX() && j == game->getBoard()[p]->getY())&& (game->getBoard()[p]->valadateMove(i, j) == VALID) &&(dp == this->game->getBoard().size()))//if can move to tile
					{
						int pre_x = game->getBoard()[p]->getX();//saves x and y
						int pre_y = game->getBoard()[p]->getY();
						game->getBoard()[p]->move(i, j);//move to new pos
						is_checkmate = false;
						for (int kc = 0; kc < this->game->getBoard().size(); kc++)//check if check is still possible
						{
							if (this->game->getBoard()[kc]->getColor() == this->game->getBoard()[selected_piece]->getColor())
							{
								if ((this->game->getBoard()[kc]->valadateMove(this->game->getBoard()[opponent_king]->getX(), this->game->getBoard()[opponent_king]->getY()) == VALID))
								{
									is_checkmate = true;
								}
							}
						}

						game->getBoard()[p]->move(pre_x, pre_y);
					}

				}
			}
		}

	}*/
	if (0)// checkmate was made
	{
		res = CHECKMATE;
	}

	if (res == CHECK || res == CHECKMATE || res == VALID)
	{
		if (dest_piece != this->game->getBoard().size()&& this->game->getBoard()[dest_piece]->getColor() != this->game->getBoard()[selected_piece]->getColor())// there is a piece of the opponent in the destination
		{
			
			//this->game->getBoard().erase(this->game->getBoard().begin()+dest_piece);
			this->game->getBoard()[dest_piece]->move(OUTSIDE_X, OUTSIDE_Y);//moving the piece outside of effective range
		}
		this->game->setIsWhiteTurn(!(this->game->getIsWhiteTurn()));// setting the turn to the other player
	}
	
	return res;
}
GameStatus* Board::getGame() const
{
	return game;
}