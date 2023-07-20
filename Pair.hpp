//
// Created by Raul Gallardo on 4/26/23.
//

#ifndef PROJECT_4_PAIR_HPP
#define PROJECT_4_PAIR_HPP
#include "Token.hpp"
#include "string"
#include "Tokenizer.hpp"
#include "iostream"
class Tokenizer;
class Pair {
    // represents a entity and its value:

public:
    Pair();
    ~Pair();
    bool isNumber();  // is the datatype of the value of this entity integer?
    int numberValue();
    std::string stringValue();
    std::string attributeName();
    void parsePair(Tokenizer *tokenizer);


private:
    std::string _attributeName, _attributeStringValue;
    int _attributeNumberValue;
    bool _isNumber;
};


#endif //PROJECT_4_PAIR_HPP
