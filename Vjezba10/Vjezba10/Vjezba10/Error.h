#pragma once
#ifndef ERROR_H
#define ERROR_H
#include "ios"
#include <string>
#include <iostream>
#include <fstream>
class Error
{
public:
	std::string error;
	//int num1, num2;
	Error(const char* s) : error(s) 
	{ 
		std::ofstream myfile; myfile.open("errors.log", std::ios_base::out | std::ios_base::app);
		myfile << s << "\n"; 
		myfile.close(); 
	};
	//bool inputFirst();
	//bool inputSecond();
};
#endif
