/**
 * @brief It implements the objects modules
 *
 * @file object.c
 * @author Héctor García Pérez
 * @version 0
 * @date 7-02-2025
 * @copyright GNU Public License
 */

#include "object.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Object
 *
 * This struct stores all the information of an object.
 */
struct _Object
{
    Id id;                    /*!< The id of the object*/
    char name[WORD_SIZE + 1]; /*!< The name of the object*/
};

/* It creates a new object, allocating memory*/
Object *object_create(Id id)
{
    Object *object;

    /* Control error*/
    if (id == NO_ID)
    {
        return NULL;
    }

    /* Allocates memory for the new object*/
    object = (Object *)malloc(sizeof(Object));
    if (!object)
    {
        return NULL;
    }

    /* Initializates the object*/
    object->id = id;
    object->name[0] = '\0';

    return object;
}

/* It destroys an object, freeing the allocated memory*/
Status object_destroy(Object *object)
{
    /* Control error*/
    if (!object)
    {
        return ERROR;
    }

    /* Free the allocated memory*/
    free(object);

    return OK;
}

/* It gets the id of an object*/
Id object_get_id(Object *object)
{
    /* Control error*/
    if (!object)
    {
        return NO_ID;
    }

    return object->id;
}

/* It gets the name of an object*/
const char *object_get_name(Object *object)
{
    /* Control error*/
    if (!object)
    {
        return NULL;
    }

    return object->name;
}

/* It sets the name of an object*/
Status object_set_name(Object *object, char *name)
{
    /* Control error*/
    if (!object || !name)
    {
        return ERROR;
    }

    /* Copy the argument to the object name*/
    if (!strcpy(object->name, name))
    {
        return ERROR;
    }

    return OK;
}

/* It prints the information of the object*/
Status object_print(Object *object)
{
    /* Control error*/
    if (!object)
    {
        return ERROR;
    }

    /* Prints the information of the object*/
    fprintf(stdout, "--> Object (Id: %ld; Name: %s)", object->id, object->name);

    return OK;
}