/**
 * @brief It implements the space module
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "space.h"
#include "set.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Space
 *
 * This struct stores all the information of a space.
 */
struct _Space
{
    Id id;                    /*!< Id number of the space, it must be unique */
    char name[WORD_SIZE + 1]; /*!< Name of the space */
    Id north;                 /*!< Id of the space at the north */
    Id south;                 /*!< Id of the space at the south */
    Id east;                  /*!< Id of the space at the east */
    Id west;                  /*!< Id of the space at the west */
    Set *objects;             /*!< Id of the space's object*/
};

/* space_create allocates memory for a new space and initializes its members*/
Space *space_create(Id id)
{
    Space *newSpace = NULL;

    /* Error control */
    if (id == NO_ID)
        return NULL;

    /* Allocates memory or the new space*/
    newSpace = (Space *)malloc(sizeof(Space));
    if (newSpace == NULL)
    {
        return NULL;
    }

    /* Create the set for objects*/
    if (!((newSpace->objects) = set_create()))
    {
        free(newSpace);
        return NULL;
    }

    /* Initialization of an empty space*/
    newSpace->id = id;
    newSpace->name[0] = '\0';
    newSpace->north = NO_ID;
    newSpace->south = NO_ID;
    newSpace->east = NO_ID;
    newSpace->west = NO_ID;

    return newSpace;
}

/* It destroys a space, freeing the allocated memory*/
Status space_destroy(Space *space)
{
    /* Error control*/
    if (!space)
    {
        return ERROR;
    }

    /*Free the allocated memory*/

    if ((space->objects))
    {
        set_destroy(space->objects);
    }

    free(space);

    return OK;
}

/* It gets the id of a space*/
Id space_get_id(Space *space)
{
    /* Error control*/
    if (!space)
    {
        return NO_ID;
    }

    return space->id;
}

/* It sets the name of a space*/
Status space_set_name(Space *space, char *name)
{
    /* Error control*/
    if (!space || !name)
    {
        return ERROR;
    }

    /* copy the name of the argument to the name of the space, and check if there was an error*/
    if (!strcpy(space->name, name))
    {
        return ERROR;
    }

    return OK;
}

/* It gets the name of a space*/
const char *space_get_name(Space *space)
{
    /* Error control*/
    if (!space)
    {
        return NULL;
    }

    return space->name;
}

/* It sets the id of the space located at the north*/
Status space_set_north(Space *space, Id id)
{
    /* Error control*/
    if (!space || id == NO_ID)
    {
        return ERROR;
    }

    /* Set the id*/
    space->north = id;

    return OK;
}

/* It gets the id of the space located at the north*/
Id space_get_north(Space *space)
{
    /* Error control*/
    if (!space)
    {
        return NO_ID;
    }

    return space->north;
}

/* It sets the id of the space located at the south*/
Status space_set_south(Space *space, Id id)
{
    /* Error control*/
    if (!space || id == NO_ID)
    {
        return ERROR;
    }

    /* Set the id*/
    space->south = id;

    return OK;
}

/* It gets the id of the space located at the south*/
Id space_get_south(Space *space)
{
    /* Error control*/
    if (!space)
    {
        return NO_ID;
    }

    return space->south;
}

/* It sets the id of the space located at the east*/
Status space_set_east(Space *space, Id id)
{
    /* Error control*/
    if (!space || id == NO_ID)
    {
        return ERROR;
    }

    /* Set the id*/
    space->east = id;

    return OK;
}

/* It gets the id of the space located at the east*/
Id space_get_east(Space *space)
{
    /* Error control*/
    if (!space)
    {
        return NO_ID;
    }

    return space->east;
}

/* It sets the id of the space located at the west*/
Status space_set_west(Space *space, Id id)
{
    /* Error control*/
    if (!space || id == NO_ID)
    {
        return ERROR;
    }

    /* Set the id*/
    space->west = id;

    return OK;
}

/* It gets the id of the space located at the west*/
Id space_get_west(Space *space)
{
    /* Error control*/
    if (!space)
    {
        return NO_ID;
    }

    return space->west;
}

/* It adds an object to the space*/
Status space_add_object(Space *space, Id object)
{
    /* Error control*/
    if (!space || object == NO_ID)
    {
        return ERROR;
    }

    /* Set the object*/
    if (set_add_id(space->objects, object) == ERROR)
    {
        return ERROR;
    }

    return OK;
}

/* It removes an object from the space*/
Status space_remove_object(Space *space, Id object)
{

    /* Control error*/
    if (!space || object == NO_ID)
    {
        return ERROR;
    }

    /* Remove the object from the set of the space*/
    if (set_del_id(space->objects, object) == ERROR)
    {
        return ERROR;
    }

    return OK;
}

/* It finds if an object is the pass object is in the space*/
Bool sapace_find_object(Space *space, Id object)
{
    /* Control error*/
    if (!space || object == NO_ID)
    {
        return FALSE;
    }

    /* Finds the object in the set of the space*/
    if (set_find_id(space->objects, object) == FALSE)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

/* It gets whether the space has an object or not*/
const Set *space_get_object(Space *space)
{
    /* Error control*/
    if (!space)
    {
        return NULL;
    }

    return space->objects;
}

/* It prints the space information*/
Status space_print(Space *space)
{
    Id idaux = NO_ID;

    /* Error Control */
    if (!space)
    {
        return ERROR;
    }

    /* 1. Print the id and the name of the space */
    fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

    /* 2. For each direction, print its link */
    idaux = space_get_north(space);
    if (idaux != NO_ID)
    {
        fprintf(stdout, "---> North link: %ld.\n", idaux);
    }
    else
    {
        fprintf(stdout, "---> No north link.\n");
    }
    idaux = space_get_south(space);
    if (idaux != NO_ID)
    {
        fprintf(stdout, "---> South link: %ld.\n", idaux);
    }
    else
    {
        fprintf(stdout, "---> No south link.\n");
    }
    idaux = space_get_east(space);
    if (idaux != NO_ID)
    {
        fprintf(stdout, "---> East link: %ld.\n", idaux);
    }
    else
    {
        fprintf(stdout, "---> No east link.\n");
    }
    idaux = space_get_west(space);
    if (idaux != NO_ID)
    {
        fprintf(stdout, "---> West link: %ld.\n", idaux);
    }
    else
    {
        fprintf(stdout, "---> No west link.\n");
    }

    /* 3. Print the set of the Space*/
    if (set_print(space->objects) == ERROR)
    {
        return ERROR;
    }

    return OK;
}
