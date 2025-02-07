CC = gcc
CFLAGS = -g -Wall -pedantic -ansi -c
EXE = anthill

all: anthill

anthill: space.o graphic_engine.o game.o game_loop.o command.o game_actions.o game_reader.o
	$(CC) -o $(EXE) $^ -lscreen -L.

space.o: space.c space.h types.h
	$(CC) $(CFLAGS) space.c

graphic_engine.o: graphic_engine.c graphic_engine.h
	$(CC) $(CFLAGS) graphic_engine.c

game.o: game.c game.h
	$(CC) $(CFLAGS) game.c

game_loop.o: game_loop.c
	$(CC) $(CFLAGS) game_loop.c

command.o: command.c command.h
	$(CC) $(CFLAGS) command.c

game_actions.o: game_actions.c game_actions.h
	$(CC) $(CFLAGS) game_actions.c

game_reader.o: game_reader.c game_reader.h
	$(CC) $(CFLAGS) game_reader.c

object.o: object.c object.h
	$(CC) $(CFLAGS) object.c

player.o: player.c player.h
	$(CC) $(CFLAGS) player.c

clean: 
	rm *.o

clear: clean
	rm $(EXE)

redo: clear $(EXE)

comprobation: $(EXE)
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXE) $(EXE).dat
