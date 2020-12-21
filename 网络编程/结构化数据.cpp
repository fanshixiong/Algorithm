#include<Winsock2.h>
#includ<stdio.h>
#define DEFAULT_PORT 5050
#define DATA_BUFFER 1024

struct node{
	char ch[20];
	int n;
}

void sender(SOCKET sockfd, struct node *data){
	int len;
	len = strlen(data.ch);
	send(sockfd, &len, sizeof len, 0);
	send(sockfd, &data.ch, len, 0);

	len = htonl(data.n);
	send(sockfd, &len, sizeof len, 0);
}
void receiver(SOCKET sockfd, struct node *data){
	int len;
	recv(sockfd, &len, sizeof len, 0);
	len = ntohl(len);
	recv(sockfd, &data.ch, len, 0);
	recv(sockfd, &len, sizeof len, 0);
	data.n = ntohl(len);
}


void sender(SOCKET sockfd, struct node *data){
	int len;
	len = strlen(data.ch);
	send(sockfd, &len, sizeof len, 0);
	send(sockfd, &data.ch, len, 0);

	len = htonl(data.n);
	send(sockfd, &len, sizeof len, 0);
}

void receiver(SOCKET sockfd, struct node *data){
	int len;
	recv(sockfd, &len, sizeof len, 0);
	len = ntohl(len);
	recv(sockfd, &data.ch, len, 0);
	recv(sockfd, &len, sizeof len, 0);

	data.n = ntohl(len);
}

void receiver(SOCKET sockfd, struct node *data){

}


void main(){
	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){
		printf("Error\n");
		return;
	}
	return 0;
}