CC = gcc
CFLAGS = -g -Wall -pedantic -ansi
EXE = anthill

all: anthill

anthill: space.o graphic_engine.o game.o game_loop.o command.o game_actions.o game_reader.o object.o player.o
	$(CC) -o $(EXE) $^ -L. -lscreen

space.o: space.c space.h types.h
	$(CC) $(CFLAGS) -c space.c

graphic_engine.o: graphic_engine.c graphic_engine.h
	$(CC) $(CFLAGS) -c graphic_engine.c

game.o: game.c game.h command.h types.h space.h object.h player.h game_reader.h
	$(CC) $(CFLAGS) -c game.c

game_loop.o: game_loop.c command.h types.h game.h space.h object.h player.h game_actions.h graphic_engine.h
	$(CC) $(CFLAGS) -c game_loop.c

command.o: command.c command.h types.h
	$(CC) $(CFLAGS) -c command.c

game_actions.o: game_actions.c game_actions.h command.h types.h game.h space.h object.h player.h
	$(CC) $(CFLAGS) -c game_actions.c

game_reader.o: game_reader.c game_reader.h types.h space.h game.h command.h object.h player.h
	$(CC) $(CFLAGS)  -c game_reader.c

object.o: object.c object.h types.h
	$(CC) $(CFLAGS) -c object.c

player.o: player.c player.h types.h
	$(CC) $(CFLAGS) -c player.c

set.o: set.c set.h types.h
	$(CC) $(CFLAGS) -c set.c

clean: 
	rm -f *.o

clear: clean
	rm -f $(EXE)

redo: clear all

run: $(EXE)
	./$(EXE) $(EXE).dat

comprobation: $(EXE)
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXE) $(EXE).dat
