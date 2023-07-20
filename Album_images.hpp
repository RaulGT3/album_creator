//
// Created by Raul Gallardo on 5/7/23.
//

#ifndef PROJECT_4_ALBUM_IMAGES_HPP
#define PROJECT_4_ALBUM_IMAGES_HPP
#include "JSONArray.hpp"
#include "Album_image.hpp"

class Album_images:public JSONArray{
public:
    Album_images();
    ~Album_images();
    //int numImages();
    //void addAlbum(Album *album);
    //Albums *ImagesForAlbumWithID(int artistID);
    void loadImagesFromFile(std::string fileName);
    //std::string htmlString();
    JSONDataObject *jsonObjectNode() { return new Album_image();  }
    std::vector<Album_image *> *listOfAlbum_images() { return (std::vector<Album_image *> *) _listOfDataObjects; }
};




#endif //PROJECT_4_ALBUM_IMAGES_HPP
