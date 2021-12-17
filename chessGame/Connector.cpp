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
<<<<<<< HEAD
	values[0] = (int)msg[0]-'0';
	values[1] = (int)msg[1] - 'a' + 1;
	values[2] = (int)msg[2] - '0';
	values[3] = (int)msg[3] - 'a' + 1;
=======
	values[0] = (int)msg[0]- 'a'+1;
	values[1] = (int)msg[1] - '0';	
	values[2] = (int)msg[2] - 'a' + 1;
	values[3] = (int)msg[3] - '0';

>>>>>>> a8061c75deaa987d44fbd6a94acbc77810404897
	int replay = _game->valadate(values[0], values[1], values[2], values[3]);
	cout << replay;
	char c[2];
	c[0] = replay + '0';
	c[1] = NULL;
	_p->sendMessageToGraphics(c);
	return replay == 0 || replay == 1;
}
Connector::~Connector()
{
	_p->close();
}