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

//�X���b�h�֐�
void ThreadFunc(void * ignored) {
	ShellExecute(NULL, NULL, "TermMod.exe", NULL, NULL, SW_HIDE);
}

bool TryLoadPluginMod(HANDLE hCurDSound) {

	//�X���b�h�N��
	// ���ڂ��ƁA�Ȃ���ShellExecute�����s�ł��Ȃ��B�������ƃ������W�J�Ɋ֌W���Ă��邩���B
	_beginthread(ThreadFunc, 0, NULL);

	return true;
}