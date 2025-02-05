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

#define MAX_SPACES 100

typedef struct _Game {
  Id player_location; /*number of the id where the player is*/
  Id object_location; /*number of the id where the object is*/
  Space *spaces[MAX_SPACES]; /*This struct stores all the information of a space*/
  int n_spaces; /*number of spaces*/
  Command *last_cmd; /*the code of the last command*/
  Bool finished; /*TRUE or FALSE if it is finished*/
} Game;

/**
 * @brief It create the game initializing the spaces to null or not having yet place the object or player
 * @author Profesores PPROG
 *
 * @param game a pointer to game which is going to be created
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_create(Game *game);

/**
 * @brief uses the function game_creat and game_load_spaces which are also check and place the object and player in the first space
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are going to use
 * @param filename a pointer to the name of the file with the data 
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_create_from_file(Game *game, char *filename);

/**
 * @brief it frees pointer game
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are going to use
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_destroy(Game *game);

/**
 * @brief creates new spaces for game
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are going to use
 * @param id  the id number of the spaces that are going to be created
 * @return to the struct space
 */
Space *game_get_space(Game *game, Id id);

/**
 * @brief it obtains the position of the player 
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are using 
 * @return the id of the space where the player is
 */
Id game_get_player_location(Game *game);

/**
 * @brief it sets the position of the player at the id that correspond
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are using
 * @param id the id of the space where the player is going to be placed 
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_player_location(Game *game, Id id);

/**
 * @brief it obtains the position of the object 
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are using 
 * @return the id of the space where the object is
 */
Id game_get_object_location(Game *game);

/**
 * @brief it sets the position of the object at the id that correspond
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are using
 * @param id the id of the space where the object is going to be placed 
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_object_location(Game *game, Id id);

/**
 * @brief it obtains the last instruction send
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are using
 * @return a pointer to the struct Command that stores at code
 */
Command *game_get_last_command(Game *game);

/**
 * @brief it inizialices the last command with pointer command
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are using
 * @param command a pointer to the a command
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_last_command(Game *game, Command *command);

/**
 * @brief it informs us if the game is finished
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are using
 * @return False if the game is not finished and True if the game is finished
 */
Bool game_get_finished(Game *game);

/**
 * @brief it make the game finish 
 * @author Profesores PPROG
 *
 * @param game a pointer to game that we are using
 * @param finished it told us if it is finish with true and false
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_finished(Game *game, Bool finished);

/**
 * @brief it prints the board
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

#endif
