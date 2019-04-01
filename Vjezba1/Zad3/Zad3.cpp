// Zad3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int& pronadi(int niz[], int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		if (niz[i] % 10 + niz[i] / 100 % 10 == 5)
		{
			temp = i;
			break;
		}
	}
	return niz[temp];
}

int main()
{
	int niz[] = {1111, 1234, 2345, 3456, 4567, 5678, 2342, 1231};
	std::cout << pronadi(niz, 8) + 1;
    return 0;
}

