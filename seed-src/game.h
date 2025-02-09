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

#define MAX_SPACES 100

/**
 * @brief Game
 *
 * This struct stores all the information of the game.
 */
typedef struct _Game
{
  Player *player;            /*!< Pointer to the player's objects*/
  Object *object;            /*!< Pointer to the game's object*/
  Space *spaces[MAX_SPACES]; /*!< This struct stores all the information of a space*/
  int n_spaces;              /*!< Number of spaces*/
  Command *last_cmd;         /*!< The code of the last command*/
  Bool finished;             /*!< TRUE or FALSE if it is finished*/
} Game;

/**
 * @brief It creates the game initializing the spaces to null or not having yet place the object or player
 * @author Héctor García Pérez
 *
 * @param game a pointer to game which is going to be created
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_create(Game *game);

/**
 * @brief It creates the game using the file of data
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are going to use
 * @param filename a pointer to the name of the file with the data
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_create_from_file(Game *game, char *filename);

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
 * @brief It obtains the position of the object
 * @author Héctor García Pérez
 *
 * @param game a pointer to game that we are using
 * @return the id of the space where the object is
 */
Id game_get_object_location(Game *game);

/**
 * @brief It sets the position of the object at the id that correspond
 * @author Héctor García Pérez
 *
 * @param game a pointer to game that we are using
 * @param id the id of the space where the object is going to be placed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_object_location(Game *game, Id id);

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
 * @brief It prints the information of the game
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are using
 */
void game_print(Game *game);

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
 * @brief It gets the pointer of the object
 * @author Héctor García Pérez
 *
 * @param game a pointer to the struct game
 * @return the pointer to the game object
 */
Object *game_get_object(Game *game);

/**
 * @brief It gets the pointer of the player
 * @author Héctor García Pérez
 *
 * @param game a pointer to the struct game
 * @return the pointer to the player
 */

Player *game_get_player(Game *player);


#endif
