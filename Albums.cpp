//
// Created by Raul Gallardo on 4/11/23.
//

#include "Albums.hpp"
#include "sstream"
Albums::~Albums() {

}


Albums::Albums() {

}

void Albums::loadAlbumFromFile(std::string fileName) {
    {

        Tokenizer *tokenizer = new Tokenizer(fileName);
        parseJSONArray(tokenizer);
        delete tokenizer;
    }
}

void Albums::addAlbum(Album *album) {
    listOfAlbums()->push_back(album);
}

Album *Albums::albumID(unsigned int aID) {
    for (int i = 0; i < listOfAlbums()->size() ; ++i){
        if (listOfAlbums()->at(i)->albumID() == aID){
            return listOfAlbums()->at(i);
        }
    }
    std::cout<<"error"<<aID;
    exit(19);
}

void Albums::setTracksForAlbums(Tracks *tracks ) {

    for (int i =0; i < tracks->listOfTracks()->size();++i){

        albumID(tracks->listOfTracks()->at(i)->AlbumID())->tracks()->addTracks(tracks->listOfTracks()->at(i));

    }

}

void Albums::setImagesForAlbums(Album_images *Images) {
    for(int i=0;i < Images->listOfAlbum_images()->size();++i){
        if(Images->listOfAlbum_images()->at(i)->type()=="primary"){
            albumID(Images->listOfAlbum_images()->at(i)->albumID())->primaryImage()=Images->listOfAlbum_images()->at(i);

        }else{
            albumID(Images->listOfAlbum_images()->at(i)->albumID())->secondaryImage()=Images->listOfAlbum_images()->at(i);
        }

    }

}

std::string Albums::htmlString() {
    //std::ofstream htmlpopuator("Album_html/html_albums.html\"");
    //std::ofstream htmlpopuator("html_albums.html");
    //std::fstream templete("album_template.html");

        for (int i=0; i < listOfAlbums()->size(); ++i) {
            std::stringstream filename;
            filename << "Album_html/html_albums"<<i<<".html";
            std::ofstream htmlpopuator(filename.str());
            std::fstream templete("album_template.html");

            if (htmlpopuator.is_open() && templete.is_open()) {
            while (!templete.eof()) {
                std::string curr_line;
                getline(templete, curr_line);

                if (curr_line == "<% album_details %>") {

                        if (listOfAlbums()->at(i)->primaryImage() != nullptr) {
                            htmlpopuator << "<img class=\"image\" width=\"250\" height=\"250\" src=\""
                            << listOfAlbums()->at(i)->primaryImage()->uri() << "\">" << std::endl;
                        } else {
                            if(listOfAlbums()->at(i)->secondaryImage() == nullptr){

                                continue;
                            }
                            htmlpopuator << "<img class=\"image\" width=\"250\" height=\"250\" src=\""
                            << listOfAlbums()->at(i)->secondaryImage()->uri() << "\">" << std::endl;
                        }
                        //htmlpopuator<<"<div class=\"clear\"></div>"<<std::endl;
                        htmlpopuator<<"<table>"<<std::endl;
                        htmlpopuator<<"<tbody>"<<std::endl;
                        htmlpopuator<<"<tr>"<<std::endl;
                        htmlpopuator<<"<td class=\"aTitle\" colspan=\"2\">"<<listOfAlbums()->at(i)->title()<<"</td>"<<std::endl;
                        htmlpopuator<<"</tr>"<<std::endl;
                        htmlpopuator<<"<tr>"<<std::endl;
                        htmlpopuator<<"<td class \"tdNarrow\"> Artist:</td>"<<std::endl;
                        htmlpopuator<<"<td class =\"value\">"<<listOfAlbums()->at(i)->tracks()->listOfTracks()->at(0)->Aristname()<<"</td>"<<std::endl;
                        htmlpopuator<<"</tr>"<<std::endl;
                        htmlpopuator<<"<tr>"<<std::endl;
                        htmlpopuator<<"<td> Genres:</td>"<<std::endl;
                        htmlpopuator<<"<td class =\"value\">"<<listOfAlbums()->at(i)->genres()<<"</td>"<<std::endl;
                        htmlpopuator<<"</tr>"<<std::endl;
                        htmlpopuator<<"<tr>"<<std::endl;
                        htmlpopuator<<"<td> Year:</td>"<<std::endl;
                        htmlpopuator<<"<td class =\"value\">"<<listOfAlbums()->at(i)->year()<<"</td>"<<std::endl;
                        htmlpopuator<<"</tr>"<<std::endl;
                        htmlpopuator<<"</table>"<<std::endl;
                        htmlpopuator<<"</tbody>"<<std::endl;
                        htmlpopuator<<"<table class = \"albuminfo\">"<<std::endl;
                        htmlpopuator<<"<tbody>"<<std::endl;
                        htmlpopuator<<"<tr>"<<std::endl;
                        htmlpopuator<<"<td class=\"aTitle\" colspan=\"2\"> Trackslist </td>"<<std::endl;
                        htmlpopuator<<"</tr>"<<std::endl;

                        for (int j=0; j < listOfAlbums()->at(i)->tracks()->listOfTracks()->size(); ++j) {
                            htmlpopuator<<"<tr class=\"tracks\">"<<std::endl;
                            htmlpopuator<<"<td class =\"trackName red\">"<<listOfAlbums()->at(i)->tracks()->listOfTracks()->at(j)->Title() <<"</td>"<<std::endl;
                            htmlpopuator<<"<td class =\"red\">"<<listOfAlbums()->at(i)->tracks()->listOfTracks()->at(j)->Duration()<<"</td>"<<std::endl;
                            htmlpopuator<<"</tr>"<<std::endl;


                        }
                        htmlpopuator<<"</table>"<<std::endl;
                        htmlpopuator<<"</tbody>"<<std::endl;
                        htmlpopuator<<"<div class=\"clear\"></div>"<<std::endl;
                        htmlpopuator.close();
                        templete.close();
                    }



                else {
                    htmlpopuator << curr_line << std::endl;
                }
            }


        }else{
                std::cout << "error when opening";
                exit(3);
                htmlpopuator.close();
                templete.close();

    }
            htmlpopuator.close();
            templete.close();
        }







        return std::string();

    }






