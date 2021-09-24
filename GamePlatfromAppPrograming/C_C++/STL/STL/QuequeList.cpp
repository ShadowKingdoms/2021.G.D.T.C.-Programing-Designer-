#include "QueueList.h"

void demo::QuequeMain()
{
	char strName[] = "GDTC2021-1";
	queue queString;
	cout << "Origin:" << strName << endl;
	char* pStr = strName;
	while (*pStr != '\0')
	{
		char cData = *pStr;
		queString.push(cData);
		cout << cData << endl;
		pStr++;
	}
	pStr = strName;
	while (!queString.empty())
	{
		*pStr = queString.front();
		queString.pop();
		pStr++;
	}
	cout << "Result:" << strName << endl;
}