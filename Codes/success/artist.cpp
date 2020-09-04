
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "artist.h"
#include "database.h"

using namespace std;
	void Artistt::addAlbum(string artist_name, string album_name){
		Album* new_album=new Album;
		new_album->set_artist(this);
		new_album->set_name(album_name);
		//cout<<new_album->get_name()<<endl;
		//this_data_base->add_album(new_album);
		albums.push_back(new_album);
	}
	void Artistt::addMusic(string music_name, string file_path){
		Music* new_music=new Music;
		new_music->set_artist(this);
		new_music->set_name_path(music_name,file_path);
		//this_data_base->add_music(new_music);
		//cout << new_music->get_name();
		musics.push_back(new_music);
	}