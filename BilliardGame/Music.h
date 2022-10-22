#pragma once

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


void PlayMainGroundMusic();
void StopMusic();
void PlayGameMusic();
void PlaySettingMusic();

void PlaySelectedMidi();
void PlayStartMidi();
void PlayQuitMidi();
void PlayMenuAMidi();
void PlayMenuBMidi();
void PlayMenuCMidi();
