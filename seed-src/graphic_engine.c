/**
 * @brief It implements a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "graphic_engine.h"

#include <stdio.h>
#include <stdlib.h>

#include "command.h"
#include "libscreen.h"
#include "space.h"
#include "types.h"

#define WIDTH_MAP 48
#define WIDTH_DES 29
#define WIDTH_BAN 23
#define HEIGHT_MAP 13
#define HEIGHT_BAN 1
#define HEIGHT_HLP 2
#define HEIGHT_FDB 3

struct _Graphic_engine
{
    Area *map, *descript, *banner, *help, *feedback; /*!< It stores the are of the mad, the area of the description, the area for the banner, the area with the help and the area of feedback*/
};

/* Graphic_engine recive all the parameter*/
Graphic_engine *graphic_engine_create()
{
    static Graphic_engine *ge = NULL;

    if (ge)
    {
        return ge;
    }

    /* Initializate the screen*/
    screen_init(HEIGHT_MAP + HEIGHT_BAN + HEIGHT_HLP + HEIGHT_FDB + 4, WIDTH_MAP + WIDTH_DES + 3);
    ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
    if (ge == NULL)
    {
        return NULL;
    }

    /* Intitializate each area of the board*/
    ge->map = screen_area_init(1, 1, WIDTH_MAP, HEIGHT_MAP);
    ge->descript = screen_area_init(WIDTH_MAP + 2, 1, WIDTH_DES, HEIGHT_MAP);
    ge->banner = screen_area_init((int)((WIDTH_MAP + WIDTH_DES + 1 - WIDTH_BAN) / 2), HEIGHT_MAP + 2, WIDTH_BAN, HEIGHT_BAN);
    ge->help = screen_area_init(1, HEIGHT_MAP + HEIGHT_BAN + 2, WIDTH_MAP + WIDTH_DES + 1, HEIGHT_HLP);
    ge->feedback = screen_area_init(1, HEIGHT_MAP + HEIGHT_BAN + HEIGHT_HLP + 3, WIDTH_MAP + WIDTH_DES + 1, HEIGHT_FDB);

    return ge;
}

/* it destroy each atribute of ge it means equal to null*/
void graphic_engine_destroy(Graphic_engine *ge)
{
    if (!ge)
        return;

    /* Destroy each area of the screen*/
    screen_area_destroy(ge->map);
    screen_area_destroy(ge->descript);
    screen_area_destroy(ge->banner);
    screen_area_destroy(ge->help);
    screen_area_destroy(ge->feedback);

    /* Destroy and liberate screen*/
    screen_destroy();
    free(ge);
}

/* it represents the board game of the videogame*/
void graphic_engine_paint_game(Graphic_engine *ge, Game *game)
{
    Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_east = NO_ID, id_west = NO_ID, obj_loc = NO_ID;
    Space *space_act = NULL, *space_back = NULL, *space_next = NULL;
    char obj = '\0', obj_east = '\0', obj_west = '\0';
    char str[255];
    CommandCode last_cmd = UNKNOWN;
    extern char *cmd_to_str[N_CMD][N_CMDT];

    /* Paint the map area */
    screen_area_clear(ge->map);
    if ((id_act = game_get_player_location(game)) != NO_ID)
    {
        space_act = game_get_space(game, id_act);
        id_back = space_get_north(space_act);
        id_next = space_get_south(space_act);
        space_next = game_get_space(game, id_next);

        /* Check if the object is in that space*/
        if (game_get_object_location(game) == id_back)
            obj = '*';
        else
            obj = ' ';

        /* 1. Paint the back space*/
        if (id_back != NO_ID)
        {
            space_back = game_get_space(game, id_back);
            id_east = space_get_east(space_back);
            id_west = space_get_west(space_back);

            /* Check if thera are space at east or west of the back space and prints it depending of the result*/
            if (id_west != NO_ID && id_east != NO_ID)
            {
                /* Check if the object is in that space*/
                if (game_get_object_location(game) == id_east)
                    obj_east = '*';
                else
                    obj_east = ' ';

                /* Check if the object is in that space*/
                if (game_get_object_location(game) == id_west)
                    obj_west = '*';
                else
                    obj_west = ' ';

                sprintf(str, "  |        %3d| < |        %3d| > |        %3d|", (int)id_west, (int)id_back, (int)id_east);
                screen_area_puts(ge->map, str);
                sprintf(str, "  |     %c     |   |     %c     |   |     %c     |", obj_west, obj, obj_east);
                screen_area_puts(ge->map, str);
                sprintf(str, "  +-----------+   +-----------+   +-----------+");
                screen_area_puts(ge->map, str);
                sprintf(str, "%18c      ^", ' ');
                screen_area_puts(ge->map, str);
            }
            else if (id_east != NO_ID && id_west == NO_ID)
            {
                /* Check if the object is in that space*/
                if (game_get_object_location(game) == id_east)
                    obj_east = '*';
                else
                    obj_east = ' ';

                sprintf(str, "%18c|        %3d| > |        %3d|", ' ', (int)id_back, (int)id_east);
                screen_area_puts(ge->map, str);
                sprintf(str, "%18c|     %c     |   |     %c     |", ' ', obj, obj_east);
                screen_area_puts(ge->map, str);
                sprintf(str, "%18c+-----------+   +-----------+", ' ');
                screen_area_puts(ge->map, str);
                sprintf(str, "%18c      ^", ' ');
                screen_area_puts(ge->map, str);
            }
            else if (id_east == NO_ID && id_west != NO_ID)
            {
                /* Check if the object is in that space*/
                if (game_get_object_location(game) == id_west)
                    obj_west = '*';
                else
                    obj_west = ' ';

                sprintf(str, "  |        %3d| < |        %3d|", (int)id_west, (int)id_back);
                screen_area_puts(ge->map, str);
                sprintf(str, "  |     %c     |   |     %c     |", obj_west, obj);
                screen_area_puts(ge->map, str);
                sprintf(str, "  +-----------+   +-----------+");
                screen_area_puts(ge->map, str);
                sprintf(str, "%18c      ^", ' ');
                screen_area_puts(ge->map, str);
            }
            else
            {
                sprintf(str, "%18c|        %3d|", ' ', (int)id_back);
                screen_area_puts(ge->map, str);
                sprintf(str, "%18c|     %c     |", ' ', obj);
                screen_area_puts(ge->map, str);
                sprintf(str, "%18c+-----------+", ' ');
                screen_area_puts(ge->map, str);
                sprintf(str, "%18c      ^", ' ');
                screen_area_puts(ge->map, str);
            }
        }

        /* Check if the object is in that space*/
        if (game_get_object_location(game) == id_act)
            obj = '*';
        else
            obj = ' ';

        /* 2.Print the actual space*/
        if (id_act != NO_ID)
        {
            id_east = space_get_east(space_act);
            id_west = space_get_west(space_act);

            /* Check if thera are space at east or west of the space and prints it depending of the result*/
            if (id_west != NO_ID && id_east != NO_ID)
            {
                /* Check if the object is in that space*/
                if (game_get_object_location(game) == id_east)
                    obj_east = '*';
                else
                    obj_east = ' ';

                /* Check if the object is in that space*/
                if (game_get_object_location(game) == id_west)
                    obj_west = '*';
                else
                    obj_west = ' ';

                sprintf(str, "  +-----------+   +-----------+   +-----------+");
                screen_area_puts(ge->map, str);
                sprintf(str, "  |        %3d| < | m0^    %3d| > |        %3d|", (int)id_west, (int)id_act, (int)id_east);
                screen_area_puts(ge->map, str);
                sprintf(str, "  |     %c     |   |     %c     |   |     %c     |", obj_west, obj, obj_east);
                screen_area_puts(ge->map, str);
                sprintf(str, "  +-----------+   +-----------+   +-----------+");
                screen_area_puts(ge->map, str);
            }
            else if (id_west != NO_ID && id_east == NO_ID)
            {
                /* Check if the object is in that space*/
                if (game_get_object_location(game) == id_west)
                    obj_west = '*';
                else
                    obj_west = ' ';

                sprintf(str, "  +-----------+   +-----------+");
                screen_area_puts(ge->map, str);
                sprintf(str, "  |        %3d| < | m0^    %3d|", (int)id_west, (int)id_act);
                screen_area_puts(ge->map, str);
                sprintf(str, "  |     %c     |   |     %c     |", obj_west, obj);
                screen_area_puts(ge->map, str);
                sprintf(str, "  +-----------+   +-----------+");
                screen_area_puts(ge->map, str);
            }
            else if (id_east != NO_ID && id_west == NO_ID)
            {
                /* Check if the object is in that space*/
                if (game_get_object_location(game) == id_east)
                    obj_east = '*';
                else
                    obj_east = ' ';

                sprintf(str, "%18c+-----------+   +-----------+", ' ');
                screen_area_puts(ge->map, str);
                sprintf(str, "%18c| m0^    %3d| > |        %3d|", ' ', (int)id_act, (int)id_east);
                screen_area_puts(ge->map, str);
                sprintf(str, "%18c|     %c     |   |     %c     |", ' ', obj, obj_east);
                screen_area_puts(ge->map, str);
                sprintf(str, "%18c+-----------+   +-----------+", ' ');
                screen_area_puts(ge->map, str);
            }
            else
            {
                sprintf(str, "%18c+-----------+", ' ');
                screen_area_puts(ge->map, str);
                sprintf(str, "%18c| m0^    %3d|", ' ', (int)id_act);
                screen_area_puts(ge->map, str);
                sprintf(str, "%18c|     %c     |", ' ', obj);
                screen_area_puts(ge->map, str);
                sprintf(str, "%18c+-----------+", ' ');
                screen_area_puts(ge->map, str);
            }
        }

        /* Check if the object is in that space*/
        if (game_get_object_location(game) == id_next)
            obj = '*';
        else
            obj = ' ';

        /* 3.Print the next space*/
        if (id_next != NO_ID)
        {
            space_next = game_get_space(game, id_next);
            id_east = space_get_east(space_next);
            id_west = space_get_west(space_next);

            /* Check if thera are space at east or west of the next space and prints it depending of the result*/
            if (id_west != NO_ID && id_east != NO_ID)
            {
                /* Check if the object is in that space*/
                if (game_get_object_location(game) == id_east)
                    obj_east = '*';
                else
                    obj_east = ' ';

                /* Check if the object is in that space*/
                if (game_get_object_location(game) == id_west)
                    obj_west = '*';
                else
                    obj_west = ' ';

                sprintf(str, "  +-----------+   +-----------+   +-----------+");
                screen_area_puts(ge->map, str);
                sprintf(str, "  |        %3d| < |        %3d| > |        %3d|", (int)id_west, (int)id_act, (int)id_east);
                screen_area_puts(ge->map, str);
                sprintf(str, "  |     %c     |   |     %c     |   |     %c     |", obj_west, obj, obj_east);
                screen_area_puts(ge->map, str);
            }
            else if (id_east != NO_ID && id_west == NO_ID)
            {
                /* Check if the object is in that space*/
                if (game_get_object_location(game) == id_east)
                    obj_east = '*';
                else
                    obj_east = ' ';

                sprintf(str, "%18c      v", ' ');
                screen_area_puts(ge->map, str);
                sprintf(str, "%18c+-----------+   +-----------+", ' ');
                screen_area_puts(ge->map, str);
                sprintf(str, "%18c|        %3d| > |        %3d|", ' ', (int)id_next, (int)id_east);
                screen_area_puts(ge->map, str);
                sprintf(str, "%18c|     %c     |   |     %c     |", ' ', obj, obj_east);
                screen_area_puts(ge->map, str);
            }
            else if (id_west != NO_ID && id_east == NO_ID)
            {
                /* Check if the object is in that space*/
                if (game_get_object_location(game) == id_west)
                    obj_west = '*';
                else
                    obj_west = ' ';

                sprintf(str, "  +-----------+   +-----------+");
                screen_area_puts(ge->map, str);
                sprintf(str, "  |        %3d| < |        %3d|", (int)id_west, (int)id_act);
                screen_area_puts(ge->map, str);
                sprintf(str, "  |     %c     |   |     %c     |", obj_west, obj);
                screen_area_puts(ge->map, str);
            }
            else
            {
                sprintf(str, "%18c      v", ' ');
                screen_area_puts(ge->map, str);
                sprintf(str, "%18c+-----------+", ' ');
                screen_area_puts(ge->map, str);
                sprintf(str, "%18c|        %3d|", ' ', (int)id_next);
                screen_area_puts(ge->map, str);
                sprintf(str, "%18c|     %c     |", ' ', obj);
                screen_area_puts(ge->map, str);
            }
        }
    }

    /* Paint in the description area */
    screen_area_clear(ge->descript);
    if ((obj_loc = game_get_object_location(game)) != NO_ID)
    {
        sprintf(str, "  Object location:%d", (int)obj_loc);
        screen_area_puts(ge->descript, str);
    }
    else if (obj_loc == NO_ID && player_get_object(game_get_player(game)) != NO_ID)
    {
        sprintf(str, "  Object location:%d",(int)id_act);
        screen_area_puts(ge->descript, str);
    }

    /*Print the position of the player*/
    sprintf(str, "  Player location:%d", (int)id_act);
    screen_area_puts(ge->descript, str);

    /* Paint in the banner area */
    screen_area_puts(ge->banner, "    The anthill game ");

    /* Paint in the help area */
    screen_area_clear(ge->help);
    sprintf(str, " The commands you can use are:");
    screen_area_puts(ge->help, str);
    sprintf(str, "     next or n, back or b, exit or e, take or t, drop or d");
    screen_area_puts(ge->help, str);

    /* Paint in the feedback area */
    last_cmd = command_get_code(game_get_last_command(game));
    sprintf(str, " %s (%s)", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
    screen_area_puts(ge->feedback, str);

    /* Dump to the terminal */
    screen_paint();
    printf("prompt:> ");
}
