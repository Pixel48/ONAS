CCOMP = g++
LIBS = -L lib -l sfml-graphics -l sfml-window -l sfml-system -l sfml-audio
OUT = main
EXE = $(OUT).exe

all: clean compile link run

run:
	./$(OUT)

compile:
	$(CCOMP) -I include -c main.cpp

link:
	$(CCOMP) $(OUT).o -o $(EXE) $(LIBS)
	rm $(OUT).o

clean:
	rm -f $(EXE) $(OUT)