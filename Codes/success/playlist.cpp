#include "playlist.h"

#include "music.h"
#include "album.h"

using namespace std;



void Playlist::set_music(Music* new_music)
{
	musics.push_back(new_music);
}
void Playlist::set_album(Album* new_album)
{
	vector<Music*>added= new_album->get_musics();
	for(int i=0;i<added.size();i++)
		musics.push_back(added[i]);
	album_names.push_back(new_album->get_name());

}

vector<string>Playlist::get_albums()
{
	return album_names;
}



void Playlist::clear()
{
	for (int i=musics.size() ;i>0;i++)
	{
		musics.erase(musics.begin()+i-1);
	}
}