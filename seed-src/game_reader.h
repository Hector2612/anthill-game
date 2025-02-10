/**
 * @brief It defines the modules that allow to inicilizate the game with the data of the file
 *
 * @file game_reader.h
 * @author Héctor García Pérez
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
 * @brief It reads the file and loads the spaces into the game
 * @author Héctor García Pérez
 *
 * @param game a pointer to the game that must be initialized
 * @param filename a pointer to the name of the file with the data
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_reader_load_spaces(Game *game, const char *filename);

#endif