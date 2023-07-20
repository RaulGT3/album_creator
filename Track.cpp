//
// Created by Raul Gallardo on 4/10/23.
//
#include "Track.hpp"
#include "iostream"
Track::Track() {
     _artistName={};
     _title={};
     _albumName={};
     _duration ={};
     _position ={};
     _albumID = 0;
    cachedArtistName= false;
     catchedtitle=false;
     cachedAlbumName=false;
     cacheDuration= false;
    cachedPosition= false;
     catchedalbumID= false;

}


Track::~Track() {

}

std::string Track::Aristname() {
    if( cachedArtistName )
        return _artistName;
    cachedArtistName = true;
    return _artistName = valueForStringAttribute("\"artist_name\"");
}

std::string Track::Title() {
    if( catchedtitle )
        return _title;
    catchedtitle = true;
    return _title = valueForStringAttribute("\"title\"");
}

std::string Track::AlbumName() {
    if( cachedAlbumName )
        return _albumName;
    cachedAlbumName = true;
    return _albumName = valueForStringAttribute("\"album_name\"");
}

std::string Track::Duration() {
    if( cacheDuration )
        return _duration;
    cacheDuration = true;
    return _duration = valueForStringAttribute("\"duration\"");
}

std::string Track::Position() {
    if( cachedPosition )
        return _position;
    cachedPosition = true;
    return _position = valueForStringAttribute("\"position\"");
}

unsigned Track::AlbumID() {
    if( catchedalbumID )
        return _albumID;
    catchedalbumID = true;
    return _albumID = valueForIntegerAttribute("\"album_id\"");
}

void Track::loadontoobject() {
    Aristname();
     Title();
    AlbumName();
    Duration();
     Position();
     AlbumID();
}
