#pragma once
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <thread>
#include <vector>
#include "Client.h"

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")
// ----------------------------
using namespace std;



class main_class
{
public:
	main_class();
	~main_class();
	void start();
	void close();
	void handle();
	// ---THREAD--- //
	void ListenNetwork();


	unsigned short port;
private:
	vector <thread> TL_User;
	vector <SOCKET> LU_Soc;
	vector <Client*> Clients;
	SOCKET this_s;
	WSAData wData;
};

