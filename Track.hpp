#include<fstream>
#include<cstring>
#include "JSONDataObject.hpp"
class Track:public JSONDataObject
{
public:
    Track();
    ~Track();

    std::string Aristname();
    std::string Title();
    std::string AlbumName();
    std::string Duration();
    std::string Position();
    unsigned    AlbumID();
    void loadontoobject();


private:
    std::string _artistName, _title, _albumName, _duration, _position;
    unsigned _albumID;
    bool cachedArtistName, catchedtitle, cachedAlbumName, cacheDuration, cachedPosition, catchedalbumID;


};

