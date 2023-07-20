//
// Created by Raul Gallardo on 4/10/23.
//

#include <iostream>
#include "Album.hpp"

Album::Album() {
   _title={};
    _genre={};
    _year={};
    _albumID=0;
    _numTracks=0;
    _numImages=0;
    _artistID =0;
    cachedtitle=false;
    cachedgenre=false;
    cachedyear= false;
    cachedAlbumID= false;
    cachednymTracks= false;
    cachednumImages= false;
    cachedArtistID= false;
    _primaryImage= nullptr;
    _secondaryImage= nullptr;
    _tracks = new Tracks();
}
Album::~Album() {

}


std::string Album::genres() {
    if( cachedgenre )
        return _genre;
    cachedgenre = true;
    return _genre = valueForStringAttribute("\"genres\"");

}


unsigned Album::albumID() {
    if( cachedAlbumID )
        return _albumID;
    cachedAlbumID = true;
    return _albumID = valueForIntegerAttribute("\"album_id\"");

}


std::string Album::title() {
    if( cachedtitle )
        return _title;
    cachedtitle = true;
    return _title = valueForStringAttribute("\"title\"");

}

unsigned Album::artistID() {
    if( cachedArtistID )
        return _artistID;
    cachedAlbumID = true;
    return _artistID = valueForIntegerAttribute("\"artist_id\"");

}

unsigned Album::numImages() {
    if( cachednumImages )
        return _numImages;
    cachednumImages = true;
    return _numImages = valueForIntegerAttribute("\"num_images\"");

}

unsigned Album::numTracks() {
    if( cachednymTracks )
        return _numTracks;
    cachednymTracks = true;
    return _numTracks = valueForIntegerAttribute("\"num_tracks\"");
}

std::string Album::year() {
    if (cachedyear)
        return _year;
    cachedyear = true;
    return _year = valueForStringAttribute("\"year\"");
}

void Album::loadontoobject() {
     title();
     genres();
     albumID();
     artistID();
     numImages();
     numTracks();
     year();
}








