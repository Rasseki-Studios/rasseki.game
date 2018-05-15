all: libAdapter.a

libAdapter.a: libAdapter.o Item.o
	ar cr libAdapter.a libAdapter.o Item.o

libAdapter.o: libAdapter.cpp
	g++ -c libAdapter.cpp

Item.o: Item.cpp
	g++ -c Item.cpp

clean:
	rm -f *.o *.a binary
