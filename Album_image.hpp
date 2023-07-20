//
// Created by Raul Gallardo on 5/7/23.
//

#ifndef PROJECT_4_ALBUM_IMAGE_HPP
#define PROJECT_4_ALBUM_IMAGE_HPP
#include "JSONDataObject.hpp"

class Album_image: public JSONDataObject{
public:
    Album_image();
    ~Album_image();


    std::string uri();
    std::string type();
    unsigned    albumID();
    unsigned width();
    unsigned height();
    void loadontoobject();
    // void        print();
    // std::string htmlString();


private:
    std::string _uri, _type;
    unsigned _width, _albumID, _height;
    bool cachedwidth, cachedheight, cacheduri, cachedtype, cachedalbumID;

};



#endif //PROJECT_4_ALBUM_IMAGE_HPP
