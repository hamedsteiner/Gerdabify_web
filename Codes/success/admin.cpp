
#ifndef ADMIN_H
#define ADMIN_H

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
//#include "album.h"
//#include "music.h"
#include "rated_object.h"

class Album;
class Music;


using namespace std;



//class Rated_object
class Admin : public User
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


#endif // ADMIN_H