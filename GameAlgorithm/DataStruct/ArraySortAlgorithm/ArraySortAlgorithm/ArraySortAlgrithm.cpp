#include <stdio.h>

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int MinArray(int arr[], int nSize)
{
	int nMin = 9999;
	for (int i = 0; i < nSize; i++)
	{
		if (nMin > arr[i])
			nMin = arr[i];
	}
	return nMin;
}

int MinArrayIdx(int start, int arr[], int nSize)
{
	int nMin = 9999;
	int nMinIdx = -1;
	for (int i = start; i < nSize; i++)
	{
		if (nMin > arr[i])
		{
			nMin = arr[i];
			nMinIdx = i;
		}
	}
	return nMinIdx;
}

void InsertSort()
{
	int arrData[] = { 8,1,7,4,2,3,9,5,6 };
	printf("Data:");
	for (int i = 0; i < 9; i++)
	{
		printf("%d,", arrData[i]);
	}
	printf("\n");
	printf("i:");
	for (int i = 0; i < 9; i++)
	{
		printf("%d,", i);
	}
	printf("\n");
	//-------------------------------
	//�迭�� ���ĵǵ��� ������ ¥��
	int nSize = sizeof(arrData) / sizeof(int);
	for (int i = 0; i < nSize; i++) // 0
	{
		int nMinIdx = MinArrayIdx(i, arrData, nSize); //0
		Swap(arrData[i], arrData[nMinIdx]); //8 <-> 1 //0<->1 //1<->1
		printf("%d:",i);
		for (int i = 0; i < 9; i++)
			printf("%d,",arrData[i]);
		printf("\n");
	}
	//-------------------------------

	//������¿��� 1~9���� ������� ���ĵǵ��� �����
	printf("Data:");
	for (int i = 0; i < 9; i++)
		printf("%d,", arrData[i]);
	printf("\n");
}

void main()
{
	InsertSort();
}