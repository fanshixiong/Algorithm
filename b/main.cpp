
#pragma comment(lib, "ws2_32.lib")

#include "winsock2.h"
#include "stdio.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevlnstance, LPSTR lpCmdLine, int nShowCmd)
{
	WSADATA wsaData;
	WORD wVersionRequested;
	wVersionRequested = MAKEWORD(2,2);

	if(WSAStartup(wVersionRequested, &wsaData) != 0)
	{
		MessageBoxA(NULL, "Winscok初始化发生错误", "failed", MB_OK | MB_ICONEXCLAMATION);
		return -1;
	}
	if(wsaData.wVersion != wVersionRequested)
	{
		MessageBoxA(NULL, "版本号不匹配！", "failed", MB_OK | MB_ICONEXCLAMATION);
		WSACleanup();
		return -1;
	}


	int r = wsaData.wVersion;
	char arr[100];
	char gg[100] = "DLL加载成功！\n Winsock加载正确！\n 版本号：";
	sprintf(arr, "%s%d", gg, r);
	MessageBoxA(NULL, arr, "秀！",MB_OK | MB_ICONEXCLAMATION);
	return 0;
}

