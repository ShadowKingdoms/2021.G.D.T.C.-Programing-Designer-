#pragma once
#include <iostream>
using namespace std;

namespace demo
{
	template <typename Type>
	class vector
	{
		Type* pArray;
		int nSize;
		void _resize(int size)//rellac은 메모리누수가 발생할수있으므로 직접 크기를 변경한다.
		{
			Type* pResizeArray = new Type[size];
			int nTypeSize = sizeof(*pArray);
			int nMemResize = size * nTypeSize;
			int nMemSize = nSize * nTypeSize;
			memset(pResizeArray,0, nMemResize);
			memcpy_s(pResizeArray, nMemResize, pArray, nMemSize);
			delete[]  pArray;
			pArray = pResizeArray;
			nSize = size;
		}
	public: 
		vector(int size = 0)
		{
			nSize = size;
			pArray = new Type[nSize];// (void*)allocator(nSize * sizeof(*pArray));
		}
		int size()
		{
			return nSize;
		}
		void resize(int size)
		{
			_resize(size);
		}
		Type& operator[](int idx)
		{
			return *(pArray + idx);
		}
		void push_back(Type data)
		{
			nSize++;
			_resize(nSize);
			*(pArray + (nSize - 1)) = data;
		}
		Type insert(int idx, Type insert)
		{
			nSize++;
			//pArray = (void*)realloc(nSize * sizeof(Type));
			_resize(nSize);
			//5 //3 //6 //0,1,2,3,4,- // //0,1,2,6,3,4
			int nStartCopyIdx = idx;
			int nEndCopyIdx = nSize - 1;
			int nCopySize = nEndCopyIdx - nStartCopyIdx;
			int nStartOriginIdx = nStartCopyIdx +1;
			int nEndOriginIdx = nSize;
			int nOriginSize = nEndOriginIdx - nStartOriginIdx;
			int nTypeSize = sizeof(*pArray);
			//cout <<"["<< nStartCopyIdx << "](dst)" << nCopySize << ":" << *(pArray + nStartCopyIdx) << endl;
			//cout << "[" << nStartOriginIdx << "](src)" << nOriginSize << ":" << *(pArray + nStartOriginIdx) << endl;
			memcpy_s(pArray + nStartOriginIdx, nOriginSize * nTypeSize, pArray + nStartCopyIdx, nCopySize * nTypeSize);
			*(pArray + idx) = insert;
			return insert;
		}
		int erase(Type idx)
		{
			int nStartCopyIdx = idx+2;
			int nEndCopyIdx = nSize;
			int nCopySize = nEndCopyIdx - nStartCopyIdx;
			int nStartOriginIdx = idx;
			int nEndOriginIdx = nSize-2;
			int nOriginSize = nEndOriginIdx - nStartOriginIdx;
			int nTypeSize = sizeof(*pArray);
			//cout << nStartCopyIdx <<"(dst)"<< nCopySize <<":"<< *(pArray + nStartCopyIdx) << endl;
			//cout << nStartOriginIdx <<"(src)"<<nOriginSize<<":"<< *(pArray + nStartOriginIdx) << endl;
			memcpy_s(pArray + nStartOriginIdx, nOriginSize * nTypeSize, pArray + nStartCopyIdx, nCopySize * nTypeSize);
			nSize--;
			_resize(nSize);
			return idx;
		}
		void pop_back()
		{
			nSize--;
			_resize(nSize);
			//pArray = (Type*)realloc(pArray, nSize * sizeof(Type));
		}
	public:

	};

	void VectorSampleTestMain()
	{
		int nSize = 5;
		vector<int> vec(nSize);
		for (int i = 0; i < vec.size(); i++) vec[i] = i;
		for (int i = 0; i < vec.size(); i++) cout << vec[i] << ","; cout << endl;
		vec.resize(6);
		cout << "resize:";  for(int i = 0; i < vec.size(); i++) cout << vec[i] << ","; cout << endl;
		vec.push_back(5);
		cout << "push_back:"; for(int i = 0; i < vec.size(); i++) cout << vec[i] << ","; cout << endl;
		vec.insert(3, 6);
		cout << "insert:"; for(int i = 0; i < vec.size(); i++) cout << vec[i] << ","; cout << endl;
		vec.erase(2);
		cout << "erase:"; for(int i = 0; i < vec.size(); i++) cout << vec[i] << ","; cout << endl;
		vec.pop_back();
		cout << "pop_back:"; for (int i = 0; i < vec.size(); i++) cout << vec[i] << ","; cout << endl;
	}

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
		
		container.erase(0);
		container.pop_back();
		for (int i = 0; i < container.size(); i++)
			cout << container[i] << ",";
		cout << endl;
	}
}