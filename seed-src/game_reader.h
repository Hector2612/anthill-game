/**
 * @brief It defines the modules that allow to inicilizate the game
 *
 * @file game_reader.h
 * @author Hector Garcia Perez
 * @version 0
 * @date 30-01-2025
 * @copyright GNU Public License
 */

#ifndef GameReader_H
#define GameReader_H

#include "types.h"
#include "space.h"
#include "game.h"

/**
 * @brief It processes all the necessary data to initialize the game
 * @author Hector Garcia Perez
 *
 * @param game a pointer to the game that must be initialized
 * @param filename a pointer to the name of the file with the data
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_reader_initialize_game(Game *game, char *filename);

/**
 * @brief It reads the file and loads the spaces into the game
 * @author Hector Garcia Perez
 *
 * @param game a pointer to the game that must be initialized
 * @param filename a pointer to the name of the file with the data
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_reader_load_spaces(Game *game, char *filename);

/**
 * @brief It adds the new processed space to the game
 * @author Hector Garcia Perez
 *
 * @param game a pointer to the game that must be initialized
 * @param space a pointer to the space that must be added
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_reader_add_space(Game *game, Space *space);

#endif