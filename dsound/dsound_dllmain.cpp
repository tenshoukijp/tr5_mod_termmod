// dsound_DllMain.cpp : dsoundのエントリポイント

#include <windows.h>

#include "PluginMod.h"

FARPROC p_DirectSoundCreate;
FARPROC p_DirectSoundEnumerateA;
FARPROC p_DirectSoundEnumerateW;
FARPROC p_DllCanUnloadNow;
FARPROC p_DllGetClassObject;
FARPROC p_DirectSoundCaptureCreate;
FARPROC p_DirectSoundCaptureEnumerateA;
FARPROC p_DirectSoundCaptureEnumerateW;
FARPROC p_GetDeviceID;
FARPROC p_DirectSoundFullDuplexCreate;
FARPROC p_DirectSoundCreate8;
FARPROC p_DirectSoundCaptureCreate8;

HANDLE hCurDSound = NULL;
HINSTANCE hOrgDSound = NULL;;


BOOL APIENTRY DllMain( HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved ) {

	switch( ul_reason_for_call )
	{
	case DLL_PROCESS_ATTACH:

		hCurDSound = hModule;
		hOrgDSound = LoadLibrary( "System32/DSound.dll" ); // XP以上のみターゲット。適当な感じもするが、ＯＳの方が勝手にWow64へとリダイレクトするし大丈夫なんじゃね？ 
		if ( hOrgDSound == NULL ) {
			return FALSE;
		}
		p_DirectSoundCreate = GetProcAddress( hOrgDSound, "DirectSoundCreate" );
		p_DirectSoundEnumerateA = GetProcAddress( hOrgDSound, "DirectSoundEnumerateA" );
		p_DirectSoundEnumerateW = GetProcAddress( hOrgDSound, "DirectSoundEnumerateW" );
		p_DllCanUnloadNow = GetProcAddress( hOrgDSound, "DllCanUnloadNow" );
		p_DllGetClassObject = GetProcAddress( hOrgDSound, "DllGetClassObject" );
		p_DirectSoundCaptureCreate = GetProcAddress( hOrgDSound, "DirectSoundCaptureCreate" );
		p_DirectSoundCaptureEnumerateA = GetProcAddress( hOrgDSound, "DirectSoundCaptureEnumerateA" );
		p_DirectSoundCaptureEnumerateW = GetProcAddress( hOrgDSound, "DirectSoundCaptureEnumerateW" );
		p_GetDeviceID = GetProcAddress( hOrgDSound, "GetDeviceID" );
		p_DirectSoundFullDuplexCreate = GetProcAddress( hOrgDSound, "DirectSoundFullDuplexCreate" );
		p_DirectSoundCreate8 = GetProcAddress( hOrgDSound, "DirectSoundCreate8" );
		p_DirectSoundCaptureCreate8 = GetProcAddress( hOrgDSound, "DirectSoundCaptureCreate8" );

		// 太閤立志伝から呼ばれている。
		if ( IsLoadTaikou5() ) {
			// WriteAsmJumperOnTenshouExeGetTmpPath(); これは太閤立志伝V1.5のみ。
			TryLoadPluginMod(hCurDSound);
		}

		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		if (hOrgDSound) { FreeLibrary(hOrgDSound); }
		break;
	default:
		break;
	}
	return TRUE;
}
