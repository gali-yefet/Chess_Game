#pragma once
#include "GameStatus.h"
#include <iostream>
using namespace std;
class Piece
{
public:
	Piece(const int x, const int y, const int color, const string type);
	void move(const int x, const int y);
	virtual int valadateMove(const int newX, const int newY ,GameStatus* board) = 0;
	int getX()const;
	int getY()const;
	int getColor()const;
	string getType()const;
	void setX(const int x);
	void setY(const int y);
	void setColor(const int color);
	void setType(const string type);

private:
	int _color;
	string _type;
	int _posX;
	int _posY;
};