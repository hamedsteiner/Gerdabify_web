
#ifndef MUSIC_H
#define MUSIC_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
//#include "Artist.h"
#include "rated_object.h"



using namespace std;



class Album;
class Artist;

class Music: public Rated_object
{
public:
	//Music(string m_name,string path,Artist* creator);
	void set_name_path(string music_name,string music_path);
	void set_artist(Artist* artist);

	string get_name();
	Album* get_album();
	Artist* get_author();
	void validate();




	 
private:
	string path_file;
	bool validated;
	Artist* author;
	Album* belonged_album;
	string name;



};









#endif // MUSIC_H