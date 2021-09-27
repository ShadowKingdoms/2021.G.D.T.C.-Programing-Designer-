/*##################################
이진트리(C언어 수업용)
파일명: BinaryTree.cpp
작성자 : 김홍규(downkhg@gmail.com)
마지막수정날짜 : 2018.04.03
버전 : 1.00
###################################*/
#include <stdio.h>

using namespace std;

struct SNode {
	int nData;
	SNode* pLeft;
	SNode* pRight;
};

SNode* CreateNode(int data)
{
	SNode* pTemp = new SNode;
	pTemp->nData = data;
	pTemp->pLeft = NULL;
	pTemp->pRight = NULL;
	return pTemp;
};
bool MakeLeft(SNode* pParent, SNode* pChild)
{
	if (pParent == NULL)
		return false;
	pParent->pLeft = pChild;
	return true;
};
bool MakeRight(SNode* pParent, SNode* pChild)
{
	if (pParent == NULL)
		return false;
	pParent->pRight = pChild;
	return true;
};

void Traverse(SNode* pNode)
{
	if (!pNode) return;
	//printf("%d\n", pNode->nData); //전위
	Traverse(pNode->pLeft);
	//printf("%d\n", pNode->nData); //중위
	Traverse(pNode->pRight);
	printf("%d\n", pNode->nData); //후위
}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void MinHipTreeInsert(SNode* pParent, SNode* pInsert)
{
	static int nCount = 0;
	if (pParent == NULL) return;
	printf("Level:%d\n", nCount);
	if (pParent->nData > pInsert->nData)
	{
		printf("Swap Parent\n");
		Swap(pParent->nData, pInsert->nData);

		MinHipTreeInsert(pParent, pInsert);
	}
	else
	{
		if (pParent->pLeft == NULL)
		{
			pParent->pLeft = pInsert;
			printf("MinHipTreeInsert_Left:%d\n", pInsert->nData);
			nCount = 0;
			return;
		}
		else if (pParent->pRight == NULL)
		{
			pParent->pRight = pInsert;
			printf("MinHipTreeInsert_Right:%d\n", pInsert->nData);
			nCount = 0;
			return;
		}
		else
		{
			nCount++;
			MinHipTreeInsert(pParent->pLeft, pInsert);
		}
	}
}

void Print(SNode* pSeed)
{
	Traverse(pSeed);
}

void HeapTreeMain()
{
	const int nSize = 5;
	SNode* pSeed;
	SNode* arrNodes[nSize];// = { CreateNode(10),CreateNode(50),CreateNode(30),CreateNode(20),CreateNode(40) };
	arrNodes[0] = CreateNode(10);
	arrNodes[1] = CreateNode(50);
	arrNodes[2] = CreateNode(30);
	arrNodes[3] = CreateNode(20);
	arrNodes[4] = CreateNode(40);
	/*for (int i = 0; i < nSize; i++)
	{
		arrNodes[i] = CreateNode((i + 1) * 10);
	}*/
	pSeed = arrNodes[0];
	for (int i = 1; i < nSize; i++)
	{
		MinHipTreeInsert(pSeed, arrNodes[i]);
	}

	Print(pSeed);
}

void BinaryTreeMain()
{
	SNode* pSeed = NULL;

	SNode* pParent = CreateNode(10);
	SNode* pLeft = CreateNode(20);
	SNode* pRight = CreateNode(30);
	SNode* pD = CreateNode(40);
	SNode* pE = CreateNode(50);

	MakeLeft(pParent, pLeft);
	MakeRight(pParent, pRight);

	MakeLeft(pLeft, pD);
	MakeRight(pLeft, pE);

	pSeed = pParent;

	Print(pSeed);
}

void main()
{
	//BinaryTreeMain();
	HeapTreeMain();
}