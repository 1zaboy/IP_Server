#include "main_class.h"

//---------------------------------

#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)
#include <iostream>
#include <WinSock2.h>
#include <winsock.h>
#include "Client.h"
using namespace std;


main_class::main_class()
{
}


main_class::~main_class()
{
}

void main_class::start()
{
	//get_
}

void main_class::ListenNetwork()
{
	if (WSAStartup(MAKEWORD(2, 2), &wData) == 0)
	{
		printf("WSA Startup succes\n");
	}
	SOCKADDR_IN addr;
	int addrl = sizeof(addr);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	this_s = socket(AF_INET, SOCK_STREAM, NULL);
	if (this_s == SOCKET_ERROR) {
		printf("Socket not created\n");
	}

	/*if (*/bind(this_s, (struct sockaddr*)&addr, sizeof(addr));/* != SOCKET_ERROR) {
		printf("Socket succed binded\n");
	}*/

	if (listen(this_s, SOMAXCONN) != SOCKET_ERROR) {
		printf("Start listenin at port%u\n", ntohs(addr.sin_port));
	}
	
	//std::thread the1;
	//the1.join();
	handle();	
}

void main_class::close() {
	closesocket(this_s);
	WSACleanup();
	cout << "Server was stoped. You can close app" << endl;
}

void main_class::handle() {
	while (true)
	{
		SOCKET acceptS;
		SOCKADDR_IN addr_c;
		int addrlen = sizeof(addr_c);
		if ((acceptS = accept(this_s, (struct sockaddr*)&addr_c, &addrlen)) != 0) {
			printf("send\n");
			printf("sended Client connected from 0  %u.%u.%u.%u:%u\n",
				(unsigned char)addr_c.sin_addr.S_un.S_un_b.s_b1,
				(unsigned char)addr_c.sin_addr.S_un.S_un_b.s_b2,
				(unsigned char)addr_c.sin_addr.S_un.S_un_b.s_b3,
				(unsigned char)addr_c.sin_addr.S_un.S_un_b.s_b4,
				ntohs(addr_c.sin_port));
			LU_Soc.push_back(acceptS);
			Client* client = new Client(acceptS, addr_c);
			Clients.push_back(client);
		}
		Sleep(50);
	}
}

