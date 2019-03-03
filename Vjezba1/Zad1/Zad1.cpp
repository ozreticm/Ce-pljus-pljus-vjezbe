// Zad1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;

int main()
{
	int n;
	cout << "Unesite broj elemenata niza"<<endl;
	cin >> n; 
	int* arr=new int[n];
	srand((unsigned)time(0));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 9 + 1;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	for (int i = 1; i < 10; i++)
	{
		int br = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[j] == i)
				br++;
		}
		if (br > 1)
			cout << "\nBroj " << i << " se ponavlja " << br << " puta";

	}
	return 0;
}

