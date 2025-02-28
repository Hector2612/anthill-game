/**
 * @brief It implements the game update through user actions
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "game_actions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
   Private functions
*/

/**
 * @brief It proccess the case in which the command is unknown
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are using
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
void game_actions_unknown(Game *game);

/**
 * @brief It proccess the case in which the command is exit
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are using
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
void game_actions_exit(Game *game);

/**
 * @brief It proccess the case in which the command is next
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are using
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
void game_actions_next(Game *game);

/**
 * @brief It proccess the case in which the command is back
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are using
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
void game_actions_back(Game *game);

/**
 * @brief It proccess the case in which the command is take
 * @author Jaime Luna Lavela
 *
 * @param game a pointer to game that we are using
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
void game_actions_take(Game *game);

/**
 * @brief It proccess the case in which the command is drop
 * @author Jaime Luna Lavela
 *
 * @param game a pointer to game that we are using
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
void game_actions_drop(Game *game);

/**
   Game actions implementation
*/

/*It is the function that will respond to our commands, doing what we say if it is possible*/
Status game_actions_update(Game *game, Command *command)
{
    CommandCode cmd;

    /* Set the last command of the game*/
    game_set_last_command(game, command);

    cmd = command_get_code(command);

    /* Call the neccessary function depending of the cmd*/
    switch (cmd)
    {
    case UNKNOWN:
        game_actions_unknown(game);
        break;

    case EXIT:
        game_actions_exit(game);
        break;

    case NEXT:
        game_actions_next(game);
        break;

    case BACK:
        game_actions_back(game);
        break;

    case TAKE:
        game_actions_take(game);
        break;

    case DROP:
        game_actions_drop(game);
        break;

    default:
        break;
    }

    return OK;
}

/**
    Calls implementation for each action
*/

/* It proccess the case in which the command is unknown*/
void game_actions_unknown(Game *game) {}

/* It proccess the case in which the command is exit*/
void game_actions_exit(Game *game) {}

/* It proccess the case in which the command is next*/
void game_actions_next(Game *game)
{
    Id current_id = NO_ID;
    Id space_id = NO_ID;

    space_id = game_get_player_location(game);

    /* Control errors*/
    if (space_id == NO_ID)
    {
        return;
    }

    /* Obtains the id of the next space*/
    current_id = space_get_south(game_get_space(game, space_id));

    /* Control errors*/
    if (current_id != NO_ID)
    {
        /* Change the id location of the player*/
        game_set_player_location(game, current_id);
    }

    return;
}

/* It proccess the case in which the command is back*/
void game_actions_back(Game *game)
{
    Id current_id = NO_ID;
    Id space_id = NO_ID;

    space_id = game_get_player_location(game);

    /* Control error*/
    if (NO_ID == space_id)
    {
        return;
    }

    /* Get the id of the space before*/
    current_id = space_get_north(game_get_space(game, space_id));

    /* Control error*/
    if (current_id != NO_ID)
    {
        /* Change the id location of the player*/
        game_set_player_location(game, current_id);
    }

    return;
}
/* It proccess the case in which the command is take*/
void game_actions_take(Game *game)
{
    Id obj_loc, player_loc, id_object;

    /* Control error*/
    if (!game)
    {
        return;
    }

    /* Gets the object location*/
    if ((obj_loc = game_get_object_location(game)) == NO_ID)
    {
        return;
    }

    /* Gets the player location*/
    if ((player_loc = game_get_player_location(game)) == NO_ID)
    {
        return;
    }

    /* It checks that the object location is equal to player location*/
    if (player_loc == obj_loc)
    {
        /* It remove the object from the space*/
        if ((space_set_object(game_get_space(game, obj_loc), NO_ID)) == ERROR)
        {
            return;
        }

        /* Gets the id of the object*/
        if ((id_object = object_get_id(game_get_object(game))) == NO_ID)
        {
            return;
        }

        /*  Puts the object with the player*/
        if (player_set_object(game_get_player(game), id_object) == ERROR)
        {
            return;
        }
    }
}

/* It proccess the case in which the command is drop*/
void game_actions_drop(Game *game)
{
    Id obj_loc, player_loc, id_object;
    Player *player;

    /* Control error*/
    if (!game || !(player = game_get_player(game)))
    {
        return;
    }

    /* It checks that the player has the object*/
    if ((obj_loc = game_get_object_location(game)) != NO_ID || player_get_object(player) == NO_ID)
    {
        return;
    }

    /* Gets the player location*/
    if ((player_loc = game_get_player_location(game)) == NO_ID)
    {
        return;
    }

    /* Remove the object from the player*/
    if (player_set_object(player, NO_ID) == ERROR)
    {
        return;
    }

    /* Sets the location of the object in the space with the player*/
    if (game_set_object_location(game, player_loc) == ERROR)
    {
        return;
    }
    
}