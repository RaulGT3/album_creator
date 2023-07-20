//
// Created by Raul Gallardo on 4/26/23.
//

#include "Token.hpp"
#include <iostream>
#include <iomanip>

Token::Token(): _isOpenSquareBracket{false},
                                 _isCloseSquareBracket{false},
                                 _isComma{false},
                                 _isCloseCurleyBracket{false},
                                 _isOpenCurleyBracket{false},
                                 _iscolon {false},
                                 _isquote{false},
                                 _TagString{},
                                 _TagInt {0} {}

bool &Token::isOpenSquareBracket() {
    return _isOpenSquareBracket;
}

bool &Token::isCloseSquareBracket() {
    return _isOpenSquareBracket;
}

bool &Token::isComma() {
    return _isComma;
}

bool &Token::isOpenCurleyBracket() {
    return _isOpenCurleyBracket;
}

bool &Token::isCloseCurleyBracket() {
    return _isCloseCurleyBracket;
}

bool &Token::iscolon() {
    return _iscolon;
}




Token::~Token() {

}

bool &Token::isquote() {
    return _isquote;
}

void Token::makeTagString(std::string name) {
    _TagString = name;
   // _isquote = true;
}

void Token::makeTagint(int num) {
    _TagInt = num;
   // _iscolon = true;
}

bool &Token::isint() {
    return _isint;
}





