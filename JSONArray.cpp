//
// Created by Raul Gallardo on 4/26/23.
//

#include "JSONArray.hpp"

JSONArray::JSONArray() {
    _listOfDataObjects = new std::vector<JSONDataObject*>();
}

JSONArray::~JSONArray() {

}

void JSONArray::parseJSONArray(Tokenizer *tokenizer) {

    Token token = tokenizer->getToken();
    if( ! token.isOpenSquareBracket() ){
        std::cout<<"is not a Curly open bracket termenating...";
        exit(3);
    }

            JSONDataObject *dItem = jsonObjectNode();
             dItem->parseDataObject(tokenizer);
           _listOfDataObjects->push_back(dItem);
            token = tokenizer->getToken();
            if( !token.isCloseSquareBracket() && ! token.isComma() ) {
                std::cout<<"Malform termenating...";
                exit(3);
            }
         while( ! token.isCloseSquareBracket() ){
             //Token token = tokenizer->getToken();
             JSONDataObject *dItem = jsonObjectNode();
             dItem->parseDataObject(tokenizer);
             _listOfDataObjects->push_back(dItem);
             token = tokenizer->getToken();
         }



}

