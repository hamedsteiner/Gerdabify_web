





#include "music.h"
#include "Artist.h"
#include "album.h"



using namespace std;





/*
	Music::Music(string m_name,string path,Artist* creator)
	{
		name=m_name;
		path_file=path;
		validated=false;
		author=creator;

	}*/
	void Music::set_artist(Artist* artist){
		author=artist;
	}
	void Music::set_name_path(string music_name,string music_path){
		name=music_name;
		path_file=music_path;
	}





	string Music::get_name()
	{
		return name;
	}
	Album* Music::get_album()
	{
		return belonged_album;
	}
	Artist* Music::get_author()
	{
		return author;
	}
	void Music::validate()
	{
		validated=true;
	}