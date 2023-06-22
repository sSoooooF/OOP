#pragma once




/*-----------------------------------*/
/*         ����� Location            */
/*-----------------------------------*/

class Location
{
protected:
	int X;	// ���������� �
	int Y;	// ���������� �

public:
	Location(int InitX, int InitY);		// ����������
	~Location();	// ����������

	int GetX();		// �������� ���������� �
	int GetY();		// �������� ��������� �
}; // end class Location


class Interface
{
public:
	virtual void Hide() = 0;
	virtual void Show() = 0;

	virtual void showBody() = 0;
	virtual void showTail() = 0;
	virtual void showEye() = 0;
	virtual void hideBody() = 0;
	virtual void hideTail() = 0;
	virtual void hideEye() = 0;
}; // end class Interface


/*-----------------------------------*/
/*         ����� Point	             */
/*-----------------------------------*/

class Point : public Location		// ������������ �� ������ Location
{
protected:
	bool Visible;	// ��������� �����

public:
	Point(int InitX, int InitY);	// �����������
	virtual ~Point();	// ����������� ����������

	virtual void Show();	// �������� �����
	virtual void Hide();	// ������ �����

	bool isVisible();		// ����� �� �����?
}; // end class Point


/*-----------------------------------*/
/*         ����� Object	             */
/*-----------------------------------*/

class Object : public Point // наслледуется от Point
{
protected:
	int RadiusX; // радиус по У
	int RadiusY; // радиус по Х
	int id; // ид функции
public:
	Object(int InitX, int InitY, int InitRadiusX, int InitRadiusY); // конструктор
	~Object(); // деструктор

	int GetRadiusX(); // получить радиус по Y 
	int GetRadiusY(); // получить радиус по X
	int GetId(); // получить id

	void MoveTo(int newX, int newY);

};

/*-----------------------------------*/
/*         ����� PlayerObject	     */
/*-----------------------------------*/


class PlayerObject : public Object, public Interface // наследуется от Object
{
protected:
	int baseX; // базовая координата Х
	int baseY; // базовая координата У
	bool Side = false;	// сторона по стандарту - влево
public:
	PlayerObject(int InitX, int InitY, int InitRadiusX, int InitRadiusY); // коструктор
	~PlayerObject(); // деструктор

	void ChangeRadius(int NewRadiusX, int NewRadiusY); // изменить радиус
	void ChangeSide(int newSide); // изменить сторону

	void Hide();
	void Show();

	virtual void showBody() = 0;
	virtual void showTail() = 0;
	virtual void showEye() = 0;
	virtual void hideBody() = 0;
	virtual void hideTail() = 0;
	virtual void hideEye() = 0;

	void MoveTo(int NewX, int NewY);
};


/*-----------------------------------*/
/*         ����� Fish			     */
/*-----------------------------------*/

class Fish : public PlayerObject	// ������������ �� ������ Point и Interface
{
public:
	Fish(int InitX, int InitY, int InitRadiusX, int InitRadiusY); // конструктор
	~Fish(); // деструктор
}; // end class Fish


/*-----------------------------------*/
/*         ����� FishWE			     */
/*-----------------------------------*/

class FishWE : public Fish // наследуется от Fish
{
public:
	FishWE(int InitX, int InitY, int InitRadiusX, int InitRadiusY); // конструктор
	~FishWE(); // деструктор

	virtual void showBody();
	virtual void showTail();
	virtual void showEye();
	virtual void hideBody();
	virtual void hideTail();
	virtual void hideEye();
}; // end class FishWE


class JustFish : public FishWE
{
public:
	JustFish(int InitX, int InitY, int InitRadiusX, int InitRadiusY);
	~JustFish();

	virtual void showBody();
	virtual void showTail();
	virtual void showEye();
	virtual void hideBody();
	virtual void hideTail();
	virtual void hideEye();
};
/*-----------------------------------*/
/*         ����� BigFishWE		     */
/*-----------------------------------*/

class BigFishWE : public FishWE // наследование от FishWE
{
public:
	BigFishWE(int InitX, int InitY, int InitRadiusX, int InitRadiusY); // конструктор
	~BigFishWE(); // деструктор
}; // end class BigFishWE


/*-----------------------------------*/
/*         ����� DamagedFishWE	     */
/*-----------------------------------*/

class DamagedFishWE : public FishWE // наследование от FishWE
{
public:
	DamagedFishWE(int InitX, int InitY, int InitRadiusX, int InitRadiusY); // конструктор
	~DamagedFishWE(); // деструктор

	virtual void showBody();
	virtual void showTail();
	virtual void showEye();
	virtual void hideBody();
	virtual void hideTail();
	virtual void hideEye();
}; // end class DamagedFishWe


/*-----------------------------------*/
/*         ����� DamagedBigFishWE    */
/*-----------------------------------*/

class DamagedBigFishWE : public DamagedFishWE // наследование от BigFishWE
{
public:
	DamagedBigFishWE(int InitX, int InitY, int InitRadiusX, int InitRadiusY); // конструктор
	~DamagedBigFishWE(); // деструктор
}; // end class DamagedBigFishWE



/*-----------------------------------*/
/*   класс DoubleDamagedBigFishWE    */
/*-----------------------------------*/

class DoubleDamagedBigFishWE : public DamagedBigFishWE
{
public:
	DoubleDamagedBigFishWE(int InitX, int InitY, int InitRadiusX, int InitRadiusY);
	~DoubleDamagedBigFishWE();

	void showBody();
	void hideBody();
};


/*-----------------------------------*/
/*         ����� DeadFishWEq	     */
/*-----------------------------------*/

class DeadFishWE : public DamagedFishWE // наследование от DamagedFishWE
{
public:
	DeadFishWE(int InitX, int InitY, int InitRadiusX, int InitRadiusY); // конструктор
	~DeadFishWE(); // деструктор

	virtual void showBody();
	virtual void showTail();
	virtual void showEye();
	virtual void hideBody();
	virtual void hideTail();
	virtual void hideEye();
}; // end class DeadFishWe


/*-----------------------------------*/
/*         ����� DeadBigFishWE	     */
/*-----------------------------------*/

class DeadBigFishWE : public DeadFishWE // наследование от DamagedBigFishWE
{
public:
	DeadBigFishWE(int InitX, int InitY, int InitRadiusX, int InitRadiusY); // конструктор
	~DeadBigFishWE(); // деструктор
}; // end class DeadBigFishWE





/*-----------------------------------*/
/*         ����� CircleFish		     */
/*-----------------------------------*/

class CircleFish : public Object	// ������������ �� ������ Object
{
public:
	CircleFish(int InitX, int InitY, int InitRadius);	// �����������
	~CircleFish();		// ����������

	void Show();		// �������� �����
	void Hide();		// �������� �����
}; // end class CircleFish

class DamagedCircleFish : public CircleFish // наследование от CircleFish
{
public:
	DamagedCircleFish(int InitX, int InitY, int InitRadius); // конструктор
	~DamagedCircleFish(); // деструктор

	void Show(); // показать
	void Hide(); // спрятать
};

/*-----------------------------------*/
/*         ����� Bomb			     */
/*-----------------------------------*/

class Bomb : public Object // наследование от Object
{
public:
	Bomb(int InitX, int InitY, int InitRadius);	// �����������
	~Bomb();		// ����������

	void Show();	// �������� �����
	void Hide();	// �������� �����
}; // end class Bomb



/*-----------------------------------*/
/*         Класс FishBomb			 */
/*-----------------------------------*/

class FishBomb : public Bomb
{

public:
	FishBomb(int InitX, int InitY, int InitRadius);
	~FishBomb();

	void Show();
	void Hide();
};


/*-----------------------------------*/
/*         Класс Herb			     */
/*-----------------------------------*/

class Herb : public Object // ����������� �� class Object
{
public:
	Herb(int InitX, int InitY); // �����������
	~Herb(); // ����������

	void Show(); // �������� ���������
	void Hide(); // �������� ���������
}; // end class Herb


