/**
 * @brief It implements the player module
 *
 * @file player.c
 * @author Jaime Luna Lavela
 * @version 0
 * @date 09-02-2025

 */

#include "player.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Player
 *
 * This struct stores all the information of a player.
 */

struct _Player
{
    Id id;
    char name[WORD_SIZE + 1]; /*!< Name of the player */
    Id location               /* id of the space where the player is*/
    /*Object *object*/
    /*falta implementar el object que porta*/
};

Player *space_create(Id id)
{
    Player *new_player = NULL;

    /* Error control */
    if (id == NO_ID)
        return NULL;

    new_player = (Player *)malloc(sizeof(Player));
    if (new_player == NULL)
    {
        return NULL;
    }

    /* Initialization of an empty space*/
    new_player->id = id;
    new_player->name[0] = '\0';
    new_player->location = NO_ID;
    /*new_player->object = FALSE;*/

    return new_player;
}

Status player_destroy(Player *player)
{
    if (!player)
    {
        return ERROR;
    }

    free(player);
    player = NULL;
    return OK;
}

Id space_get_id(Player *player)
{
    if (!player)
    {
        return NO_ID;
    }
    return player->id;
}

Status player_set_name(Player *player, char *name)
{
    if (!player || !name)
    {
        return ERROR;
    }

    if (!strcpy(player->name, name))
    {
        return ERROR;
    }
    return OK;
}

const char *player_get_name(Player *player)
{
    if (!player)
    {
        return NULL;
    }
    return player->name;
}

Status player_set_location(Player *player, Id id)
{
    if (!player || id == NO_ID)
    {
        return ERROR;
    }
    player->location = id;
    return OK;
}

Id player_get_location(Player *player)
{
    if (!player)
    {
        return NO_ID;
    }
    return player->location;
}

/*falta meter el get y set del object*/

Status player_print(Player *player)
{
    Id idaux = NO_ID;

    /* Error Control */
    if (!player)
    {
        return ERROR;
    }

    /* 1. Print the id and the name of the player */
    fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", player->id, player->name);

    /* 2. print the location of the player*/
    fprintf(stdout, "--> Location(Id: %ld)\n", player->location);

    /* 3. Print if the id of the object he is carrying
    if (space_get_object(space)) {
      fprintf(stdout, "---> Object in the space.\n");
    } else {
      fprintf(stdout, "---> No object in the space.\n");
    }
                                                       */
    return OK;
}
