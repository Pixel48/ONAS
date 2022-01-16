CC = g++
LIBS = -L lib -l sfml-graphics -l sfml-window -l sfml-system -l sfml-audio
INC = -I include# -I header
# H = header/

DEV = -D DEV

ifdef OS
	D = -D WIN
endif

onas.exe: main.o area.o
	$(CC) $^ -o $@ $(LIBS)

main.o: main.cpp
	$(CC) $(INC) $D -c $< $(DEV)

area.o: area.cpp area.hpp
	$(CC) $(INC) $D -c $< $(DEV)

clean:
	rm -f *.exe *.o

build: onas.exe

remake: clean build

run: onas.exe
	./$^

rerun: clean run