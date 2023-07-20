//
// Created by Raul Gallardo on 4/26/23.
//

#include "JSONDataObject.hpp"

JSONDataObject::JSONDataObject() {
    _listOfDataItems = new std::vector<Pair*>();

}

JSONDataObject::~JSONDataObject() {

}

void JSONDataObject::parseDataObject(Tokenizer *tokenizer) {
    Token token = tokenizer->getToken();
    if( ! token.isOpenCurleyBracket() ){
        std::cout<<"is not a curly open bracket termenating...";
        exit(5);
    }
    Pair *pair = new Pair();
    pair->parsePair(tokenizer);
        _listOfDataItems->push_back(pair);
      token = tokenizer->getToken();
    if( ! token.isCloseCurleyBracket() && !token.isComma() ) {
        std::cout<<"Malform termenating...";
        exit(5);
    }
    while( ! token.isCloseCurleyBracket() ){
        Pair *pair = new Pair();
        pair->parsePair(tokenizer);

        _listOfDataItems->push_back(pair);


        token = tokenizer->getToken();


    }
    loadontoobject();

}

std::string JSONDataObject::valueForStringAttribute(std::string s) {
        for(int i = 0 ; i < _listOfDataItems->size(); ++i){
            if(_listOfDataItems->at(i)->attributeName() == s){

                return _listOfDataItems->at(i)->stringValue();
            }
        }
        std::cout << "Error: attribute " << s << " not found" << std::endl;
        exit(9);
    }

int JSONDataObject::valueForIntegerAttribute(std::string s) {
        for(int i = 0 ; i < _listOfDataItems->size(); ++i){
            if(_listOfDataItems->at(i)->attributeName() == s){
                return _listOfDataItems->at(i)->numberValue();
            }
        }
        std::cout << "Error: attribute " << s << " not found" << std::endl;
        exit(9);
    }


void JSONDataObject::loadontoobject() {

}




