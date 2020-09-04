
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>

#include "User.h"
//#include "rated_object.h"
//#include "Artist.h"
//#include "database.h"


#include "artist.h"
using namespace std;


 ///////////////////// initial place to home , friend vclasss place

class Database;


/*User::User(UserData _this_person,string _password) /// virtual constructor
{
	this_person=_this_person;
	password=_password;
	//current_place=new Home;
}*/

 UserData User::getUserDetails()
{
	return this_person;
}
 string User::get_password()
{
	return password;
}

 void User::enterBrowserMode()
{
    current_mode=Browse;
}
 void User::enterPlayMode()
{
    current_mode=Player;
}






/*
 void User::validate()
{
	// if admin  not
	throw MethodNotAvailable();
	// 
}
*/
 void User::addMusic(string music_name,string file_path)
{
	throw NotAuthorized();
}
 void User::addAlbum(string artist_name,string album_name)
{
	throw NotAuthorized();
}


 void User::createPlaylist(string new_playlist) // to data base asli hm eafe she
{
    for (int i = 0; i < playlists.size(); i++)
    {
        if(playlists[i]->get_name()==new_playlist)
            throw AlreadyExists();
    }
    Playlist* n_playlist=new Playlist;
    n_playlist->set_name(new_playlist);
    
    playlists.push_back(n_playlist) ;

}




















/*

  void User::goToHome() // chjori palce pointer bayad bargardonim ???
{
    Place* temp;
    temp=current_place->goToHome();
    delete current_place;
    current_place=temp;
}
 void User::goToPlayLists()
{
    bool flag;
    Place* temp;
    flag=current_place->goToPlayLists();
    if(flag==true)
    {
        delete current_place;
        temp=new Playlist_place(playlists,current_playlist,this_person.username);
        current_place=temp;
    }
}
 void User::goToLibrary()
{
    Place* temp;
    temp=current_place->goToLibrary();
    delete current_place;
    current_place=temp;
    dynamic_cast<Library*>(current_place)->set_db(database);

}
 void User::goToAlbum()
{
    current_place=current_place->goToHome();
}

 void User::goToArtist()
{
    current_place=current_place->goToHome();
}




 List User::list()
{
   return (current_place->list());
}

 List User::listMusics()
{
   return current_place->listMusics();
}

 List User::listAlbums()
{
   return current_place->listAlbums();
}

 List User::listPlaylists()
{
   return current_place->listPlaylists();
}

 List User::listArtists()
{
    return current_place->listArtists();
}

 void User::rate(int thing)
{
    current_place->rate(thing);
}

 string User::getArtist()
{
    return current_place->getArtist();
}
 string User::getAlbum()
{
    return current_place->getAlbum();
}

 string User::getName()
{
    return current_place->getName();
}
 string User::getCompleteName()
{
    return current_place->getCompleteName();
}

 int User::getRate()
{
    return current_place->getRate();
}

 int User::getUserRate()
{
    return current_place->getUserRate();
}

 int User::getCriticRate()
{
    return current_place->getCriticRate();
}



  void User::goTo(string _playlist_name) // should queue and playlist be one kind? and what should our current  playlist* if we use queue
{
    ///????...
    Playlist* temp;
    bool is_queue=false;
    for (int i=0 ; i<playlists.size();i++)
    {   if(playlists[i]->get_name()==_playlist_name)
        {
            temp=playlists[i];
            break;
        }
        else if("queue"==_playlist_name)
        {
            is_queue=true;
            break;
        }
        else
            throw ItemDoesNotExists();
    }

    if(is_queue==true)
    {
        delete current_place;
        current_place=new Queue_place();
    }
    else
    {
        delete current_place;
        current_place=new Playlist_place(temp,this_person.username);

    }

}


   List User::search(string thing) // mage data base asli liste pakhsh haro hm dare?
{
    List output;

    output=(database->search_all(thing));
    for(int i=0;i<playlists.size();i++)
    {
        if(playlists[i]->get_name()==thing)
            output.push_back(this_person.username+" - "+ thing);
    }
    return output;
}







/*virtual *//* void User::addTo(string thing)
    {
        if(current_place->get_type()!="music" || current_place->get_type()!="album")
        {
            throw MethodNotAvailable();
        }
        else
        {
            current_place->addTo(thing);

        }
    
    }




*/





/*
  void User::select(string thing)//music album play list
{
    bool available=false;

    for(int i=0;i<playlists.size();i++)
    {
        if(playlists[i]->get_name()==thing) // bayad dorost she va cureent play list po  ..
        {
            available=true;
            delete current_place;
            current_place=new Playlist_place(playlists,playlists[i],this_person.username);
            break;

        }
    }
    if(available==false)
    {
        vector<Artist*> temp_artists=database->get_artists();;
        for(int i=0;i<(database->get_artists()).size();i++)
            if(temp_artists[i]->get_name()==thing)
            {
                available=true;
                delete current_place;
                current_place=new Artistplace(temp_artists[i],this_person);
                break;

            }

    }

    if(available==false)
    {
        for(int i=0;i<database->get_albums().size();i++)
            if(database->get_albums()[i]->get_name()==thing)
            {
                available=true;
                delete current_place;
                current_place=new Albumplace(database->get_albums()[i],this_person);
                break;

            }

    }    
     
    if(available==false)
    {
        for(int i=0;i<database->get_musics().size();i++)
            if(database->get_musics()[i]->get_name()==thing)
            {
                available=true;
                delete current_place;
                current_place=new Musicplace(database->get_musics()[i],this_person);
                break;

            }

    }
}











 void User::clearPlaylist(string _playlist_name)  // remove VS erase
{
    Playlist* temp;
    for (int i = 0; i < playlists.size(); i++)
    {
        if(playlists[i]->get_name()==_playlist_name)
        {
            temp=playlists[i];
            break;
        }
    }
    temp->clear();

    

}




/*
virtual void User::orderItem(string music_name, int order)
{

}


/*




virtual void User::next();
virtual void User::previous();
virtual void User::pause();
virtual void User::seek(int, int);
virtual void User::shuffle();
virtual void User::repeatOne();
virtual void User::repeat();

    void User::play()
    {
        current_place->play();
    }

    

	void User::remove(string thing)     /////////////////????????????
    {
        current_place->remove(thing);
    }

   */