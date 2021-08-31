#include "Commender.h"
#include  <iostream>
#include  <string>
#include  <algorithm>

Marin::Marin()
{
}
Marin::~Marin()
{
}
void Marin::Move(int x, int y)//클래스의 멤버함수의 정의
{
	cout << typeid(*this).name() << "::Move(" << x << "," << y << ")" << endl;
}
void Marin::Attack(int x, int y)
{
	cout << typeid(*this).name() << "::Attack(" << x << "," << y << ")" << endl;
}
Medic::Medic()
{
}
Medic::~Medic()
{
}
void Medic::Move(int x, int y)
{
	cout << typeid(*this).name() << "::Move(" << x << "," << y << ")" << endl;
}
void Medic::Attack(int x, int y)
{
	Move(x, y);
}
void Commonder::Move(int x, int y)
{
	list<Unit*>::iterator it = listUnitCollection.begin();
	for (; it != listUnitCollection.end(); it++)
	{
		Unit* pUnit = *it;
		pUnit->Move(x, y);
	}
}
void Commonder::Attack(int x, int y)
{
	list<Unit*>::iterator it = listUnitCollection.begin();
	for (; it != listUnitCollection.end(); it++)
	{
		Unit* pUnit = *it;
		pUnit->Attack(x, y);
	}
}