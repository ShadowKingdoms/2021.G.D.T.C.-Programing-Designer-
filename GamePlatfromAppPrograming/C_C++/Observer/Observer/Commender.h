#pragma once
#include  <list>
//헤더파일을 이용하여 인터페이스만 제공한다.
class Unit; //클래스의 선언

using namespace std;

//추상클래스: 순수가상함수를 1개이상 가진함수. 객체화를 할수없다.
class Unit //클래스의 정의
{
	int x;
	int y;
public:
	virtual void Move(int x, int y) = 0; //순수가상함수: 상속받은 자식클래스에서 반드시 정의해야하는 멤버변수
	virtual void Attack(int x, int y) = 0;
};
//추상클래스를 상속받은 객체는 반드시 함수를 구현해야하므로, 
//공통으로 사용하는 기능을 정의하도록 강제 할 수 있는 문법이다.
//실체화는 사용가능한 상태로 만들기때문에 상속받지만 멤버가 추가가 없더라도 해야한다.
class Marin : public Unit //실체화: 추상클래스를 상속받아 사용할수 있는 클래스로 만드는것.
{
public:
	Marin();
	~Marin();
	void Move(int x, int y) override; //클래스 멤버함수의 선언
	void Attack(int, int y) override;
private:

};

class Medic : public Unit
{
public:
	Medic();
	~Medic();
	void Move(int x, int y) override;
	void Attack(int x, int y) override;
private:

};

class Commonder
{
	list<Unit*> listUnitCollection;
public:
	void SelectUnit(Unit* pUnit)
	{
		listUnitCollection.push_back(pUnit);
	}
	void Deselect(Unit* pUnit)
	{
		listUnitCollection.remove(pUnit);
	}
	void Move(int x, int y);
	void Attack(int x, int y);
};
