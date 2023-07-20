//
// Created by Raul Gallardo on 5/7/23.
//

#include "Artist_images.hpp"

Artist_images::Artist_images() {

}

Artist_images::~Artist_images() {

}

void Artist_images::loadImagesFromFile(std::string fileName) {
    Tokenizer *tokenizer = new Tokenizer(fileName);
    parseJSONArray(tokenizer);
    delete tokenizer;
}
