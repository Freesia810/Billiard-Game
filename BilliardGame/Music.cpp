#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <WinUser.h>
#include <Windows.h>
#include <mmsystem.h>
#include <dsound.h>
#include <windows.h>
#include <Windows.h>
#include <Mmsystem.h>
#pragma comment(lib,"winmm.lib")

#include "Music.h"

extern bool isSound;

void PlayMainGroundMusic()
{
	if (isSound)
		PlaySound(TEXT("Source/mainground.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

}
void StopMusic()
{
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
}
void PlayGameMusic()
{
	if (isSound)
		PlaySound(TEXT("Source/game.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void PlaySettingMusic()
{
	if (isSound)
	{
		PlaySound(TEXT("Source/setting.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
	else {
		PlaySound(NULL, NULL, NULL);
	}
}

void PlaySelectedMidi()
{
	if (isSound)
		PlaySound(TEXT("Source/selected.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void PlayStartMidi()
{
	if (isSound)
		PlaySound(TEXT("Source/start.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void PlayQuitMidi()
{
	if (isSound)
		PlaySound(TEXT("Source/quit_menu.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void PlayMenuAMidi()
{
	if (isSound)
		PlaySound(TEXT("Source/quit_menu.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void PlayMenuBMidi()
{
	if (isSound)
		PlaySound(TEXT("Source/quit_menu.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void PlayMenuCMidi()
{
	if (isSound)
		PlaySound(TEXT("Source/quit_menu.wav"), NULL, SND_FILENAME | SND_SYNC);
}
