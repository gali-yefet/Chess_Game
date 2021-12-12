#include "Connector.h"
Connector::Connector()
{
	_p = Pipe();
	_game = Board();
	_p.connect();
	char c[1024];
	const char* c = _game.getGame().toString().c_str();
	_p.sendMessageToGraphics(c);
}
bool Connector::turn()
{
	string msg = _p.getMessageFromGraphics();
	//1a3d
	int values[4];
	values[0] = (int)msg[0]-'0';
	values[1] = (int)msg[0] - 'a'+1;
	values[2] = (int)msg[0] - '0';
	values[3] = (int)msg[0] - 'a' + 1;
	int replay = _game.valadate(values[0], values[1], values[2], values[3]);
	char c[2];
	c[0] = replay + '0';
	c[1] = NULL;
	_p.sendMessageToGraphics(c);
	return replay == 0 || replay == 1;
}