//******************************************************************************************
//		File:			PasswordGenerator.cpp
//
//		Date:			2-16-2022
//
//		Author:			Zach
//
//		Description:	Program creates a random length array using a pointer and
//						generates random ASCII values to add to array to print out
//
//******************************************************************************************

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
using namespace std;

int main()
{
	//Used for generating password length
	const int MAX_RANGE = 16;
	const int MIN_RANGE = 8;
	
	//Used for generating ASCII value - greater than 32, less than 127 [33-126]
	const int MAX = 126;
	const int MIN = 33;
	
	int size;

	char* ptr = nullptr;

	char character;

	// 37 & 38 Generate a random number for the length [8-16]
	srand(time(0));
	size = rand() % (MAX_RANGE - MIN_RANGE + 1) + MIN_RANGE;

	ptr = new char[size];


	for (int i = 0; i < size; i++)
	{
		character = rand() % (MAX - MIN + 1) + MIN;

		ptr[i] = character;
	}

	cout << endl;
	for (int x = 0; x < size; x++)
	{
		cout << ptr[x];
	}

	cout << endl;

	return 0;
}


/*	SAMPLE OUTPUT

cNP:\I-Oz!9-

*/