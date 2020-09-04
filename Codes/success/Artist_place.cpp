#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>


#include "Artist.h"

#include "Artist_place.h"


using namespace std;


Place* Artistplace::goToHome()
{
	Place* temp;
	temp = new Home;
	return temp;
}



/////////////////////////////////////////////////////////
/*

void Artistplace::play()
{
	throw MethodNotAvailable();
}
void Artistplace::addTo(string music_thing)
{
	throw MethodNotAvailable();
}

*/
///////////////////////////////////////////////////////////

Artistplace::Artistplace(Artist* _pointed_artist, UserData username )
{
	type="artist";
	pointed_artist=_pointed_artist;
	current_user=username;
}



List Artistplace::list()
{
	vector<Album*> temp;
	List output;
	temp=pointed_artist->get_albums();
	for(int i=0;i<temp.size();i++)
		output.push_back(temp[i]->get_name());
	return output;

}
List Artistplace::listMusics()/// az album ham misshe add kard
{
	vector<Music*> temp;
	List output;
	temp=pointed_artist->get_musics();
	for(int i=0;i<temp.size();i++)
		output.push_back(temp[i]->get_name());
	return output;
}

List Artistplace::listAlbums()
{
	vector<Album*> temp;
	List output;
	temp=pointed_artist->get_albums();
	for(int i=0;i<temp.size();i++)
		output.push_back(temp[i]->get_name());

	return output;

}



void Artistplace::rate(int rate)
{
	if(rate>10 || rate<0)
		throw InvalidArguments();
	else
		pointed_artist->rate(rate,current_username) /// esme USER ham mohem
}


string Artistplace::getName()
{
	return (pointed_artist->get_name());
}

string Artistplace::getCompleteName()
{
	return (pointed_artist->get_name());
}

int Artistplace::getRate()
{
	return ( pointed_artist->getRate(current_user) );
}

int Artistplace::getUserRate()
{
	return ( pointed_artist->getRate_avg() );
}

int Artistplace::getCriticRate()
{
	return ( pointed_artist->getRate_critic() );
}
