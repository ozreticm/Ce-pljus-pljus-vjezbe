// Vjezba10.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Error.h"
int unosBroj(int a)
{
	int num;
	std::cout << "Unesite "<<a<<". broj:\n";
	try
	{
		std::cin >> num;
		if (std::cin.fail())
		{
			if(a==1)
				throw Error("Neuspješno unesen prvi broj!");
			else if(a==2)
				throw Error("Neuspješno unesen drugi broj!");
			return NULL;
		}
	}
	catch(Error)
	{
		std::cin.clear();
		std::cin.ignore();
		return NULL;
	}
	return a;
}

int main()
{
	int num1,num2;
	char op;
	double d;
	std::vector<double> results;
	while (true)
	{
		num1 = unosBroj(1);
		num2 = unosBroj(2);
		std::cout << "Unesite operaciju\n";
		try
		{
			std::cin >> op;
			if (op == '+')
			{
				d = double(num1) + num2;
			}
			else if (op == '-')
			{
				d = double(num1) - num2;
			}
			else if (op == '*')
			{
				d = double(num1) * num2;
			}
			else if (op == '/')
			{
				if (num2 == 0)
				{
					throw Error("Dijeljenje sa nulom!");
					break;
				}
				d = double(num1) / num2;
			}
			else
			{
				throw Error("Unesena neispravna operacija!");
				break;
			}
			results.push_back(d);
		}
		catch (Error)
		{
			std::cout << "Neuspjesno\n";
		}
	}
    return 0;
}

