// 太閤立志伝V1.5のみ。

#include <windows.h>
#include <stdlib.h>
#include <shlwapi.h>

#pragma comment(lib, "shlwapi.lib")

// これは太閤立志伝V1.5(2005に発売された最終盤)のみ対応。

/*
00D5C31C   E8 EF050000      CALL    TAIKOU5.00D5C910

00D5CF30   83EC 34          SUB     ESP, 34
00D5CF33   53               PUSH    EBX
00D5CF34   55               PUSH    EBP
00D5CF35   8B6C24 4C        MOV     EBP, DWORD PTR SS:[ESP+4C]
00D5CF39   56               PUSH    ESI
00D5CF3A   8B7424 4C        MOV     ESI, DWORD PTR SS:[ESP+4C]
00D5CF3E   57               PUSH    EDI
00D5CF3F   8B7C24 4C        MOV     EDI, DWORD PTR SS:[ESP+4C]
00D5CF43   56               PUSH    ESI
00D5CF44   55               PUSH    EBP
00D5CF45   C74424 54 000000>MOV     DWORD PTR SS:[ESP+54], 0
00D5CF4D   8B1F             MOV     EBX, DWORD PTR DS:[EDI]
00D5CF4F   FF53 3C          CALL    DWORD PTR DS:[EBX+3C]            ; KERNEL32.GetTempPathA
00D5CF52   85C0             TEST    EAX, EAX
00D5CF54   75 0B            JNZ     SHORT TAIKOU5.00D5CF61
00D5CF56   5F               POP     EDI
00D5CF57   5E               POP     ESI
00D5CF58   5D               POP     EBP
00D5CF59   66:33C0          XOR     AX, AX
00D5CF5C   5B               POP     EBX
00D5CF5D   83C4 34          ADD     ESP, 34
00D5CF60   C3               RETN
*/


void OnTenshouExeGetTmpPathExecute() {

	char szModulePath[256] = "";
	GetModuleFileNameA(NULL, szModulePath, sizeof(szModulePath));
	PathRemoveFileSpec(szModulePath);
	strcat(szModulePath, "\\");
	strcpy((char *)0x19FD48, szModulePath);
}
/*
00D5CF61   8D4424 4C        LEA     EAX, DWORD PTR SS:[ESP+4C]
00D5CF65   50               PUSH    EAX
00D5CF66   56               PUSH    ESI

*/
int pTenshouExeJumpFromToOnTenshouExeGetTmpPath = 0xD5CF61;
int pTenshouExeReturnLblFromOnTenshouExeGetTmpPath = 0xD5CF66;
// この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
// TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
__declspec(naked) void WINAPI OnTenshouExeGetTmpPath() {
	__asm {

		pushad
	}

	OnTenshouExeGetTmpPathExecute();

	__asm {
		popad

		// 元の処理をここに刻む
		LEA     EAX, DWORD PTR SS : [ESP + 0x4C]
		PUSH    EAX

		jmp pTenshouExeReturnLblFromOnTenshouExeGetTmpPath
	}
}
char cmdOnTenshouExeJumpFromGetTmpPath[6] = "\xE9";
void WriteAsmJumperOnTenshouExeGetTmpPath() {
	int iAddress = (int)OnTenshouExeGetTmpPath;
	int SubAddress = iAddress - (pTenshouExeJumpFromToOnTenshouExeGetTmpPath + 5);
	memcpy(cmdOnTenshouExeJumpFromGetTmpPath + 1, &SubAddress, 4); // +1 はE9の次から4バイト分書き換えるから。 
	WriteProcessMemory(GetCurrentProcess(), (LPVOID)(pTenshouExeJumpFromToOnTenshouExeGetTmpPath), cmdOnTenshouExeJumpFromGetTmpPath, 5, NULL); // 一応安全のため 
}
