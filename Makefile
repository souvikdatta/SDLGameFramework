CC=g++
CFLAGS=`sdl2-config --libs --cflags` -D_REENTRANT -O0 -Wall -lSDL2_image -lm -I.
EXE=game

$(EXE):game.o main.o textureManager.o player.o
	$(CC) player.o textureManager.o main.o game.o -o $(EXE) $(CFLAGS)

game.o:game.cpp game.hpp textureManager.hpp gameobject.hpp player.hpp loadparams.hpp sdlgameobject.hpp
	$(CC) game.cpp -c -o game.o

main.o:main.cpp game.hpp
	$(CC) main.cpp -c -o main.o

textureManager.o:textureManager.cpp textureManager.hpp
	$(CC) textureManager.cpp -c -o textureManager.o

player.o:player.cpp player.hpp sdlgameobject.hpp gameobject.hpp
	$(CC) player.cpp -c -o player.o

clean:
	rm $(EXE) *.o
