#ifndef Token_H
#define Token_H

#include <string>
#include <iostream>

using namespace std;

enum EToken
{
	COMMA,
    PERIOD, 
    Q_MARK, 
    L_PAREN, 
    R_PAREN, 
    COLON, 
    COLON_DASH,
    SCHEMES, 
    FACTS, 
    RULES, 
    QUERIES, 
    ID, 
    EOFILE, 
    STRING, 
    UNDEFINED,
    COMMENT,
    ADD,
    MULTIPLY
};


class Token{

private:
	string tokenName;
	string tokenSymbol;
	int tokenLine;


public:
	Token();
	Token(string tokenName, string tokenSymbol, int tokenLine);
	Token(string tokenName);
	Token(string tokenName, string tokenSymbol);
	void toString();
    string getTokenNameAsString();
    string getTokenSymbol();
    int getTokenLine();

};

#endif