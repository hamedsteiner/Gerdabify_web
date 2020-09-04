#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "Gerdabify_logic.h"
//#include "User.h"
#include "User.h"
#include "music.h"
#include "album.h"
using namespace std;


class Artistt;





    bool Gerdabify_logic::Is_iterative(UserData _new_user)
    {
        for(int i=0;i<users.size();i++)
            if(users[i]->getUserDetails().username == _new_user.username || 
               users[i]->getUserDetails().firstname == _new_user.firstname ||
               users[i]->getUserDetails().lastname == _new_user.lastname
               )
                return true;
        return false;
    }



    void Gerdabify_logic::signup(UserData _new_user, string password)//////// no vverify in PROJECT
    {
        if(Is_iterative(_new_user)==true)
            throw AlreadyExists();
        else
        {
            User* new_user;

            if(_new_user.userType==Admin)
            {
                 new_user=new User;//Admin
                 new_user->set_person(_new_user);
                 new_user->set_password(password);
            }

            else if(_new_user.userType==Artist)
            {
                 new_user=new Artistt;//Artist////////////////////////////////////nashod !
                 new_user->set_person(_new_user);
                 new_user->set_password(password);
                 user_artists.push_back(new_user);
            }
            else if(_new_user.userType==Editor)
            {
                 new_user=new User;//Editor
                 new_user->set_person(_new_user);
                 new_user->set_password(password);
            }
            else
            {
                 new_user=new User;
                 new_user->set_person(_new_user);
                 new_user->set_password(password);
            }
            users.push_back(new_user);
        }
         cout<<"sakhti\n";
        
    }
    void Gerdabify_logic::login(string user_name, string password)
    {
        bool exist=false;
        for(int i=0;i<users.size();i++)
            if(users[i]->getUserDetails().username==user_name)
                if(users[i]->get_password()==password)
                {
                    active_user=users[i];
                    cout<<"welcome \n";
                    exist=true;
                }
                else
                    throw InvalidCredentials();


        if(exist==false)
        {
            throw ItemDoesNotExists();
        }
    }


    void Gerdabify_logic::enterBrowserMode()
    {
        active_user->enterBrowserMode();
    }
    void Gerdabify_logic::enterPlayMode()
    {
        active_user->enterPlayMode();
    }
    

    void Gerdabify_logic::addMusic(string music, string path)
    {
        active_user->addMusic(music,path);

    }


    void Gerdabify_logic::addAlbum(string artist_name, string album_name)
    {
        active_user->addAlbum(artist_name,album_name);
    }







    List  Gerdabify_logic::get_artists_name(string token)
    {
        if(token!= active_user->getUserDetails().username)
            throw InvalidCredentials();///////////
        else
        {
            List out;
            vector<User*> temp_u=user_artists;
         
            for(int i=0;i<temp_u.size();i++)
                out.push_back(temp_u[i]->get_password());
            return out;
        }

    }


    List  Gerdabify_logic::get_musics_name(string token)
    {
        if(token!= active_user->getUserDetails().username)
            throw InvalidCredentials();///////////
        else
        {
            List out;
            vector<User*> temp=user_artists;
            vector<Music*>temp_m;
            //cout<<temp_m.size()<<endl;
            for(int i=0;i<temp.size();i++)
            {
            string aaa;
               temp_m=dynamic_cast<Artistt *>(temp[i])->get_musics();
               cout<<"";
               //cout<<temp_m.size()<<endl;
               for(int j=0;j<temp_m.size();j++)
               {
                    if(temp_m[j]->get_album() == NULL)
                    {
                        aaa=" < "+(temp_m[j]->get_artist()->getUserDetails().firstname + " "+temp_m[j]->get_artist()->getUserDetails().lastname )+" > " + " - " + " < No Artist Assigned > " + " - " + " < "+temp_m[j]->get_name()+" > ";
                    }
                    else
                    {
                        aaa=" < " +(temp_m[j]->get_artist()->getUserDetails().firstname + " "+temp_m[j]->get_artist()->getUserDetails().lastname )+ " > "+ " - " + " < "+temp_m[j]->get_album()->get_name()+" > " + " - "  + " < "+temp_m[j]->get_name()+" > ";
                    }
                    
                    out.push_back(aaa);
               }
                //temp_m.clear();
             
            }
            cout<<"";
            return out;
        }

    }

    List  Gerdabify_logic::get_albums_name(string token)
    {
        if(token!= active_user->getUserDetails().username)
            throw InvalidCredentials();///////////
        else
            {
            string aaa;
            List out;
            vector<User*> temp=user_artists;
            vector<Album*>temp_a;
            //cout<<temp_m.size()<<endl;
            for(int i=0;i<temp.size();i++)
            {
               temp_a=dynamic_cast<Artistt *>(temp[i])->get_albums();

               cout<<temp_a.size()<<endl;
               for(int j=0;j<temp_a.size();j++)
                    out.push_back(" < " +(temp_a[j]->get_artist()->getUserDetails().firstname + " "+temp_a[j]->get_artist()->getUserDetails().lastname )+ " > "+ " - " + " < "+ temp_a[j]->get_name() + " > ");
                //temp_m.clear();
             
            }
            return out;
        }

    }


    List  Gerdabify_logic::get_playlists_name(string token)
    {
        if(token!= active_user->getUserDetails().username)
            throw InvalidCredentials();///////////
        else
        {
            List out;
            vector<Playlist*>temp_p;
            //cout<<temp_m.size()<<endl;
            for(int i=0;i<users.size();i++)
            {
               temp_p=(users[i])->get_playlists();
               //cout<<temp_a.size()<<endl;
               for(int j=0;j<temp_p.size();j++)
                    out.push_back(" < " + users[i]->getUserDetails().username +" > " + " - "+" < "+ temp_p[j]->get_name()+ " > ");
                //temp_m.clear();
             
            }
            for(int i=0;i<out.size();i++)
        cout<<out[i]<<endl;
            return out;
        }

    }



    void Gerdabify_logic::createPlaylist(string thing)
    {
        active_user->createPlaylist(thing);
    }






List  Gerdabify_logic::search(string token, string word)
{
    if(token!= active_user->getUserDetails().username)
            throw InvalidCredentials();///////////
        else
        {
            List out;
            string music_name;
            vector<User*> temp=user_artists;
            vector<Music*>temp_m;
            //cout<<temp_m.size()<<endl;
            for(int i=0;i<temp.size();i++)
            {
                string aaa;
               temp_m=dynamic_cast<Artistt *>(temp[i])->get_musics();
               cout<<"";
               //cout<<temp_m.size()<<endl;
               for(int j=0;j<temp_m.size();j++)
               {
                    music_name=temp_m[j]->get_name();
                    if(music_name.find(word) != std::string::npos)
                    {


                        if(temp_m[j]->get_album() == NULL)
                        {
                            aaa=" < "+(temp_m[j]->get_artist()->getUserDetails().firstname + " "+temp_m[j]->get_artist()->getUserDetails().lastname )+" > " + " - " + " < No Artist Assigned > " + " - " + " < "+temp_m[j]->get_name()+" > ";
                        }
                        else
                        {
                            aaa=" < " +(temp_m[j]->get_artist()->getUserDetails().firstname + " "+temp_m[j]->get_artist()->getUserDetails().lastname )+ " > "+ " - " + " < "+temp_m[j]->get_album()->get_name()+" > " + " - "  + " < "+temp_m[j]->get_name()+" > ";
                        }
                        
                        out.push_back(aaa);
                    }
                }
                //temp_m.clear();
             
            }
            cout<<"";
            return out;
        }
}
















/*
    void Gerdabify_logic::validate()
    {
        active_user->validate();
    }


    
    void Gerdabify_logic::goToHome()
    {
        active_user->goToHome();
    }
    void Gerdabify_logic::goToPlayLists()
    {
        active_user->goToPlayLists();
    }

    void Gerdabify_logic::goToLibrary()
    {
        active_user->goToLibrary();
    }

    void Gerdabify_logic::goToAlbum()
    {
        active_user->goToAlbum();
    }

    void Gerdabify_logic::goToArtist()
    {
        active_user->goToArtist();
    }


    List Gerdabify_logic::search(string thing)
    {
        active_user->search(thing);
    }

    void Gerdabify_logic::select(string thing)
    {
        active_user->select(thing);
    }

    
    List Gerdabify_logic::list()
    {
        active_user->list();
    }

    List Gerdabify_logic::listMusics()
    {
        active_user->listMusics();
    }

    List Gerdabify_logic::listAlbums()
    {
        active_user->listAlbums();
    }

    List Gerdabify_logic::listPlaylists()
    {
        active_user->listPlaylists();
    }

    List Gerdabify_logic::listArtists()
    {
        active_user->listArtists();
    }

     void Gerdabify_logic::rate(int thing)
    {
        active_user->rate(thing);
    }

    string Gerdabify_logic::getArtist()
    {
        active_user->getArtist();
    }

    string Gerdabify_logic::getAlbum()
    {
        active_user->getAlbum();
    }

    int Gerdabify_logic::getLength()
    {
        active_user->getLength();
    }

    string Gerdabify_logic::getName()
    {
        active_user->getName();
    }

    string Gerdabify_logic::getCompleteName()
    {
        active_user->getCompleteName();
    }

    int Gerdabify_logic::getRate()
    {
        active_user->getRate();
    }

    int Gerdabify_logic::getUserRate()
    {
        active_user->getUserRate();
    }

    int Gerdabify_logic::getCriticRate()
    {
        active_user->getCriticRate();
    }
     void Gerdabify_logic::goTo(string thing)
    {
        active_user->goTo(thing);
    }   



    void Gerdabify_logic::play()
    {
        active_user->play();
    }





    void Gerdabify_logic::addTo(string thing)
    {
        active_user->addTo(thing);
    }
   

    void Gerdabify_logic::createPlaylist(string thing)
    {
        active_user->createPlaylist(thing);
    }

    void Gerdabify_logic::clearPlaylist(string thing)
    {
        active_user->clearPlaylist(thing);
    }








    void Gerdabify_logic::remove(string thing)
    {
        active_user->remove(thing);
    }

    void Gerdabify_logic::orderItem(string thing, int order)
    {
        active_user->orderItem(thing,order);
    }


    void Gerdabify_logic::next()
    {
        active_user->next();
    }

    void Gerdabify_logic::previous()
    {
        active_user->previous();
    }

    void Gerdabify_logic::pause()
    {
        active_user->pause();
    }

    void Gerdabify_logic::seek(int minute, int second)
    {
        active_user->seek(int minute, int second);
    }

    void Gerdabify_logic::shuffle()
    {
        active_user->shuffle();
    }

    void Gerdabify_logic::repeatOne()
    {
        active_user->repeatOne();
    }

    void Gerdabify_logic::repeat()
    {
        active_user->repeat();
    }

*/

////////////////over ride mishe


    









    UserData Gerdabify_logic::getUserDetails(string user_name)
    {
        bool exist=false;
        for(int i=0;i<users.size();i++)
            if(users[i]->getUserDetails().username==user_name)
                {//if(users[i]->get_password()==password)
                //{
                    exist=true;
                    return users[i]->getUserDetails();
                }

        if(exist==false)
            throw InvalidCredentials();
    }

    //void verifyUser(string);





