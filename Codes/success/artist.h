
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

#include "rated.h"
#include "User.h"


//#include "database.h"
//class Database;

using namespace std;
class Music;
class Album;
class Artistt :public User, public Rated
{
public:

    virtual void addAlbum(string artist_name, string album_name);
    virtual void addMusic(string music_name, string file_path);

    vector<Album*> get_albums(){return albums;}
    vector<Music*> get_musics(){return musics;}

     UserData get_userdata()
{
    return this_person;
}
protected:
	std::vector<Music*> musics;
	std::vector<Album*> albums;
	bool granted;
};



#endif //ARTIST_H