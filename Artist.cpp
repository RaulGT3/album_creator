//
// Created by Raul Gallardo on 4/10/23.
//
#include "Artist.hpp"
#include "iostream"
Artist::Artist() {
_name={};
_realName={};
_profile={};
 _numImages={};
 _artistID=0;
_albums = new Albums();
_primaryImage= nullptr;
_secondaryImage= nullptr;
cachedArtistID =false;
cachedNumImages=false;
cachedName=false;
cachedRealName=false;
cachedProfile=false;

}


std::string Artist::profile() {
        if( cachedProfile )
            return _profile;
        cachedProfile = true;
        return _profile = valueForStringAttribute("\"profile\"");

}

std::string Artist::artistName() {
        if( cachedName )
            return _name;
        cachedName = true;
        return _name = valueForStringAttribute("\"artist_name\"");
}

std::string Artist::realName() {

        if( cachedRealName )
            return _realName;
        cachedRealName = true;
        return _realName = valueForStringAttribute("\"real_name\"");
}

std::string Artist::numImages() {

        if( cachedNumImages )
            return _numImages;
        cachedNumImages = true;
        return _numImages = valueForStringAttribute("\"num_images\"");

}

unsigned Artist::artistID() {
    if( cachedArtistID )
        return _artistID;
    cachedArtistID = true;
    return _artistID = valueForIntegerAttribute("\"artist_id\"");
}
Artist::~Artist()  {

}

void Artist::loadontoobject() {

   profile();
   artistName();
   realName();
   numImages();
   artistID();
}
