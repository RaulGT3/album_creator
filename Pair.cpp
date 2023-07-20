//
// Created by Raul Gallardo on 4/26/23.
//

#include "Pair.hpp"




void Pair::parsePair(Tokenizer *tokenizer) {

    Token token = tokenizer->getToken();
    if( ! token.isquote() ){

        std::cout<<"is not a quoat termenating...";
        exit(6);
    }
    std::string stringval= token.tagstring();;
    _attributeName =stringval;
    token = tokenizer->getToken();
    if(token.isint()){
        int val =0;
        val = token.tagInt();
        _attributeNumberValue=val;
        _isNumber=true;

    }else{
        std::string val ={};
        val = token.tagstring();
        _attributeStringValue = val;
        _isNumber=false;
    }

}

std::string Pair::stringValue() {
    return _attributeStringValue;
}

std::string Pair::attributeName() {
    return _attributeName;
}

int Pair::numberValue() {
    return _attributeNumberValue;
}

bool Pair::isNumber() {
    return _isNumber;
}

Pair::Pair() {

}

Pair::~Pair() {

}


