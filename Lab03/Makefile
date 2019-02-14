FLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
PROJ_NAME = lab3
SOURCES = Star.o Planet.o $(PROJ_NAME).o $(PROJ_NAME)

all: $(PROJ_NAME).o Star.o Planet.o
	g++ $(FLAGS) $(PROJ_NAME).o Star.o Planet.o -o $(PROJ_NAME)

$(PROJ_NAME).o: $(PROJ_NAME).cpp Star.h Planet.h
	g++ $(FLAGS) $(PROJ_NAME).cpp -o $(PROJ_NAME).o -c

Star.o: Star.cpp Star.h
	g++ $(FLAGS) Star.cpp -o Star.o -c
	
Planet.o: Planet.cpp Planet.h
	g++ $(FLAGS) Planet.cpp -o Planet.o -c

run: all
	./$(PROJ_NAME)

memcheck: all
	valgrind ./$(PROJ_NAME)

clean:
	rm $(SOURCES)
