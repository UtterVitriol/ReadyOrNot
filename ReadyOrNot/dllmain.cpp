#include <Windows.h>
#include <iostream>
#include <cstdio>

#include "Game.h"
#include "Hack.h"
#include "Menus.h"
#include "aimbot.h"

#include "d3d12hook.h"

D3D12Hook MyHook;
MyGame g_Game;
MyAimBot g_AimBot;

DWORD WINAPI HackThread(HMODULE hModule) {


	MyHook.MyMenu = MyMenu;
	g_Game.Start();

	
	if (!MyHook.d3d12InitHook())
	{
		goto END;
	}
	
	while (1) {
		if (g_AimBot.bRun)
		{
			g_AimBot.run();
		}

		if (GetAsyncKeyState(VK_END) & 1)
		{
			
			MyHook.bShutDown = true;
			Sleep(500);
			break;
		}

		g_Game.UpdateValues();

		Sleep(5);
	}
	
	MyHook.d3d12UnHook();

END:
	FreeLibraryAndExitThread(hModule, 0);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	DisableThreadLibraryCalls(hModule);

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:

		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr));
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
