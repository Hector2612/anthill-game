/**
 * @brief It defines common types for the whole project
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 1000
#define NO_ID -1

/* Define the type of Id*/
typedef long Id;

/* Define the boole condition TRUE or FALSE*/
typedef enum
{
    FALSE,
    TRUE
} Bool;

/* Define the status of the game ERROR or OK*/
typedef enum
{
    ERROR,
    OK
} Status;

/* Define the directions of the game*/
typedef enum
{
    N,
    S,
    E,
    W
} Direction;

#endif
