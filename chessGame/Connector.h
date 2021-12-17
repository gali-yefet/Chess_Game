#pragma once
#ifndef CONNECTOR_H
#define CONNECTOR_H
#include "Board.h"
#include "Pipe.h"
class Connector
{
private:
	Board* _game;
	Pipe* _p;

public:
	Connector();
	~Connector();
	bool turn();
};


#endif