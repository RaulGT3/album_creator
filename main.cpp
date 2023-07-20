

#include "Albums.hpp"
#include "Artists.hpp"
#include "Tracks.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include "Artist_images.hpp"
#include "Album_images.hpp"

int main(int argc, char *argv[]) {



    if( argc != 6) {  // we expect the name of the file as an argument to the program.
        std::cout << "usage: " << argv[0] << "nameOfAnInputFile" << std::endl;
        exit(1);
    }
    std::fstream inputStream1;
    inputStream1.open(argv[1], std::ios::in);    // open for reading
    if( !inputStream1.is_open()) {
        std::cout << "Unable top open " << argv[1] << ". Terminating...";
        std::cout << strerror(errno) << std::endl;
        exit(2);
    }

    Artists *artist = new Artists();
    artist->loadArtistsFromFile(argv[1]);



    inputStream1.close();

    std::fstream inputStream2;



    inputStream2.open(argv[2], std::ios::in);    // open for reading
    if( !inputStream2.is_open()) {
        std::cout << "Unable top open " << argv[2] << ". Terminating...";
        std::cout << strerror(errno) << std::endl;
        exit(2);
    }
    Artist_images *ARTISTIMAG =new Artist_images();
    ARTISTIMAG->loadImagesFromFile(argv[2]);


    inputStream2.close();
    std::fstream inputStream3;


    inputStream3.open(argv[3], std::ios::in);    // open for reading
    if( ! inputStream3.is_open()) {
        std::cout << "Unable top open " << argv[3] << ". Terminating...";
        std::cout << strerror(errno) << std::endl;
        exit(2);
    }
    Albums *albums = new Albums();
    albums->loadAlbumFromFile(argv[3]);
    inputStream3.close();
    std::fstream inputStream4;


    inputStream4.open(argv[4], std::ios::in);    // open for reading
    if( !inputStream4.is_open()) {
        std::cout << "Unable top open " << argv[4] << ". Terminating...";
        std::cout << strerror(errno) << std::endl;
        exit(2);
    }
    Album_images *ALBUMIMAGE = new Album_images() ;
    ALBUMIMAGE->loadImagesFromFile(argv[4]);

    inputStream4.close();
    std::fstream inputStream5;
    inputStream5.open(argv[5], std::ios::in);    // open for reading
    if( !inputStream5.is_open()) {
        std::cout << "Unable top open " << argv[5] << ". Terminating...";
        std::cout << strerror(errno) << std::endl;
        exit(2);
    }
    Tracks *tracks=new Tracks();
    tracks->loadTrackFromFile(argv[5]);








    artist->setAlbumsForArtists(albums);
    artist->setImagesForArtists(ARTISTIMAG);
    albums->setTracksForAlbums(tracks);
    albums->setImagesForAlbums(ALBUMIMAGE);
    albums->htmlString();
    artist->htmlString();

    return 0;

}
