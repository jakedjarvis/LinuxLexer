#ifndef FileHandler_H
#define FileHandler_H

#include <string>
#include <fstream>

using namespace std;

class FileHandler{

private:
	int lineNum;
	string line;

public:
	ifstream input;
	FileHandler();
	int fileOpener(string inputFile);
	string getNewLine();
	int getLineNum();
	char getNextChar();
	void plusLineNum();

};

#endif