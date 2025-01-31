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

Status game_reader_initialize_game(Game *game, char *filename);

Status game_reader_load_spaces(Game *game, char *filename);

Status game_reader_add_space(Game *game, Space *space);

#endif