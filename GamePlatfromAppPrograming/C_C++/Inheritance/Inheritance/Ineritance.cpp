#include <iostream>
#include <vector>
using namespace std;

class Effect
{
public:
	Effect() { cout << typeid(*this).name() << endl; }
	~Effect() { cout << typeid(*this).name() << endl; }
	void Use()
	{
		cout << typeid(*this).name() << "::" << "Use()" << endl;
	}
};

class SuperModeEffect : public Effect
{
public:
	SuperModeEffect() { cout << typeid(*this).name() << endl; }
	~SuperModeEffect() { cout << typeid(*this).name() << endl; }
	void Use()
	{
		cout << typeid(*this).name() << "::" << "Use()" << endl;
	}
};

class RecoveryEffect : public Effect
{
public:
	RecoveryEffect() { cout << typeid(*this).name() << endl; }
	~RecoveryEffect() { cout << typeid(*this).name() << endl; }
	void Use()
	{
		cout << typeid(*this).name() << "::" << "Use()" << endl;
	}
};

class Gun {};

class BulletEffect : public Effect
{
	Gun* m_pGun = NULL;
public:
	BulletEffect() { cout << typeid(*this).name() << endl; }
	~BulletEffect() { cout << typeid(*this).name() << endl; }
	void Init(Gun* pGun) { m_pGun = pGun; }
	void Use()
	{
		cout << typeid(*this).name() << "::" << "Use()" << endl;
	}
};

class LaserEffect : public Effect
{
	Gun* m_pGun = NULL;
public:
	LaserEffect() { cout << typeid(*this).name() << endl; }
	~LaserEffect() { cout << typeid(*this).name() << endl; }
	void Init(Gun* pGun) { m_pGun = pGun; }
	void Use()
	{
		cout << typeid(*this).name() << "::" << "Use()" << endl;
	}
};

class EffectManager
{
	vector<Effect*> m_listItemData;
public:
	Effect* GetEffect(int idx)
	{
		return m_listItemData[idx];
	}
	void SetEffect(Effect* pEffect)
	{
		m_listItemData.push_back(pEffect);
	}
	void Init()
	{
		m_listItemData.resize(EffectFucntion::MAX);
		m_listItemData[0] = new SuperModeEffect();
		m_listItemData[1] = new RecoveryEffect();
		m_listItemData[2] = new BulletEffect();
		m_listItemData[3] = new LaserEffect();
	}

	void Release()
	{
		for (int i = 0; i < m_listItemData.size(); i++)
			delete m_listItemData[i];
		m_listItemData.clear();
	}

	enum EffectFucntion { SUPER_MODE, RECOVERY, BULLET, LASER, GRENADE, MAX };
};

class ItemData
{
	string m_strName;
	string m_strCommet;
	Effect* m_pEffect;
public:
	ItemData(const char* name, const char* comment, Effect* pEffect)
	{
		m_strName = name;
		m_strCommet = comment;
		m_pEffect = pEffect;
	}
};

class ItemDataMnager
{
	vector<ItemData> m_listItemData;
public:

	ItemData GetItemData(int idx)
	{
		return m_listItemData[idx];
	}
	void SetItemData(ItemData itemdata)
	{
		m_listItemData.push_back(itemdata);
	}
	void Init(EffectManager* const pEffectManager)
	{
		m_listItemData.resize(E_ITEMDATA::MAX);
		m_listItemData[0] = ItemData("무적", "일정시간동안 데미지를 받지않는다.", pEffectManager->GetEffect(EffectManager::SUPER_MODE));
		m_listItemData[1] = ItemData("체리", "체력을 모두 회복한다.", pEffectManager->GetEffect(EffectManager::SUPER_MODE));
		m_listItemData[2] = ItemData("총알", "총알을 1개씩 발사한다.", pEffectManager->GetEffect(EffectManager::SUPER_MODE));
		m_listItemData[3] = ItemData("레이저", "직선상에 적에게 일정주기마다 데미지를 준다.", pEffectManager->GetEffect(EffectManager::SUPER_MODE));
	}
	void Release()
	{
		m_listItemData.clear();
	}
	enum E_ITEMDATA { SUPER_MODE, CHERRY, BULLET, LASER, GRENADE, MAX };
};

void ItemSimulationMain()
{

}

void main()
{

}