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
			iterator* Next()
			{
				return pNext;
			}
			iterator* Prev()
			{
				return pPre;
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
			pEnd = new iterator(-1);
		}
		~list()
		{
			if (pEnd) delete pEnd;
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
			iterator* pPre = pEnd->pPre;
			pTemp->pPre = pPre;
			pTemp->pNext = pEnd;
			pEnd->pPre = pTemp;
			if(pPre) pPre->pNext = pTemp;
			if (pBegin == NULL) pBegin = pTemp;
		}
		iterator* insert(iterator* pFind, Type insert)
		{
			if (pFind != pEnd)
			{
				iterator* pInsert = new iterator(insert);
				iterator* pNext = pFind->pNext;
				iterator* pPre = pFind->pPre;
				pFind->pNext = pInsert;
				pNext->pPre = pInsert;
				pInsert->pPre = pFind;
				pInsert->pNext = pNext;
				return pInsert;
			}
			return pEnd;
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
		void clear()
		{
			iterator* pNode = pBegin;
			while (pNode != pEnd)
			{
				iterator* pNext = pNode->pNext;
				iterator* pPre = pNode->pPre;
				pNode = pNext;
				delete pPre;
			}
			pBegin = NULL;
		}
		void pop_back()
		{
			iterator* pDel = pEnd->pPre;
			iterator* pPre = pDel->pPre;
			iterator* pNext = pDel->pNext;
			pEnd->pPre = pPre;
			pPre->pNext = pNext;
			delete pDel;
		}
	private:
		iterator* pBegin;
		iterator* pEnd;
	};

	void ListTestMain()
	{
		list<int> container;
		container.push_back(10);
		container.push_back(20);
		container.push_back(30);
		container.push_back(40);
		container.push_back(50);
		
		list<int>::iterator* it = container.begin();//�ݺ���
		for (it = container.begin(); it != container.end(); it = it->Next())
			cout << it->data << ",";
		cout << endl;
		list<int>::iterator* pFind = container.begin();//10
		pFind = pFind->pNext;//20
		pFind = pFind->pNext;//30
		list<int>::iterator* pInsert = container.insert(pFind, 60);
		for (it = container.begin(); it != container.end(); it = it->Next())
			cout << it->data << ",";
		cout << endl;
		container.erase(pInsert);
		for (it = container.begin(); it != container.end(); it = it->Next())
			cout << it->data << ",";
		cout << endl;
		container.pop_back();
		container.push_back(70);
		for (it = container.begin(); it != container.end(); it = it->Next())
			cout << it->data << ",";
		cout << endl;
		container.clear();
		for (it = container.begin(); it != container.end(); it = it->Next())
			cout << it->data << ",";
		cout << endl;
	}

	void ListMain()
	{
		list<int> container(1);
		list<int>::iterator* it = container.begin();//�ݺ���
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
		container.clear();
	}

}