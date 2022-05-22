#ifndef FILEPARSER_H 
#define FILEPARSER_H
//class FileParser. Will contain functions needed to check a database of files to see if the user picks a valid car model and color.
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
class fileParser {
private:

public:
	//uses default constructor
	bool CheckWord(const string&, string); //see if a car model or car color actually exists.
};
#endif