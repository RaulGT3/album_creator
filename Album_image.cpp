//
// Created by Raul Gallardo on 5/7/23.
//

#include "Album_image.hpp"

Album_image::Album_image() :cachedwidth{false}, cachedheight{false}, cacheduri{false}, cachedtype{false}, cachedalbumID{false}{}

Album_image::~Album_image() {

}
std::string Album_image::uri() {
    if( cacheduri )
        return _uri;
    cacheduri = true;
    return _uri = valueForStringAttribute("\"uri\"");
}

std::string Album_image::type() {
    if( cachedtype )
        return _type;
    cachedtype = true;
    return _type = valueForStringAttribute("\"type\"");
}

unsigned Album_image::albumID() {
    if( cachedalbumID )
        return _albumID;
    cachedalbumID = true;
    return _albumID = valueForIntegerAttribute("\"album_id\"");
}

unsigned Album_image::height() {
    if( cachedheight )
        return _height;
    cachedheight = true;
    return _height = valueForIntegerAttribute("\"height\"");
}

unsigned Album_image::width() {
    if( cachedwidth )
        return _width;
    cachedwidth = true;
    return _width = valueForIntegerAttribute("\"width\"");
}

void Album_image::loadontoobject() {
    uri();
    type();
    albumID();
    width();
    height();
}