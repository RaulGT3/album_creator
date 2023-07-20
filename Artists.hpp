//
// Created by Raul Gallardo on 4/16/23.
//

#ifndef PROJECT_4_ARTISTS_HPP
#define PROJECT_4_ARTISTS_HPP
#include "iostream"
#include "Artist.hpp"
#include "vector"
#include "fstream"
#include "JSONArray.hpp"
#include "Tokenizer.hpp"
//#include "Artist_images.hpp"
class Artist_images;

class Artists:public JSONArray {
public:
    Artists();
    ~Artists();

    int numArtists();
    void addArtist(Artist *artist);
    Artist *artistWithID(unsigned int aID);
    void loadArtistsFromFile(std::string fileName);
    std::string htmlString();
    JSONDataObject *jsonObjectNode() { return new Artist();  }
    void setAlbumsForArtists(Albums *albums);
    void setImagesForArtists(Artist_images *);
    std::vector<Artist *> *listOfArtists() { return (std::vector<Artist *> *) _listOfDataObjects; }

    //void runAsserts();
};


#endif //PROJECT_4_ARTISTS_HPP
