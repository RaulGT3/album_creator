#ifndef PROJECT_4_ALBUM_HPP
#define PROJECT_4_ALBUM_HPP
#include<fstream>
#include<cstring>
#include "vector"
#include "JSONDataObject.hpp"
#include "Tracks.hpp"
#include "Album_image.hpp"
class Album: public JSONDataObject {
public:
public:
    Album();
    ~Album();

    std::string title();
    std::string genres();
    unsigned albumID();
    unsigned artistID();
    unsigned numImages();
    unsigned numTracks();
    std::string year();
    void loadontoobject();

    Tracks *tracks() { return _tracks; }
    Album_image *&primaryImage() { return _primaryImage;   }
    Album_image *&secondaryImage()  { return _secondaryImage; }
    //void print();
    //std::string htmlString();
private:
    std::string _title, _genre, _year;
    unsigned _albumID, _numTracks, _numImages, _artistID;
    bool cachedtitle, cachedgenre, cachedyear, cachedAlbumID, cachednymTracks,cachednumImages,cachedArtistID;
    Tracks *_tracks;

    Album_image *_primaryImage, *_secondaryImage;

};
#endif