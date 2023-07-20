//
// Created by Raul Gallardo on 4/16/23.
//
#include "Artists.hpp"

Artists::Artists() {

}


std::string Artists::htmlString() {
    std::ofstream htmlpopuator("Html_Masterfile.html");
    std::fstream templete("artist_template.html");

    if (htmlpopuator.is_open() && templete.is_open()) {
        while (!templete.eof()) {
            std::string curr_line;
            getline(templete,curr_line);
            if(curr_line == "<% artist_details %>" ) {

                for(int i = 0; i < listOfArtists()->size();++i ) {


                    htmlpopuator<<"<table>"<<std::endl;
                    htmlpopuator<<"<tbody>"<<std::endl;
                    htmlpopuator<<"<tr >"<<std::endl;
                    htmlpopuator<<"<td colspan=\"2\"><h1>"<<listOfArtists()->at(i)->artistName()<<"</h1></td>"<<std::endl;
                    htmlpopuator<<"</tr>"<<std::endl;
                    htmlpopuator<<"<tr>"<<std::endl;
                    if (listOfArtists()->at(i)->primaryImage() != nullptr) {
                        htmlpopuator << "<td> <img class=\"image\" width=\"250\" height=\"250\" src=\""
                                     << listOfArtists()->at(i)->primaryImage()->uri() << "\"> </td>" << std::endl;
                    }
                    else if(listOfArtists()->at(i)->secondaryImage() != nullptr && listOfArtists()->at(i)->primaryImage() == nullptr){
                        htmlpopuator << "<td> <img class=\"image\" width=\"250\" height=\"250\" src=\""
                                     << listOfArtists()->at(i)->secondaryImage()->uri() << "\"> </td>" << std::endl;
                    }
                    htmlpopuator<<"<td>"<<std::endl;
                    htmlpopuator<<"<table>"<<std::endl;
                    htmlpopuator<<"<tr>"<<std::endl;
                    htmlpopuator<<"<td class=\"numImages\"> Number of Images:</td>"<<std::endl;
                    htmlpopuator<<"<td class =\"value\">"<<listOfArtists()->at(i)->numImages()<<"</td>"<<std::endl;
                    htmlpopuator<<"</tr>"<<std::endl;
                    htmlpopuator<<"<tr>"<<std::endl;
                    htmlpopuator<<"<td> Profile:</td>"<<std::endl;
                    htmlpopuator<<"<td class =\"value\">"<<listOfArtists()->at(i)->profile()<<"</td>"<<std::endl;
                    htmlpopuator<<"</tr>"<<std::endl;
                    htmlpopuator<<"</table>"<<std::endl;
                    htmlpopuator<<"</td>"<<std::endl;
                    htmlpopuator<<"</tr>"<<std::endl;
                    htmlpopuator<<"</tbody>"<<std::endl;
                    htmlpopuator<<"</table>"<<std::endl;
                    htmlpopuator<<"<div class=\"clear\"></div>"<<std::endl;
                    htmlpopuator<<"<tr>"<<std::endl;
                    htmlpopuator<<"<td colspan =\"2\"><h1>Albums</h1> </td>"<<std::endl;
                    htmlpopuator<<"</tr>"<<std::endl;


                    for (int r=0; r < listOfArtists()->at(i)->albums()->listOfAlbums()->size(); ++r) {
                        int check = r;
                        check+=1;
                        htmlpopuator<<"<p>"<<check<<". "<<"</p>"<<std::endl;
                        //htmlpopuator<<"<li>"<<listOfArtists()->at(i)->albums()->listOfAlbums()->at(r)->tracks()->listOfTracks()->at(0)->Title()<<"</li>"<<std::endl;
                        //htmlpopuator<<"<li> "<<"hello"<<"</li>"<<std::endl;
                        if (listOfArtists()->at(i)->albums()->listOfAlbums()->at(r)->primaryImage() != nullptr) {
                            htmlpopuator << "<img class=\"image\" width=\"250\" height=\"250\" src=\""
                                         << listOfArtists()->at(i)->albums()->listOfAlbums()->at(r)->primaryImage()->uri() << "\">" << std::endl;
                        } else {
                            if(listOfArtists()->at(i)->albums()->listOfAlbums()->at(r)->secondaryImage() == nullptr){
                                continue;
                            }
                            htmlpopuator << "<img class=\"image\" width=\"250\" height=\"250\" src=\""
                                         <<listOfArtists()->at(i)->albums()->listOfAlbums()->at(r)->secondaryImage()->uri() << "\">" << std::endl;
                        }
                        //htmlpopuator<<"<p>"<<i<<"</p>"<<std::endl;
                        //htmlpopuator<<"<div class=\"clear\"></div>"<<std::endl;
                        htmlpopuator<<"<table>"<<std::endl;
                        htmlpopuator<<"<tbody>"<<std::endl;

                        htmlpopuator<<"<tr>"<<std::endl;
                        htmlpopuator<<"<td class=\"aTitle\" colspan=\"2\">"<<listOfArtists()->at(i)->albums()->listOfAlbums()->at(r)->tracks()->listOfTracks()->at(0)->Title()<<"</td>"<<std::endl;
                        htmlpopuator<<"</tr>"<<std::endl;
                        htmlpopuator<<"<tr>"<<std::endl;
                        htmlpopuator<<"<td class \"tdNarrow\"> Artist:</td>"<<std::endl;
                        htmlpopuator<<"<td class =\"value\">"<<listOfArtists()->at(i)->albums()->listOfAlbums()->at(r)->tracks()->listOfTracks()->at(0)->Aristname()<<"</td>"<<std::endl;
                        htmlpopuator<<"</tr>"<<std::endl;
                        htmlpopuator<<"<tr>"<<std::endl;
                        htmlpopuator<<"<td> Genres:</td>"<<std::endl;
                        htmlpopuator<<"<td class =\"value\">"<<listOfArtists()->at(i)->albums()->listOfAlbums()->at(r)->genres()<<"</td>"<<std::endl;
                        htmlpopuator<<"</tr>"<<std::endl;
                        htmlpopuator<<"<tr>"<<std::endl;
                        htmlpopuator<<"<td> Year:</td>"<<std::endl;
                        htmlpopuator<<"<td class =\"value\">"<<listOfArtists()->at(i)->albums()->listOfAlbums()->at(r)->year()<<"</td>"<<std::endl;
                        htmlpopuator<<"</tr>"<<std::endl;
                        htmlpopuator<<"</table>"<<std::endl;
                        htmlpopuator<<"</tbody>"<<std::endl;
                        htmlpopuator<<"<table class = \"albuminfo\">"<<std::endl;
                        htmlpopuator<<"<tbody>"<<std::endl;
                        htmlpopuator<<"<tr>"<<std::endl;
                        htmlpopuator<<"<td class=\"aTitle\" colspan=\"2\"> Trackslist </td>"<<std::endl;
                        htmlpopuator<<"</tr>"<<std::endl;
                        //htmlpopuator<<"</ol>"<<std::endl;
                        htmlpopuator<<"<div class=\"clear\"></div>"<<std::endl;
                        for (int j=0; j < listOfArtists()->at(i)->albums()->listOfAlbums()->at(r)->tracks()->listOfTracks()->size(); ++j) {
                            htmlpopuator<<"<tr class=\"tracks\">"<<std::endl;
                            htmlpopuator<<"<td class =\"trackName red\">"<<listOfArtists()->at(i)->albums()->listOfAlbums()->at(r)->tracks()->listOfTracks()->at(j)->Title() <<"</td>"<<std::endl;
                            htmlpopuator<<"<td class =\"red\">"<<listOfArtists()->at(i)->albums()->listOfAlbums()->at(r)->tracks()->listOfTracks()->at(j)->Duration()<<"</td>"<<std::endl;
                            htmlpopuator<<"</tr>"<<std::endl;


                        }
                        htmlpopuator<<"</table>"<<std::endl;
                        htmlpopuator<<"</tbody>"<<std::endl;
                        htmlpopuator<<"<div class=\"clear\"></div>"<<std::endl;
                    }
                }


            }
            else {
                htmlpopuator <<curr_line<<std::endl;
            }
        }
    }else{
        std::cout<<"error when opening";
        exit(3);
    }
    htmlpopuator.close();
    templete.close();



    return std::string();
}
Artists::~Artists() {

}

void Artists::loadArtistsFromFile(std::string artistsFileName)
{

    Tokenizer *tokenizer = new Tokenizer(artistsFileName);
    parseJSONArray(tokenizer);
    delete tokenizer;
}

int Artists::numArtists() {
    return listOfArtists()->size();
}

void Artists::addArtist(Artist *artist) {
        listOfArtists()->push_back(artist);
}

Artist *Artists::artistWithID(unsigned int aID) {
    for(int i=0;i<listOfArtists()->size();++i){
        if(listOfArtists()->at(i)->artistID()==aID){
            return listOfArtists()->at(i);
        }
    }
    return nullptr;
}

void Artists::setAlbumsForArtists(Albums *albums) {

    for(int i=0;i<albums->listOfAlbums()->size();++i){
        artistWithID(albums->listOfAlbums()->at(i)->artistID())->albums()->addAlbum(albums->listOfAlbums()->at(i));

    }
}

void Artists::setImagesForArtists(Artist_images *Images) {

    for(int i=0;i<Images->listOfArtistsImg()->size();++i){
        if(Images->listOfArtistsImg()->at(i)->type()=="primary"){
            artistWithID(Images->listOfArtistsImg()->at(i)->artistID())->primaryImage()=Images->listOfArtistsImg()->at(i);
         }else{
            artistWithID(Images->listOfArtistsImg()->at(i)->artistID())->secondaryImage()=Images->listOfArtistsImg()->at(i);
        }

    }

}




