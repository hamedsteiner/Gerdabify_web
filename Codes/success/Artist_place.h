
#ifndef ARTISTPLACE_H
#define ARTISTPLACE_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>

#include "place.h"
#include "static_declare.h"


class Artist;

using namespace std;

class Artistplace: public Place
{
public:

Artistplace(Artist* pointed_artist, UserData user );



Place* goToHome();
Place* goToPlaylists();
Place* goToLibrary();
Place* goToAlbum();
Place* goToArtist();


List list();
List listMusics();

//void play();
//void addTo(string music_thing);
//void remove(string music_name);
void rate(int rate);

string getArtist();
string getAlbum();
string getName();
string getCompleteName();
int getRate();
int getUserRate();
int getCriticRate();







	 
private:
	Artist* pointed_artist;
	UserData current_user;

	


};









#endif // ARTISTPLACE_H