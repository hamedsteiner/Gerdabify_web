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
#include "artist.h"
#include "Gerdabify_logic.h"
#include "rated.h"
#include "music.h"
#include "album.h"


using namespace std;




int main()
{
	Gerdabify_logic r;
	string b;
	vector<string>ggg;
	b="hamed123";

	UserData a,c,d,e;
	a.firstname="hamed";
	a.lastname="rahmani";
	a.username="steiner";
	a.userType=Artist;

	c.firstname="sheri";
	c.lastname="killer";
	c.username="shalil";
	c.userType=Artist;


	r.signup(a,b);
	//cout<<"1"<<endl;

	r.login(a.username,b);

	r.addAlbum("SHOMBOL","TALA");
	//cout<<"2"<<endl;
	r.addMusic("pesare gozo","khone babash");
	r.addMusic("pesare shasho","khone nanash");
	r.createPlaylist("AN o GOH");




	//cout<<"3"<<endl;
	//ggg=r.get_artists_name();
	//cout<<ggg[0]<<endl;
	//ggg=r.get_albums_name();
	//ggg=r.get_musics_name();

	//ggg=r.get_playlists_name();
	



	//cout<<"4"<<endl;


	for(int i=0;i<ggg.size();i++)
		cout<<ggg[i]<<endl;Artistt

	//cout<<"5"<<endl;
		

	
	


	
}

"<!DOCTYPE html><html><head><title>My Blog</title>
<link href=" 'https://fonts.googleapis.com/css?family=Handlee" rel="stylesheet">
</head>
<body>
<!-- Form section start -->
<div class="section">
<h1><span>Contact Me</span></h1>
<form>
<input name="name" type="text" /><br/>
<input name="email" type="email" /><br/>
<textarea name="message" ></textarea>
<input type="submit" value="SEND" class="submit" />
</form></div><!-- Form section end --></body></html>'








"<form><input type= 'text' name= 'username'' /><br /><input type= 'password name= 'password' /></form>"