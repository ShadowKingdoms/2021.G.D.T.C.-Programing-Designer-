#include <iostream>
using namespace std;

//��ü������: ������ ����� �𵨸��Ͽ� ���α׷��� �ϴ� ��. 
//�ڵ���: �Ӽ�(���ۿ����ؼ� ����Ǵ� ��-����)-�ӵ�, ���, ����(�Ӽ��� �����ϴ� ��ȣ�ۿ�-�Լ�)-�׼�, �극��ũ, ����
//���赵�� �ۼ��Ͽ�, �������� �ڵ����� �����ϴ� ��.
//Ŭ������ �ۼ��Ͽ�, �������� ��ü�� �����ϴ� ��.
//�̱���: 1���̻� ��ü�� ���������ʰ� ���� ����� ��.

class SingleObject
{
private: //�ٸ���ü�� ������ ��������ʴ� ���
	//����: ��ü�������� ����� ���� �����Ϸ� �˸��� ��.
	static SingleObject* m_pInstance; //�����ɹ�����: ��� ��ü���� �����Ǵ� �������. ��ü�� �����Ǳ����� ���ٰ����ϴ�.
	SingleObject() { cout << "SingleObject:" << this << endl; } //������: ��ü�� �����ɶ� ȣ��Ǵ� �Լ�.
	int m_nData; //�������: Ŭ�������� ����.
public: //���ü�� ���ٰ����� ���(���: Ŭ������ ������ ��� �Լ��� ����)
	~SingleObject() { cout << "~SingleObject:" << this << endl; } //�Ҹ���: ��ü�� �ı��ɶ� ȣ��Ǵ� �Լ�.
	static SingleObject* GetInstance() //��������Լ�: ��ü���� ����Լ��� ȣ���Ҽ��ִ� �Լ�.
	{
		cout << "GetInstance Start:" << endl;
		if (m_pInstance == NULL)
			m_pInstance = new SingleObject();
		cout << "GetInstance End:" << endl;
		return m_pInstance;
	}
	//����Լ�: Ŭ�����ȿ� �Լ�.
	void ShowMessage()
	{
		cout << this << " SingleObject ShowMSG[" << &m_nData << "]:" << m_nData << endl;
	}
	void Release()
	{
		delete m_pInstance;
	}
};
//������� ������ ��ü�� �����Ǳ������� �����Ǿ���ϹǷ�,
//���α׷��� ����ɶ����� �޸𸮰� �����Ǿ���Ѵ�.(��������)
//��������: ���α׷� ����ñ��� �޸𸮰� �����Ǵ� ����.
//����: �տ� �����Ѱ��� ������ ������ִ°���.
//Ÿ�� �Ҽ�Ŭ����::������
SingleObject* SingleObject::m_pInstance;

//�̱���: Ŭ������ �ν��Ͻ��� 1���̻� ���� �Ҽ����� Ŭ������ ����� ���.(������ ����,�������)
int main()
{
	//�����Ҵ�Ǵ��� �����Ѱ�?
	//�̱����� �ݵ�� ��ü�� 1�������ϹǷ�,
	//������ ���� ������ �����ϸ� �ȵȴ�. 
	//�׷��Ƿ�, private���� �����.
	//SingleObject cSingleObject[100]; //��ü������ �Ұ����ϴ�.
	//�����ʹ� ����� ���� �޸𸮰� �Ҵ�Ǵ� ���� �ƴϹǷ�,
	//�������� �����ȴٰ��ص� ��ü�� ������� �ƴϴ�.
	//�������� �޸𸮰� ����ٰ��ؼ� ����ų �޸𸮰� ������ ���� �ƴ�.
	SingleObject* pSingleObjectA = NULL;
	SingleObject* pArrSingleObjects[2] = {};
	//�����Ҵ��� �����Ѱ�?
	//�����Ҵ絵 ��ü�� �����Ҷ��� �����ڰ� public�̿��� �����ϴ�.
	//pSingleObjectA = new SingleObject();
	//��ü�� �������ε� �Ϲݸ���� �����ϴ°��� ��Ģ�����δ� �Ұ����ϳ�, �Լ��� ��ü ���������� �����Ҽ�������,
	//�޸𸮸� ����Ͽ� �����ϴµ��� ������ �����Ƿ� ������ �����ϴ�. ��, ��ü�� �Ϲݸ�������� ����Ϸ����Ѵٸ�, 
	//�Ϲ� ����� ��ü�� �����Ǳ����� ������ �Ұ����ϹǷ�, �����Ͽ����� ���Եȴ�.
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
	//�ν��Ͻ��� 1���̹Ƿ� ���� ������ �ҷ����ʿ�� ����.
	pSingleObjectA->Release();
}