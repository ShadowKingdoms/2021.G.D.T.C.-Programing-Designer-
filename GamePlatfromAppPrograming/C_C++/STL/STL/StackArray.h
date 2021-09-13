#pragma once

#define SIZE 20

//using namespace std;

namespace demo
{
	template<typename Type> 
	class stack
	{
		Type stackArray[SIZE];
		int nCurIdx = 0;
		int nTopIdx = -1;
	public:
		void push(Type data)
		{
			stackArray[nCurIdx] = data;
			nCurIdx++; //1
			nTopIdx++; //0
		}
		Type top()
		{
			return stackArray[nTopIdx];
		}
		void pop()
		{
			stackArray[nCurIdx] = 0;
			nCurIdx--;
			nTopIdx--;
		}
		bool empty()
		{
			if (nTopIdx == -1) return true;
			else return false;
		}
	};
	extern void StackMain();
}