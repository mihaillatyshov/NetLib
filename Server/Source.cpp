//Server Code [Tutorial 11 dev] [Nonblocking] [Winsock]
//Author: Jacob Preston 2019-06-28

#include "MyServer.h"
#include <iostream>
#ifdef _WIN32
	#include <conio.h>
#endif

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
#ifdef _WIN32
				if (_kbhit()) 
				{
					_getch();
					server.SendMyMessage("New message from the server!");
				}
#endif
			}
		}
	}
	Network::Shutdown();
	system("pause");
	return 0;
}