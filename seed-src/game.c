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
 * @brief Game
 *
 * This struct stores all the information of the game.
 */
struct _Game
{
    Player *player;               /*!< Pointer to the player's objects*/
    Object *objects[MAX_OBJECTS]; /*!< Pointer to the pointers of the game's objects*/
    int n_objects;                /*!< Number of objects*/
    Space *spaces[MAX_SPACES];    /*!< Pointer to the pointers of the game's spaces*/
    int n_spaces;                 /*!< Number of spaces*/
    Command *last_cmd;            /*!< The code of the last command*/
    Bool finished;                /*!< TRUE or FALSE if it is finished*/
};

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
Status game_create(Game **game)
{
    int i;

    if (!game)
    {
        return ERROR;
    }

    if (!((*game) = (Game *)malloc(sizeof(Game))))
    {
        return ERROR;
    }

    /* Initializates all the spaces to Null*/
    for (i = 0; i < MAX_SPACES; i++)
    {
        (*game)->spaces[i] = NULL;
    }

    /* Initializates all the fields of the struct game*/

    (*game)->n_spaces = 0;

    if (!((*game)->player = player_create(5)))
    {
        return ERROR;
    }

    if (player_set_name((*game)->player, "Player 1") == ERROR)
    {
        free(*game);
        player_destroy((*game)->player);
        return ERROR;
    }

    if (!((*game)->last_cmd = command_create()))
    {
        free(*game);
        player_destroy((*game)->player);
        return ERROR;
    }

    (*game)->finished = FALSE;

    return OK;
}

/* It creates the game using the file of data*/
Status game_create_from_file(Game **game, char *filename)
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
    if (game_reader_load_spaces(*game, filename) == ERROR)
    {
        game_destroy(*game);
        return ERROR;
    }

    /* The player is located in the first space */
    game_set_player_location(*game, game_get_space_id_at(*game, 0));

    return OK;
}

/* It frees pointer game*/
Status game_destroy(Game *game)
{
    int i = 0;
    if (game)
    {
        /* Destroy all the spaces*/
        for (i = 0; i < game->n_spaces; i++)
        {
            space_destroy(game->spaces[i]);
        }

        /* Destroy the commands*/
        command_destroy(game->last_cmd);

        /* Destroy all the objects*/
        for (i = 0; i < game->n_objects; i++)
        {
            object_destroy(game->objects[i]);
        }

        /* Destroy the player*/
        player_destroy(game->player);

        free(game);
    }

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

/* It obtains the position of the player*/
Id game_get_player_location(Game *game)
{
    /* Control error*/
    if (!game)
    {
        return NO_ID;
    }

    return player_get_location(game->player);
}

/* It sets the position of the player at the id that correspond*/
Status game_set_player_location(Game *game, Id id)
{
    /* Control error*/
    if (!game || id == NO_ID)
    {
        return ERROR;
    }

    /* Set the id of the player*/
    if (player_set_location(game->player, id) == ERROR)
    {
        return ERROR;
    }

    return OK;
}

/* It gets the pointer of the object */
Player *game_get_player(Game *game)
{

    /* Control error*/

    if (!game)
    {
        return NULL;
    }

    return game->player;
}

/* It obtains the position of the object*/
Id game_get_object_location(Game *game, Id object)
{
    int i;
    Id obj_loc = NO_ID;

    /* Control error*/
    if (!game)
    {
        return NO_ID;
    }

    /* Find the object*/
    for (i = 0; i < game->n_spaces; i++)
    {
        if (space_find_object(game->spaces[i], object) == TRUE)
        {
            obj_loc = space_get_id(game->spaces[i]);
        }
    }

    return obj_loc;
}

/* It sets the position of the object at the id that correspond*/
Status game_set_object_location(Game *game, Id space, Id object)
{
    /* Control error*/
    if (space == NO_ID || !game || object == NO_ID)
    {
        return ERROR;
    }

    /* Add the object to the space*/
    if (space_add_object(game_get_space(game, space), object) == ERROR)
    {
        return ERROR;
    }

    return OK;
}

/* It gets the pointer of the object with the pass name*/
Object *game_get_object_with_name(Game *game, char *name_object)
{
    int i;
    Object *object = NULL;

    /* Control error*/
    if (!game || !name_object)
    {
        return NULL;
    }

    /* Find the object*/
    for (i = 0; i < game->n_objects; i++)
    {
        if (!strcmp(object_get_name(game->objects[i]), name_object))
        {
            object = game->objects[i];
        }
    }

    return object;
}

/* It gets the pointer of the object with the pass id*/
Object *game_get_object_with_id(Game *game, Id object)
{
    int i;
    Object *object = NULL;

    /* Control error*/
    if (!game || object == NO_ID)
    {
        return NULL;
    }

    /* Find the object*/
    for (i = 0; i < game->n_objects; i++)
    {
        if (object_get_id(game->objects[i]) == object)
        {
            object = game->objects[i];
        }
    }

    return object;
}

/* It gets an array of all the object's ids of the game*/
Id *game_get_all_objects(Game *game)
{
    Id *ids;
    Id object;
    int i;

    /* Control error*/
    if (!game)
    {
        return NULL;
    }

    /* Allocs memory for the array of ids*/
    if (ids = (Id *)malloc((game->n_objects) * sizeof(Id)))
    {
        return NULL;
    }

    /* Initializates the array of ids*/
    for (i = 0; i < game->n_objects; i++)
    {
        if ((object = object_get_id(game->objects[i]) == NO_ID))
        {
            free(ids);
            return NULL;
        }

        ids[i] = object;
    }

    return ids;
}

/* It adds the new processed object to the game*/
Status game_add_object(Game *game, Object *object)
{
    /* Control error*/
    if (!game || !object || (game->n_objects >= MAX_OBJECTS))
    {
        return ERROR;
    }

    /* Add the new object*/
    game->objects[game->n_objects] = object;
    (game->n_objects)++;

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

    printf("=> Objects: \n");
    for (i = 0; i < game->n_objects; i++)
    {
        ("=> %s location: %d\n", object_get_name(game->objects[i]), (int)game_get_object_location(game, object_get_id(game->objects[i])));
    }

    /* Prints the player location*/
    printf("=> Player location: %d\n", (int)game_get_player_location(game));
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
