#pragma once

#include <windows.h>

// このDLLが太閤立志伝から呼ばれているかどうか。、
extern bool IsLoadTaikou5();
extern bool TryLoadPluginMod(HANDLE);
