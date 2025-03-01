/**
 * @brief It defines the game interface
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "types.h"
#include "object.h"
#include "player.h"
#include "character.h"

#define MAX_SPACES 100
#define MAX_OBJECTS 20
#define MAX_CHARACTERS 10

typedef struct _Game Game;

/**
 * @brief It creates the game initializing the spaces to null or not having yet place the object or player
 * @author Héctor García Pérez
 *
 * @param game a pointer to game which is going to be created
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_create(Game **game);

/**
 * @brief It creates the game using the file of data
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are going to use
 * @param filename a pointer to the name of the file with the data
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_create_from_file(Game **game, char *filename);

/**
 * @brief It frees pointer game
 * @author Héctor García Pérez
 *
 * @param game a pointer to game that we are going to use
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_destroy(Game *game);

/**
 * @brief Creates new spaces for game
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are going to use
 * @param id  the id number of the spaces that are going to be created
 * @return to the struct space
 */
Space *game_get_space(Game *game, Id id);

/**
 * @brief It adds the new processed space to the game
 * @author Profesores PPROG
 *
 * @param game a pointer to the game that must be initialized
 * @param space a pointer to the space that must be added
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_add_space(Game *game, Space *space);

/**
 * @brief It obtains the position of the player
 * @author Héctor García Pérez
 *
 * @param game a pointer to game that we are using
 * @return the id of the space where the player is
 */
Id game_get_player_location(Game *game);

/**
 * @brief It sets the position of the player at the id that correspond
 * @author Héctor García Pérez
 *
 * @param game a pointer to game that we are using
 * @param id the id of the space where the player is going to be placed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_player_location(Game *game, Id id);

/**
 * @brief It gets the pointer of the player
 * @author Héctor García Pérez
 *
 * @param game a pointer to the struct game
 * @return the pointer to the player
 */
 Player *game_get_player(Game *game);

/**
 * @brief It gets the pointer of the character with the pass id
 * @author Héctor García Pérez
 *
 * @param game a pointer to the struct game
 * @param character id of the character
 * @return the pointer to the character with the pass id
 */
Character *game_get_character(Game *game, Id character);

/**
 * @brief It gets the location of the character
 * @author Héctor García Pérez
 *
 * @param game a pointer to the struct game
 * @param character id of the character
 * @return the id of the space where the character is or NO_ID if there was some error
 */
Id game_get_character_location(Game *game, Id character);

/**
 * @brief It gets the array of the ids of all the characters in the game
 * @author Héctor García Pérez
 *
 * @param game a pointer to the struct game
 * @return the pointer to the array of ids
 */
Id *game_get_all_characters(Game *game);

/**
 * @brief It gets the number of characters of the game
 * @author Héctor García Pérez
 *
 * @param game a pointer to the struct game
 * @return the number of characters or -1 if there was an error
 */
int game_get_n_characters(Game *game);

/**
 * @brief It obtains the position of the object
 * @author Héctor García Pérez
 *
 * @param game a pointer to game that we are using
 * @param object the id of the object we want to know its position
 * @return the id of the space where the object is
 */
Id game_get_object_location(Game *game, Id object);

/**
 * @brief It sets the position of the object at the id that correspond
 * @author Héctor García Pérez
 *
 * @param game a pointer to game that we are using
 * @param space the id of the space where the object is going to be placed
 * @param object the id og the object we want to set in the space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_object_location(Game *game, Id space, Id object);

/**
 * @brief It gets the pointer of the object with the pass name
 * @author Héctor García Pérez
 *
 * @param game a pointer to the struct game
 * @param name_object the name of the object, we are looking for
 * @return the pointer to the game object
 */
Object *game_get_object_with_name(Game *game, char *name_object);

/**
 * @brief It gets the pointer of the object with the pass id
 * @author Héctor García Pérez
 *
 * @param game a pointer to the struct game
 * @param object the id of the object, we are looking for
 * @return the pointer to the game object
 */
Object *game_get_object_with_id(Game *game, Id object);

/**
 * @brief It gets an array of all the object's ids of the game
 * @author Héctor García Pérez
 *
 * @param game a pointer to the struct game
 * @return the pointer to the allocated array
 */
Id *game_get_all_objects(Game *game);

/**
 * @brief It gets the number of objects in the game
 * @author Héctor García Pérez
 *
 * @param game a pointer to the struct game
 * @return the number of objects or -1 if there was an error
 */
int game_get_n_objects(Game *game);

/**
 * @brief It adds the new processed object to the game
 * @author Héctor García Pérez
 *
 * @param game a pointer to the game that must be initialized
 * @param object a pointer to the object that must be added
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_add_object(Game *game, Object *object);

/**
 * @brief It obtains the last instruction send
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are using
 * @return a pointer to the struct Command that stores at code
 */
Command *game_get_last_command(Game *game);

/**
 * @brief It inizialices the last command with pointer command
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are using
 * @param command a pointer to the a command
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_last_command(Game *game, Command *command);

/**
 * @brief It informs us if the game is finished
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are using
 * @return False if the game is not finished and True if the game is finished
 */
Bool game_get_finished(Game *game);

/**
 * @brief It make the game finish
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are using
 * @param finished it told us if it is finish with true and false
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_finished(Game *game, Bool finished);

/**
 * @brief It gets the last message of the game
 * @author Héctor García Pérez
 *
 * @param game a pointer to the game that must be initialized
 * @return a pointer to the string with the character
 */
char *game_get_last_message(Game *game);

/**
 * @brief It sets the last message of the game
 * @author Héctor García Pérez
 *
 * @param game a pointer to the game that must be initialized
 * @param message a pointer to the last message of the game
 * @return OK, if all went well, or ERROR otherwise
 */
Status game_set_last_message(Game *game, char *message);

/**
 * @brief It prints the information of the game
 * @author Héctor García Pérez
 *
 * @param game a pointer to game that we are using
 */
void game_print(Game *game);

#endif