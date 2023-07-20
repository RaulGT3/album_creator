//
// Created by Raul Gallardo on 4/11/23.
//

#ifndef PROJECT_4_ALBUMS_HPP
#define PROJECT_4_ALBUMS_HPP
#include "vector"
#include "iostream"
#include <fstream>
#include "Album.hpp"
#include "JSONArray.hpp"
#include "Tokenizer.hpp"
#include "Album_images.hpp"
//#include "Tracks.hpp"


class Albums: public JSONArray{
public:
    Albums();
 ~Albums();
    void addAlbum(Album *album);
    Album  * albumID(unsigned int aID);
    void loadAlbumFromFile(std::string fileName);
    std::string htmlString();
    JSONDataObject *jsonObjectNode() { return new Album();  }
    void setImagesForAlbums(Album_images *);
    void setTracksForAlbums(Tracks *tracks);
    std::vector<Album *> *listOfAlbums() { return (std::vector<Album *> *) _listOfDataObjects; }

};


#endif //PROJECT_4_ALBUMS_HPP
