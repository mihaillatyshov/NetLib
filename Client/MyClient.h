#pragma once
#include <PNet/IncludeMe.h>

class MyClient : public Client
{
	void OnConnect() override;
	bool ProcessPacket(std::shared_ptr<Packet> packet) override;
public:
	void SendMyMessage(const std::string& MyMessage);
	//void OnConnectFail() override;
	//void OnDisconnect(std::string reason) override;
};