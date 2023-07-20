//
// Created by Raul Gallardo on 4/26/23.
//


//
// Created by Ali Kooshesh on 1/22/23.
//

#include <iostream>
#include <string>
#include "Tokenizer.hpp"

Tokenizer::Tokenizer(std::string name):
                                        inputFileName{name} {
    inputStream.open(inputFileName, std::ios::in);  // open the input file. We will make sure that it is open in getToken.
}

bool Tokenizer::charOfInterest(char c) {
    // is c the initial (or the sole) character of a token?
    if(c == '[' || c == ']' || c == '{' || c== '}' || c == ',' || c == '"'||c==':' ){
        return true ;
    }
    return false;   // you need to replace this with code that compares c with characters like '<', '>', etc.
}

Token Tokenizer::getToken() {
    char c;

    if (!inputStream.is_open()) {
        std::cout << "Tokenizer::getToken() called with a stream that is not open." << std::endl;
        std::cout << "Make sure that " << inputFileName << " exists and is readable. Terminating.";
        exit(2);
    }

    while (inputStream.get(c) && !charOfInterest(c)) {

    }
        Token token;

        if (c == '[' ) {

            std::string remover;
            remover += c;

            token.isOpenSquareBracket()= true;

            return token;
        }
        if (c == ']' ) {

            std::string remover;
            remover += c;

            token.isCloseSquareBracket()= true;

            return token;
        }
        if (c == '{' ) {

            std::string remover;
            remover += c;

            token.isOpenCurleyBracket()= true;

            return token;
        }
        if (c == '}' ) {

            std::string remover;
            remover += c;

            token.isCloseCurleyBracket()= true;

            return token;
        }
        if (c == ',' ) {

            std::string remover;
            remover += c;

            token.isComma()= true;

            return token;
        }
        if (c == ':' ) {
            std::string stringval;
            int intval;
            std::string remover;
            remover += c;
            token.iscolon()= true;
            inputStream>>c;

            if(isdigit(c)){
                inputStream.putback(c);
                inputStream>>intval;
                token.makeTagint(intval);
                token.isint() =true;

                return token;
            }
            if( c == '"' ){
                inputStream.get(c);
                //stringval+=c;
                while (c != '"' ){
                    if(c == '\\' && inputStream.peek() == '"'){
                        remover = c ;
                        inputStream.get(c);
                        stringval+=c;
                        inputStream.get(c);
                        continue;

                    }
                    stringval+=c;
                    inputStream.get(c);
                }



                token.makeTagString(stringval);
                token.isint() =false;
                return token;

            }

            return token;
        }
        if (c == '"' ) {

            std::string remover;
            std::string stringval;
            remover += c;
            stringval+=c;
            while (inputStream.peek() != ':'){
            inputStream.get(c);
            stringval+=c;
            }
            token.makeTagString(stringval);
            token.isquote()= true;

            return token;
    }

        else {

            std::cout << "There is a logic error in unction Tokenizer::getToken.\n";
            std::cout << "The function doesn't know how to process this character: ->" << c << "<-\n";
            exit(1);
        }

        return token; // The control SHOULD NOT reach this statement.
    }


Tokenizer::~Tokenizer() {

}
