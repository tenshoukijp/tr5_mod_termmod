// dsound_Funcs.cpp : 基本デフォルトの処理へジャンプ。一部処理を挟む
//

#include <windows.h>
#include "dsound.h"
__declspec( naked ) void WINAPI d_DirectSoundCreate() { _asm{ jmp p_DirectSoundCreate } }
__declspec( naked ) void WINAPI d_DirectSoundEnumerateA() { _asm{ jmp p_DirectSoundEnumerateA } }
__declspec( naked ) void WINAPI d_DirectSoundEnumerateW() { _asm{ jmp p_DirectSoundEnumerateW } }
__declspec( naked ) void WINAPI d_DllCanUnloadNow() { _asm{ jmp p_DllCanUnloadNow } }
__declspec( naked ) void WINAPI d_DllGetClassObject() { _asm{ jmp p_DllGetClassObject } }
__declspec( naked ) void WINAPI d_DirectSoundCaptureCreate() { _asm{ jmp p_DirectSoundCaptureCreate } }
__declspec( naked ) void WINAPI d_DirectSoundCaptureEnumerateA() { _asm{ jmp p_DirectSoundCaptureEnumerateA } }
__declspec( naked ) void WINAPI d_DirectSoundCaptureEnumerateW() { _asm{ jmp p_DirectSoundCaptureEnumerateW } }
__declspec( naked ) void WINAPI d_GetDeviceID() { _asm{ jmp p_GetDeviceID } }
__declspec( naked ) void WINAPI d_DirectSoundFullDuplexCreate() { _asm{ jmp p_DirectSoundFullDuplexCreate } }
__declspec( naked ) void WINAPI d_DirectSoundCreate8() { _asm{ jmp p_DirectSoundCreate8 } }
__declspec( naked ) void WINAPI d_DirectSoundCaptureCreate8() { _asm{ jmp p_DirectSoundCaptureCreate8 } }
