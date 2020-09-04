a.out: main.o Gerdabify_logic.o User.o rated.o playlist.o  artist.o  album.o music.o database.o 
	g++ main.o Gerdabify_logic.o User.o rated.o playlist.o artist.o  album.o music.o database.o 


main.o: main.cpp
	g++ -c main.cpp

database.o: database.cpp
	g++ -c database.cpp

User.o: User.cpp 
	g++ -c User.cpp

rated.o: rated.cpp
	g++ -c rated.cpp

playlist.o: playlist.cpp
	g++ -c playlist.cpp	


artist.o: artist.cpp User.h rated.h
	g++ -c artist.cpp


Gerdabify_logic.o: Gerdabify_logic.cpp artist.h
	g++ -c Gerdabify_logic.cpp	

album.o: album.cpp rated.h
	g++ -c album.cpp
 
music.o: music.cpp rated.h
	g++ -c music.cpp





clean: rm -rf *o a.out

