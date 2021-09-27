#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>

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

void SetMain()
{
	set<int> container;

	for (int i = 0; i < 7; i++)
	{
		container.insert((i + 1) * 10);
	}

	set<int>::iterator it = container.begin();
	for (; it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
}

void MapMain()
{
	map<int, string> container;

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

	map<int, string>::iterator it = container.begin();
	for (; it != container.end(); it++)
		cout << it->first << ":" << it->second << ",";
	cout << endl;
}

void main()
{

}