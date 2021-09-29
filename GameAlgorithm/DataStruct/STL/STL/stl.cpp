#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

void PriorityQuequeMain()
{
	priority_queue<int> container;

	container.push(10);
	container.push(50);
	container.push(20);
	container.push(30);
	container.push(60);

	while (container.empty() == false)
	{
		cout << container.top() << endl;
		container.pop();
	}
}
//O(log(n))
//레드블랙이진트리: 순서X -> 빠르게 자료구조를 찾을수있다.
void SetMain()
{
	set<int> container;

	for (int i = 0; i < 7; i++)
	{
		container.insert((i + 1) * 10);
	}

	container.find(70);

	set<int>::iterator it = container.begin();
	for (; it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
}

//void MapMain()
//{
//	map<int, string> container;
//
//	container[0] = "Zero";
//	container[1] = "One";
//	container[2] = "Two";
//	container[3] = "Three";
//	container[4] = "Four";
//	container[5] = "Five";
//	container[6] = "Six";
//
//	for (int i = 0; i < container.size(); i++)
//	{
//		cout << i << ":" << container[i] << ",";
//	}
//	cout << endl;
//
//	map<int, string>::iterator it = container.begin();
//	for (; it != container.end(); it++)
//		cout << it->first << ":" << it->second << ",";
//	cout << endl;
//}
//맵: 키값을 이용하여 자료를 찾을수 있음.
//셋과 같은자료구조지만 키값을 가짐.
void MapMain()
{
	map<string, int> container;
	string strNumber[] = { "Zero","One","Two" ,"Three","Four","Five","Six" };

	container["Zero"] = 0;
	container["One"] = 1;
	container["Two"] = 2;
	container["Three"] = 3;
	container["Four"] = 4;
	container["Five"] = 5;
	container["Six"] = 6;

	for (int i = 0; i < container.size(); i++)
	{
		cout << i << ":" << container[strNumber[i]] << ",";
	}
	cout << endl;

	map<string, int>::iterator it = container.begin();
	for (; it != container.end(); it++)
		cout << it->first << ":" << it->second << ",";
	cout << endl;
}
//해시테이블: 해시함수를 이용하여 찾기에 O(1)의 성능을 가진다.
void HashMapMin()
{
	unordered_map<int, string> container;
	
	container[0] = "Zero";
	container[1] = "One";
	container[2] = "Two";
	container[3] = "Three";
	container[4] = "Four";
	container[5] = "Five";
	container[6] = "Six";
	
	for (int i = 0; i < container.size(); i++)
	{
		cout << i << ":" << container[i] << ",";
	}
	cout << endl;
	
	unordered_map<int, string>::iterator it = container.begin();
	for (; it != container.end(); it++)
		cout << it->first << ":" << it->second << ",";
	cout << endl;
}


void main()
{
	//PriorityQuequeMain();
	//SetMain();
	MapMain();
}