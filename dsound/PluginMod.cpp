#include "dsound.h"
#include <process.h>


HINSTANCE hPluginMod = NULL;


bool IsLoadTaikou5() {

	char szModuleFileName[MAX_PATH];

	GetModuleFileName( NULL, szModuleFileName, sizeof(szModuleFileName) );

	strlwr(szModuleFileName);

	if (strstr(szModuleFileName, "taikou5")) {
		return true;
	}

	return false;
}

//スレッド関数
void ThreadFunc(void * ignored) {
	ShellExecute(NULL, NULL, "TermMod.exe", NULL, NULL, SW_HIDE);
}

bool TryLoadPluginMod(HANDLE hCurDSound) {

	//スレッド起動
	// 直接だと、なぜかShellExecuteが実行できない。復号化とメモリ展開に関係しているかも。
	_beginthread(ThreadFunc, 0, NULL);

	return true;
}