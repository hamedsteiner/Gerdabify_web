
#ifndef USER_H
#define USER_H

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
#include "static_declare.h"




/*
#include "Album_place.h"

#include "Artist_place.h"

#include "place.h"

#include "Library.h"

#include "Music_place.h"

#include "playlist.h"

#include "Database.h"*/


//#include "database.h"

#include "playlist.h"


using namespace std;
//class Database;
enum Mode {Browse, Player};
/*
class Playlist;
class Queue;
class Artist_place;
class Album_place;
class Library;
class Album_place;
class Place;
class Database;
class Music;
*/
class User
{
public:
	//// constructor baa this_person


// user funcs ***
 //User(UserData _this_person,string _password);

virtual void set_person(UserData _this_person){this_person=_this_person;}
virtual void set_password(string _password){password=_password;}
 virtual UserData getUserDetails();
/*virtual*/  string get_password();



virtual void enterBrowserMode();
virtual void enterPlayMode();
virtual vector<Playlist*> get_playlists(){return playlists; }


virtual void addMusic(string music_name,string file_path);
virtual void addAlbum(string artist_name,string album_name);

virtual void createPlaylist(string new_playlist);






/*
//over ride
virtual void validate();



////////////////////////////////////////////////////////


virtual void goToHome();
virtual void goToPlayLists();
virtual void goToLibrary();
virtual void goToAlbum();
virtual void goToArtist();
virtual List list();
virtual List listMusics();
virtual List listAlbums();
virtual List listPlaylists();
virtual List listArtists();

virtual void rate(int rate);
virtual string getArtist();
virtual string getAlbum();
virtual int getLength();
virtual string getName();
virtual string getCompleteName();
virtual int getRate();
virtual int getUserRate();
virtual int getCriticRate();




virtual void goTo(string _playlist_name); // playlist * bere 


virtual List search(string all_music_things); /// bere to user


virtual void select(string music_thing); /// music, album ,artist , playlist






virtual void clearPlaylist(string _playlist_name);





/*void orderItem(string music_name, int order);
virtual void addTo(string music_thing);
void next();
void previous();
void pause();
void seek(int, int);
void shuffle();
void repeatOne();
void repeat();
//////////////////////////FOR PLACE
void play();
void remove(string music_name);







*/


/// hame male place ro inja benevism

	 
protected:
	//Place* current_place;

	vector<Playlist*> playlists;
	Playlist* current_playlist;
	//Queue queue;

	Mode current_mode;

	//Database* database;


	string password;
	UserData this_person;

	
};









#endif // USER_H