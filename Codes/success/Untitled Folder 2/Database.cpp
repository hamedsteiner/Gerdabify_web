
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "exception.h"

#include "Database.h"


#include "Artist.h"

using namespace std;

	List Database::search_all(string name)
	{
		List output;
		string artist_name;
		string album_name;
		for(int i =0;i<artists.size();i++)
		{
			if(artists[i]->get_name()==name)
				output.push_back(name);
		}

		for(int i =0;i<albums.size();i++)
		{
			if(albums[i]->get_name()==name)
			{
				artist_name=(albums[i]->get_author()->getUserDetails().firstname + albums[i]->get_author()->getUserDetails().lastname );
				output.push_back(artist_name +" - "+ name);
			}
				
		}

		for(int i =0;i<musics.size();i++)
		{
			if(musics[i]->get_name()==name)
				{
					artist_name=(musics[i]->get_author()->getUserDetails().firstname + musics[i]->get_author()->getUserDetails().lastname );
					album_name=musics[i]->get_album()->get_name();

					output.push_back(artist_name+" - "+album_name+name);
				}
		}
		
		return output;











	}

	vector<Artist*> Database::get_artists()
	{
		return artists;
	}
	vector<Music*> Database::get_musics()
	{
		return musics;
	}
	vector<Album*> Database::get_albums()
	{
		return albums;
	}

	Artist* Database::get_artist(int location)
	{
		return artists[location];
	}
	Music* Database::get_music(int location)
	{
		return musics[location];
	}
	Album* Database::get_album(int location)
	{
		return albums[location];
	}

	
	void Database::set_artist();
	void Database::set_music(Music* new_music)
	{
		musics.push_back(new_music);
	}
	void Database::set_album(Album* new_album)
	{
		albums.push_back(new_album);
	}