all: example1 gerdabServer.o web++.o Gerdabify_logic.o User.o rated.o playlist.o  artist.o  album.o music.o database.o

example1: web++.o gerdabServer.o Gerdabify_logic.o User.o rated.o playlist.o  artist.o  album.o music.o database.o  examples/example1.cpp
		g++ -std=c++11 web++.o gerdabServer.o Gerdabify_logic.o User.o rated.o playlist.o  artist.o  album.o music.o database.o  examples/example1.cpp -o example1.out

gerdabServer.o: gerdabServer.cpp
		g++ -std=c++11 -c gerdabServer.cpp -o gerdabServer.o

web++.o: web++.cpp
		g++ -std=c++11 -c web++.cpp -o web++.o
#include "../src/gerdabServer.hpp"


database.o: success/database.cpp
	g++ -c success/database.cpp

User.o: success/User.cpp 
	g++ -c success/User.cpp

rated.o: success/rated.cpp
	g++ -c success/rated.cpp

playlist.o: success/playlist.cpp
	g++ -c success/playlist.cpp	


artist.o: success/artist.cpp success/User.h success/rated.h
	g++ -c success/artist.cpp


Gerdabify_logic.o: success/Gerdabify_logic.cpp success/artist.h
	g++ -c success/Gerdabify_logic.cpp	

album.o: success/album.cpp success/rated.h
	g++ -c success/album.cpp
 
music.o: success/music.cpp success/rated.h
	g++ -c success/music.cpp