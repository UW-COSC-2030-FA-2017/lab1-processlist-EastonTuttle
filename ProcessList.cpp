/*
ProcessList.cpp
Easton Tuttle
Computer Science II
September 11, 2017
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::getline;
using std::ifstream;
using std::string;

ifstream numberFile;
string fileName;
int numberCount;
double first;
double second;
double firstLast;
double secondLast;

// Function that asks the user for a valid file name until the file name given can be opened.
void getFile()
{
	// Ask the user for a file name.
	cout << "Please enter the name of the file you would like analyzed: ";
	getline(cin, fileName);
	numberFile.open(fileName);

	// Continue to ask for a new file name until the file does not fail to open.
	while (numberFile.fail())
	{
		cout << "The file could not be opened. Please check the spelling of the file name and ensure the file exists.\n\n";
		cout << "Please enter the name of the file you would like analyzed: ";
		getline(cin, fileName);
		numberFile.open(fileName);
	}
}

// Function that counts the amount of numbers within the file given and grabs the first two and last two numbers.
void countNumbers()
{
	while (!numberFile.eof() && !numberFile.fail())
	{
		if (numberCount == 0)
		{
			numberFile >> first;
			firstLast = first;
		}

		if (numberCount == 1)
		{
			numberFile >> second;
			secondLast = firstLast;
			firstLast = second;
		}

		if (numberCount > 1)
		{
			secondLast = firstLast;
			numberFile >> firstLast;
		}

		numberCount++;
	}
}

// Print out the statistics for the user.
void printStats()
{
	cout << "\nAmount of numbers in file: " << numberCount;
	cout << "\nFirst two numbers in file: " << first << " and " << second;
	cout << "\nLast two numbers in file:  " << secondLast << " and " << firstLast << "\n";
}

// Main testing function for the Process List program.
int main()
{
	getFile();
	countNumbers();
	printStats();
	// Close the file before the program ends to ensure that the file closes.
	numberFile.close();
	return 0;
}