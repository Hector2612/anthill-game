/**
 * @brief It defines the game update interface
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef GAME_ACTIONS_H
#define GAME_ACTIONS_H

#include "command.h"
#include "game.h"
#include "types.h"

/**
 * @brief It is the function that will respond to our commands, doing what we say if it is possible
 * @author Héctor García Pérez
 *
 * @param game a pointer to game that we are using
 * @param cmd a word with our movement or command
 * @param specification a pointer to he specification of some commands
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_actions_update(Game *game, Command *cmd, char *command_specification);

#endif
