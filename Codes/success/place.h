
#ifndef PLACE_H
#define PLACE_H

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

using namespace std;

class User;




class Place
{
public:

Place* goToHome();
bool goToPlayLists();
Place* goToLibrary();
Place* goToAlbum();
Place* goToArtist();


List list();
List listMusics();
List listAlbums();
List listPlaylists();
List listArtists();

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

virtual string get_type();






	 
protected:

string type;
	


};









#endif // PLACE_H