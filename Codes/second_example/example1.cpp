#include <iostream>
#include <map>
#include <string>
#include "../src/gerdabServer.hpp"
#include "../success/Gerdabify_logic.h"
#include "../success/User.h"
#include "../success/artist.h"
//#include "../success/api.hpp"
#include "../success/rated.h"
#include "../success/music.h"
#include "../success/album.h"
#include "../success/exception.h"
#include "signup.h"
#include "login.h"

class HomePageHandler: public RequestHandler
{
    void callback(Request* req, Response* res) 
    {
        cout<<req->getParam("token")<<endl;
        res->body << "<body>"<< "<input type="<<'"'<<"button"<<'"' <<" onclick="<<'"'<<"alert"<<'('<<"'"<<"tnx for your like"<<"'"<<')'<<'"'<<"value="<<'"'<<"Gimme a like!"<<'"'<<">"
        <<
        "<h1>GerdabServer</h1><p>This is Gerdab Server Home Page</p></body>";
    }
};



class FormHandler: public RequestHandler
{
    void callback(Request* req, Response* res)
    {
        cout<<req->getParam("token")<<endl;

        res->body << "<form><input type=" << '"' <<"text"<< '"' 
        <<
        "name="<<

         '"'<< "username" << '"'
        << "/><br /><input type= 'password' name= 'password' /></form>";
    }
};




class MusicsHandler: public RequestHandler
{
public:

	void set_conncetion(Gerdabify_logic* client_user)
	{
		offline_api =client_user;
	}


	void callback(Request* req, Response* res) 
    {
    	string token;
        token=req->getParam("token");
        List out;
        out=offline_api->get_musics_name(token);
		res->body<< "<!DOCTYPE html><html><head>"<<"<link rel="<<'"'<<"stylesheet"<<'"'<<" href="<<
		'"'<<"styles.css"<<'"'<<">"<<
		"<style>table, th, td {border: 1px solid black;}"
		<<"table#t01 {width: 100%;background-color: #f1f1c1;}"<<
		"table#t01tr:nth-child(even){background-color: #eee;}table#t01 tr:nth-child(odd) {background-color:#fff;}table#t01 th {background-color: black;color: white;}"
		<<"</style></head>";

        res->body << "<body>"<<"<img src="<<'"'<<"img_girl.jpg"<<'"'<<" alt=" <<'"'<<"Girl with a jacket"<<'"'<<" width="<<'"'<<500<<" height="
        <<'"'<<"600"<<'"'<<">"<<
        "<h1 style="<<"color:blue;"<<">GerdabMusics</h1><p>This is Gerdab Musics List</p>";


		res->body <<"<table id=" <<"t01"<< "%"<< 
		">"<<"<tr><th>Artist  -  Album  -  Music</th></tr>";

		for(int i=0;i<out.size();i++)
		{
			res->body <<"<tr><td>"<<out[i]<<"</td></tr>";
		}
		
        res->body <<"</body></html>";
    }
private:
	Gerdabify_logic* offline_api;
};






class AlbumsHandler: public RequestHandler
{
public:

	void set_conncetion(Gerdabify_logic* client_user)
	{
		offline_api =client_user;
	}


	void callback(Request* req, Response* res) 
    {
    	string token;
        token=req->getParam("token");
        List out;


        out=offline_api->get_albums_name(token);
		res->body<< "<!DOCTYPE html><html><head>"<<"<link rel="<<'"'<<"stylesheet"<<'"'<<" href="<<
		'"'<<"styles.css"<<'"'<<">"<<
		"<style>table, th, td {border: 1px solid black;}"
		<<"table#t01 {width: 100%;background-color: #f1f1c1;}"<<
		"table#t01tr:nth-child(even){background-color: #eee;}table#t01 tr:nth-child(odd) {background-color:#fff;}table#t01 th {background-color: black;color: white;}"
		<<"</style></head>";

        res->body << "<body>"<<"<img src="<<'"'<<"img_girl.jpg"<<'"'<<" alt=" <<'"'<<"Girl with a jacket"<<'"'<<" width="<<'"'<<500<<" height="
        <<'"'<<"600"<<'"'<<">"<<
        "<h1 style="<<"color:blue;"<<">GerdabAlbumss</h1><p>This is Gerdab albums List</p>";


		res->body <<"<table id=" <<"t01"<< "%"<< 
		">"<<"<tr><th>Artist  -  Album</th></tr>";

		for(int i=0;i<out.size();i++)
		{
			res->body <<"<tr><td>"<<out[i]<<"</td></tr>";
		}
		
        res->body <<"</body></html>";
    }
private:
	Gerdabify_logic* offline_api;
};


class PlaylistMaker: public RequestHandler
{
public:

	void set_conncetion(Gerdabify_logic* client_user)
	{
		offline_api =client_user;
	}


	void callback(Request* req, Response* res) 
    {
    	string token,name;
        token=req->getParam("token");
        cout<<token;
        name=req->getParam("name");
        cout<<name;
        try
        {
	        offline_api->createPlaylist(name);

	        res->body << "<body><h1>Operation Successful</h1><p>New playlist has been created with the name :</p>";
	        res->body<<"<h1 style="<<"color:blue;"<<">"<<name<<"</h1>";
	        res->body <<"</body>";
	    }
	    catch(AlreadyExists e )
	    {
	    	res->body << "<body><h1>Operation failed</h1><p>another playlist already exists with the name :</p>";
	        res->body<<"<h1 style="<<"color:blue;"<<">"<<name<<"</h1>";
	        res->body <<"</body>";
	    }
    }

private:
	Gerdabify_logic* offline_api;
};



class PlaylistHandler: public RequestHandler
{
public:

	void set_conncetion(Gerdabify_logic* client_user)
	{
		offline_api =client_user;
	}


	void callback(Request* req, Response* res) 
    {
    	string token;
        token=req->getParam("token");
        List out;
        out=offline_api->get_playlists_name(token);
        res->body<< "<!DOCTYPE html><html><head>"<<"<link rel="<<'"'<<"stylesheet"<<'"'<<" href="<<
		'"'<<"styles.css"<<'"'<<">"<<
		"<style>table, th, td {border: 1px solid black;}"
		<<"table#t01 {width: 100%;background-color: #f1f1c1;}"<<
		"table#t01tr:nth-child(even){background-color: #eee;}table#t01 tr:nth-child(odd) {background-color:#fff;}table#t01 th {background-color: black;color: white;}"
		<<"</style></head>";

        res->body << "<body>"<<"<img src="<<'"'<<"img_girl.jpg"<<'"'<<" alt=" <<'"'<<"Girl with a jacket"<<'"'<<" width="<<'"'<<500<<" height="
        <<'"'<<"600"<<'"'<<">"<<
        "<h1 style="<<"color:blue;"<<">GerdabPlaylists</h1><p>This is Gerdab Playlists</p>";


		res->body <<"<table id=" <<"t01"<< "%"<< 
		">"<<"<tr><th>Playlist</th></tr>";

		for(int i=0;i<out.size();i++)
		{
			res->body <<"<tr><td>"<<out[i]<<"</td></tr>";
		}
		
        res->body <<"</body></html>";
    }
private:
	Gerdabify_logic* offline_api;
};




class SearchHandler: public RequestHandler
{
public:

	void set_conncetion(Gerdabify_logic* client_user)
	{
		offline_api =client_user;
	}


	void callback(Request* req, Response* res) 
    {
    	string token,keyword;
        token=req->getParam("token");
        keyword=req->getParam("keyword");
        List out;
        out=offline_api->search(token,keyword);
        res->body<< "<!DOCTYPE html><html><head>"<<"<link rel="<<'"'<<"stylesheet"<<'"'<<" href="<<
		'"'<<"styles.css"<<'"'<<">"<<
		"<style>table, th, td {border: 1px solid black;}"
		<<"table#t01 {width: 100%;background-color: #f1f1c1;}"<<
		"table#t01tr:nth-child(even){background-color: #eee;}table#t01 tr:nth-child(odd) {background-color:#fff;}table#t01 th {background-color: black;color: white;}"
		<<"</style></head>";

        res->body << "<body>"<<"<img src="<<'"'<<"img_girl.jpg"<<'"'<<" alt=" <<'"'<<"Girl with a jacket"<<'"'<<" width="<<'"'<<500<<" height="
        <<'"'<<"600"<<'"'<<">"<<
        "<h1 style="<<"color:blue;"<<">Search music</h1><p>This is your enquiry</p>";


		res->body <<"<table id=" <<"t01"<< "%"<< 
		">"<<"<tr><th>Founded musics with " <<keyword<<"</th></tr>";

		for(int i=0;i<out.size();i++)
		{
			res->body <<"<tr><td>"<<out[i]<<"</td></tr>";
		}
		
        res->body <<"</body></html>";
    }
private:
	Gerdabify_logic* offline_api;
};


















int main(int argc, const char* argv[]) {
    try 
    {
        
    	Gerdabify_logic client_user;

    	UserData a,c,d,e;
		a.firstname="hamed";
		a.lastname="rahmani";
		a.username="steiner";
		a.userType=Artist;
		std::string b="hamed123";
		client_user.signup(a,b);
		client_user.login(a.username,b);
		client_user.createPlaylist("SLlist");
		client_user.addMusic("pesare bi adab","khone babash");
		client_user.addMusic("gangestere kachal","khone nanash");
		client_user.addAlbum("gangestere ","hentai");

		std::vector<std::string>ggg;
		//ggg=client_user.get_playlists_name();
	    //for(int i=0;i<ggg.size();i++)
		//cout<<ggg[i]<<endl;
		c.firstname="a";
		c.lastname="a";
		c.username="a";
		c.userType=Artist;
		//client_user.signup(c,b);



		//client_user.login(a.username,b);
		/*user.signup(a,b);
		
		user.createPlaylist("Ab o piss");
		std::vector<std::string>ggg;
		ggg=user.get_playlists_name();
	    for(int i=0;i<ggg.size();i++)
		cout<<ggg[i]<<endl;*/
        Server server;

        RequestHandler* homePage = new HomePageHandler();
        RequestHandler* form = new FormHandler();

        RequestHandler* signup = new SignupHandler();
        RequestHandler* login = new LoginHandler();
        RequestHandler* musics = new MusicsHandler();
        RequestHandler* albums = new AlbumsHandler();
        RequestHandler* playlistmaker = new PlaylistMaker();
        RequestHandler* playlists = new PlaylistHandler();
        RequestHandler* search = new SearchHandler();

        dynamic_cast<SignupHandler*>(signup)->set_conncetion(& client_user);
        dynamic_cast<LoginHandler*>(login)->set_conncetion(& client_user);
        dynamic_cast<MusicsHandler*>(musics)->set_conncetion(& client_user);
        dynamic_cast<AlbumsHandler*>(albums)->set_conncetion(& client_user);
        dynamic_cast<PlaylistMaker*>(playlistmaker)->set_conncetion(& client_user);
        dynamic_cast<PlaylistHandler*>(playlists)->set_conncetion(& client_user);
        dynamic_cast<SearchHandler*>(search)->set_conncetion(& client_user);

        server.get("/home", homePage);
        server.post("/form", form);
        server.post("/signup", signup);
        server.post("/login", login);
        server.get("/musics", musics);
        server.get("/albums", albums);
        server.get("/playlists", playlists);
        server.post("/playlists", playlistmaker);
         server.post("/search", search);

        cout << "Listening on port 5000" << endl;
        server.start(5000);




    } catch(Exception e) {
        cerr << "WebServer: " << e.getMessage() << endl;
    }

    return EXIT_SUCCESS;
}
