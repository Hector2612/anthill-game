anthill: space.o graphic_engine.o game.o game_loop.o command.o game_actions.o
	gcc -o anthill *.o -lscreen -L.

space.o: space.c space.h types.h
	gcc -g -Wall -c space.c

graphic_engine.o: graphic_engine.c graphic_engine.o
	gcc -g -Wall -c graphic_engine.c

game.o: game.c game.h
	gcc -g -Wall -c game.c

game_loop.o: game_loop.o
	gcc -g -Wall -c game_loop.c

command.o: command.c command.h
	gcc -g -Wall -c command.c

game_actions.o: game_actions.c game_actions.h
	gcc -g -Wall -c game_actions.c

clean: 
	rm *.o anthill