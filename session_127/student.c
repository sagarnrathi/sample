#include<windows.h>
#include<stdio.h>
#include<stdlib.h>

#pragma comment(lib,"user32.lib")
#pragma comment(lib,"gdi32.lib")
#pragma comment(lib,"kernel32.lib")

#define NR_MAX_CHAR_IN_ROLL 8
#define NR_MAX_CHAR_IN_NAME 16
#define NR_MAX_CHAR_IN_ATTENDANCE

LRESULT CALLBACK  WndProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lparam);

int WINAPT WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd )
{

}