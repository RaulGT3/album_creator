//
// Created by Raul Gallardo on 5/7/23.
//

#include "Artist_image.hpp"

Artist_image::Artist_image() : cachedwidth{false}, cachedheight{false}, cacheduri{false}, cachedtype{false}, cachedArtistID{false}{}


Artist_image::~Artist_image() {

}

std::string Artist_image::uri() {
    if( cacheduri )
        return _uri;
    cacheduri = true;
    return _uri = valueForStringAttribute("\"uri\"");
}

std::string Artist_image::type() {
    if( cachedtype )
        return _type;
    cachedtype = true;
    return _type = valueForStringAttribute("\"type\"");
}

unsigned Artist_image::artistID() {
    if( cachedArtistID )
        return _artistID;
    cachedArtistID = true;
    return _artistID = valueForIntegerAttribute("\"artist_id\"");
}

unsigned Artist_image::height() {
    if( cachedheight )
        return _height;
    cachedheight = true;
    return _height = valueForIntegerAttribute("\"height\"");
}

unsigned Artist_image::width() {
    if( cachedwidth )
        return _width;
    cachedwidth = true;
    return _width = valueForIntegerAttribute("\"width\"");
}

void Artist_image::loadontoobject() {
    uri();
     type();
     artistID();
     width();
    height();
}
