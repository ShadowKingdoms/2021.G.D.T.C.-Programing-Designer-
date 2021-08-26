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
	//arrCopyScore = arrScores; //배열의이름은 포인터가 아니다.
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

//정적할당: 프로그램이 컴파일시에 메모리를 할당이 결정되는 것.
//코드작성시에 변수(메모리의 이름)을 부여하여 선언하는것.
//
//동적할당: 프로그램 실행중에 메모리를 할당하는 것.
//실행중에 메모리가 할당시에는 이름을 붙여줄수없으므로 주소값을 사용해야한다.
//void포인터: 타입이 정해지지않은 메모리의 주소값을 저장하는 변수.
//동적할당시에 주소값을 저장해야하므로 포인터가 필요하다.
void DynamicAllocateMain()
{
	int* pInt = NULL;//포인터가 비어있다.(가르키는것이 없음)
	pInt = new int();//(int*)malloc(sizeof(int));//메모리를 할당하고 타입크기에 맞추어 할당해서 사용하는것.
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