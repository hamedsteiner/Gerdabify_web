
#ifndef HOME_H
#define HOME_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "place.h"

using namespace std;




class Home : public Place
{
public:

Place* goToHome();
bool goToPlaylists();
Place* goToLibrary();
Place* goToAlbum();
Place* goToArtist();


List list();


string getName();
string getCompleteName();





	 
private:

	


};









#endif // HOME_H
