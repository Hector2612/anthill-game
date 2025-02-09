/**
 * @brief It defines the player module
 *
 * @file player.c
 * @author Jaime Luna Lavela
 * @version 0
 * @date 09-02-2025
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

typedef struct _Player Player;

/**
 * @brief It creates a new space, allocating memory and initializing its members
 * @author Profesores PPROG
 *
 * @param id the identification number for the new space
 * @return a new space, initialized
 */
Player *player_create(Id id);

/**
 * @brief It destroys a player, freeing the allocated memory
 * @author Jaime Luna Lavela
 *
 * @param player a pointer to the player that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_destroy(Player *player);

/**
 * @brief It gets the id of a space
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return the id of space
 */
Id player_get_id(Player *player);

/**
 * @brief It sets the name of a space
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_name(Player *player, char *name);

/**
 * @brief It gets the name of a space
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return  a string with the name of the space
 */
const char *player_get_name(Player *player);

/**
 * @brief It sets the id location of the space where the player is  located
 * @author Jaime Luna Lavela
 *
 * @param player a pointer to the player
 * @param id the id number of the space where the player is located
 * @return OK, if everything goes well or ERROR if there was some mistake
 */

Status player_set_location(Player *player, Id id);

/**
 * @brief It gets the id of the space where the player is located
 * @author Profesores PPROG
 *
 * @param player a pointer to the player
 * @return the id number where the player is located
 */
Id player_get_location(Player *player);

/**
 * @brief It prints the player information
 * @author Jaime Luna Lavela
 *
 * This fucntion shows the id and name of the player, also where is located and if he is carrying and object
 * @param player a pointer to the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_print(Player *player);

#endif
