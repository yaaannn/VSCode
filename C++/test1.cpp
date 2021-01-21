#include <Windows.h>
#include <stdio.h>


int main()
{
	DWORD  getLastError;
	//找到窗口
	HWND hWinmine = FindWindowW(NULL, L"Plants vs. Zombies");
	DWORD dwPID = 0;
	GetWindowThreadProcessId(hWinmine, &dwPID);	//获取进程标识
	if (dwPID == 0)
	{
		printf("获取PID失败\n");
		return -1;
	}
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, dwPID);
	if (hProcess == NULL)
	{
		printf_s("进程打开失败\n");
		getLastError = GetLastError();
		return -1;
	}

	DWORD dwNum = 0, dwSize = 0;

	//基址
	DWORD SunShineBaseAddress = 0x00731C50;
	//基址值
	DWORD SunShineBaseAddressValue = 0;
	if (0 == ReadProcessMemory(hProcess, (LPVOID)SunShineBaseAddress, &SunShineBaseAddressValue, sizeof(DWORD), &dwSize))
	{
		printf("静态址获取失败\n");
		getLastError = GetLastError();
		return -1;
	}
	//一级偏移
	DWORD SunShineOffsetFirst = 0x868;
	//一级偏移值
	DWORD SunShineOffsetFirstValue = 0;

	if (0 == ReadProcessMemory(hProcess, (LPVOID)(SunShineBaseAddressValue + SunShineOffsetFirst), &SunShineOffsetFirstValue, sizeof(DWORD), &dwSize))
	{
		printf("一级偏移获取失败\n");
		getLastError = GetLastError();
		return -1;
	}

	//二级偏移
	DWORD SunShineOffsetSecond = 0x5578;
	//最后值
	DWORD SunShineNum = 0;
	if (0 == ReadProcessMemory(hProcess, (LPVOID)(SunShineOffsetFirstValue + SunShineOffsetSecond), &SunShineNum, sizeof(DWORD), &dwSize))
	{
		printf("二级偏移获取失败\n");
		getLastError = GetLastError();
		return -1;
	}
	int modifySunshine;
	printf("SunShineNum:%d\n", SunShineNum);
	printf("输入你要修改后的值：");
	scanf("%d", &modifySunshine);
	WriteProcessMemory(hProcess, (LPVOID)(SunShineOffsetFirstValue + SunShineOffsetSecond), &modifySunshine, sizeof(DWORD), &dwSize);


	CloseHandle(hProcess);
	system("pause");
	return 0;
}