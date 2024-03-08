// BinaryInputOutput.cpp : Defines the entry point for the console application.

/* Dean Hartfield

3-3-2016

Module 09 Activity - Input/Ouput in C Language

Write a C program that reads binary numbers from an input file, 
converts them to base-10, and writes the results to an output file.

*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <Windows.h>
#include <shellapi.h>

using namespace std;

int main()
{
	// Bit size constant
	const size_t bits = sizeof(long) * CHAR_BIT;

	// First create the input text file with binary numbers
	cout << "Creating input file named input.txt." << endl;
	Sleep(1500);

	ofstream binaryFile("input.txt", ofstream::out | ofstream::trunc);
	if (binaryFile.is_open()) {
		binaryFile.clear();

		binaryFile << "0000000000100010" << endl;
		binaryFile << "0000000001000100" << endl;
		binaryFile << "0000000010001000" << endl;
		binaryFile << "0000000100010000" << endl;
		binaryFile << "0000001000100000" << endl;
		binaryFile << "0000010001000000" << endl;
		binaryFile << "0000010000000000" << endl;
		binaryFile << "0011000000111001" << endl;
		binaryFile << "0001010110110011" << endl;
		binaryFile << "1010101010101010" << endl;

		binaryFile.close();

		cout << "File input.txt has been created successfully." << endl;
		Sleep(1500);
		ShellExecute(NULL, L"open", L"input.txt", NULL, NULL, SW_SHOW);
	}
	else {
		cout << "Unable to create file input.txt." << endl;
	}

	// Open the input file, read a line, convert it to a base 10 number, then write the number to the output file
	ifstream inFile("input.txt");
	if (inFile.is_open()) {
		cout << "Input file has been opened for reading." << endl;
		Sleep(1500);

		// Open the output file for writing
		ofstream outFile("output.txt", ofstream::out | ofstream::trunc);
		if (outFile.is_open()) {
			cout << "Output file has been opened for writing." << endl;
			Sleep(1500);

			// Loop through all lines in the input file
			string line;
			while (getline(inFile, line)) {
				// Create a bitset with the line from the input file
				bitset<bits> bs(line);

				// Convert the bitset to an unsigned long int
				unsigned long ulong = bs.to_ulong();

				// Write the number to the output file
				outFile << ulong << endl;
			}

			outFile.close();

			cout << "Output file has been closed and created successfully." << endl;
			Sleep(1500);
			ShellExecute(NULL, L"open", L"output.txt", NULL, NULL, SW_SHOW);
		}
		else {
			cout << "Unable to open output file." << endl;
		}

		inFile.close();

		cout << "Input file has been closed." << endl;
		Sleep(1500);
	}
	else {
		cout << "Unable to open input file." << endl;
	}

	cout << endl;
	system("pause");
    return 0;
}
