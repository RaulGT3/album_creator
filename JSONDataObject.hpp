//
// Created by Raul Gallardo on 4/26/23.
//

#ifndef PROJECT_4_JSONDATAOBJECT_HPP
#define PROJECT_4_JSONDATAOBJECT_HPP
#include "string"
#include "Pair.hpp"
#include "Token.hpp"
#include "Tokenizer.hpp"
#include "iostream"
#include "vector"

class JSONDataObject {
public:
    JSONDataObject();
    virtual ~JSONDataObject();
    std::vector<Pair *> *listOfDataItems() { return _listOfDataItems; }
    void parseDataObject(Tokenizer *tokenizer);
    //virtual void print();
    std::string valueForStringAttribute(std::string s);
    int valueForIntegerAttribute(std::string s);
    virtual void loadontoobject();

private:
    std::vector<Pair *> *_listOfDataItems;
};


#endif //PROJECT_4_JSONDATAOBJECT_HPP
