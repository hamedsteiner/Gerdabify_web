
#ifndef MUSICPLACE_H
#define MUSICPLACE_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "music.h"
#include "place.h"
using namespace std;


//class Music;

class Musicplace: public Place
{
public:

Musicplace(Music* _pointed_music, UserData user );



Place* goToHome();
Place* goToAlbum();
Place* goToArtist();



//void play();
//void addTo(string music_thing);
//void remove(string music_name);
void rate(int rate);

string getArtist();
string getAlbum();
string getName();
string getCompleteName();
int getRate(UserData user);
int getUserRate();
int getCriticRate();







	 
private:
	Music* pointed_music;
	UserData current_user;

	


};









#endif // MUSICPLACE_H