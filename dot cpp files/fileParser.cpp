#include "fileParser.h"

bool fileParser::CheckWord(const string& filename, string search) { //function to see if an input is found in a text file
	string line;
	ifstream Myfile;
	Myfile.open(filename);
	bool isFound = 0;
	if (!Myfile.good()) { //is the file in existence?
		return false;
	}
	else {
		while (getline(Myfile, line))
		{
			transform(line.begin(), line.end(), line.begin(), ::tolower);
			transform(search.begin(), search.end(), search.begin(), ::tolower);
			if (line == search) {
				return true;
			}
			else {
				isFound = 0;
			}
		}
	}
	Myfile.close();
	return isFound;
}