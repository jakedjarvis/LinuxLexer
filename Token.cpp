#include "Token.h"

Token::Token()
{

}

Token::Token(string tokenName, string tokenSymbol, int tokenLine)
{
	this->tokenName = tokenName;
	this->tokenSymbol = tokenSymbol;
	this->tokenLine = tokenLine;
}

Token::Token(string tokenName)
{
	this->tokenName = tokenName;
	this->tokenSymbol = "Empty";
	this->tokenLine = -1;
}

Token::Token(string tokenName, string tokenSymbol)
{
	this->tokenName = tokenName;
	this->tokenSymbol = tokenSymbol;
	this->tokenLine = -1;
}

void Token::toString()
{

}


string Token::getTokenNameAsString()
{
	return this->tokenName;
}

string Token::getTokenSymbol()
{
	return this->tokenSymbol;
}

int Token::getTokenLine()
{
	return this->tokenLine;
}