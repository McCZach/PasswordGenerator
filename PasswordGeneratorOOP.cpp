//*************************************************************************
//	File:			PasswordGeneratorOOP.cpp
//
//	Date:			4-23-2022
//
//	Author:			Zach
//
//	Description:		Object oriented program based on 
//				'PasswordGenerator.cpp'
//
//*************************************************************************

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

//*************************************************************************

class Password
{
	private:
		string pass = "";
		int length;
	public:
		string getPassword() const
		{
			return pass;
		}
	
		void setPassword(const string& input)
		{
			pass = input;
		}
	
		int getLength() const
		{
			return length;
		}
	
		void setLength(const int& size)
		{
			length = size;
		}
};

//*************************************************************************

void getSize(Password& password, const int& MAX_RANGE, const int& MIN_RANGE, const int& MAX, const int& MIN);
void generatePassword(Password& password, const int& MAX, const int& MIN);
void writeToFile(const Password& password);

//*************************************************************************

int main()
{
	//Used for generating password length
	const int MAX_RANGE = 16;
	const int MIN_RANGE = 8;
	//Used for generating ASCII value - greater than 32, less than 127 [33-126]
	const int MAX = 126;
	const int MIN = 33;

	Password p;

	getSize(p, MAX_RANGE, MIN_RANGE, MAX, MIN);

	generatePassword(p, MAX, MIN);

	writeToFile(p);

	cout << "Password: " << p.getPassword() << endl;

	return 0;
}

//*************************************************************************

void getSize(Password& password, const int& MAX_RANGE, const int& MIN_RANGE, const int& MAX, const int& MIN)
{
	char input;
	int size = 0;
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
		password.setLength(size);
		while (password.getLength() < 8 || password.getLength() > 16)
		{
			cout << "ERROR - Please enter a valid length [8-16]: ";
			cin >> size;
			password.setLength(size);
		}
		break;

	case 'N':
		//Random length created and random characters added
		size = rand() % (MAX_RANGE - MIN_RANGE + 1) + MIN_RANGE;
		password.setLength(size);
		break;

	default:
		break;
	}
}

//*************************************************************************

void generatePassword(Password& password, const int& MAX, const int& MIN)
{
	char character;

	for (int i = 0; i < password.getLength(); i++)
	{
		character = rand() % (MAX - MIN + 1) + MIN;

		password.setPassword(password.getPassword() += character);
	}
}

//*************************************************************************

void writeToFile(const Password& password)
{
	fstream file("Passwords.txt", ios::app);
	if (file)
	{
		file << password.getPassword() << endl;
	}
	else
	{
		cout << "ERROR - Could not open file!" << endl;
	}

	file.close();
}

//*************************************************************************
