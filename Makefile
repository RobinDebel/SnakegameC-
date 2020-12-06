# The compiler to use
CC=g++

# Compiler flags
CFLAGS=-c -Wall
    # -c: Compile or assemble the source files, but do not link.
    # The linking stage simply is not done.
    # The ultimate output is in the form of an object file
    # for each source file.
    #
    # -Wall: This enables all the warnings about constructions that
    # some users consider questionable, and that are easy to avoid
    # (or modify to prevent the warning), even in conjunction with macros.

# Name of executable output
EXECUTABLE=Snakegame

all: $(EXECUTABLE)

# The executable depends on all the separate object files
$(EXECUTABLE): main.o candy.o controller.o canvas.o snake.o wall.o entity.o tail.o game.o menu.o
	$(CC) main.o candy.o controller.o canvas.o snake.o wall.o entity.o tail.o game.o menu.o -o $(EXECUTABLE)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

candy.o: src/candy.cpp
	$(CC) $(CFLAGS) src/candy.cpp

canvas.o: src/canvas.cpp
	$(CC) $(CFLAGS) src/canvas.cpp

controller.o: src/controller.cpp
	$(CC) $(CFLAGS) src/controller.cpp

snake.o: src/snake.cpp
	$(CC) $(CFLAGS) src/snake.cpp

wall.o: src/wall.cpp
	$(CC) $(CFLAGS) src/wall.cpp

entity.o: src/entity.cpp
	$(CC) $(CFLAGS) src/entity.cpp

game.o: src/game.cpp
	$(CC) $(CFLAGS) src/game.cpp

tail.o: src/tail.cpp
	$(CC) $(CFLAGS) src/tail.cpp

menu.o: src/menu/menu.cpp
	$(CC) $(CFLAGS) src/menu/menu.cpp

clean:
	rm -f *.o $(EXECUTABLE)