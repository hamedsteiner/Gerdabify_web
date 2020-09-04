
#ifndef DATABASE_H
#define DATABASE_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>

#include "static_declare.h"

#include "music.h"
#include "album.h"

using namespace std;



class Artist;
//class Queue;
//class Music;
//class Album;



class Database
{
public:

	List search_all(string name);

	vector<Artist*> get_artists();
	vector<Music*> get_musics();
	vector<Album*> get_albums();

	Artist* get_artist(int location);
	Music* get_music(int location);
	Album* get_album(int location);

	
	void add_artist();
	void add_music(Music* new_music);
	void add_album(Album* new_album);




	 
protected:
	std::vector<Artist*> artists;  ///////////????????? az to sign up
	std::vector<Music*> musics;
	std::vector<Album*> albums;

	//Queue queue;

	

	
};









#endif // DATABASE_H