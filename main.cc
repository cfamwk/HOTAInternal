#include <Windows.h>
#undef DrawText
#include <memory>
#include <vector>

#include "detours/redraw_parts_of_screen.h"
#include "detours/draw_text.h"

#include "modules/morale_chance.h"
#include "modules/force_map_seed.h"
#include "modules/accurate_creature_tooltips.h"
#include "modules/accurate_treasure_tooltips.h"
#include "modules/reveal_map.h"
#include "modules/menu.h"

HMODULE g_module_handle;

std::vector<std::unique_ptr<utility::BaseDetour>> detours;
std::vector<std::unique_ptr<modules::BaseModule>> modules;

DWORD WINAPI MainThread(LPVOID lpReserved)
{
	// load modules

	// load detours
	detours.push_back(std::make_unique<detours::RedrawPartsOfScreen>());
	detours.push_back(std::make_unique<detours::DrawText>());
	
	while (!GetAsyncKeyState(VK_DELETE))
	{
		Sleep(10);
	}

	//unload modules
	modules.clear();

	//unload detours
	detours.clear();

	FreeLibraryAndExitThread(g_module_handle, 0);

	return 0;
}


BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	DisableThreadLibraryCalls(hModule);

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		g_module_handle = hModule;

		if (auto h = CreateThread(0, 0, MainThread, lpReserved, 0, 0))
			CloseHandle(h);

		break;
	}
	case DLL_THREAD_ATTACH:
	{
		break;
	}
	case DLL_THREAD_DETACH:
	{

		break;
	}
	case DLL_PROCESS_DETACH:
	{
		break;
	}
	}
	return TRUE;
}

