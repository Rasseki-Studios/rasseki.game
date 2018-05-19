all: libAdapter.a

libAdapter.a: Item.o Located.o Artifact.o Creature.o Hero.o Movable.o Storage.o SurfaceData.o libAdapter.o 
	ar crs libAdapter.a libAdapter.o Item.o Located.o Artifact.o Creature.o Hero.o Movable.o Storage.o SurfaceData.o

libAdapter.o: libAdapter.cpp
	g++ -std=c++11 -c -pthread libAdapter.cpp

Item.o: Item.cpp
	g++ -std=c++11 -c Item.cpp

Located.o: Located.cpp
	g++ -std=c++11 -c Located.cpp

Artifact.o: Artifact.cpp
	g++ -std=c++11 -c Artifact.cpp

Creature.o: Creature.cpp
	g++ -std=c++11 -c Creature.cpp

Hero.o: Hero.cpp
	g++ -std=c++11 -c Hero.cpp

Movable.o: Movable.cpp
	g++ -std=c++11 -c Movable.cpp

Storage.o: Storage.cpp
	g++ -std=c++11 -c Storage.cpp

SurfaceData.o: SurfaceData.cpp
	g++ -std=c++11 -c SurfaceData.cpp

clean:
	rm -f *.o *.a binary
