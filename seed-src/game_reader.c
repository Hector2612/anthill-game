/**
 * @brief It implement the functions that allow to inicilizate the game
 *
 * @file game_reader.c
 * @author Hector Garcia Perez
 * @version 0
 * @date 30-01-2025
 * @copyright GNU Public License
 */

#include "game_reader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*game_reader_load_spaces reads the file and loads the spaces into the game*/
Status game_reader_load_spaces(Game *game, const char *filename)
{
    FILE *file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char *toks = NULL;
    Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
    Space *space = NULL;
    Status status = OK;

    /* Control error*/
    if (!game || !filename)
    {
        return ERROR;
    }

    /* Open the file*/
    if (!(file = fopen(filename, "r")))
    {
        return ERROR;
    }

    /* Read all the file*/
    while (fgets(line, WORD_SIZE, file))
    {
        /*check each line of the file*/
        if (strncmp("#s:", line, 3) == 0) 
        {
            /*stores the information of the line, in the correct field*/
            toks = strtok(line + 3, "|");
            id = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(name, toks);
            toks = strtok(NULL, "|");
            north = atol(toks);
            toks = strtok(NULL, "|");
            east = atol(toks);
            toks = strtok(NULL, "|");
            south = atol(toks);
            toks = strtok(NULL, "|");
            west = atol(toks);

#ifdef DEBUG
            printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
            /*creates the space with the store id*/
            if (!(space = space_create(id)))
            {
                return ERROR;
            }

            /*saves the information in the new space*/
            space_set_name(space, name);
            space_set_north(space, north);
            space_set_east(space, east);
            space_set_south(space, south);
            space_set_west(space, west);

            /* Add the new space to the game*/
            if (game_add_space(game, space) == ERROR)
            {
                space_destroy(space);
                return ERROR;
            }
        }
    }

    /* Check if there was an error*/
    if (ferror(file))
    {
        status = ERROR;
    }

    /* Close the file*/
    fclose(file);

    return status;
}