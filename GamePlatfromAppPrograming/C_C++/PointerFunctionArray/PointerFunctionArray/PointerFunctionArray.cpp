#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void OpMain()
{
	printf("OpMain\n");
}

void PointerBasicMain()
{
	printf("PointerBasicMain\n");
}

void ArrayMain()
{
	const int nSize = 4;
	int arrScores[nSize];
	int arrSize = sizeof(arrScores) / sizeof(arrScores[0]);
	for (int i = 0; i < nSize; i++)
		arrScores[i] = 100 - i * 10;
	printf("Scores[%d]%d:", arrScores,&arrScores);
	for (int i = 0; i < nSize; i++)
		printf("[%d]%d,", i, arrScores[i]);
	printf("\n");
	for (int i = 0; i < nSize; i++)
		printf("[%d/%d]%d,", i, arrScores + i, *(arrScores + i));
	printf("\n");
	int* pArrScores = arrScores;
	for (int i = 0; i < nSize; i++)
		printf("[%d/%d]%d,", i, pArrScores++, *pArrScores);
	printf("\n");
	int arrCopyScore[nSize];
	//arrCopyScore = arrScores; //�迭���̸��� �����Ͱ� �ƴϴ�.
	printf("arrScore:%d/%d\n",arrCopyScore,arrScores);
	for (int i = 0; i < nSize; i++)
		arrCopyScore[i] = arrScores[i];
	memcpy(arrCopyScore, arrScores, sizeof(arrScores));
}

void FunctionPtrMain()
{
	void (*pfn)();
	pfn = ArrayMain;
	pfn();
	pfn = OpMain;
	pfn();
	pfn = PointerBasicMain;
	pfn();
}

//�����Ҵ�: ���α׷��� �����Ͻÿ� �޸𸮸� �Ҵ��� �����Ǵ� ��.
//�ڵ��ۼ��ÿ� ����(�޸��� �̸�)�� �ο��Ͽ� �����ϴ°�.
//
//�����Ҵ�: ���α׷� �����߿� �޸𸮸� �Ҵ��ϴ� ��.
//�����߿� �޸𸮰� �Ҵ�ÿ��� �̸��� �ٿ��ټ������Ƿ� �ּҰ��� ����ؾ��Ѵ�.
//void������: Ÿ���� ������������ �޸��� �ּҰ��� �����ϴ� ����.
//�����Ҵ�ÿ� �ּҰ��� �����ؾ��ϹǷ� �����Ͱ� �ʿ��ϴ�.
void DynamicAllocateMain()
{
	int* pInt = NULL;//�����Ͱ� ����ִ�.(����Ű�°��� ����)
	pInt = new int();//(int*)malloc(sizeof(int));//�޸𸮸� �Ҵ��ϰ� Ÿ��ũ�⿡ ���߾� �Ҵ��ؼ� ����ϴ°�.
	*pInt = 10;
	printf("Int[%d]:%d\n",*pInt,pInt);
	int nSize = 3;
	printf("ArraySize:");
	scanf("%d", &nSize);
	int* pArray = NULL;
	pArray	= new int[nSize];//(int*)malloc(sizeof(int) * nSize);
	for (int i = 0; i < nSize; i++) pArray[i] = i * 10;
	for (int i = 0; i < nSize; i++) printf("[%d/%d]%d,", &pArray[i], i, pArray[i]); printf("\n");
	delete pInt;//free(pInt);
	delete[] pArray;//free(pArray);
}

void main()
{
	//OpMain();
	//PointerBasicMain();
	//FunctionPtrMain();
	DynamicAllocateMain();
}