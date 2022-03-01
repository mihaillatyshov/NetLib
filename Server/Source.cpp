//Server Code [Tutorial 11 dev] [Nonblocking] [Winsock]
//Author: Jacob Preston 2019-06-28

#include "MyServer.h"
#include <iostream>
#include <conio.h>

int main()
{
	if (Network::Initialize())
	{
		MyServer server;
		if (server.Initialize(IPEndpoint("0.0.0.0", 6112)))
		{
			while (true)
			{
				server.Frame();
				if (_kbhit()) 
				{
					_getch();
					server.SendMyMessage("New message from the server!");
				}
			}
		}
	}
	Network::Shutdown();
	system("pause");
	return 0;
}