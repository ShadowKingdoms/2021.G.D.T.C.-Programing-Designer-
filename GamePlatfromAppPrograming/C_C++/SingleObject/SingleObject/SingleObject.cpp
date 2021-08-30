#include <iostream>
using namespace std;

//객체지향언어: 현실의 대상을 모델링하여 프로그래밍 하는 것. 
//자동차: 속성(동작에의해서 변경되는 값-변수)-속도, 기어, 동작(속성을 변경하는 상호작용-함수)-액셀, 브레이크, 기어변경
//설계도를 작성하여, 여러대의 자동차를 생성하는 것.
//클래스를 작성하여, 여러개의 객체를 생성하는 것.
//싱글톤: 1개이상 객체를 생성되지않게 강제 만드는 것.

class SingleObject
{
private: //다른객체의 접근을 허용하지않는 멤버
	//선언: 실체가없지만 사용할 것을 컴파일러 알리는 것.
	static SingleObject* m_pInstance; //정적맴버변수: 모든 객체에서 공유되는 멤버변수. 객체가 생성되기전에 접근가능하다.
	SingleObject() { cout << "SingleObject:" << this << endl; } //생성자: 객체가 생성될때 호출되는 함수.
	int m_nData; //멤버변수: 클래스안의 변수.
public: //어떤객체든 접근가능한 멤버(멤버: 클래스가 가지는 모든 함수나 변수)
	~SingleObject() { cout << "~SingleObject:" << this << endl; } //소멸자: 객체가 파괴될때 호출되는 함수.
	static SingleObject* GetInstance() //정적멤버함수: 객체없이 멤버함수를 호출할수있는 함수.
	{
		cout << "GetInstance Start:" << endl;
		if (m_pInstance == NULL)
			m_pInstance = new SingleObject();
		cout << "GetInstance End:" << endl;
		return m_pInstance;
	}
	//멤버함수: 클래스안에 함수.
	void ShowMessage()
	{
		cout << this << " SingleObject ShowMSG[" << &m_nData << "]:" << m_nData << endl;
	}
	void Release()
	{
		delete m_pInstance;
	}
};
//정적멤버 변수는 객체가 생성되기전부터 생성되어야하므로,
//프로그램이 종료될때까지 메모리가 유지되어야한다.(전역변수)
//전역변수: 프로그램 종료시까지 메모리가 유지되는 변수.
//정의: 앞에 선언한것을 실제로 만들어주는과정.
//타입 소속클래스::변수명
SingleObject* SingleObject::m_pInstance;

//싱글톤: 클래스의 인스턴스가 1개이상 존재 할수없는 클래스를 만드는 기법.(생성자 은닉,정적멤버)
int main()
{
	//정적할당되는지 가능한가?
	//싱글톤은 반드시 객체가 1개여야하므로,
	//다음과 같은 생성이 가능하면 안된다. 
	//그러므로, private으로 만든다.
	//SingleObject cSingleObject[100]; //객체성성이 불가능하다.
	//포인터는 대상을 직접 메모리가 할당되는 것이 아니므로,
	//여러개가 생성된다고해도 객체가 생긴것은 아니다.
	//포인터의 메모리가 생긴다고해서 가르킬 메모리가 생성된 것은 아님.
	SingleObject* pSingleObjectA = NULL;
	SingleObject* pArrSingleObjects[2] = {};
	//동적할당은 가능한가?
	//동적할당도 객체를 생성할때는 생성자가 public이여만 가능하다.
	//pSingleObjectA = new SingleObject();
	//객체가 생성전인데 일반멤버에 접근하는것은 원칙적으로는 불가능하나, 함수는 객체 생성전부터 존재할수있으며,
	//메모리를 사용하여 접근하는데는 지장이 없으므로 실행이 가능하다. 단, 객체가 일반멤버변수를 출력하려고한다면, 
	//일반 멤버는 객체가 생성되기전에 접근이 불가능하므로, 컴파일오류가 나게된다.
	//pSingleObjectA->ShowMessage(); 
	pSingleObjectA = SingleObject::GetInstance();
	pSingleObjectA->ShowMessage();
	for (int i = 0; i < 2; i++)
		pArrSingleObjects[i] = SingleObject::GetInstance();

	cout << "pSingleObjectA:" << pSingleObjectA << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "pSingleObject[" << i << "]:" << pArrSingleObjects[i] << endl;
		pArrSingleObjects[i]->ShowMessage();
	}
	//인스턴스가 1개이므로 굳이 여러번 불러줄필요는 없다.
	pSingleObjectA->Release();
}