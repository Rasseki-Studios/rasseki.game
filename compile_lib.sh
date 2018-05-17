g++ -g -O2 $1 --std=c++17 -c libAdapter.cpp surface.cpp location.cpp item.cpp event.cpp event_factory.cpp event_parser.cpp artifact.cpp storage.cpp artifact_factory.cpp artifact_parser.cpp mapscanner.cpp movable.cpp units.cpp libs/EasyBMP/EasyBMP.cpp items_data.cpp session_data.cpp -lstdc++fs

ar rcs libAdapter.a libAdapter.o surface.o location.o item.o event.o event_factory.o event_parser.o artifact.o storage.o artifact_factory.o artifact_parser.o mapscanner.o movable.o units.o EasyBMP.o items_data.o session_data.o

rm libAdapter.o surface.o location.o item.o event.o event_factory.o event_parser.o artifact.o storage.o artifact_factory.o artifact_parser.o mapscanner.o movable.o units.o EasyBMP.o items_data.o session_data.o

