
#ifndef ALBUMPLACE_H
#define ALBUMPLACE_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "static_declare.h"


#include "place.h"
#include "Artist_place.h"
#include "album.h"

using namespace std;

//typedef vector<string> List;




class Albumplace: public Place
{
public:

Albumplace(Album* _pointed_album, UserData user );



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
	Album* pointed_album;
	UserData current_user;

	


};









#endif // ALBUMPLACE_H