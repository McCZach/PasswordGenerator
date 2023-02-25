//******************************************************************************************************
//	File:			PasswordGenerator.cpp
//
//	Date:			2-16-2022
//
//	Author:			Zach
//
//	Description:		Program creates a random length array using a pointer and
//				generates random ASCII values to add to array to print 
//				out and add to file
//
//******************************************************************************************************

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

//******************************************************************************************************

void fillArray(char* ptr, int size, const int MAX, const int MIN);

//******************************************************************************************************

int main()
{
	const int MAX_RANGE = 16;
	const int MIN_RANGE = 8;
	//Used for generating ASCII value - greater than 32, less than 127 [33-126]
	const int MAX = 126;
	const int MIN = 33;
	
	char input;
	
	int size = 0;

	char* ptr = nullptr;
	

	srand(time(0));

	cout << "Do you have a desired length? ";
	cin >> input;
	input = toupper(input);
	while (input != 'Y' && input != 'N')
	{
		cout << "ERROR - Please enter Y or N: ";
		cin >> input;
	}
	input = toupper(input);
	cout << endl;

	switch (input)
	{
		case 'Y':
			cout << "What is your wanted length? [8-16]: ";
			cin >> size;
			while (size < 8 || size > 16)
			{
				cout << "ERROR - Please enter a valid length [8-16]: ";
				cin >> size;
			}
			ptr = new char[size];

			fillArray(ptr, size, MAX, MIN);

			break;

		case 'N':
			//Random length created and random characters added
			size = rand() % (MAX_RANGE - MIN_RANGE + 1) + MIN_RANGE;
			ptr = new char[size];
			
			fillArray(ptr, size, MAX, MIN);

			break;

		default:
			break;
	}
	

	//Write to file
	fstream file;
	file.open("Passwords.txt", file.app);

	for (int x = 0; x < size; x++)
	{
		file << ptr[x];
	}
	file << "\n";


	//Password output
	cout << endl;
	for (int x = 0; x < size; x++)
	{
		cout << ptr[x];
	}
	cout << endl;
	
	file.close();
	return 0;
}

//******************************************************************************************************

void fillArray(char* ptr, int size, const int MAX, const int MIN)
{
	char character;

	for (int i = 0; i < size; i++)
	{
		character = rand() % (MAX - MIN + 1) + MIN;

		ptr[i] = character;
	}
}

//******************************************************************************************************

/*	SAMPLE OUTPUT

cNP:\I-Oz!9-

*/

//Passwords will keep being written to the .txt
