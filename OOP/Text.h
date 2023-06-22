#include <windows.h>
#include "TX18X16.h"

char ch;
char t[2];

void Draw(HDC hdc, char k, int x, int y)
{
	t[0] = ch;
	t[1] = '\0';
	k = k - 192;

	SetBkMode(hdc, TRANSPARENT);

	for (int j = 0; j < jmax; j++)
		for (int i = 0; i < imax; i++)
		{
			if (image[k][j][i] == 3)
			{
				SetTextColor(hdc, RGB(100, 100, 255));
				TextOutA(hdc, (x + i) * 2, (y + j) * 2, t, 1);
				// SetPixel(hdc, x+i, y+j, RGB(255,0,0));
			}
			if (image[k][j][i] == 2)
			{
				SetTextColor(hdc, RGB(0, 0, 255));
				TextOutA(hdc, (x + i) * 2, (y + j) * 2, t, 1);
				// SetPixel(hdc, x+i, y+j, RGB(255,255,200));
			}
			if (image[k][j][i] == 1)
			{
				SetTextColor(hdc, RGB(0, 0, 155));
				TextOutA(hdc, (x + i) * 2, (y + j) * 2, t, 1);
				// SetPixel(hdc, x+i, y+j, RGB(255,0,0));
			}
			else {
				SetTextColor(hdc, RGB(255, 255, 255));
				TextOutA(hdc, (x + i) * 2, (y + j) * 2, " ", 1);
				// SetPixel(hdc,x+i, (y+j),  RGB(255,255,200));
			}
		}
}

void TextOut(HDC hdc, int x, int y, const char* text)
{
	unsigned char* p = (unsigned char*) text;
	for (; *p; p++)
	{
		for (unsigned char k = 192; k < 255; k++)
			if ((*p) == k) Draw(hdc, k, x, y);
		x += imax + 1;
	}
}