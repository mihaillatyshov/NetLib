#pragma once
#include "Socket.h"
#include "PacketManager.h"

#ifndef _WIN32
	#include <poll.h>
	typedef pollfd WSAPOLLFD;
	#ifndef WSAPoll
		#define WSAPoll(fds, nfds, timeout) poll(fds, nfds, timeout)
	#endif
#endif

namespace PNet
{
	class TCPConnection
	{
	public:
		TCPConnection(Socket socket, IPEndpoint endpoint);
		TCPConnection() :socket(Socket()) {}
		void Close();
		std::string ToString();
		Socket socket;

		PacketManager pm_incoming;
		PacketManager pm_outgoing;
		char buffer[PNet::g_MaxPacketSize];
		bool simpleTransmissionMode = false; //simple transmission = text only (for dcs)
	private:
		IPEndpoint endpoint;
		std::string stringRepresentation = "";
	};
}