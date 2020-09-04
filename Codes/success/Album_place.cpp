#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>

#include "Album_place.h"
#include "music.h"





Place* Albumplace::goToHome()
{
	Place* temp;
	temp = new Home;
	return temp;
}




Place* Albumplace::goToArtist()
{
	Place* temp;
	temp = new Artistplace(_pointed_music->get_author(),current_user);
	return temp;
}


/////////////////////////////////////////////////////////
/*

void Musicplace::play()
{
	throw MethodNotAvailable();
}
void Musicplace::addTo(string music_thing)
{
	throw MethodNotAvailable();
}

*/
///////////////////////////////////////////////////////////

Albumplace::Albumplace(Album* _pointed_album, UserData username )
{
	type="album";
	pointed_album=_pointed_album;
	current_user=username;
}



List Albumplace::list()
{
	vector<Music*> temp;
	List output;
	temp=pointed_album->get_musics();
	for(int i=0;i<temp.size();i++)
		output.push_back(temp[i]->get_name());
	return output;

}
List Albumplace::listMusics()
{
	vector<Music*> temp;
	List output;
	temp=pointed_album->get_musics();
	for(int i=0;i<temp.size();i++)
		output.push_back(temp[i]->get_name());
	return output;
}





void Albumplace::rate(int rate)
{
	if(rate>10 || rate<0)
		throw InvalidArguments();
	else
	{
		pointed_album->rate(rate,current_user) /// esme USER ham mohem
	}
}


string Albumplace::getArtist()
{
	return (pointed_album->get_author()->getUserDetails().firstname + pointed_album->get_author()->getUserDetails().lastname );
}


string Albumplace::getName()
{
	return (pointed_album->get_name());
}

string Albumplace::getCompleteName()
{
	string artist_name,album_name,space,complete_name;
	artist_name=(pointed_album->get_author()->getUserDetails().firstname + pointed_album->get_author()->getUserDetails().lastname );
	album_name=pointed_album->get_name();
	space=" - ";
	complete_name=artist_name+space+album_name;
	return complete_name;



}

int Albumplace::getRate()
{
	return ( pointed_album->getRate(current_user) );
}

int Albumplace::getUserRate()
{
	return ( pointed_album->getRate_avg() );
}

int Albumplace::getCriticRate()
{
	return ( pointed_album->getRate_critic() );
}
