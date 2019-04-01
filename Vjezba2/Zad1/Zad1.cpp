// Zad1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>


int* popuniNiz(int* niz, int n)
{
	int br = 0;
	for (int i = 0; i < n; i++)
	{
		std::cout << "Unesite: " << i+1 << ". clan niza!\n";
		std::cin >> niz[i];
	}
	int pomocniNiz[] = { 0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < n; i++)
	{
		if (niz[i] < 10 && niz[i]>0)
			pomocniNiz[niz[i] - 1]++;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (pomocniNiz[i-1] == 0 && br==0)
		{
			niz[n] = i;
			br = 1;
		}
	}
	std::sort(niz, niz+n+1);
	return niz;
}

int main()
{
	int n;
	std::cout << "Unesite broj elemenata niza\n";
	std::cin >> n;
	int* niz;
	niz = new int[n+1];
	popuniNiz(niz, n);
	for (int i = 0; i < n + 1; i++)
	{
		std::cout << niz[i]<<" ";
	}
	delete[] niz;
	niz = 0;
    return 0;
}

