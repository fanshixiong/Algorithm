#include<Winsock2.h>
#include<stdio.h>
#define DEFAULT_PORT 5050
#define DATA_BUFFER 1024

void main(){
	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(2, 2), &wsaData)!=0){ //error
		printf("load error\n");
		return;
	}
	SOCKET server = socket(AF_INET, SOCK_STREAM, 0); // INVALID_SOCKET WSACleanup()
	if(server == INVALID_SOCKET){
		printf("socket error\n");
		WSACleanup();
		return;
	}

	struct sockaddr_in sip;
	memset(&sip, 0, sizeof sip);
	sip.sin_family = AF_INET;
	sip.sin_port = htons(9999);
	sip.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(bind(server, (struct sockaddr*)&sip, sizeof sip) == SOCKET_ERROR){
		closesocket(server);
		WSACleanup();
		return;
	}

	if(listen(server, 5) == SOCKET_ERROR){
		closesocket(server);
		WSACleanup();
		return;
	}

	struct sockaddr_in resip;
	SOCKET client = accept(server, (struct sockaddr*)&sip, sizeof sip);
	if(client == INVALID_SOCKET){
		error();
		closesocket(server);
		WSACleanup();
		return;
	}

	printf("客户机IP：%s\n 端口：%d\n", 
		inet_ntoa(resip.sin_addr), ntohs(resip.sin_port));

	char data[254];
	int cnt = 0;
	do{
		int n = recv(client, data, 250, 0);
		if(n == 0) break;
		if(n == SOCKET_ERROR){
			error();
			closesocket(client);
			closesocket(server);
			WSACleanup();
			return;
		}

		data[n] = '\0';
		printf("data\n");

		char sd[254];
		sprintf(sd, "字母个数:%s", count(data));
		n = send(client, sd, strlen(sd), 0);
		if(n == SOCKET_ERROR){
			errror();
			closesocket(client);
			closesocket(server);
			WSACleanup();
			return;
		}

	}while(strcmp(data, "quit") != 0)

	closesocket(client);
	closesocket(server);
	WSACleanup();
}


void main(){
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET server = socket(AF_INET, SOCK_STREAM, 0);
	if(server == INVALID_SOCKET){
		error();
		WSACleanup();
		return;
	}

	struct sockaddr_in sip;
	memet(&sip, 0, sizeof sip);
	sip.sin_family = AF_INET;
	sip.sin_port = htons(9999);
	sip.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(bind(server, (struct sockaddr*)&sip, sizeof sip) == SOCKET_ERROR){
		error();
		closesocket(server);
		WSACleanup();
		return;
	}

	if(listen(server, 5) == SOCKET_ERROR){
		error();
		closesocket(server);
		WSACleanup();
		return;
	}

	struct sockaddr_in resip;
	memset(&resip, 0, sizeof resip);
	SOCKET client = accept(server, (struct sockaddr*)&resip, sizeof resip);
	if(client == INVALID_SOCKET){
		error();
		closesocket(server);
		WSACleanup();
		return;
	}
	printf("客户端IP%s\n端口:%d\n", 
		inet_ntoa(resip.sin_addr), ntohs(resip.sin_port));


	char data[254];
	dp{
		int n = recv(client, data, 254, 0);
		if(n == 0) break;
		if(n == SOCKET_ERROR){
			error();

			//```
		}

		data[n] = '\0';
		printf("data\n");

		char sd[254];
		sprintf(sd, "个数:%s", count(data));
		if(send(client, sd, strlen(sd)) == SOCKET_ERROR){
			error();
			return;
		}

	}while(strcmp(data, "quit") != 0);

	closesocket(client);
	closesocket(server);
	WSACleanup();
}


void main(){

}