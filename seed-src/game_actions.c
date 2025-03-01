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
#include <time.h>

#define NUM_ALEAT_MAX 9
#define MAX_CHARACTER_ALEAT_ATTACK 4

/**
 *   Private functions
 */

/**
 * @brief It proccess the case in which the command is unknown
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are using
 */
void game_actions_unknown(Game *game);

/**
 * @brief It proccess the case in which the command is exit
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are using
 */
void game_actions_exit(Game *game);

/**
 * @brief It proccess the case in which the command is next
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are using
 */
void game_actions_next(Game *game);

/**
 * @brief It proccess the case in which the command is back
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are using
 */
void game_actions_back(Game *game);

/**
 * @brief It proccess the case in which the command is take
 * @author Héctor García Pérez
 *
 * @param game a pointer to game that we are using
 * @param name a pointer to the name of the object we want to take
 */
void game_actions_take(Game *game, char *name);

/**
 * @brief It proccess the case in which the command is drop
 * @author Héctor García Pérez
 *
 * @param game a pointer to game that we are using
 */
void game_actions_drop(Game *game);

/**
 * @brief It attacks an enemy
 * @author Héctor García Pérez
 *
 * @param game a pointer to game that we are using
 */
void game_actions_attack(Game *game);

/**
 * @brief It chats with a friendly character
 * @author Héctor García Pérez
 *
 * @param game a pointer to game that we are using
 */
void game_actions_chat(Game *game);

/**
 *   Game actions implementation
 */

/*It is the function that will respond to our commands, doing what we say if it is possible*/
Status game_actions_update(Game *game, Command *command, char *command_specification)
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
        game_actions_take(game, command_specification);
        break;

    case DROP:
        game_actions_drop(game);
        break;

    case ATTACK:
        game_actions_attack(game);
        break;

    case CHAT:
        game_actions_chat(game);
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
void game_actions_take(Game *game, char *name)
{
    Id obj_loc, player_loc, id_object, object_id;
    Object *object;

    /* Control error*/
    if (!game || !name)
    {
        return;
    }

    /* Gets the object's pointer*/
    if (!(object = game_get_object_with_name(game, name)))
    {
        return;
    }

    /* Gets the object id*/
    if ((object_id = object_get_id(object)) == NO_ID)
    {
        return;
    }

    /* Gets the object location*/
    if ((obj_loc = game_get_object_location(object, object_id)) == NO_ID)
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
        if ((space_remove_object(game_get_space(game, obj_loc), object_id)) == ERROR)
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
    if ((id_object = player_get_object(player)) == NO_ID)
    {
        return;
    }

    /* Gets the player location*/
    if ((player_loc = game_get_player_location(game)) == NO_ID)
    {
        return;
    }

    /* Sets the location of the object in the space with the player*/
    if (game_set_object_location(game, player_loc, id_object) == ERROR)
    {
        return;
    }

    /* Remove the object from the player*/
    player_set_object(player, NO_ID);
}

/* It attacks an enemy*/
void game_actions_attack(Game *game)
{
    int num_attack;
    Player *player;
    Character *character;
    Id player_loc, character_id;

    /* Control error*/
    if (!game)
    {
        return;
    }

    srand(time(NULL));

    /* Gets the location of the player*/
    if ((player_loc = game_get_player_location(game)) == NO_ID)
    {
        return;
    }

    /* Gets the id of the character in that space*/
    if ((character_id = space_get_character(player_loc)) == NO_ID)
    {
        return;
    }

    /* Gets the pointer to the character*/
    if (!(character = game_get_character(game, character_id)))
    {
        return;
    }

    /* Checks if the character is an enemy*/
    if (character_get_friendly(character) == TRUE)
    {
        return;
    }

    /* Generetes a rand number*/
    num_attack = (rand() % (NUM_ALEAT_MAX + 1));

    /* Depending of the result the character or the player attack*/
    if (num_attack <= MAX_CHARACTER_ALEAT_ATTACK)
    {
        if (!(player = game_get_player(game)))
        {
            return;
        }

        player_set_health(player, player_get_health(player) - 1);
    }
    else
    {
        character_set_health(player, character_get_health(character) - 1);
    }
}

/* It chats with a friendly character*/
void game_actions_chat(Game *game)
{
    Id player_loc, character_id;
    Character *character;

    /* Control error*/
    if (!game)
    {
        return;
    }

    /* Gets the player location*/
    if ((player_loc = game_get_player_location(game)) == NO_ID)
    {
        return;
    }

    /* Gets the id of the character in that space*/
    if ((character_id = space_get_character(player_loc)) == NO_ID)
    {
        return;
    }

    /* Gets the pointer of the character*/
    if (!(character = game_get_character(game, character_id)))
    {
        return;
    }

    /* Checks that the character is friendley*/
    if (character_get_friendly(character) == FALSE)
    {
        return;
    }

    /* Set the last message of the game to the character's message*/
    game_set_last_message(game, character_get_message(character));
}