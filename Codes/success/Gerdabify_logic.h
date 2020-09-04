
#ifndef GERDABIFY_LOGIC_H
#define GERDABIFY_LOGIC_H

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
#include "artist.h"

/*
#include "Artist.h"
#include "admin.h"
#include "Database.h"*/

using namespace std;

//#include "Database.h"


class User;
class Artist;

class Gerdabify_logic
{
public:
    bool Is_iterative(UserData _new_user);

    void signup(UserData new_user, string password);
    void login(string user_name, string password);


    void enterBrowserMode();
    void enterPlayMode();  





    void addMusic(string, string);
    void addAlbum(string, string);

    List get_artists_name(string token);
    List get_musics_name(string token);
    List get_albums_name(string token);
    List get_playlists_name(string token);
    List search(string token, string word);




    void createPlaylist(string name);


   /* void validate();



    void goToHome();
    void goToPlayLists();
    void goToLibrary();
    void goToAlbum();
    void goToArtist();

    List search(string);
    void select(string);
    
    List list();
    List listMusics();
    List listAlbums();
    List listPlaylists();
    List listArtists();

    //void play();
    //void addTo(string);
    void goTo(string);
   /* void createPlaylist(string);
    void clearPlaylist(string);
    void remove(string);
    void orderItem(string, int);*/



    /*
    void rate(int);
    string getArtist();
    string getAlbum();
    int getLength();
    string getName();
    string getCompleteName();
    int getRate();
    int getUserRate();
    int getCriticRate();

    /*
    void next();
    void previous();
    void pause();
    void seek(int, int);
    void shuffle();
    void repeatOne();
    void repeat();*/



    UserData getUserDetails(string);
    //void verifyUser(string);	



	 
private:
	std::vector<User*> users;
	User* active_user;
	//Database main_database;
    vector<User*> user_artists;



};









#endif // GERDABIFY_LOGIC_H