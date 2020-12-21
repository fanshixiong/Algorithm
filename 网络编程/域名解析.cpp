#include<Winsock2.h>
#include<stdio.h>
#define DEFAULT_PORT 5050
#define DATA_BUFFER 1024

void main(){
	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){
		printf("Error\n");
		return;
	}

	char name[80] = "www.sina.com";
	struct hostent *host;
	char **temp;

	host = gethostbyname(name);
	if(host == NULL){
		printf("gethostbyname() error. \n");
		WSACleanup();
		return;
	}

	printf("正式主机名： %s\n 长度： %d\n, 地址类型: %d\n", 
		host->h_name, host->h_length, host->h_addrtype);

	printf("主机别名列表如下：\n");
	for(temp = host->h_aliases; *temp != NULL; temp++){
		printf("%s\n", *temp);
	}

	printf("主机的IP列表如下:\n");
	for(temp = h->h_addr_list; *temp != NULL; temp++){
		printf("%s\n", inet_ntoa(*(struct in_addr*)(*temp)));
	}
	WSACleanup();
}


int main(){
	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){
		printf("load error!\n");
		exit(0);
	}

	char name[20] = "www.sina.com";
	struct hostent * host;
	char **temp;

	host = gethostbyname(name);
	if(host == NULL){
		printf("gethostbyname error\n");
		WSACleanup();
		exit(0);
	}

	printf("正式主机名：%s\n长度：%d\n地址类型：%d\n",
		host->h_name, host->h_length, host->addrtype);

	printf("主机别名列表如下：\n");
	for(temp = host->h_aliases; *temp != NULL; temp++){
		printf("%s\n", *temp);
	}

	printf("主机IP列表如下：\n");
	for(temp = host->h_aliases; *temp != NULL; temp++){
		printf("%s\n", inet_ntoa(*(struct in_addr*)(*temp)));
	}

	WSACleanup();
}

int main(){
	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){
		printf("load error!\n");
		return;
	}

	char name[20] = "www.sina.com";
	struct hostent *host;
	char **temp;

	host = gethostbyname(name);
	if(host == NULL){
		printf("gethostbyname error\n");
		WSACleanup();
		return;
	}

	printf("正式主机名称:%s\n长度：%d\n地址类型：%d\n", 
		host->h_name, host->h_length, host->h_addrtype);

	printf("主机别名列表如下：\n");
	for(temp = host->h_aliases; *temp != NULL; temp++){
		printf("%s\n", *temp);
	}

	printf("主机IP列表如下:\n");
	for(temp = host->h_addr_list; *temp != NULL; temp++){
		printf("%s\n", inet_ntoa(*(struct in_addr*)(*temp)));
	}

	WSACleanup();
}