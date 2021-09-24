#pragma once
#include <list>
#include <iostream>
using namespace std;
namespace demo
{
	class queue
	{
		std::list<char>  queueList;
	public:
		void push(char data)
		{
			queueList.push_back(data);
		}
		char front()
		{
			return queueList.front();
		}
		void pop()
		{
			queueList.pop_front();
		}
		bool empty()
		{
			if (queueList.size() == 0)
				return true;
			else
				return false;
		}
	};

	extern void QuequeMain();
}