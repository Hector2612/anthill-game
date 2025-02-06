/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef GRAPHIC_ENGINE_H
#define GRAPHIC_ENGINE_H

#include "game.h"

typedef struct _Graphic_engine Graphic_engine;

/**
 * @brief Graphic_engine recive all the parameter
 * @author Profesores PPROG
 *
 * @return Graphic_engine recive all the parameter
 */
Graphic_engine *graphic_engine_create();

/**
 * @brief it destroy each atribute of ge it means equal to null
 * @author Profesores PPROG
 *
 * @param ge pointer to ge the graphic engine of the videogame
 */
void graphic_engine_destroy(Graphic_engine *ge);

/**
 * @brief it represents the board game of the videogame
 * @author Héctor García Pérez
 *
 * @param ge the pointer with the measures
 * @param game the pointer to the game that is going to be initialized
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

#endif
