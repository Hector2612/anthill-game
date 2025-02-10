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

game.o: game.c game.h
	$(CC) $(CFLAGS) -c game.c

game_loop.o: game_loop.c
	$(CC) $(CFLAGS) -c game_loop.c

command.o: command.c command.h
	$(CC) $(CFLAGS) -c command.c

game_actions.o: game_actions.c game_actions.h
	$(CC) $(CFLAGS) -c game_actions.c

game_reader.o: game_reader.c game_reader.h
	$(CC) $(CFLAGS)  -c game_reader.c

object.o: object.c object.h
	$(CC) $(CFLAGS) -c object.c

player.o: player.c player.h
	$(CC) $(CFLAGS) -c player.c

clean: 
	rm -f *.o

clear: clean
	rm -f $(EXE)

redo: clear all

run: $(EXE)
	./$(EXE) $(EXE).dat

comprobation: $(EXE)
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXE) $(EXE).dat
