#include "Point.h"
#include <Windows.h>
#include "collision.h"

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

extern HDC hdc;


/*-----------------------------------*/
/*        МЕТОДЫ КЛАССА Location     */
/*-----------------------------------*/

Location::Location(int InitX, int InitY)
{
	X = InitX;
	Y = InitY;
}; // end Location::Location()

Location::~Location()
{
}; // end Location::~Location()

int Location::GetX()
{
	return X;
} // end Location::GetX()

int Location::GetY()
{
	return Y;
} // end Location::GetY()


/*-----------------------------------*/
/*        МЕТОДЫ КЛАССА Point        */
/*-----------------------------------*/

Point::Point(int InitX, int InitY) : Location(InitX, InitY)
{
	Visible = true;
}; // end Point::Point()

Point::~Point()
{
}; // end Point::~Point()

void Point::Show()
{
	Visible = true;
	SetPixel(hdc, X, Y, RGB(255, 0, 0));
	SetPixel(hdc, X+1, Y, RGB(255, 0, 0));
	SetPixel(hdc, X, Y+1, RGB(255, 0, 0));
	SetPixel(hdc, X+1, Y+1, RGB(255, 0, 0));

}; // end Point::Show()

void Point::Hide()
{
	Visible = false;
	SetPixel(hdc, X, Y, RGB(255, 255, 255));
}; // end Point::Hide()

bool Point::isVisible()
{
	return Visible;
};// end Point::isVisible()

Object::Object(int InitX, int InitY, int InitRadiusX, int InitRadiusY) : Point(InitX, InitY)
{
	id = 0;
	RadiusX = InitRadiusX;
	RadiusY = InitRadiusY;
} // end Object::Object()

int Object::GetId()
{
	return id;
} // end PlayerObject::GetId()

void Object::MoveTo(int newX, int newY)
{
	X = newX;
	Y = newY;
}

Object::~Object()
{
} // end Object::~Object()

int Object::GetRadiusX()
{
	return RadiusX;
}

int Object::GetRadiusY()
{
	return RadiusY;
}

/*-----------------------------------*/
/*     МЕТОДЫ КЛАССА PlayerObject      */
/*-----------------------------------*/

PlayerObject::PlayerObject(int InitX, int InitY, int InitRadiusX, int InitRadiusY) : Object(InitX, InitY, InitRadiusX, InitRadiusY)
{
	baseX = InitX;
	baseY = InitY;
	id = 666;
} // end PlayerObject()

PlayerObject::~PlayerObject()
{
}

void PlayerObject::ChangeRadius(int NewRadiusX, int NewRadiusY)
{
	Hide();
	RadiusX = NewRadiusX;
	RadiusY = NewRadiusY;
	Show();
} // end PlayerObject::changeRadius()

void PlayerObject::ChangeSide(int newSide)
{
	Side = newSide;
}

void PlayerObject::Hide()
{
	hideBody();
	hideEye();
	hideTail();
}

void PlayerObject::Show()
{
	Visible = true;
	showBody();
	showEye();
	showTail(); 
}


/*-----------------------------------*/
/*        МЕТОДЫ КЛАССА Fish         */
/*-----------------------------------*/

Fish::Fish(int InitX, int InitY, int InitRadiusX, int InitRadiusY) : PlayerObject(InitX, InitY, InitRadiusX, InitRadiusY)
{
	id = 1;
} // end Fish::Fish();

Fish::~Fish()
{
} // end Fish::~Fish()

FishWE::FishWE(int InitX, int InitY, int InitRadiusX, int InitRadiusY) : Fish(InitX, InitY, 2*InitRadiusX, 2*InitRadiusY)
{
	id = 2;
} // end FishWE::FishWE()

FishWE::~FishWE()
{
}

void FishWE::showBody()
{
	Visible = true;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));	// красный цвет
	SelectObject(hdc, Pen);

	Ellipse(hdc, X - RadiusX, Y - RadiusY, X + RadiusX, Y + RadiusY);	// рисование тела рыбки

	DeleteObject(Pen);
}

void FishWE::showTail()
{
	Visible = true;
	HPEN Pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));	// красный цвет
	SelectObject(hdc, Pen);
	if (!Side) // если смотрит вправо
	{
		MoveToEx(hdc, X - RadiusX, Y, NULL);
		LineTo(hdc, X - RadiusX * 4 / 3, Y + RadiusY);
		LineTo(hdc, X - RadiusX * 4 / 3, Y - RadiusY);
		LineTo(hdc, X - RadiusX, Y);
	}
	else
	{	MoveToEx(hdc, X + RadiusX, Y, NULL);
		LineTo(hdc, X + RadiusX * 4 / 3, Y + RadiusY);
		LineTo(hdc, X + RadiusX * 4 / 3, Y - RadiusY);
		LineTo(hdc, X + RadiusX, Y);
	}
	DeleteObject(Pen);
}

void FishWE::showEye()
{
	Visible = true;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));	// красный цвет
	SelectObject(hdc, Pen);
	Ellipse(hdc, X + RadiusX / 3, Y - RadiusY / 2+5, X + RadiusX / 3-10, Y - RadiusY / 2-5);
	if (!Side) // если смотрит вправо
	{
		SetPixel(hdc, X + RadiusX / 3, Y - RadiusY / 2, RGB(255, 255, 255));
		SetPixel(hdc, X + RadiusX / 3 + 1, Y - RadiusY / 2, RGB(255, 255, 255));
		SetPixel(hdc, X + RadiusX / 3 + 1, Y - RadiusY / 2 + 1, RGB(255, 255, 255));
		SetPixel(hdc, X + RadiusX / 3, Y - RadiusY / 2 + 1, RGB(255, 255, 255));
	}
	else
	{
		SetPixel(hdc, X - RadiusX / 3, Y - RadiusY / 2, RGB(255, 255, 255));
		SetPixel(hdc, X - RadiusX / 3 + 1, Y - RadiusY / 2, RGB(255, 255, 255));
		SetPixel(hdc, X - RadiusX / 3 + 1, Y - RadiusY / 2 + 1, RGB(255, 255, 255));
		SetPixel(hdc, X - RadiusX / 3, Y - RadiusY / 2 + 1, RGB(255, 255, 255));
	}
	DeleteObject(Pen);
}

void FishWE::hideBody()
{
	Visible = true;
	HPEN Pen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));	// красный цвет
	SelectObject(hdc, Pen);

	Ellipse(hdc, X - RadiusX, Y - RadiusY, X + RadiusX, Y + RadiusY);	// рисование тела рыбки

	DeleteObject(Pen);
}

void FishWE::hideTail()
{
	Visible = true;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));	// красный цвет
	SelectObject(hdc, Pen);
	if (!Side) // если смотрит вправо
	{
		MoveToEx(hdc, X - RadiusX, Y, NULL);
		LineTo(hdc, X - RadiusX * 4 / 3, Y + RadiusY);
		LineTo(hdc, X - RadiusX * 4 / 3, Y - RadiusY);
		LineTo(hdc, X - RadiusX, Y);
	}
	else
	{
		MoveToEx(hdc, X + RadiusX, Y, NULL);
		LineTo(hdc, X + RadiusX * 4 / 3, Y + RadiusY);
		LineTo(hdc, X + RadiusX * 4 / 3, Y - RadiusY);
		LineTo(hdc, X + RadiusX, Y);
	}
	DeleteObject(Pen);
}

void FishWE::hideEye()
{
	Visible = true;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));	// красный цвет
	SelectObject(hdc, Pen);
	Ellipse(hdc, X + RadiusX / 3, Y - RadiusY / 2 + 2, X + RadiusX / 3, Y - RadiusY / 2 - 5);
	if (!Side) // если смотрит вправо
	{
		SetPixel(hdc, X + RadiusX / 3, Y - RadiusY / 2, RGB(255, 255, 255));
		SetPixel(hdc, X + RadiusX / 3 + 1, Y - RadiusY / 2, RGB(255, 255, 255));
		SetPixel(hdc, X + RadiusX / 3 + 1, Y - RadiusY / 2 + 1, RGB(255, 255, 255));
		SetPixel(hdc, X + RadiusX / 3, Y - RadiusY / 2 + 1, RGB(255, 255, 255));
	}
	else
	{
		SetPixel(hdc, X - RadiusX / 3, Y - RadiusY / 2, RGB(255, 255, 255));
		SetPixel(hdc, X - RadiusX / 3 + 1, Y - RadiusY / 2, RGB(255, 255, 255));
		SetPixel(hdc, X - RadiusX / 3 + 1, Y - RadiusY / 2 + 1, RGB(255, 255, 255));
		SetPixel(hdc, X - RadiusX / 3, Y - RadiusY / 2 + 1, RGB(255, 255, 255));
	}
	DeleteObject(Pen);
}



JustFish::JustFish(int InitX, int InitY, int InitRadiusX, int InitRadiusY) : FishWE(InitX, InitY, InitRadiusX, InitRadiusY)
{
}

JustFish::~JustFish()
{
}

void JustFish::showBody()
{
	Visible = true;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));	// красный цвет
	SelectObject(hdc, Pen);

	Ellipse(hdc, X - RadiusX, Y - RadiusY, X + RadiusX, Y + RadiusY);	// рисование тела рыбки

	DeleteObject(Pen);
}

void JustFish::showTail()
{
	Visible = true;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));	// красный цвет
	SelectObject(hdc, Pen);
	if (!Side) // если смотрит вправо
	{
		MoveToEx(hdc, X - RadiusX, Y, NULL);
		LineTo(hdc, X - RadiusX * 4 / 3, Y + RadiusY);
		LineTo(hdc, X - RadiusX * 4 / 3, Y - RadiusY);
		LineTo(hdc, X - RadiusX, Y);
	}
	else
	{
		MoveToEx(hdc, X + RadiusX, Y, NULL);
		LineTo(hdc, X + RadiusX * 4 / 3, Y + RadiusY);
		LineTo(hdc, X + RadiusX * 4 / 3, Y - RadiusY);
		LineTo(hdc, X + RadiusX, Y);
	}
	DeleteObject(Pen);
}

void JustFish::showEye()
{
}

void JustFish::hideBody()
{
	Visible = true;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));	// красный цвет
	SelectObject(hdc, Pen);

	Ellipse(hdc, X - RadiusX, Y - RadiusY, X + RadiusX, Y + RadiusY);	// рисование тела рыбки

	DeleteObject(Pen);
}

void JustFish::hideTail()
{
	Visible = true;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));	// красный цвет
	SelectObject(hdc, Pen);
	if (!Side) // если смотрит вправо
	{
		MoveToEx(hdc, X - RadiusX, Y, NULL);
		LineTo(hdc, X - RadiusX * 4 / 3, Y + RadiusY);
		LineTo(hdc, X - RadiusX * 4 / 3, Y - RadiusY);
		LineTo(hdc, X - RadiusX, Y);
	}
	else
	{
		MoveToEx(hdc, X + RadiusX, Y, NULL);
		LineTo(hdc, X + RadiusX * 4 / 3, Y + RadiusY);
		LineTo(hdc, X + RadiusX * 4 / 3, Y - RadiusY);
		LineTo(hdc, X + RadiusX, Y);
	}
	DeleteObject(Pen);
}

void JustFish::hideEye()
{
}

BigFishWE::BigFishWE(int InitX, int InitY, int InitRadiusX, int InitRadiusY) : FishWE(InitX, InitY, 2*InitRadiusX, 2*InitRadiusY)
{
	id = 3;
}

BigFishWE::~BigFishWE()
{
}

DeadFishWE::DeadFishWE(int InitX, int InitY, int InitRadiusX, int InitRadiusY) : DamagedFishWE(InitX, InitY, InitRadiusX, InitRadiusY)
{
	id = -1;
}

DeadFishWE::~DeadFishWE()
{
}

void DeadFishWE::showBody()
{
	Visible = true;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));	// красный цвет
	SelectObject(hdc, Pen);

	Ellipse(hdc, X - RadiusX, Y - RadiusY, X + RadiusX, Y + RadiusY);	// рисование тела рыбки

	if (!Side) // если смотрит вправо
	{
		MoveToEx(hdc, X, Y + RadiusY, NULL);
		LineTo(hdc, X - RadiusX / 4, Y);
		LineTo(hdc, X, Y - RadiusY);

	}
	else
	{
		MoveToEx(hdc, X, Y + RadiusY, NULL);
		LineTo(hdc, X - RadiusX / 4, Y);
		LineTo(hdc, X, Y - RadiusY);
	}

	DeleteObject(Pen);
}

void DeadFishWE::showTail()
{
	Visible = true;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));	// красный цвет
	SelectObject(hdc, Pen);
	if (!Side) // если смотрит вправо
	{
		MoveToEx(hdc, X - RadiusX, Y, NULL);
		LineTo(hdc, X - RadiusX * 4 / 3, Y + RadiusY);
		LineTo(hdc, X - RadiusX * 4 / 3, Y - RadiusY);
		LineTo(hdc, X - RadiusX, Y);

	}
	else
	{
		MoveToEx(hdc, X + RadiusX, Y, NULL);
		LineTo(hdc, X + RadiusX * 4 / 3, Y + RadiusY);
		LineTo(hdc, X + RadiusX * 4 / 3, Y - RadiusY);
		LineTo(hdc, X + RadiusX, Y);
	}

	DeleteObject(Pen);
}

void DeadFishWE::showEye()
{
	Visible = true;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));	// красный цвет
	SelectObject(hdc, Pen);
	if (!Side) // если смотрит вправо
	{
		MoveToEx(hdc, X + RadiusX / 3 - 3, Y - RadiusY / 2 - 3, NULL);
		LineTo(hdc, X + RadiusX / 3 + 3, Y - RadiusY / 2 + 3);
		MoveToEx(hdc, X + RadiusX / 3 - 3, Y - RadiusY / 2 - 3, NULL);
		LineTo(hdc, X + RadiusX / 3 + 3, Y - RadiusY / 2 + 3);

	}
	else
	{
		MoveToEx(hdc, X - RadiusX / 3 - 3, Y - RadiusY / 2 - 3, NULL);
		LineTo(hdc, X - RadiusX / 3 + 3, Y - RadiusY / 2 + 3);
		MoveToEx(hdc, X - RadiusX / 3 - 3, Y - RadiusY / 2 - 3, NULL);
		LineTo(hdc, X - RadiusX / 3 + 3, Y - RadiusY / 2 + 3);
	}

	DeleteObject(Pen);
}

void DeadFishWE::hideBody()
{
	Visible = false;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));	// красный цвет
	SelectObject(hdc, Pen);

	if (!Side) // если смотрит вправо
	{
		MoveToEx(hdc, X, Y + RadiusY, NULL);
		LineTo(hdc, X - RadiusX / 4, Y);
		LineTo(hdc, X, Y - RadiusY);

	}
	else
	{
		MoveToEx(hdc, X, Y + RadiusY, NULL);
		LineTo(hdc, X - RadiusX / 4, Y);
		LineTo(hdc, X, Y - RadiusY);
	}


	Ellipse(hdc, X - RadiusX, Y - RadiusY, X + RadiusX, Y + RadiusY);	// рисование тела рыбки
	DeleteObject(Pen);
}

void DeadFishWE::hideTail()
{
	Visible = false;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));	// красный цвет
	SelectObject(hdc, Pen);
	if (!Side) // если смотрит вправо
	{
		MoveToEx(hdc, X - RadiusX, Y, NULL);
		LineTo(hdc, X - RadiusX * 4 / 3, Y + RadiusY);
		LineTo(hdc, X - RadiusX * 4 / 3, Y - RadiusY);
		LineTo(hdc, X - RadiusX, Y);

	}
	else
	{
		MoveToEx(hdc, X + RadiusX, Y, NULL);
		LineTo(hdc, X + RadiusX * 4 / 3, Y + RadiusY);
		LineTo(hdc, X + RadiusX * 4 / 3, Y - RadiusY);
		LineTo(hdc, X + RadiusX, Y);
	}

	DeleteObject(Pen);
}

void DeadFishWE::hideEye()
{
	Visible = false;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));	// красный цвет
	SelectObject(hdc, Pen);
	if (!Side) // если смотрит вправо
	{
		MoveToEx(hdc, X + RadiusX / 3 - 3, Y - RadiusY / 2 - 3, NULL);
		LineTo(hdc, X + RadiusX / 3 + 3, Y - RadiusY / 2 + 3);
		MoveToEx(hdc, X + RadiusX / 3 - 3, Y - RadiusY / 2 - 3, NULL);
		LineTo(hdc, X + RadiusX / 3 + 3, Y - RadiusY / 2 + 3);

	}
	else
	{
		MoveToEx(hdc, X - RadiusX / 3 - 3, Y - RadiusY / 2 - 3, NULL);
		LineTo(hdc, X - RadiusX / 3 + 3, Y - RadiusY / 2 + 3);
		MoveToEx(hdc, X - RadiusX / 3 - 3, Y - RadiusY / 2 - 3, NULL);
		LineTo(hdc, X - RadiusX / 3 + 3, Y - RadiusY / 2 + 3);
	}

	DeleteObject(Pen);
}



DamagedFishWE::DamagedFishWE(int InitX, int InitY, int InitRadiusX, int InitRadiusY) : FishWE(InitX, InitY, InitRadiusX, InitRadiusY)
{
	id = 0;
} // end DamagedFish::DamagedFish()

DamagedFishWE::~DamagedFishWE()
{
} // end DamagedFish::~DamagedFish()

void DamagedFishWE::showBody()
{
	Visible = true;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));	// красный цвет
	SelectObject(hdc, Pen);

	Ellipse(hdc, X - RadiusX, Y - RadiusY, X + RadiusX, Y + RadiusY);	// рисование тела рыбки

	if (!Side) // если смотрит вправо
	{
		MoveToEx(hdc, X, Y + RadiusY, NULL);
		LineTo(hdc, X - RadiusX / 4, Y);
		LineTo(hdc, X, Y - RadiusY);

	}
	else
	{
		MoveToEx(hdc, X, Y + RadiusY, NULL);
		LineTo(hdc, X - RadiusX / 4, Y);
		LineTo(hdc, X, Y - RadiusY);
	}

	DeleteObject(Pen);
}

void DamagedFishWE::showTail()
{
	Visible = true;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));	// красный цвет
	SelectObject(hdc, Pen);
	if (!Side) // если смотрит вправо
	{
		MoveToEx(hdc, X - RadiusX, Y, NULL);
		LineTo(hdc, X - RadiusX * 4 / 3, Y + RadiusY);
		LineTo(hdc, X - RadiusX * 4 / 3, Y - RadiusY);
		LineTo(hdc, X - RadiusX, Y);

	}
	else
	{
		MoveToEx(hdc, X + RadiusX, Y, NULL);
		LineTo(hdc, X + RadiusX * 4 / 3, Y + RadiusY);
		LineTo(hdc, X + RadiusX * 4 / 3, Y - RadiusY);
		LineTo(hdc, X + RadiusX, Y);
	}

	DeleteObject(Pen);
}

void DamagedFishWE::showEye()
{
	Visible = true;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));	// красный цвет
	SelectObject(hdc, Pen);
	if (!Side) // если смотрит вправо
	{
		SetPixel(hdc, X + RadiusX / 3, Y - RadiusY / 2, RGB(255, 255, 255));
		SetPixel(hdc, X + RadiusX / 3 + 1, Y - RadiusY / 2, RGB(255, 255, 255));
		SetPixel(hdc, X + RadiusX / 3 + 1, Y - RadiusY / 2 + 1, RGB(255, 255, 255));
		SetPixel(hdc, X + RadiusX / 3, Y - RadiusY / 2 + 1, RGB(255, 255, 255));
	}
	else
	{
		SetPixel(hdc, X - RadiusX / 3, Y - RadiusY / 2, RGB(255, 255, 255));
		SetPixel(hdc, X - RadiusX / 3 + 1, Y - RadiusY / 2, RGB(255, 255, 255));
		SetPixel(hdc, X - RadiusX / 3 + 1, Y - RadiusY / 2 + 1, RGB(255, 255, 255));
		SetPixel(hdc, X - RadiusX / 3, Y - RadiusY / 2 + 1, RGB(255, 255, 255));
	}
	DeleteObject(Pen);
}

void DamagedFishWE::hideBody()
{
	Visible = false;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));	// красный цвет
	SelectObject(hdc, Pen);

	if (!Side) // если смотрит вправо
	{
		MoveToEx(hdc, X, Y + RadiusY, NULL);
		LineTo(hdc, X - RadiusX / 4, Y);
		LineTo(hdc, X, Y - RadiusY);

	}
	else
	{
		MoveToEx(hdc, X, Y + RadiusY, NULL);
		LineTo(hdc, X - RadiusX / 4, Y);
		LineTo(hdc, X, Y - RadiusY);
	}


	Ellipse(hdc, X - RadiusX, Y - RadiusY, X + RadiusX, Y + RadiusY);	// рисование тела рыбки
	DeleteObject(Pen);
}

void DamagedFishWE::hideTail()
{
	Visible = false;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));	// красный цвет
	SelectObject(hdc, Pen);
	if (!Side) // если смотрит вправо
	{
		MoveToEx(hdc, X - RadiusX, Y, NULL);
		LineTo(hdc, X - RadiusX * 4 / 3, Y + RadiusY);
		LineTo(hdc, X - RadiusX * 4 / 3, Y - RadiusY);
		LineTo(hdc, X - RadiusX, Y);

	}
	else
	{
		MoveToEx(hdc, X + RadiusX, Y, NULL);
		LineTo(hdc, X + RadiusX * 4 / 3, Y + RadiusY);
		LineTo(hdc, X + RadiusX * 4 / 3, Y - RadiusY);
		LineTo(hdc, X + RadiusX, Y);
	}

	DeleteObject(Pen);
}

void DamagedFishWE::hideEye()
{
	Visible = false;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));	// красный цвет
	SelectObject(hdc, Pen);
	if (!Side) // если смотрит вправо
	{
		SetPixel(hdc, X + RadiusX / 3, Y - RadiusY / 2, RGB(255, 255, 255));
		SetPixel(hdc, X + RadiusX / 3 + 1, Y - RadiusY / 2, RGB(255, 255, 255));
		SetPixel(hdc, X + RadiusX / 3 + 1, Y - RadiusY / 2 + 1, RGB(255, 255, 255));
		SetPixel(hdc, X + RadiusX / 3, Y - RadiusY / 2 + 1, RGB(255, 255, 255));
	}
	else
	{
		SetPixel(hdc, X - RadiusX / 3, Y - RadiusY / 2, RGB(255, 255, 255));
		SetPixel(hdc, X - RadiusX / 3 + 1, Y - RadiusY / 2, RGB(255, 255, 255));
		SetPixel(hdc, X - RadiusX / 3 + 1, Y - RadiusY / 2 + 1, RGB(255, 255, 255));
		SetPixel(hdc, X - RadiusX / 3, Y - RadiusY / 2 + 1, RGB(255, 255, 255));
	}
	DeleteObject(Pen);
}

DamagedBigFishWE::DamagedBigFishWE(int InitX, int InitY, int InitRadiusX, int InitRadiusY) : DamagedFishWE(InitX, InitY, 2*InitRadiusX, 2*InitRadiusY)
{
	id = 1;
}

DamagedBigFishWE::~DamagedBigFishWE()
{
}


DoubleDamagedBigFishWE::DoubleDamagedBigFishWE(int InitX, int InitY, int InitRadiusX, int InitRadiusY) : DamagedBigFishWE(InitX, InitY, InitRadiusX, InitRadiusY)
{
	id = 4;
}

DoubleDamagedBigFishWE::~DoubleDamagedBigFishWE()
{
}

void DoubleDamagedBigFishWE::showBody()
{
	Visible = true;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));	// красный цвет
	SelectObject(hdc, Pen);

	Ellipse(hdc, X - RadiusX, Y - RadiusY, X + RadiusX, Y + RadiusY);	// рисование тела рыбки

	if (!Side) // если смотрит вправо
	{
		MoveToEx(hdc, X, Y + RadiusY, NULL);
		LineTo(hdc, X - RadiusX / 4, Y);
		LineTo(hdc, X, Y - RadiusY);
	}
	else
	{
		MoveToEx(hdc, X, Y + RadiusY, NULL);
		LineTo(hdc, X - RadiusX / 4, Y);
		LineTo(hdc, X, Y - RadiusY);
	}


	MoveToEx(hdc, X + RadiusX / 2, Y, NULL);
	LineTo(hdc, X - RadiusX / 2, Y);

	DeleteObject(Pen);
}

void DoubleDamagedBigFishWE::hideBody()
{
	Visible = false;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));	// белый цвет
	SelectObject(hdc, Pen);

	Ellipse(hdc, X - RadiusX, Y - RadiusY, X + RadiusX, Y + RadiusY);	// рисование тела рыбки

	if (!Side) // если смотрит вправо
	{
		MoveToEx(hdc, X, Y + RadiusY, NULL);
		LineTo(hdc, X - RadiusX / 4, Y);
		LineTo(hdc, X, Y - RadiusY);
	}
	else
	{
		MoveToEx(hdc, X, Y + RadiusY, NULL);
		LineTo(hdc, X - RadiusX / 4, Y);
		LineTo(hdc, X, Y - RadiusY);
	}


	MoveToEx(hdc, X + RadiusX / 2, Y, NULL);
	LineTo(hdc, X - RadiusX / 2, Y);

	DeleteObject(Pen);
}



DeadBigFishWE::DeadBigFishWE(int InitX, int InitY, int InitRadiusX, int InitRadiusY) : DeadFishWE(InitX, InitY, 2*InitRadiusX, 2*InitRadiusY)
{
	id = -1;
} // end DeadBigFishWE::DeadBigFishWE()

DeadBigFishWE::~DeadBigFishWE()
{
} // end DeadBigFishWE::~DeadBigFishWE()



CircleFish::CircleFish(int InitX, int InitY, int InitRadius) : Object(InitX, InitY, InitRadius, InitRadius)
{
	id = 0;
} // end CircleFish()

CircleFish::~CircleFish()
{
} // end CircleFish::~CircleFish()

void CircleFish::Show()
{
	Visible = true;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // красный цвет
	SelectObject(hdc, Pen);

	Ellipse(hdc, X - RadiusX, Y - RadiusX, X + RadiusX, Y + RadiusX);	// тело рыбки в синий
	Ellipse(hdc, X - RadiusX / 5, Y - RadiusX / 5, X, Y);
	MoveToEx(hdc, X + RadiusX, Y, NULL);
	LineTo(hdc, X + RadiusX * 4 / 3, Y + RadiusY / 2);
	LineTo(hdc, X + RadiusX * 4 / 3, Y - RadiusY / 2);
	LineTo(hdc, X + RadiusX, Y);

	DeleteObject(Pen);
} // end CircleFish::Show()

void CircleFish::Hide() 
{
	Visible = false;	// рыбка не видна

	//HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255)); // синий цвет
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255)); // белый цвет
	SelectObject(hdc, Pen);

	Ellipse(hdc, X - RadiusX/2, Y - RadiusX/2, X + RadiusX/2, Y + RadiusX/2);	// тело рыбки в синий
	Ellipse(hdc, X - RadiusX / 5, Y - RadiusX / 5, X, Y);
	MoveToEx(hdc, X + RadiusX, Y, NULL);
	LineTo(hdc, X + RadiusX * 4 / 3, Y + RadiusY / 2);
	LineTo(hdc, X + RadiusX * 4 / 3, Y - RadiusY / 2);
	LineTo(hdc, X + RadiusX, Y);

	DeleteObject(Pen);
} // end CircleFish::Hide()



Bomb::Bomb(int InitX, int InitY, int InitRadius) : Object(InitX, InitY, InitRadius, InitRadius)
{
	id = 1;
} // end Bomb::Bomb()

Bomb::~Bomb()
{
} // end Bomb::~Bomb()

void Bomb::Show()
{
	Visible = true;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // red цвет
	SelectObject(hdc, Pen);

	Ellipse(hdc, X - RadiusX, Y - RadiusY, X + RadiusX, Y + RadiusY);
	Ellipse(hdc, X-RadiusX, Y + 1, X + RadiusX, Y - 1);
	Ellipse(hdc, X - 1, Y + RadiusY, X + 1, Y - RadiusY);

	DeleteObject(Pen);
} // end Bomb::Show()

void Bomb::Hide()
{
	Visible = false;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255)); // red цвет
	SelectObject(hdc, Pen);

	Ellipse(hdc, X - RadiusX, Y - RadiusX, X + RadiusX, Y + RadiusY);
	Ellipse(hdc, X - RadiusX, Y + 1, X + RadiusX, Y - 1);
	Ellipse(hdc, X - 1, Y + RadiusY, X + 1, Y - RadiusY);

	DeleteObject(Pen);
} // end Bomb::Hide()

Herb::Herb(int InitX, int InitY) : Object(InitX, InitY, 10, 20)
{
	id = 2;
}

Herb::~Herb()
{
}

void Herb::Show()
{
	Visible = true;

	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // red цвет
	SelectObject(hdc, Pen);

	Ellipse(hdc, X - RadiusX, Y + RadiusY, X + RadiusX, Y - RadiusY);

	DeleteObject(Pen);

}

void Herb::Hide()
{
	Visible = false;

	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255)); // white цвет
	SelectObject(hdc, Pen);

	Ellipse(hdc, X - RadiusX, Y + RadiusY, X + RadiusX, Y - RadiusY);

	DeleteObject(Pen);
}

DamagedCircleFish::DamagedCircleFish(int InitX, int InitY, int InitRadius) : CircleFish(InitX, InitY, InitRadius)
{
	id = 66;
}

DamagedCircleFish::~DamagedCircleFish()
{
}

void DamagedCircleFish::Show()
{
	Visible = true;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // красный цвет
	SelectObject(hdc, Pen);

	Ellipse(hdc, X - RadiusX, Y - RadiusX, X + RadiusX, Y + RadiusX);	// тело рыбки в синий
	Ellipse(hdc, X - RadiusX / 5, Y - RadiusX / 5, X, Y);
	MoveToEx(hdc, X + RadiusX, Y, NULL);
	LineTo(hdc, X + RadiusX * 4 / 3, Y + RadiusY / 2);
	LineTo(hdc, X + RadiusX * 4 / 3, Y - RadiusY / 2);
	LineTo(hdc, X + RadiusX, Y);

	MoveToEx(hdc, X, Y + RadiusY, NULL);
	LineTo(hdc, X, Y - RadiusY);

	DeleteObject(Pen);
}

void DamagedCircleFish::Hide()
{
	Visible = false;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255)); // красный цвет
	SelectObject(hdc, Pen);

	Ellipse(hdc, X - RadiusX, Y - RadiusX, X + RadiusX, Y + RadiusX);	// тело рыбки в синий
	Ellipse(hdc, X - RadiusX / 5, Y - RadiusX / 5, X, Y);
	MoveToEx(hdc, X + RadiusX, Y, NULL);
	LineTo(hdc, X + RadiusX * 4 / 3, Y + RadiusY / 2);
	LineTo(hdc, X + RadiusX * 4 / 3, Y - RadiusY / 2);
	LineTo(hdc, X + RadiusX, Y);

	MoveToEx(hdc, X, Y + RadiusY, NULL);
	LineTo(hdc, X, Y - RadiusY);

	DeleteObject(Pen);
}

void PlayerObject::MoveTo(int NewX, int NewY)
{
	hideBody();
	hideTail();
	hideEye();
	X = NewX;
	Y = NewY;
	showBody();
	showTail();
	showEye();
}

FishBomb::FishBomb(int InitX, int InitY, int InitRadius) : Bomb(InitX, InitY, InitRadius)
{ 
	id = 3;
	RadiusY = 2 * InitRadius;
}

FishBomb::~FishBomb()
{
}

void FishBomb::Show()
{
	Visible = true;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // красный цвет
	SelectObject(hdc,Pen);

	Ellipse(hdc, X - RadiusX, Y - RadiusX, X + RadiusX, Y + RadiusX);
	Ellipse(hdc, X - RadiusX / 5, Y - RadiusX / 5, X, Y);
	MoveToEx(hdc, X + RadiusX, Y, NULL);
	LineTo(hdc, X + RadiusX * 4 / 3, Y + RadiusY / 2);
	LineTo(hdc, X + RadiusX * 4 / 3, Y - RadiusY / 2);
	LineTo(hdc, X + RadiusX, Y);

	LineTo(hdc, X - RadiusX, Y);
	MoveToEx(hdc, X, Y + RadiusY, NULL);
	LineTo(hdc, X, Y - RadiusY);

	DeleteObject(Pen);
}

void FishBomb::Hide()
{
	Visible = false;
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255)); // белый цвет
	SelectObject(hdc, Pen);

	Ellipse(hdc, X - RadiusX, Y - RadiusX, X + RadiusX, Y + RadiusX);
	Ellipse(hdc, X - RadiusX / 5, Y - RadiusX / 5, X, Y);
	MoveToEx(hdc, X + RadiusX, Y, NULL);
	LineTo(hdc, X + RadiusX * 4 / 3, Y + RadiusY / 2);
	LineTo(hdc, X + RadiusX * 4 / 3, Y - RadiusY / 2);
	LineTo(hdc, X + RadiusX, Y);

	LineTo(hdc, X - RadiusX, Y);
	MoveToEx(hdc, X, Y + RadiusY, NULL);
	LineTo(hdc, X, Y - RadiusY);

	DeleteObject(Pen);
}

