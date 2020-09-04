#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>

#include "Home.h"


using namespace std;

//typedef vector<string> List;

// efalt constructor

Place* Home::goToHome()
{
	Place* temp;
	temp = new Home;
	return temp;
}

bool Home::goToPlayLists()
{
	return true;
}





bool Home::goToLibrary()
{
	Place* temp;
	temp = new Library;
	return temp;
}

bool Home::goToAlbum()
{
	throw MethodNotAvailable();
}

bool Home::goToArtist()
{
	throw MethodNotAvailable();
}



List Home::list()
{
	List output;
	output.push_back("playlists");
	output.push_back("library");
	return output;
}



string Home::getCompleteName()
{
	string out="Home";
	return out;
}


string Home::getName()
{
	string out="Home";
	return out;
}