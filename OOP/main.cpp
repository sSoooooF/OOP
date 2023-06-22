#include "Point.h" // объ€вление классов 
#include <Windows.h>
#include <cmath>
#include "collision.h"
#include "HWnd.h"    // указатель на консольное окно
#include "PrKey.h"
#include <iostream>

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

using namespace std;

HDC hdc; // ќбъ€вление контектса устройтсва - структура, содеражаща€ описание видеокарты на ѕ  и всех необходимых графических устройств

HWND GetConcolWindow();

// Ўирина и высота окна
const int space_width = 970;
const int space_height = 510;

int x0 = 200;   // начальные 
int Y0 = 250;   // координаты
int radx0 = 15;   // начальный радиус
int rady0 = 7;

PlayerObject* fishs[7] = {
	new BigFishWE(x0, Y0, radx0,rady0), new FishWE(x0, Y0, radx0,rady0),
	new DamagedFishWE(x0,Y0,radx0,rady0), new DamagedBigFishWE(x0,Y0,radx0,rady0),
	new DeadFishWE(x0,Y0,radx0,rady0), new DeadBigFishWE(x0,Y0,radx0,rady0),
	new DoubleDamagedBigFishWE(x0,Y0,radx0,rady0)
};

Object* objects[5] = {
	new Bomb(600, 300, 40), new CircleFish(400, 200, 20), new Herb(100, 100), new DamagedCircleFish(1000,1000,20), new FishBomb(600, 100, 30)
};

Object* cfish[2] = {
	new CircleFish(400,200,20), new DamagedCircleFish(400,200,20)
};

//PlayerObject* matrix[4][3] = {
//								//cfish		//bomb		//herb
//	/*damaged fish*/			{fishs[3],	fishs[4],	fishs[1]},
//	/*dmg b fish*/				{fishs[3],	fishs[5],	fishs[0]},
//	/*fish*/					{fishs[0],	fishs[2],	fishs[1]},
//	/*big fish*/				{fishs[0],	fishs[3],	fishs[0]}
//};

PlayerObject* matrix[5][4] = {
								//cfish		//bomb		//herb		//fbomb
	/*damaged fish*/			{fishs[3],	fishs[4],	fishs[1],	fishs[4]},
	/*dmg b fish*/				{fishs[3],	fishs[6],	fishs[0],	fishs[6]},
	/*fish*/					{fishs[0],	fishs[2],	fishs[1],	fishs[2]},
	/*big fish*/				{fishs[0],	fishs[3],	fishs[0],	fishs[3]},
	/*dd b fish*/				{fishs[6],	fishs[5],	fishs[2],	fishs[5]}
};



int main()
{
	system("color F0");

	HWND hwnd = GetConcolWindow(); // получим дескриптор консольного окна

	if (hwnd != NULL)   // если дескриптор существует
	{
		hdc = GetWindowDC(hwnd); // получим контекст устройства дл€ консольного окна
		if (hdc != 0)    // если контекст существует
		{
			PlayerObject* fish = fishs[1];

			//PlayerObject* fish = new JustFish(x0, Y0, radx0, rady0);

			fish->Show();

			for (const auto& obj : objects)
				obj->Show();

			int FigX, FigY;
			FigX = fish->GetX();
			FigY = fish->GetY();
			int Step = 15;

			while (1)
			{
				if (KEY_DOWN(VK_ESCAPE))
					break;

				if (KEY_DOWN(VK_LEFT)) // влево
				{
					FigX -= Step;

					fish->MoveTo(FigX, FigY);
					fish->ChangeSide(1);

					for (auto& obj : objects)
						if (checkCollision(fish, obj))
						{
							if (obj->GetId() == 66)
								continue;
							fish->Hide();
							fish = matrix[fish->GetId()][obj->GetId()];
							if (obj->GetId() == 0)
							{
								obj = objects[3];
								obj->MoveTo(400, 200);
							}
							if (fish->GetId() == -1)
							{
								fish->Show();
								std::cout << "GAME OVER!!!";
								return 0;
							}
							fish->MoveTo(x0, Y0);
							FigX = x0;
							FigY = Y0;

						}

					for (const auto& obj : objects)
						obj->Show();
				} // end if

				if (KEY_DOWN(VK_RIGHT)) // вправо
				{
					FigX += Step;

					fish->MoveTo(FigX, FigY);
					fish->ChangeSide(0);

					for (auto& obj : objects)
						if (checkCollision(fish, obj))
						{
							if (obj->GetId() == 66)
								continue;
							fish->Hide();
							fish = matrix[fish->GetId()][obj->GetId()];
							if (obj->GetId() == 0)
							{
								obj = objects[3];
								obj->MoveTo(400, 200);
							}
							if (fish->GetId() == -1)
							{
								fish->Show();
								std::cout << "GAME OVER!!!";
								return 0;
							}
							fish->MoveTo(x0, Y0);
							FigX = x0;
							FigY = Y0;

						}

					for (const auto& obj : objects)
						obj->Show();
				} // end for

				if (KEY_DOWN(VK_DOWN)) // вниз
				{
					FigY += Step;
					fish->MoveTo(FigX, FigY);

					for (auto& obj : objects)
						if (checkCollision(fish, obj))
						{
							if (obj->GetId() == 66)
								continue;
							fish->Hide();
							fish = matrix[fish->GetId()][obj->GetId()];
							if (obj->GetId() == 0)
							{
								obj = objects[3];
								obj->MoveTo(400, 200);
							}
							if (fish->GetId() == -1)
							{
								fish->Show();
								std::cout << "GAME OVER!!!";
								return 0;
							}
							fish->MoveTo(x0, Y0);
							FigX = x0;
							FigY = Y0;

						}

					for (const auto& obj : objects)
						obj->Show();
				} // end if

				if (KEY_DOWN(VK_UP)) // вверх
				{
					FigY -= Step;
					fish->MoveTo(FigX, FigY);

					for (auto& obj : objects)
						if (checkCollision(fish, obj))
						{
							if (obj->GetId() == 66)
								continue;
							fish->Hide();
							fish = matrix[fish->GetId()][obj->GetId()];
							if (obj->GetId() == 0)
							{
								obj = objects[3];
								obj->MoveTo(400, 200);
							}
							if (fish->GetId() == -1)
							{
								fish->Show();
								std::cout << "GAME OVER!!!";
								return 0;
							}
							fish->MoveTo(x0, Y0);
							FigX = x0;
							FigY = Y0;

						}

					for (const auto& obj : objects)
						obj->Show();
				} // end if

				Sleep(200);
			} // end while

			ReleaseDC(hwnd, hdc); // освобождение контекста устройства дл€ консольного окна
		} // end if
	} // end if

	return 0;
}// end main()
