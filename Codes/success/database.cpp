
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "database.h"
#include "artist.h"


using namespace std;

	void DataBase::add_album(Album* new_album){
		albums.push_back(new_album);

	}
	void DataBase::add_music(Music* new_music){
		musics.push_back(new_music);

	}
	void DataBase::add_artist(Artistt* new_artist){
		artists.push_back(new_artist);
	}

	std::vector<Music*> DataBase::get_musics(){
		return musics;
	}
	std::vector<Album*> DataBase::get_albums(){
		return albums;
	}
	std::vector<Artistt*> DataBase::get_artists(){
		return artists;
	}

	/*std::vector<string> DataBase::search(string item_name){
		vector<string> searched;
		for(int i=0;i<musics.size();i++){

			if(musics[i]->getCompleteName()==item_name)
				searched.push_back(musics[i]->get_name());
		}
		for(int i=0;i<albums.size();i++){

			if(albums[i]->getCompleteName()==item_name)
				searched.push_back(albums[i]->get_name());
		}
		for(int i=0;i<artists.size();i++){

			if(artists[i]->getCompleteName()==item_name)
				searched.push_back(artists[i]->get_name());
		}
		return searched;
	}
*/