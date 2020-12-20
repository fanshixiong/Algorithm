#include<Winsock2.h>
#includ<stdio.h>
#define DEFAULT_PORT 5050
#define DATA_BUFFER 1024

int main(){
	SOCKET sockid = socket(AF_INET, SOCK_STREAM, 0);
	SOCKET sockfd = socket(AF_INET, SOCK_STREAM, 0);
	SOCKET sockfd = socket(AF_INET, SOCK_STREAM, 0);
	SOCKET sockfd = socket(AF_INET, SOCK_STREAM, 0);

	SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	if(sockfd == INVALID_SOCKET){
		printf("socket error: %d \n", WSAGetLastError());
	}
}

int main(){
	SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKET sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if(sockfd == INVALID_SOCKET){
		printf("socket erroe: %d \n", WSAGetLastError());
	}
}

int main(){
	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){
		printf("Failed to load Winsock\n");
		return;
	}

	WSACleanup();


	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(2, 2), &wsaDATA) != 0){
		printf("Failed to load Winsock\n");
		return;
	}
	WSACleanup();

}