#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <string>

//using namespace std;
#include"DynamicArray.h"
#include"LinkedList.h"
//#include"QueueList.h"
#include"StackArray.h"
//using namespace demo;
using namespace std;

//�ڷᱸ�����̺귯
//����: �����迭 <-> List(�÷���) �������÷��̾�
//1.������ ũ�⸦ 1�� �����, ù��°���� 10�� �ʱ�ȭ�ϰ� ���.
//2.ũ�⸦ 3���θ���� ���
//3.�߰�: �����͸� �߰�
//4.����: �߰��� �����͸� �߰�
//5.����,��λ���
//6.�� �˰����� ��� �����۵�Ȯ���ϱ�.
void VectorMain()
{
	vector<int> container(1);
	container[0] = 10;
	for (int i = 0; i < container.size(); i++)
		cout << container[i] << ",";
	cout << endl;
	container.resize(3);
	for (int i = 0; i < container.size(); i++)
		cout << container[i] << ",";
	cout << endl;
	container.push_back(99);
	vector<int>::iterator it = container.begin();//�ݺ���
	container.insert(it+2, 88);
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	it = container.end();
	container.erase(it-2);
	container.pop_back();
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
}
//����Ʈ: ���߿��Ḯ��Ʈ <-> LinkedList(�÷���) ����������
void ListMain()
{
	list<int> container(1);
	list<int>::iterator it = container.begin();//�ݺ���
	*it = 10;
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	container.resize(3);
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	container.push_back(99);
	it = container.begin();//�ݺ���
	it++; it++;//���Ḯ��Ʈ�̹Ƿ� ������� ���ϴ� ���� �����ؾ��Ѵ�.
	container.insert(it, 88);
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	it = container.end();
	it--; it--;
	container.erase(it);
	container.pop_back();
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
}
//ť: ���Լ���
//���ڿ��� ������� �ְ�, ������� ť�� ������ �ִ´�.
void QuequeMain()
{
	char strName[] = "GDTC2021-1";
	queue<char> queString;
	cout << "Origin:" << strName << endl;
	char* pStr = strName;
	while (*pStr != '\0')
	{
		char cData = *pStr;
		queString.push(cData);
		cout << cData << endl;
		pStr++;
	}
	pStr = strName;
	while (!queString.empty())
	{
		*pStr = queString.front();
		queString.pop();
		pStr++;
	}
	cout << "Result:"<< strName << endl;
}
//����: ��������
//���ڿ��� ���ʷ� �ְ�, �ڿ��� ������.(������)
void StackMain()
{
	char strName[] = "GDTC2021-1";
	stack<char> queString;
	cout << "Origin:" << strName << endl;
	char* pStr = strName;
	while (*pStr != '\0')
	{
		char cData = *pStr;
		queString.push(cData);
		cout << cData << endl;
		pStr++;
	}
	pStr = strName;
	while (!queString.empty())
	{
		*pStr = queString.top();
		queString.pop();
		pStr++;
	}
	cout << "Result:" << strName << endl;
}

void main()
{
	//VectorMain();
	//demo::VectorSampleTestMain();
	//demo::VectorMain();
	//demo::ListMain();
	//demo::ListTestMain();
	//ListMain();
	//QuequeMain();
	//StackMain();
	demo::StackMain();
}