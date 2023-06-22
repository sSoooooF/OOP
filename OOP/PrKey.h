#pragma once
#include <WinUser.h>
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

/*------------------------------*/
/*  Задержка экрана до нажатия  */
/*      указанной клавиши       */
/*------------------------------*/
void PressKey(int VCode) 
{
	while (1)
		if (KEY_DOWN(VCode))
			break;
}