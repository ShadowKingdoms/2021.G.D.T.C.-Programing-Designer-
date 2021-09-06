#pragma once
#include <iostream>
using namespace std;

namespace demo
{
	template <typename Type>
	class list
	{
		int nSize = 0;
	public :
		class iterator
		{
		public:
			Type data;
			iterator* pPre;
			iterator* pNext;
			iterator(Type data = 0)
			{
				this->data = data;
				pNext = NULL;
				pPre = NULL;
			}
			Type operator=(Type data)
			{
				return data;
			}
			/*bool operator==(iterator& it)
			{
				return data == it.data;
			}
			bool operator!=(iterator& it)
			{
				return  data != it.data;;
			}*/
			Type operator*()
			{
				return data;
			}
			friend ostream& operator<<(ostream& os, iterator& it)
			{
				os << it.data;
				return os;
			}
		};
	public:
		list(int size = 0)
		{
			for (int i = 0; i < size; i++)
				push_back(0);
			nSize = size;
		}
		int size()
		{
			return nSize;
		}
		void resize(int size)
		{
			for (int i = nSize; i < size; i++)
				push_back(0);
			nSize = size;
		}
		iterator* begin()
		{
			return pBegin;
		}
		iterator* end()
		{
			return pEnd;
		}
		void push_back(Type data)
		{
			iterator* pTemp = new iterator(data);
			if(pEnd) pEnd->pNext = pTemp;
			pTemp->pPre = pEnd;
			pEnd = pTemp;
			if (pBegin == NULL) pBegin = pEnd;
		}
		iterator* insert(iterator* it, Type insert)
		{
			iterator* pInsert = new iterator(insert);
			pInsert->pNext = it->pNext;
			pInsert->pPre = it->pPre;
			return pInsert;
		}
		iterator* erase(iterator* it)
		{
			iterator* pNext = it->pNext;
			iterator* pPre = it->pPre;
			pNext->pPre = pPre;
			pPre->pNext = pNext;
			delete it;
			return NULL;
		}
		void pop_back()
		{
			iterator* pDel = pEnd;
			iterator* pPre = pDel->pPre;
			pEnd = pPre;
			pPre->pNext = NULL;
			delete pDel;
		}
	private:
		iterator* pBegin;
		iterator* pEnd;
	};

	void ListMain()
	{
		list<int> container(1);
		list<int>::iterator* it = container.begin();//반복자
		*it = 10;
		for (it = container.begin(); it != container.end(); it++)
			cout << *it << ",";
		cout << endl;
		container.resize(3);
		for (it = container.begin(); it != container.end(); it++)
			cout << *it << ",";
		cout << endl;
		container.push_back(99);
		it = container.begin();//반복자
		it++; it++;//연결리스트이므로 순서대로 원하는 값에 접근해야한다.
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

}