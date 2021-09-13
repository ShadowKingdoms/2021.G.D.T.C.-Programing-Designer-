#include "StackArray.h"
#include <iostream>

void demo::StackMain()
{
	char strName[] = "GDTC2021-1";
	stack<char> queString;
	std::cout << "Origin:" << strName << std::endl;
	char* pStr = strName;
	while (*pStr != '\0')
	{
		char cData = *pStr;
		queString.push(cData);
		std::cout << cData << std::endl;
		pStr++;
	}
	pStr = strName;
	while (!queString.empty())
	{
		*pStr = queString.top();
		queString.pop();
		pStr++;
	}
	std::cout << "Result:" << strName << std::endl;
}
