#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <WinUser.h>
#include <Windows.h>
#include <mmsystem.h>
#include <windows.h>

#include "CONST.h"
#include "DataStructure.h"
#include "Display.h"
#include "Rand.h"
#include "Load_Save.h"
#include "Physics.h"
#include "Music.h"

Mode Gamemode;
FILEMODE Filemode;
bool isDisplayLine;
bool isSound;

bool isStart;
bool isRoll = 1;
int Array[30];
BOOL isQuit = 0;
bBallNode* ballHead;
bBallNode* ballTail;
int gameTime = 0;
int turn = A;
int winner = 0;
int gameStatus = 0;
int Gameover = 0;

extern int Freemode;
extern double menuWidth;
extern double menuHeight;


int main(int argc, char* argv[])
{
	UpdateSettingFromFile();
	GameMain();
	return 0;
}

void GameMain()
{
	initgraph(menuWidth, menuHeight);
	load_img();
	PlayMainGroundMusic();
	while (1)
	{
		if (gameStatus == 0)
		{
			DrawMenu();
			if (isRoll)
			{
				UpdateWithoutInput_menu();
			}
			UpdateWithInput_menu();
		}
		if (gameStatus == 1)
		{
			UpdateSettingFromFile();
			if (Gamemode == POOL || Gamemode == NINEBALL)
			{
				initgraph(1080, 580);
			}
			else if (Gamemode == SNOOKER)
			{
				initgraph(1480, 780);
				Freemode = 1;
			}
			PlayGameMusic();
			DisplayBoard();
			InitLocation();
			if (Gamemode == 1)
			{
				MessageBox(NULL, _T("请用鼠标点击在D型区域内放置白球的位置"), _T("Manager"), MB_OK | MB_SYSTEMMODAL);
				isStart = 1;
			}
			GameProcess();
		}
		else if (gameStatus == 2)
		{
			if (LoadFile(Filemode))
			{
				UpdateColor(Gamemode);
			}
			else {
				HWND wnd = GetHWnd();
				MessageBox(wnd, _T("无存档"), _T("错误"), MB_OK | MB_ICONWARNING | MB_SYSTEMMODAL);
				gameStatus = 0;
				PlayMainGroundMusic();
				continue;
			}
			PlayGameMusic();
			GameProcess();
		}
		else if (gameStatus == 3)
		{
			DisplaySetting();
		}
		else if (gameStatus == 4)
		{
			break;
		}
	}
	EndBatchDraw();
	_getch();
	closegraph();
}
void GameProcess()
{
	BeginBatchDraw();
	while (1)
	{
		UpdateBalls();
		DisplayBoard();
		Boom();
		ScoreCal();
		MouseEventProcess();
		if (Gameover == 1)
		{
			break;
		}
		if (isQuit == 1)
		{
			break;
		}
	}
	if (!isQuit)
	{
		FlushBatchDraw();
		showwinner();
	}
	else {
		isQuit = 0;
	}
	gameStatus = 0;
	EndBatchDraw();
	initgraph(menuWidth, menuHeight);
	PlayMainGroundMusic();
}
