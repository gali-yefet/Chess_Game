#include "Piece.h"
/*moves the piece
* input: x, y
* output: none
*/
void Piece::move(const int x, const int y)
{
	setX(x);
	setY(y);
}
/*set x
* input: x
* output: none
*/
void Piece::setX(const int x)
{
	_posX = x;
}
/*set y
* input: y
* output: none
*/
void Piece::setY(const int y)
{
	_posY = y;
}
/*set color
* input: color
* output: none
*/
void Piece::setColor(const int color)
{
	_color = color;
}
/*set type
* input: type
* output: none
*/
void Piece::setType(const string type)
{
	_type = type;
}
/*get x
* input: none
* output: x
*/
int Piece::getX()const
{
	return _posX;
}
/*get y
* input: none
* output: y
*/
int Piece::getY()const
{
	return _posY;
}
/*get color
* input: none
* output: color
*/
int Piece::getColor()const
{
	return _color;
}
/*get type
* input: none
* output: type
*/
string Piece::getType()const
{
	return _type;
}
/*get board
* input: none
* output: board
*/
GameStatus* Piece::getGame()const
{
	return _game;
}
/*constructor
* input: x, y, color and type
* output: none
*/
Piece::Piece(const int x, const int y, const int color, const string type, GameStatus* board)
{
	_posX = x;
	_posY = y;
	_color = color;
	_type = type;
	_game = board;
}
Piece::~Piece()
{
	delete _game;
}