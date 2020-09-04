
#ifndef ARTIST_H
#define ARTIST_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "User.h"
#include "rated_object.h"


class DataBase;

using namespace std;


class Music;
class Album;
//class Rated_object
class Artist : public User , public Rated_object
{
public:

	

	 vector<Album*> get_albums();
	 vector<Music*> get_musics();
	 string get_name();


	 void addMusic(string music_name,string file_path);
	 void addAlbum(string artist_name,string album_name);



	
private:
	vector<Music*> musics;
	vector<Album*> albums;
	bool verifed;
	


};


#endif // ARTIST_H