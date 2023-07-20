//
// Created by Raul Gallardo on 4/15/23.
//

#ifndef PROJECT_4_TRACKS_HPP
#define PROJECT_4_TRACKS_HPP
#include "iostream"
#include "fstream"
#include "Track.hpp"
#include "vector"
#include "JSONArray.hpp"

class Tracks:public JSONArray {
public:
    Tracks();
    ~Tracks();

    void addTracks(Track *track);
    void loadTrackFromFile(std::string fileName);
    JSONDataObject *jsonObjectNode() { return new Track(); }
    std::vector<Track *> *listOfTracks() { return (std::vector<Track *> *) _listOfDataObjects; }
    std::string  htmlString();
};




#endif //PROJECT_4_TRACKS_HPP
