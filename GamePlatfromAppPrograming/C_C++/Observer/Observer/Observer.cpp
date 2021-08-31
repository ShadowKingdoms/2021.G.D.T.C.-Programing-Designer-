#include "Commender.h"
#include <vector>

void CommederMain()
{
	//Unit cUnit; //추상클래스는 객체화 할 수 없다.
	Commonder cCommonder;
	vector<Unit*> vecUnits;

	vecUnits.push_back(new Marin());//0
	vecUnits.push_back(new Marin());//1
	vecUnits.push_back(new Marin());//2
	vecUnits.push_back(new Marin());//3
	vecUnits.push_back(new Medic());//4
	vecUnits.push_back(new Medic());//5

	for (int i = 0; i < vecUnits.size(); i++)
		cCommonder.SelectUnit(vecUnits[i]);

	cCommonder.Move(10, 10);
	cCommonder.Deselect(vecUnits[3]);
	cCommonder.Attack(10, 10);

	for (int i = 0; i < vecUnits.size(); i++)
	{
		delete vecUnits[i];
	}
	vecUnits.clear();
}

void main()
{
	CommederMain();
}