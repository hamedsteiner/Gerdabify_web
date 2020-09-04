#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>

#include "Music_place.h"
#include "User.h"


Musicplace::Musicplace(Music* _pointed_music, UserData user )
{
	pointed_music=_pointed_music;
	current_user=user;
	type="music";
}


Place* Musicplace::goToHome()
{
	Place* temp;
	temp = new Home;
	return temp;
}


Place* Musicplace::goToAlbum()
{
	Place* temp;
	temp = new Albumplace(_pointed_music->get_album(),current_user);
	return temp;
}

Place* Musicplace::goToArtist()
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

void Musicplace::rate(int rate)
{
	if(rate>10 || rate<0)
		throw InvalidArguments();
	else
	{
		pointed_music->rate(rate,current_user) /// esme USER ham mohem
	}
}


string Musicplace::getArtist()
{
	return (pointed_music->get_author()->getUserDetails().firstname + pointed_music->get_author()->getUserDetails().lastname );
}

string Musicplace::getAlbum()
{
	return ( pointed_music->get_album()->get_name() );
}

string Musicplace::getName()
{
	return (pointed_music->get_name());
}

string Musicplace::getCompleteName()
{
	string artist_name,album_name,space,complete_name;
	artist_name=(pointed_music->get_author()->getUserDetails().firstname + pointed_music->get_author()->getUserDetails().lastname );
	album_name=pointed_music->get_album()->get_name();
	space=" - ";
	complete_name=artist_name+space+album_name+space+( pointed_music->get_name() );
	return complete_name;



}

int Musicplace::getRate()
{
	return ( pointed_music->getRate(current_user) );
}

int Musicplace::getUserRate()
{
	return ( pointed_music->getRate_avg() );
}

int Musicplace::getCriticRate()
{
	return ( pointed_music->getRate_critic() );
}
