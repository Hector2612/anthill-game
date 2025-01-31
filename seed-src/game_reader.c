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

Status game_reader_initialize_game(Game *game, char *filename)
{
    if (!game || !filename)
    {
        return ERROR;
    }

    if (game_create(game) == ERROR)
    {
        return ERROR;
    }

    if (game_reader_load_spaces(game, filename) == ERROR)
    {
        return ERROR;
    }

    return OK;
}

Status game_reader_load_spaces(Game *game, char *filename)
{
    FILE *file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char *toks = NULL;
    Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
    Space *space = NULL;
    Status status = OK;

    if (!game || !filename)
    {
        return ERROR;
    }

    if (!(file = fopen(filename, "r")))
    {
        return ERROR;
    }

    while (fgets(line, WORD_SIZE, file))
    {
        if (strncmp("#s:", line, 3) == 0)
        {
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

            if (!(space = space_create(id)))
            {
                return ERROR;
            }

            space_set_name(space, name);
            space_set_north(space, north);
            space_set_east(space, east);
            space_set_south(space, south);
            space_set_west(space, west);

            if (game_reader_add_space(game, space) == ERROR)
            {
                space_destroy(space);
                return ERROR;
            }
        }
    }

    if (ferror(file))
    {
        status = ERROR;
    }

    fclose(file);

    return status;
}

Status game_reader_add_space(Game *game, Space *space)
{
    if (!game || !space || (game->n_spaces >= MAX_SPACES))
    {
        return ERROR;
    }

    game->spaces[game->n_spaces] = space;
    (game->n_spaces)++;

    return OK;
}