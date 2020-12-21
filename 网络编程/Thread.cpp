#include"windows.h"
#include"process.h"

unsigned int CALLBACK MyThread(void *param){
	for(int i = 1; i <= 10; i++){
		printf("线程:%d, 打印:%d\n", GetCurrentThreadId(), i);
		Sleep(2000);
	}
	return 1;
}

void main(){
	DWORD Threadid1 = 0, Threadid2 = 0;
	u_int id1 = 0, id2 = 0;
	HANDLE hThread1 = (HANDLE)_beginthreadex(NULL, 0, MyThread, NULL, 0, &id1);
	if(hThread1 != 0){
		printf("线程1：%d, handle:%d启动\n", id1, hThread1);
	}
	int n = 2;
	HANDLE hThread2 = (HANDLE)_beginthreadex(NULL, 0, MyThreadm NULL, (void*)n, &id2);
	if(hThread2 != 0){
		printf("线程2：%d\n", id2);
	}
	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);

	printf("线程1 2 结束\n");
	CloseHandle(hThread1);
	CloseHandle(hThread2);
}


unsigned int CALLBACK MyThread(void *param){
	for(int i = 1; i <= 10; i++){
		printf("线程: %d, 打印：%d\n", GetCurrentThreadId(), i);
		Sleep(2000);
	}
	return 1;
}
void main(){
	DWORD threadid1, threadid2;
	u_int id1 == 0, id2 = 0;
	HANDLE hThread1 = (HANDLE)_beginthreadex(NULL, 0, MyThread, NULL, 0, &id1);
	if(hThread1 != 0){
		printf("%s\n", id1, hThread1);
	}

	int n = 2;
	HANDLE hThread2 = (HANDLE)_beginthreadex2(NULL, 0, MyThread, (void*)n, &id2);
	if(hThread2 != 0){
		printf("%s\n", id2);
	}

	WaitFOrSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);

	printf("end\n");
	CloseHandle(hThread1);
	CloseHandle(hThread2);
}