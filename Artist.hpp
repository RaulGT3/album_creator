#ifndef PROJECT_4_ARTIST_HPP
#define PROJECT_4_ARTIST_HPP
#include<fstream>
#include<cstring>
#include "Albums.hpp"
#include "JSONDataObject.hpp"
#include "Artist_images.hpp"
class Artist: public JSONDataObject {
public:
    Artist();
    ~Artist();

    std::string profile();
    std::string artistName();
    std::string realName();
    std::string numImages();  // since it's a string in the JSON file
    unsigned    artistID();
    void loadontoobject();

   // void        print();
   // std::string htmlString();

    // the following 4 function-prototypes are new to this project.
    void setAlbums(Albums *albums) { _albums = albums; }
    Albums *albums() { return _albums; }
    Artist_image *&primaryImage()       { return _primaryImage;   }
    Artist_image *&secondaryImage()     { return _secondaryImage; }

private:
    std::string _name, _realName, _profile,_numImages;
    unsigned _artistID;
    bool cachedName, cachedRealName, cachedProfile, cachedNumImages, cachedArtistID;

    // the following 3 variables are new to this project.
    Artist_image *_primaryImage, *_secondaryImage;
    Albums *_albums;

};
#endif //PROJECT_4_ARTIST_HPP