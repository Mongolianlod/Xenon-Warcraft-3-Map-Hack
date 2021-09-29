#include "Warcraft.h"

extern GAME_ClearTextMessages ClearTextMessages;

void WINAPI HotKeys()
{
	SetTls();

	bool bIsShown  = false;

	while (true)
	{
		if (IsInGame() && !bIsShown)
		{
			MapHack(true);

	
			bIsShown = true;
		}
		else if (!IsInGame() && bIsShown)
				bIsShown = false;

		if (HotKeyPressed(VK_MapHack))
		{
			MapHack();
			while (HotKeyPressed(VK_MapHack))
				Sleep(100);
		}

		if (HotKeyPressed(VK_FogOfWar))
		{
			ToggleFogOfWar();
			while (HotKeyPressed(VK_FogOfWar))
				Sleep(100);
		}

		if (HotKeyPressed(VK_WoodCutter))
		{
			if (IsInGame())
				WoodCutter();

			while (HotKeyPressed(VK_WoodCutter))
				Sleep(100);
		}

		//if (HotKeyPressed(VK_DelayReducer))
		//{
		//	if (IsInGame())
		//		DelayReducer();

		//	while (HotKeyPressed(VK_DelayReducer))
		//		Sleep(100);
		//}

		if (HotKeyPressed(VK_SafeClick))
		{
			if (IsInGame())
				SafeClickInit(false);

			while (HotKeyPressed(VK_SafeClick))
				Sleep(100);
		}

		else if (HotKeyPressed(VK_ZoomIn))
		{
			CameraDistanceHack(VK_ZoomIn);
			while (HotKeyPressed(VK_ZoomIn))
				Sleep(100);
		}

		else if (HotKeyPressed(VK_ZoomOut))
		{
			CameraDistanceHack(VK_ZoomOut);
			while (HotKeyPressed(VK_ZoomOut))
				Sleep(100);
		}

		else if (HotKeyPressed(VK_Default))
		{
			CameraDistanceHack(VK_Default);
			while (HotKeyPressed(VK_Default))
				Sleep(100);
		}

		else if (HotKeyPressed(VK_Scoreboard))
		{
			ScoreboardShortcutKey();
			while (HotKeyPressed(VK_Scoreboard))
				Sleep(100);
		}

		else if (HotKeyPressed(VK_ClearScreen))
		{
			if (IsInGame() && !IsChatBoxOpen())
				ClearTextMessages();

			while (HotKeyPressed(VK_ClearScreen))
				Sleep(100);
		}

		Sleep(100);
	}

	return;
}

bool HotKeyPressed(int iKey)
{
	if (GetForegroundWindow() != hWnd)
		return false;

	if (GetAsyncKeyState(iKey))
		return true;

	return false;
}
