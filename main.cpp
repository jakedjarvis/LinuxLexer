#include "FileHandler.h"
#include "Lexer.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){

	FileHandler handler;

	int openCheck = handler.fileOpener(argv[1]);


	vector<Token> tokenVector;

	Lexer lex;



	//If the first char in the file is EOF...
	if (handler.input.peek() == EOF) {
		tokenVector.push_back(Token("EOF", "", handler.getLineNum()));
	}
	//If the file isn't empty...
	else {

		while (!handler.input.eof()) {

			char currentChar = handler.getNextChar();

			Token lexCheck = lex.singleCheck(currentChar, &handler);


			tokenVector.push_back(lexCheck);


		}

	}




	//Could be in print function

        tokenVector.pop_back();

	vector<Token> finalVector;

	for (int l = 0; l < tokenVector.size(); l++){
		if ((tokenVector[l].getTokenNameAsString() == "COMMENT" && tokenVector[l].getTokenSymbol() == "") || (tokenVector[l].getTokenNameAsString() == "UNDEFINED" && tokenVector[l].getTokenSymbol() == "") || (tokenVector[l].getTokenNameAsString() == "UNDEFINED" && tokenVector[l].getTokenSymbol() == " ") || (tokenVector[l].getTokenNameAsString() == "UNDEFINED" && tokenVector[l].getTokenSymbol() == "^@")){
		}
		else{
			finalVector.push_back(tokenVector[l]);
		}
	}

	int last = finalVector.size() - 1;
	if (finalVector[last].getTokenNameAsString() != "EOF"){
		finalVector.push_back(Token("EOF", "", handler.getLineNum()));
	}

	for (int j=0; j < finalVector.size(); j++){
		cout << "(";
		cout << finalVector[j].getTokenNameAsString() << ",";
		cout << "\"" << finalVector[j].getTokenSymbol() << "\"" << ",";
		cout << finalVector[j].getTokenLine();
		cout << ")";
		cout << endl;
	}
	
	cout << "Total Tokens = " << finalVector.size() << endl;
	
	handler.input.close();


	return 0;
}
