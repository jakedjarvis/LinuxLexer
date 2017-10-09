#ifndef LEXER_H
#define LEXER_H

#include "Token.h"
#include "FileHandler.h"
#include <string>
#include <sstream>

using namespace std;

class Lexer
{
private:




public:
	Token singleCheck(char inputWord, FileHandler* handler);
	Token multiCheck(char inputWord, FileHandler* handler);
	//Token idCheck(char inputWord, FileHandler* handler);
};

#endif