// Zad2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib> 
#include <ctime>

void evenOdd(int* arr, int n)
{
	int temp,poz=0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			temp = arr[poz];
			arr[poz] = arr[i];
			arr[i] = temp;
			poz++;
		}
	}
}

int main()
{
	int n;
	std::cout << "Unesite broj elemenata niza!\n";
	std::cin >> n;
	int* arr = new int[n];
	srand((unsigned)time(0));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 9 + 1;
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	evenOdd(arr, n);
	std::cout << "\n";
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	delete[] arr;
	arr = 0;
    return 0;
}

