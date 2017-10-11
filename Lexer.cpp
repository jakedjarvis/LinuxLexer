#include "Lexer.h"

Token Lexer::singleCheck(char inputWord, FileHandler* handler){

	Token token;
	stringstream ss;
	string s;

	ss << inputWord;
	ss >> s;

	
	token = Token("UNDEFINED", s, handler->getLineNum());

	switch (inputWord) {
	case '\n':
	{
		handler->plusLineNum();
		break;
	}
	case '\'':
	{
		string content;
		int line = handler->getLineNum();
		content.push_back(inputWord);
		inputWord = handler->getNextChar();

		while (inputWord != '\'' || (inputWord == '\'' && handler->input.peek() == '\'')) {

			if (inputWord == '\'' && handler->input.peek() == '\'') {
				content.push_back(inputWord);
				inputWord = handler->getNextChar();
				content.push_back(inputWord);
				inputWord = handler->getNextChar();
			}

			content.push_back(inputWord);
			inputWord = handler->getNextChar();
			if (inputWord == '\n') {
				handler->plusLineNum();
			}
			if (handler->input.eof()) {
				token = Token("UNDEFINED", content, line);
				return token;
			}
		}

		content.push_back(inputWord);

		token = Token("STRING", content, line);

		break;
	}
	case '#':
	{
		if (handler->input.peek() == '|') {
			string multiLineComment;
			int line = handler->getLineNum();
			while (!(inputWord == '|' && handler->input.peek() == '#')) {
				multiLineComment.push_back(inputWord);
				inputWord = handler->getNextChar();
				if (inputWord == '\n') {
					handler->plusLineNum();
				}
				if (handler->input.eof()) {
					token = Token("UNDEFINED", multiLineComment, line);
					return token;
				}
			}
			token = Token("COMMENT", multiLineComment, line);
			inputWord = handler->getNextChar();
		}
		else {
			string singleLineComment;
			while (inputWord != '\n' && !handler->input.eof()) {

				if (inputWord != '\n') {
					singleLineComment.push_back(inputWord);
				}

				inputWord = handler->getNextChar();




			}

			token = Token("COMMENT", singleLineComment, handler->getLineNum());

			if (inputWord == '\n') {
				handler->plusLineNum();
			}

			
		}
		break;
	}
	case ',':
	{
		ss << inputWord;
		ss >> s;
		token = Token("COMMA", s, handler->getLineNum());
		break;
	}
	case '.':
	{
		ss << inputWord;
		ss >> s;
		token = Token("PERIOD", s, handler->getLineNum());
		break;
	}
	case '?':
	{
		ss << inputWord;
		ss >> s;
		token = Token("Q_MARK", s, handler->getLineNum());
		break;
	}
	case '(':
	{
		ss << inputWord;
		ss >> s;
		token = Token("LEFT_PAREN", s, handler->getLineNum());
		break;
	}
	case ')':
	{
		ss << inputWord;
		ss >> s;
		token = Token("RIGHT_PAREN", s, handler->getLineNum());
		break;
	}
	case ':':
	{
                string cChecker;
                cChecker.push_back(inputWord);

                if (handler->input.peek() == '-')
		{
                        inputWord = handler->getNextChar();
                        cChecker.push_back(inputWord);
                        token = Token("COLON_DASH", cChecker, handler->getLineNum());
		}
		else {
                        token = Token("COLON", cChecker, handler->getLineNum());
		}
		break;
	}
	case '*':
	{
		ss << inputWord;
		ss >> s;
		token = Token("MULTIPLY", s, handler->getLineNum());
		break;
	}
	case '+':
	{
		ss << inputWord;
		ss >> s;
		token = Token("ADD", s, handler->getLineNum());
		break;
	}
	case 'Q':
	{
		string queriesChecker;

                while (isalnum(inputWord)) {
			queriesChecker.push_back(inputWord);
			inputWord = handler->getNextChar();
			if (inputWord == '\n') {
                            if(queriesChecker == "Queries"){
                                token = Token("QUERIES", queriesChecker, handler->getLineNum());
                                handler->plusLineNum();
                                return token;
                            }
                            else{
                                token = Token("ID", queriesChecker, handler->getLineNum());
                                handler->plusLineNum();
                                return token;
                            }
			}
		}
		if (queriesChecker == "Queries") {
			token = Token("QUERIES", queriesChecker, handler->getLineNum());
		}
                else{
                    token = Token("ID", queriesChecker, handler->getLineNum());
                }
		break;
	}
	case 'S':
	{
            string schemesChecker;

            while (isalnum(inputWord)) {

                    schemesChecker.push_back(inputWord);
                    inputWord = handler->getNextChar();
                    if (inputWord == '\n') {
                        if(schemesChecker == "Schemes"){
                            token = Token("SCHEMES", schemesChecker, handler->getLineNum());
                            handler->plusLineNum();
                            return token;
                        }
                        else{
                            token = Token("ID", schemesChecker, handler->getLineNum());
                            handler->plusLineNum();
                            return token;
                        }


                    }
            }
            if (schemesChecker == "Schemes") {
                    token = Token("SCHEMES", schemesChecker, handler->getLineNum());
            }
            else{
                token = Token("ID", schemesChecker, handler->getLineNum());
            }
            break;
	}
	case 'F':
	{
		string factsChecker;

                while (isalnum(inputWord)) {
			factsChecker.push_back(inputWord);
			inputWord = handler->getNextChar();
			if (inputWord == '\n') {
                            if(factsChecker == "Facts"){
                                token = Token("FACTS", factsChecker, handler->getLineNum());
                                handler->plusLineNum();
                                return token;
                            }
                            else{
                                token = Token("ID", factsChecker, handler->getLineNum());
                                handler->plusLineNum();
                                return token;
                            }
			}
		}
		if (factsChecker == "Facts") {
			token = Token("FACTS", factsChecker, handler->getLineNum());
		}
                else{
                    token = Token("ID", factsChecker, handler->getLineNum());
                }
		break;
	}
	case 'R':
	{
		string rulesChecker;

                while (isalnum(inputWord)) {
			rulesChecker.push_back(inputWord);
			inputWord = handler->getNextChar();
			if (inputWord == '\n') {
                            if(rulesChecker == "Rules"){
                                token = Token("RULES", rulesChecker, handler->getLineNum());
                                handler->plusLineNum();
                                return token;
                            }
                            else{
                                token = Token("ID", rulesChecker, handler->getLineNum());
                                handler->plusLineNum();
                                return token;
                            }
			}
		}
                if (rulesChecker == "Rules") {
			token = Token("RULES", rulesChecker, handler->getLineNum());
		}
                else{
                    token = Token("ID", rulesChecker, handler->getLineNum());
                }
		break;
	}
	case EOF:
	{
		token = Token("EOF", "", handler->getLineNum());
		break;
	}
	default:
	{

		if (isalpha(inputWord)){
			string id;
			int IDLineNum = handler->getLineNum();
		
                        while (isalnum(inputWord)) {

				id.push_back(inputWord);
                                inputWord = handler->getNextChar();
				
				if (inputWord == '\n') {
					handler->plusLineNum();
				}
			}
		
			token = Token("ID", id, IDLineNum);
		}
		else if (!isspace(inputWord)) {
			string undefString;
			undefString.push_back(inputWord);

			token = Token("UNDEFINED", undefString, handler->getLineNum());
		}
		break;
	} //end of default case


	} //end of switch statement

	return token;

}



Token Lexer::multiCheck(char inputWord, FileHandler* handler){
	Token token;
	return token;
}

//Token Lexer::idCheck(char inputWord, FileHandler* handler)
//{
//	Token token;
//	if (isalpha(inputWord)){
//		string id;
//
//		while (isalnum(inputWord)) {
//			id.push_back(inputWord);
//			inputWord = handler->getNextChar();
//		}
//
//		token = Token("ID", id, handler->getLineNum());
//	}
//	return token;
//}
