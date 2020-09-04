
#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>



using namespace std;

class Music;
class Album;


class Playlist
{
public:

	 void set_name(string _name){name=_name;}
	 string get_name(){return name;}
	 vector<Music*> get_musics(){return musics;}
	 void set_music(Music* new_music);
	 void set_album(Album* new_album);
	 vector<string>get_albums();
	 void clear();


	 
private:
	std::vector<Music*> musics;
	string name;
	vector<string>album_names;

	


};









#endif // PLAYLIST_H