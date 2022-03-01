//Client Code [Tutorial 11 dev] [Nonblocking] [Winsock]
//Author: Jacob Preston 2019-06-28

#include "MyClient.h"
#include <iostream>
#include <conio.h>

int main()
{
	if (Network::Initialize())
	{
		MyClient client;
		if (client.Connect(IPEndpoint("localhost", 6112)))
		{
			while (client.IsConnected())
			{
				client.Frame();
				if (_kbhit())
				{
					_getch();
					std::cout << "Enter you messsage: ";
					std::string MyMessage;
					std::cin >> MyMessage;
					client.SendMyMessage(MyMessage);
				}
			}
		}
	}
	Network::Shutdown();
	system("pause");
	return 0;
}