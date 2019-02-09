#pragma once
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <thread>
#include <string>

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")
// ----------------------------

using namespace std;

class Client
{
public:
	Client(SOCKET s, SOCKADDR_IN sock_in);
	~Client();

	void handle();
	bool send_data(string data);
	//---------------------
	thread get_net;
	

private:
	SOCKET c_sock;
	SOCKADDR_IN c_addr;
	char buffer[1024];
};

