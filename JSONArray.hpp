//
// Created by Raul Gallardo on 4/26/23.
//

#ifndef PROJECT_4_JSONARRAY_HPP
#define PROJECT_4_JSONARRAY_HPP
#include "JSONDataObject.hpp"
#include "string"
//#include "Token.hpp"
#include "Tokenizer.hpp"
#include "iostream"
#include "vector"
class JSONArray {
public:
    JSONArray();
    ~JSONArray();
    std::vector<JSONDataObject *> *listOfDataObjects() { return _listOfDataObjects; }
    virtual JSONDataObject *jsonObjectNode() = 0;
        //int numJSONObjects();
        void parseJSONArray(Tokenizer *tokenizer);
        //virtual void print();

protected:
    std::vector<JSONDataObject *> *_listOfDataObjects = new std::vector<JSONDataObject*>();
    //std::vector<JSONDataObject *> *_listOfDataObjects;

};

#endif //PROJECT_4_JSONARRAY_HPP
