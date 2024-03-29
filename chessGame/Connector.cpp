#include "Connector.h"
Connector::Connector()
{
	_p = new Pipe();
	_game = new Board();
	_p->connect();
	string c = _game->getGame()->toString();
	char char_array[1024];
	strcpy_s(char_array, c.c_str());
	_p->sendMessageToGraphics(char_array);

}
bool Connector::turn()
{
	string msg = _p->getMessageFromGraphics();
	//1a3d
	int values[4];

	values[0] = (int)msg[0]- 'a'+1;
	values[1] = (int)msg[1] - '0';	
	values[2] = (int)msg[2] - 'a' + 1;
	values[3] = (int)msg[3] - '0';

	int reply = _game->valadate(values[0], values[1], values[2], values[3]);
	cout << reply;
	char c[2];
	c[0] = reply + '0';
	c[1] = NULL;
	_p->sendMessageToGraphics(c);
	return (reply == 0 || reply == 1);
}
Connector::~Connector()
{
	_p->close();
}