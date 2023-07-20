//
// Created by Raul Gallardo on 5/7/23.
//

#ifndef PROJECT_4_ARTIST_IMAGE_HPP
#define PROJECT_4_ARTIST_IMAGE_HPP
#include "JSONDataObject.hpp"

class Artist_image: public JSONDataObject{
public:
    Artist_image();
    ~Artist_image();

    std::string uri();
    std::string type();
    unsigned   artistID();
    unsigned width();
    unsigned height();
    void loadontoobject();
    // void        print();
    // std::string htmlString();


private:
    std::string _uri, _type;
    unsigned _width, _artistID, _height;
    bool cachedwidth, cachedheight, cacheduri, cachedtype, cachedArtistID;

};



#endif //PROJECT_4_ARTIST_IMAGE_HPP
