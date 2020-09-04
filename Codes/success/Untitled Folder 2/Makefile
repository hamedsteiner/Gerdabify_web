a.out: main.o Gerdabify_logic.o User.o rated_object.o Artist.o album.o music.o
	g++ main.o Gerdabify_logic.o User.o rated_object.o Artist.o album.o music.o


main.o: main.cpp
	g++ -c main.cpp

Gerdabify_logic.o: Gerdabify_logic.cpp
	g++ -c Gerdabify_logic.cpp

User.o: User.cpp
	g++ -c User.cpp

rated_object.o: rated_object.cpp
	g++ -c rated_object.cpp	

Artist.o: Artist.cpp User.h rated_object.h
	g++ -c Artist.cpp

album.o: album.cpp rated_object.h
	g++ -c album.cpp
 
music.o: music.cpp rated_object.h
	g++ -c music.cpp





clean: rm -rf *o a.out

