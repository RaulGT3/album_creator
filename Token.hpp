//
// Created by Raul Gallardo on 4/26/23.
//

#ifndef PROJECT_4_TOKEN_HPP
#define PROJECT_4_TOKEN_HPP


#include <string>

class Token {
public:
    Token();
    ~Token();
    bool &isquote();
    bool &isOpenSquareBracket();
    bool & isCloseSquareBracket();

    bool &isComma();
    bool &isint();

    bool & isOpenCurleyBracket();
    bool &isCloseCurleyBracket();

    bool &iscolon();
    std::string tagstring(){return _TagString;}
    int tagInt(){return _TagInt;}

    void makeTagString(std::string name);
    void makeTagint(int num);


private:
    bool _isOpenSquareBracket, _isCloseSquareBracket, _isComma, _isCloseCurleyBracket,
    _isOpenCurleyBracket,_iscolon,_isquote, _isint;
    int _TagInt;
    std::string _TagString;
};



#endif //PROJECT_4_TOKEN_HPP
