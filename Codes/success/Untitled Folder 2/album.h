
#ifndef ALBUM_H
#define ALBUM_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
//#include "music.h"
//#include "User.h"
#include "rated_object.h"

 

using namespace std;

class Artist;
class Music;

class Album: public Rated_object
{
public:

	 //Album(Artist* creator,string _name);
	void set_name(string album_name);
	void set_artist(Artist* artist);
	 string get_name();
	 void validate();
	 Artist* get_author(){return author;}
	 vector<Music*> get_musics();


	 
private:
	bool validated;
	Artist* author;
	std::vector<Music*> musics;
	string name;

	


};









#endif // ALBUM_H