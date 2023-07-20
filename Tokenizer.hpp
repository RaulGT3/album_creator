//
// Created by Raul Gallardo on 4/26/23.
//

#ifndef PROJECT_4_TOKENIZER_HPP
#define PROJECT_4_TOKENIZER_HPP

#include "Token.hpp"
#include "fstream"
class Tokenizer {

public:
    Tokenizer(std::string);
    Token getToken();
    ~Tokenizer();

private:

    std::string inputFileName;
    std::ifstream inputStream;

    bool charOfInterest(char c);
};



#endif //PROJECT_4_TOKENIZER_HPP
