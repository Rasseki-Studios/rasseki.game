all: libAdapter.a

libAdapter.a: item.o location.o artifact.o Hero.o movable.o Storage.o libAdapter.o units.o items_data.o session_data.o surface.o map.o mapscanner.o artifact_factory.o artifact_parser.o event.o event_factory.o event_parser.o
	ar crs libAdapter.a libAdapter.o item.o location.o artifact.o Hero.o movable.o Storage.o units.o items_data.o session_data.o surface.o map.o mapscanner.o artifact_factory.o artifact_parser.o event.o event_factory.o event_parser.o

libAdapter.o: libAdapter.cpp
	g++ -std=c++11 -c -pthread libAdapter.cpp

Item.o: Item.cpp
	g++ -std=c++11 -c Item.cpp

item.o: item.cpp
	g++ -std=c++11 -c item.cpp

Located.o: Located.cpp
	g++ -std=c++11 -c Located.cpp

location.o: location.cpp
	g++ -std=c++11 -c location.cpp

Artifact.o: Artifact.cpp
	g++ -std=c++11 -c Artifact.cpp

artifact.o: artifact.cpp
	g++ -std=c++11 -c artifact.cpp

Creature.o: Creature.cpp
	g++ -std=c++11 -c Creature.cpp

Hero.o: Hero.cpp
	g++ -std=c++11 -c Hero.cpp

Movable.o: Movable.cpp
	g++ -std=c++11 -c Movable.cpp

movable.o: movable.cpp
	g++ -std=c++11 -c movable.cpp

Storage.o: Storage.cpp
	g++ -std=c++11 -c Storage.cpp

SurfaceData.o: SurfaceData.cpp
	g++ -std=c++11 -c SurfaceData.cpp

units.o: units.cpp
	g++ -std=c++11 -c units.cpp

items_data.o: items_data.cpp
	g++ -std=c++11 -c items_data.cpp

session_data.o: session_data.cpp
	g++ -std=c++11 -c session_data.cpp

surface.o: surface.cpp
	g++ -std=c++11 -c surface.cpp

map.o: map.cpp
	g++ -std=c++11 -c map.cpp

mapscanner.o: mapscanner.cpp
	g++ -std=c++11 -c mapscanner.cpp

artifact_factory.o: artifact_factory.cpp
	g++ -std=c++11 -c artifact_factory.cpp

artifact_parser.o: artifact_parser.cpp
	g++ -std=c++11 -c artifact_parser.cpp

event.o: event.cpp
	g++ -std=c++11 -c event.cpp

event_factory.o: event_factory.cpp
	g++ -std=c++11 -c event_factory.cpp

event_parser.o: event_parser.cpp
	g++ -std=c++11 -c event_parser.cpp

clean:
	rm -f *.o *.a binary
