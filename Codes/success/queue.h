
#ifndef QUEUE_H
#define QUEUE_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>

using namespace std;


class Music;
class Album;



class Queue
{
public:

	 string get_name();
	 vector<Music*> get_musics();
	 void set_music(Music* new_music);
	 void set_album(Album* new_album);
	 vector<string>get_albums();
	 void clear();


	 
private:
	std::vector<Music*> musics;
	string name;


	


};









#endif // PLAYLIST_H