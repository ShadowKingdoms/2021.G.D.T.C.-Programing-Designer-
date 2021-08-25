#include <stdio.h>
#include <string.h>

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

void main()
{
	//OpMain();
	//PointerBasicMain();
	FunctionPtrMain();
}