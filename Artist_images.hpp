//
// Created by Raul Gallardo on 5/7/23.
//

#ifndef PROJECT_4_ARTIST_IMAGES_HPP
#define PROJECT_4_ARTIST_IMAGES_HPP
#include "JSONArray.hpp"
#include "Artist_image.hpp"

class Artist_images: public JSONArray{
public:
    Artist_images();
    ~Artist_images();
    //int numImages();
    //void addAlbum(Album *album);
    //Albums *ImagesForArtistWithID(int artistID);
    void loadImagesFromFile(std::string fileName);
    //std::string htmlString();
    JSONDataObject *jsonObjectNode() { return new Artist_image();  }
    std::vector<Artist_image *> *listOfArtistsImg() { return (std::vector<Artist_image *> *) _listOfDataObjects; }
};



#endif //PROJECT_4_ARTIST_IMAGES_HPP
