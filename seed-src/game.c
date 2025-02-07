/**
 * @brief It implements the game structure
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "game.h"
#include "game_reader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
   Private functions
*/

/**
 * @brief It gets the id of a space with his position in the array
 * @author Profesores PPROG
 *
 * @param game a pointer to game which is going to be created
 * @param position the position of the ne space in the array of spaces
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Id game_get_space_id_at(Game *game, int position);

/**
   Game interface implementation
*/

/* It creates the game initializing the spaces to null or not having yet place the object or player*/
Status game_create(Game *game)
{
    int i;

    /* Initializates all the spaces to Null*/
    for (i = 0; i < MAX_SPACES; i++)
    {
        game->spaces[i] = NULL;
    }

    /* Initializates all the fields of the struct game*/
    game->n_spaces = 0;
    game->player_location = NO_ID;
    game->object_location = NO_ID;
    game->last_cmd = command_create();
    game->finished = FALSE;

    return OK;
}

/* It creates the game using the file of data*/
Status game_create_from_file(Game *game, char *filename)
{
    /* Control error*/
    if (!game || !filename)
    {
        return ERROR;
    }

    /* Call the function game_create an makes a control errors*/
    if (game_create(game) == ERROR)
    {
        return ERROR;
    }

    /* Call the function which read the file an makes a control errors*/
    if (game_reader_load_spaces(game, filename) == ERROR)
    {
        return ERROR;
    }

    /* The player and the object are located in the first space */
    game_set_player_location(game, game_get_space_id_at(game, 0));
    game_set_object_location(game, game_get_space_id_at(game, 0));

    return OK;
}

/* It frees pointer game*/
Status game_destroy(Game *game)
{
    int i = 0;

    /* Destroy all the spaces*/
    for (i = 0; i < game->n_spaces; i++)
    {
        space_destroy(game->spaces[i]);
    }

    /* Destroy the commands*/
    command_destroy(game->last_cmd);

    return OK;
}

/* Creates new spaces for game*/
Space *game_get_space(Game *game, Id id)
{
    int i = 0;

    /* Control error*/
    if (!game || id == NO_ID)
    {
        return NULL;
    }

    /* Look for the space we want to find*/
    for (i = 0; i < game->n_spaces; i++)
    {
        if (id == space_get_id(game->spaces[i]))
        {
            return game->spaces[i];
        }
    }

    return NULL;
}

/* It obtains the position of the player*/
Id game_get_player_location(Game *game) { return game->player_location; }

/* It sets the position of the player at the id that correspond*/
Status game_set_player_location(Game *game, Id id)
{
    /* Control error*/
    if (!game || id == NO_ID)
    {
        return ERROR;
    }

    /* Set the id of the player*/
    game->player_location = id;

    return OK;
}

/* It obtains the position of the object*/
Id game_get_object_location(Game *game) { return game->object_location; }

/* It sets the position of the object at the id that correspond*/
Status game_set_object_location(Game *game, Id id)
{
    /* Control error*/
    if (!game || id == NO_ID)
    {
        return ERROR;
    }

    /* Set the id of the object*/
    game->object_location = id;
    space_set_object(game_get_space(game, id), TRUE);

    return OK;
}

/* It obtains the last instruction send*/
Command *game_get_last_command(Game *game) { return game->last_cmd; }

/* It inizialices the last command with pointer command*/
Status game_set_last_command(Game *game, Command *command)
{
    /* Control error*/
    if (!game || !command)
    {
        return ERROR;
    }

    /* Set the last command*/
    game->last_cmd = command;

    return OK;
}

/* It informs us if the game is finished*/
Bool game_get_finished(Game *game) { return game->finished; }

/* It make the game finish*/
Status game_set_finished(Game *game, Bool finished)
{
    /* Control error*/
    if (!game)
    {
        return ERROR;
    }

    /* set the game finished*/
    game->finished = finished;

    return OK;
}

/* It prints the information of the game*/
void game_print(Game *game)
{
    int i = 0;

    printf("\n\n-------------\n\n");

    /* Print the spaces*/
    printf("=> Spaces: \n");
    for (i = 0; i < game->n_spaces; i++)
    {
        space_print(game->spaces[i]);
    }

    /* Prints object location and player location*/
    printf("=> Object location: %d\n", (int)game->object_location);
    printf("=> Player location: %d\n", (int)game->player_location);
}

/* It adds the new processed space to the game*/
Status game_add_space(Game *game, Space *space)
{ 
    /* Control error*/
    if (!game || !space || (game->n_spaces >= MAX_SPACES))
    {
        return ERROR;
    }

    /* Add the new space*/
    game->spaces[game->n_spaces] = space;
    (game->n_spaces)++;

    return OK;
}

/**
Implementation of private functions
*/

/* It gets the id of a space with his position in the array */
Id game_get_space_id_at(Game *game, int position)
{
    /* Control error*/
    if (position < 0 || position >= game->n_spaces)
    {
        return NO_ID;
    }

    return space_get_id(game->spaces[position]);
}
