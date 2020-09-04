
#ifndef PLAYLISTPLACE_H
#define PLAYLISTPLACE_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>

#include "place.h"

class Artist;
class Playlist;
class Music;

using namespace std;

//typedef vector<string> List;


class Playlistplace: public Place
{
public:

Playlistplace(vector<Playlist*> pointed_playlists,Playlist*  pointed_playlist,string _username);

List list();
List listMusics();
List listAlbums();
List listPlaylists();



//void addTo(string music_thing);
//void remove(string music_name);


string getName();
string getCompleteName();



private:
	vector<Playlist*> pointed_playlists;
	Playlist*  pointed_playlist;

};


#endif // PLAYLISTPLACE_H