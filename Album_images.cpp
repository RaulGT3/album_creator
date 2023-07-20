//
// Created by Raul Gallardo on 5/7/23.
//

#include "Album_images.hpp"

Album_images::Album_images() {

}

Album_images::~Album_images() {

}



void Album_images::loadImagesFromFile(std::string fileName) {
    Tokenizer *tokenizer = new Tokenizer(fileName);
    parseJSONArray(tokenizer);
    delete tokenizer;
}
