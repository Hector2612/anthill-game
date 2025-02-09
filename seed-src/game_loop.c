/**
 * @brief It defines the game loop
 *
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>

#include "command.h"
#include "game.h"
#include "game_actions.h"
#include "graphic_engine.h"

/**
 * @brief It initializates the loop of the game storing the necessary memory
 * @author Profesores PPROG
 *
 * @param game a pointer to the game that must be initialized
 * @param gengine a pointer of the board
 * @param file_name a pointer to the name of the file with the data
 * @return 0, if everything goes well or 1 if there was some mistake
 */
int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name);

/**
 * @brief It runs the game
 * @author Profesores PPROG
 *
 * @param game a pointer to the game that must be initialized
 * @param gengine a pointer of the board
 */
void game_loop_run(Game game, Graphic_engine *gengine);

/**
 * @brief It ends the game freeing all the store memory
 * @author Profesores PPROG
 *
 * @param game a pointer to the game that must be initialized
 * @param gengine a pointer of the board
 */
void game_loop_cleanup(Game game, Graphic_engine *gengine);

/**
 * @brief The main function, which inizializates the call stack of the others functions
 * @author Profesores PPROG
 *
 * @param argc the number of arguments
 * @param argv a pointer of the name of the data file
 * @return 0, if everything goes well or 1 if there was some mistake
 */
int main(int argc, char *argv[])
{
    Game game;
    Graphic_engine *gengine;

    /* Check if the file with the data was given*/
    if (argc < 2)
    {
        fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
        return 1;
    }

    /* Initializate the game*/
    if (!game_loop_init(&game, &gengine, argv[1]))
    {
        /* run the game loop*/
        game_loop_run(game, gengine);
        
        /* Destroy all the allocated memory*/
        game_loop_cleanup(game, gengine);
    }

    return 0;
}

/* It initializates the loop of the game storing the necessary memory*/
int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name)
{
    /* Call the neccessary function to create the game with the data file, and check for possible errors*/
    if (game_create_from_file(game, file_name) == ERROR)
    {
        /* There was an error*/
        fprintf(stderr, "Error while initializing game.\n");

        return 1;
    }

    /* Create the game interface*/
    if ((*gengine = graphic_engine_create()) == NULL)
    {
        /* If there was an error, it free the allocated memory*/
        fprintf(stderr, "Error while initializing graphic engine.\n");
        game_destroy(game);

        return 1;
    }

    return 0;
}

/* It runs the game*/
void game_loop_run(Game game, Graphic_engine *gengine)
{
    Command *last_cmd;

    /* Control error*/
    if (!gengine)
    {
        return;
    }

    last_cmd = game_get_last_command(&game);

    /* While the command isn´t exit the loop continue*/
    while ((command_get_code(last_cmd) != EXIT) && (game_get_finished(&game) == FALSE))
    {
        graphic_engine_paint_game(gengine, &game);
        command_get_user_input(last_cmd);
        game_actions_update(&game, last_cmd);
    }
}

/* It ends the game freeing all the store memory*/
void game_loop_cleanup(Game game, Graphic_engine *gengine)
{
    game_destroy(&game);
    graphic_engine_destroy(gengine);
}
