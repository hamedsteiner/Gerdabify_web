a.out: main.o Gerdabify_logic.o User.o 
	g++ main.o Gerdabify_logic.o User.o 


main.o: main.cpp
	g++ -c main.cpp

Gerdabify_logic.o: Gerdabify_logic.cpp
	g++ -c Gerdabify_logic.cpp

User.o: User.cpp
	g++ -c User.cpp





clean: rm -rf *o a.out
