
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream>
#include <algorithm>


#include "Artist.h"
//#include "music.h"
//#include "album.h"
#include "Database.h"

using namespace std;




	 vector<Album*> Artist::get_albums()
	 {
	 	return albums;
	 }
	 vector<Music*> Artist::get_musics()
	 {
	 	return musics;
	 }
	 string Artist::get_name()
	 {
	 	return (this_person.firstname + this_person.lastname);
	 }


	 void Artist::addMusic(string music_name,string file_path)
	 {
	 	Music* new_music;
	 	new_music=new Music;
	 	new_music->set_name_path(music_name,file_path);
	 	new_music->set_artist(this);

	 	musics.push_back(new_music);
	 	//database->add_music(new_music)

	 }
	 void Artist::addAlbum(string artist_name,string album_name)
	 {
	 	Album* new_album;
	 	new_album=new Album;
	 	new_album->set_name(album_name);
	 	new_album->set_artist(this);
	 	albums.push_back(new_album);
	 	//database->add_album(new_album);

	 }



