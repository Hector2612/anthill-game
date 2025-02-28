/**
 * @brief It defines the game update interface
 *
 * @file character.h
 * @author Jaime Luna Lavela
 * @version 0
 * @date 19-02-25
 * @copyright GNU Public License
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#define TAMGDESC 6
#define CHARACTER_HEALTH 10

#include "types.h"

typedef struct _Character Character;

/**
 * @brief It creates a new player, allocating memory and initializing its members
 * @author Jaime Luna Lavela
 *
 * @param id the identification number for a new character
 * @return a new character, initialized
 */
Character *character_create(Id id);

/**
 * @brief It destroys a character, freeing the allocated memory
 * @author Jaime Luna Lavela
 *
 * @param player a pointer to the character that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_destroy(Character *character);

/**
 * @brief It gets the id of a character
 * @author Jaime Luna Lavela
 *
 * @param character a pointer to the character
 * @return the id of player
 */
Id character_get_id(Character *character);

/**
 * @brief It sets the name of a character
 * @author Jaime Luna Lavela
 *
 * @param space a pointer to the character
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_name(Character *character, const char *name);

/**
 * @brief It gets the name of a character
 * @author Jaime Luna Lavela
 *
 * @param space a pointer to the character
 * @return  a string with the name of the player
 */
char *character_get_name(Character *character);

/**
 * @brief It sets the description of a character
 * @author Jaime Luna Lavela
 *
 * @param character a pointer to the character
 * @param gdesc a string with the grphic description to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_gdesc(Character *character, const char *gdesc);

/**
 * @brief It gets the description of a character
 * @author Jaime Luna Lavela
 *
 * @param character a pointer to the character
 * @return  a string with the description of the character
 */
char *character_get_gdesc(Character *character);

/**
 * @brief It sets the health of a character
 * @author Jaime Luna Lavela
 *
 * @param character a pointer to the character
 * @param health cuantity of health
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_health(Character *character,int health);

/**
 * @brief It gets the health of a character
 * @author Jaime Luna Lavela
 *
 * @param character a pointer to the character
 * @return  cuantity of health
 */
int character_get_health(Character *character);

/**
 * @brief It sets if the character is either friend or enemy
 * @author Jaime Luna Lavela
 *
 * @param character a pointer to the character
 * @param friend 0 enemy, 1 friend
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_friendly(Character *character,Bool friend);

/**
 * @brief It gets wheter the characther is friend or not
 * @author Jaime Luna Lavela
 *
 * @param character a pointer to the character
 * @return  friend or not friend 
 */
Bool character_get_friendly(Character *character);

/**
 * @brief It sets the message of the character
 * @author Jaime Luna Lavela
 *
 * @param character a pointer to the character
 * @param message the string that contains the message
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_message(Character *character,const char *message);

/**
 * @brief It gets the message of a character
 * @author Jaime Luna Lavela
 *
 * @param character a pointer to the character
 * @return  message of the character
 */
char *character_get_message(Character *character);

/**
 * @brief It prints the character information
 * @author Jaime Luna Lavela
 *
 * This fucntion shows the id and name of the character,life points and gdesc
 * @param player a pointer to the character
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_print(Character *character);

#endif
