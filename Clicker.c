#define WINVER 0x0500
#include <stdio.h>
#include <Windows.h>
#pragma comment (lib,   "User32.lib")

int main()
{
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = VK_LCONTROL; //VK_CONTROL;
    input.ki.dwFlags = 0;
    
    for (;;)
    {
        Sleep(5*6000);
        SendInput(1, &input, sizeof(INPUT));
    }

    return 0;
}