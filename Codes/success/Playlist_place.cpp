

#include "Playlist_place.h"

#include "playlist.h"
#include "music.h"



class Playlistplace: public Place
{
public:

Playlistplace::Playlistplace(vector<Playlist*> _pointed_playlists,Playlist*  _pointed_playlist,string _username)
{
	pointed_playlists=_pointed_playlists;
	pointed_playlist=_pointed_playlist;
	username=_username;
}

List Playlistplace::list()
{
	List output;
	std::vector<Music*> temp =pointed_playlist->get_musics() ;
	for(int i=0 ; i<temp.size();i++)
	{
		output.push_back(temp[i]->get_name());
	}
	return output;

}

List Playlistplace::listMusics()
{
	List output;
	std::vector<Music*> temp =pointed_playlist->get_musics() ;
	for(int i=0 ; i<temp.size();i++)
	{
		output.push_back(temp[i]->get_name());
	}
	return output;
}

List Playlistplace::listAlbums()
{
	List output;
	output=pointed_playlist->get_albums();
	return output
}
List Playlistplace::listPlaylists()
{
	List output;
	for(int i=0 ; i<temp.size();i++)
	{
		output.push_back(pointed_playlists[i]->get_name());
	}
	return output;
}



//void addTo(string music_thing);
//void remove(string music_name);


string Playlistplace::getName()
{
	return pointed_playlist->get_name();
}
string Playlistplace::getCompleteName()
{
	return(username + "- " +pointed_playlist->get_name());
}



private:
	vector<Playlist*> pointed_playlists;
	Playlist*  pointed_playlist;
	string username;

};