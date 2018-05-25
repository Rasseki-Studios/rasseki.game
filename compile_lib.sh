g++ -g -O2 $1 --std=c++17 -c libAdapter.cpp matrix.cpp surface.cpp location.cpp item.cpp event.cpp event_factory.cpp event_parser.cpp artifact.cpp storage.cpp artifact_factory.cpp artifact_parser.cpp mapscanner.cpp movable.cpp hero.cpp libs/EasyBMP/EasyBMP.cpp items_data.cpp session_data.cpp -lstdc++fs

ar rcs libAdapter.a matrix.p libAdapter.o surface.o location.o item.o event.o event_factory.o event_parser.o artifact.o storage.o artifact_factory.o artifact_parser.o mapscanner.o movable.o hero.o EasyBMP.o items_data.o session_data.o

rm libAdapter.o matrix.o surface.o location.o item.o event.o event_factory.o event_parser.o artifact.o storage.o artifact_factory.o artifact_parser.o mapscanner.o movable.o hero.o EasyBMP.o items_data.o session_data.o

