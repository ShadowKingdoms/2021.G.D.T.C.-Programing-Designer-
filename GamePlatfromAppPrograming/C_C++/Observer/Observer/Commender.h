#pragma once
#include  <list>
//��������� �̿��Ͽ� �������̽��� �����Ѵ�.
class Unit; //Ŭ������ ����

using namespace std;

//�߻�Ŭ����: ���������Լ��� 1���̻� �����Լ�. ��üȭ�� �Ҽ�����.
class Unit //Ŭ������ ����
{
	int x;
	int y;
public:
	virtual void Move(int x, int y) = 0; //���������Լ�: ��ӹ��� �ڽ�Ŭ�������� �ݵ�� �����ؾ��ϴ� �������
	virtual void Attack(int x, int y) = 0;
};
//�߻�Ŭ������ ��ӹ��� ��ü�� �ݵ�� �Լ��� �����ؾ��ϹǷ�, 
//�������� ����ϴ� ����� �����ϵ��� ���� �� �� �ִ� �����̴�.
//��üȭ�� ��밡���� ���·� ����⶧���� ��ӹ����� ����� �߰��� ������ �ؾ��Ѵ�.
class Marin : public Unit //��üȭ: �߻�Ŭ������ ��ӹ޾� ����Ҽ� �ִ� Ŭ������ ����°�.
{
public:
	Marin();
	~Marin();
	void Move(int x, int y) override; //Ŭ���� ����Լ��� ����
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
