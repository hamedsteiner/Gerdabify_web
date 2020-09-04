



#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "album.h"

#include "Artist.h"

using namespace std;
/*
Album::Album(Artist* creator,string _name)
{
	author=creator;
	name=_name;
}*/
	void Album::set_name(string album_name)
	{
		name=album_name;
	}
	void Album::set_artist(Artist* artist)
	{
		author=artist;
	}

string Album::get_name(){
	return name;
}
void Album::validate()
{
	validated=true;

}


vector<Music*> Album::get_musics()
{
	return musics;
}