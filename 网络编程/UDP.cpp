#include<Winsock2.h>
#include<stdio.h>
#define DEFAULT_PORT 5050
#define DATA_BUFFER 1024

void main(){
	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){
		printf("load error\n");
		return;
	}

	SOCKET server = socket(AF_INET, SOCK_DGRAM, 0);
	if(server == INVALID_SOCKET){
		printf("socket error\n");
		WSACleanup();
		return;
	}

	sockaddr_in sip;
	memeset(&sip, 0, sizeof sip);
	sip.sin_family = AF_INET;
	sip.sin_port = htons(9999);
	sip.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(server, (sockaddr*)&sip, sizeof sip);
	printf("服务器在9999上接受UDP包\n");

	while(1){
		char ch[254];
		int n = recvfrom(server, ch, 253, 0, (sockaddr*)&sip, sizeof(sip));
		ch[n] = '\0';

		printf("客户机IP： %s\n端口号： %d\n发来的UDP包： %s\n",
			inet_ntoa(sip.sin_addr), ntohs(sip.sin_port), ch);

		char sd[254]="";
		sprintf(sd, "字母个数:%d", count(ch));
		sendto(server, sd, strlen(sd), 0, (sockaddr*)&sip, sizeof(sip));
	}
	closesocket(server);
	WSACleanup();
}

int main(){
	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){
		error();
	}

	SOCKET server = socket(AF_INET, SOCK_DGRAM, 0);
	if(server == INVALID_SOCKET){
		error();
		WSACleanup();
	}

	sockaddr_in sip;
	memset(&sip, 0, sizeof sip);
	sip.sin_port = htons(9999);
	sip.sin_addr.s_addr = htonl(INADDR_ANY);
	sip.sin_family = AF_INET;

	bind(server, (sockaddr*)&sip, 0, sizeof(sip));
	while(1){
		char ch[254];
		int n = recvfrom(server, ch, 253, 0, (sockaddr*)&sip, sizeof sip);
		ch[n] = '\0';

		printf("客户端IP：%s\n端口:%d\nUDP包：%s\n", 
			inet_ntoa(sip.sin_addr), ntohs(sip.sin_port), ch);
		char sd[254];
		sprintf(sd, "字母个数：%d", count(ch));
		sendto(server, sd, strlen(sd), 0, (sockaddr*)&sip, sizeof(sip));
	}

	closesocket(server);
	WSACleanup();
}


void main(){
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData); //load error

	SOCKET client = socket(AF_INET, SOCK_DGRAM, 0); //INVALID_SOCKET WSACleanup()
	sockaddr_in sip;
	memset(&sip, 0, sizeof sip);
	sip.port = htons(9999);
	sip.sin_addr.s_addr = inet_addr("127.0.0.1");
	sip.sin_family = AF_INET;

	char ch[254];
	do{
		gets(ch);
		sendto(client, ch, strlen(ch), 0, (sockaddr*)&sip, sizeof sip);

		char rd[254];
		int n = recvfrom(client, rd, 253, 0, (sockaddr*)&sip, sizeof sip);
		rd[n] = '\0';
		printf("rd\n");
	}while(strcmp(ch, "quit") != 0);

	closesocket(client);
	WSACleanup();
}

void main(){
	WSADATA wsaData;
	WSAStartup(MAKE(2, 2), &wsaData); //load error
	SOCKET client = socket(AF_INET, SOCK_DGRAM, 0); ///INVALID_SOCKET WSACleanup()

	sockaddr_in sip;
	memset(&sip, 0, sizeof sip);
	sip.sin_family = AF_INET;
	sip.sin_port = htons(9999);
	sip.sin_addr.s_addr = inet_addr("125.5.5.5");

	char ch[254];
	do{
		gets(ch);
		sendto(client, ch, strlen(ch), 0, (sockaddr*)&sip, sizeof sip);

		char rf[254] = "";
		int n = recvfrom(client, rf, 253, 0, (sockaddr*)&sip, sizeof sip);
		rf[n] = '\0';
		printf("rf\n");
	}while(strcmp(ch, "quit") != 0);

	closesocket(client);
	WSACleanup();
}