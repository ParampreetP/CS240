FLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
PROJECT_NAME = lab2
SOURCES = Star.o $(PROJECT_NAME).o $(PROJECT_NAME)

all: $(PROJECT_NAME).o Star.o
	g++ $(FLAGS) $(PROJECT_NAME).o Star.o -o $(PROJECT_NAME)

$(PROJECT_NAME).o: $(PROJECT_NAME).cpp Star.h
	g++ $(FLAGS) $(PROJECT_NAME).cpp -o $(PROJECT_NAME).o -c

Star.o: Star.cpp Star.h
	g++ $(FLAGS) Star.cpp -o Star.o -c

run: all
	./$(PROJECT_NAME)

memcheck: all
	valgrind ./$(PROJECT_NAME)

clean:
	rm $(SOURCES)
