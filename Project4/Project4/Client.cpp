#include "Client.h"


Client::Client(SOCKET s, SOCKADDR_IN sock_in)
{
	c_sock = s;
	c_addr = sock_in;
	printf("Client created\n");
	thread get_net1(handle);
	get_net = get_net1;
	
}


Client::~Client()
{
}

void Client::handle()
{
	while (true)
	{
		int k = recv(c_sock, buffer, sizeof(buffer), NULL);
		if (k > 0) {
			printf(buffer);
		}
		Sleep(30);
	}
}
bool Client::send_data(string data) 
{
	//Send some data
	if (send(c_sock, data.c_str(), strlen(data.c_str()), 0) < 0) 
	{
		perror("Send failed : ");
		return false;
	}
	printf("Data send\n");
	return true;
}
