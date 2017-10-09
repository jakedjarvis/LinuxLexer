#include "FileHandler.h"
#include <iostream>

FileHandler::FileHandler(){
	this->lineNum = 0;
}

int FileHandler::fileOpener(string inputFile){
	input.open(inputFile, std::ifstream::in);

	lineNum = 1;

	return 0;

	
}

string FileHandler::getNewLine(){
	if (input.eof()){
		return "\0";
	}

	//get the line and return it
	getline(input, line);

	//increment the line count and track the old one if its multiline line count is private with a getter
	this->lineNum++;

	return line;
}

int FileHandler::getLineNum(){
	return this->lineNum;
}

void FileHandler::plusLineNum(){
	this->lineNum++;
}

char FileHandler::getNextChar(){
	

	char passedC;
	input.get(passedC);


	if (passedC < 0){
		return -1;
	}

	return passedC;
}