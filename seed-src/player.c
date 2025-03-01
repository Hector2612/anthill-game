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
    Id location;              /*!< Id of the space where the player is*/
    Id object;                /*!< Id of the player's object*/
    int health;               /*!< Quantity of life*/
};

/* It creates a new player, allocating memory and initializing its members*/
Player *player_create(Id id)
{
    Player *new_player = NULL;

    /* Error control */
    if (id == NO_ID)
        return NULL;

    /* Allocates memory for the new player*/
    new_player = (Player *)malloc(sizeof(Player));
    if (new_player == NULL)
    {
        return NULL;
    }

    /* Initialization of an empty player*/
    new_player->id = id;
    new_player->name[0] = '\0';
    new_player->location = NO_ID;
    new_player->object = NO_ID;
    new_player->health = PLAYER_HEALTH;

    return new_player;
}

/* It destroys a player, freeing the allocated memory*/
Status player_destroy(Player *player)
{
    /* Control error*/
    if (!player)
    {
        return ERROR;
    }

    /* Free the allocated memory*/
    free(player);

    return OK;
}

/* It gets the id of a player*/
Id player_get_id(Player *player)
{
    /* Control error*/
    if (!player)
    {
        return NO_ID;
    }

    return player->id;
}

/* It sets the name of a player*/
Status player_set_name(Player *player, const char *name)
{
    /* Control error*/
    if (!player || !name)
    {
        return ERROR;
    }

    /* Copy the pass name to the struct player*/
    if (!strcpy(player->name, name))
    {
        return ERROR;
    }

    return OK;
}

/* It gets the name of a player*/
char *player_get_name(Player *player)
{
    /* Control error*/
    if (!player)
    {
        return NULL;
    }

    return player->name;
}

/* It sets the id location of the space where the player is located*/
Status player_set_location(Player *player, Id id)
{
    /* Control error*/
    if (!player || id == NO_ID)
    {
        return ERROR;
    }

    /* Sets the player location to the pass id*/
    player->location = id;

    return OK;
}

/* It gets the id of the space where the player is located*/
Id player_get_location(Player *player)
{
    /* Control error*/
    if (!player)
    {
        return NO_ID;
    }

    return player->location;
}

/* It gets the id of the player's object*/
Id player_get_object(Player *player)
{
    /* Control error*/
    if (!player)
    {
        return NO_ID;
    }

    return player->object;
}

/* It sets the id of the player's object*/
Status player_set_object(Player *player, Id id)
{
    /* Control error*/
    if (!player)
    {
        return ERROR;
    }

    /* Sets the player's object*/
    player->object = id;

    return OK;
}

Status player_set_health(Player *player, int health)
{

    /* Control error*/
    if (!player || health < 0)
    {
        return ERROR;
    }

    player->health = health;
    return OK;
}

int player_get_health(Player *player)
{

    /* Control error*/
    if (!player)
    {
        return NO_ID;
    }

    return player->health;
}

/* It prints the player information*/
Status player_print(Player *player)
{
    Id idaux = NO_ID;

    /* Error Control */
    if (!player)
    {
        return ERROR;
    }

    /* 1. Print the id , the name and health of the player */
    fprintf(stdout, "--> Player (Id: %ld; Name: %s; (%d))\n", player->id, player->name, player->health);

    /* 2. print the location of the player*/
    fprintf(stdout, "--> Location(Id: %ld)\n", player->location);

    idaux = player_get_object(player);

    /* 3. Print if the id of the object he is carrying*/
    if (idaux != NO_ID)
    {
        fprintf(stdout, "---> Object: %ld.\n", idaux);
    }
    else
    {
        fprintf(stdout, "---> No object.\n");
    }

    return OK;
}

