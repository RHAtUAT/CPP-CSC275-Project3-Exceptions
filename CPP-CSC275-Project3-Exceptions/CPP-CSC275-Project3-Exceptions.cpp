// CPP-CSC275-Project3-Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <new>
#include <locale>
#include <codecvt>
#include <bitset>

using namespace std;

void Exception_length_error()
{
	try {
		// throws bad_alloc because there is no index of -1,
		vector<int>(-1); 
	}
	catch (const length_error& e) {
		cout << "Caught length_error: " << e.what() << endl;
	}
}
void Exception_out_of_range()
{
	vector<int> vect(0);
	try {
		vect.at(1) = 22; // throws std::overflow_error because memory hasn't been reserved for 2 elements, only 1 
	}
	catch (out_of_range& e) {
		cout << "Caught out_of_range: " << e.what() << endl;
	}
}

//Causes stack overflow
//int CrashMe(int overflow)
//{
//		return CrashMe(overflow);
//}

//Why doesn't this catch?
void Exception_overflow_error()
{

	try {

		//CrashMe(33554);

	}
	catch (const exception& e) {
		cout << "Caught range_error: " << e.what() << endl;
	}
}

void Exception_zero_division()
{
	int n = 11;
	int d = 0;
	try {
		//Cant divide by zero so throw the error
		if (d == 0)
		{
			throw "Zero Division error";
		}
		else
		{
			n / d;
		} 
	}	
	catch (...) {
		cout << "Caught Zero Division error" << endl;
	}
	
}

int main()
{
	do
	{
		Exception_length_error();
		Exception_overflow_error();
		Exception_zero_division();
		Exception_out_of_range();

		system("pause");

	} while (true);
}
