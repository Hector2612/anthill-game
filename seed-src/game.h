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

typedef struct _Game
{
  Id player_location;
  Id object_location;
  Space *spaces[MAX_SPACES];
  int n_spaces;
  Command *last_cmd;
  Bool finished;
} Game;

Status game_create(Game *game);

Status game_create_from_file(Game *game, char *filename);

Status game_destroy(Game *game);

Space *game_get_space(Game *game, Id id);

Id game_get_player_location(Game *game);

Status game_set_player_location(Game *game, Id id);

Id game_get_object_location(Game *game);

Status game_set_object_location(Game *game, Id id);

Command *game_get_last_command(Game *game);

Status game_set_last_command(Game *game, Command *command);

Bool game_get_finished(Game *game);

Status game_set_finished(Game *game, Bool finished);

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
