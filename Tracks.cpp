//
// Created by Raul Gallardo on 4/15/23.
//

#include "Tracks.hpp"

Tracks::Tracks() {
}

Tracks::~Tracks() {

}

void Tracks::loadTrackFromFile(std::string fileName) {
    Tokenizer *tokenizer = new Tokenizer(fileName);
    parseJSONArray(tokenizer);
    delete tokenizer;
}

void Tracks::addTracks(Track *track) {
    listOfTracks()->push_back(track);
}
std::string Tracks::htmlString() {
    std::ofstream htmlpopuator("Tracksoutput.html");
    std::fstream templete("TempleteTracks.html");

    if (htmlpopuator.is_open() && templete.is_open()) {
        while (!templete.eof()) {
            std::string curr_line;
            getline(templete,curr_line);
            if(curr_line == "{% Temp %}" ) {

                for(int i = 0; i < listOfTracks()->size();++i ) {
                    htmlpopuator <<"<li>"<<listOfTracks()->at(i)->Title() <<" <dl>" << std::endl;
                    htmlpopuator <<"<dt>artist_name</dt>"<< std::endl;
                    htmlpopuator<<"<dd>"<< listOfTracks()->at(i)->Aristname()<<"</dd>"<<std::endl;
                    htmlpopuator <<"<dt>Album_name</dt>"<< std::endl;
                    htmlpopuator<<"<dd>"<< listOfTracks()->at(i)->AlbumName()<<"</dd>"<<std::endl;
                    htmlpopuator <<"<dt>Album_id</dt>"<< std::endl;
                    htmlpopuator<<"<dd>"<< listOfTracks()->at(i)->AlbumID()<<"</dd>"<<std::endl;
                    htmlpopuator <<"<dt>duration</dt>"<< std::endl;
                    htmlpopuator<<"<dd>"<< listOfTracks()->at(i)->Duration()<<"</dd>"<<std::endl;
                    htmlpopuator <<"<dt>position</dt>"<< std::endl;
                    htmlpopuator<<"<dd>"<< listOfTracks()->at(i)->Position()<<"</dd>"<<std::endl;
                    htmlpopuator<<"    </dl>"<<std::endl;
                    htmlpopuator<<"  </li>"<<std::endl;
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



