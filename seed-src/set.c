/**
 * @brief It implements the sets modules
 *
 * @file set.c
 * @author Héctor García Pérez
 * @version 0
 * @date 18-02-2025
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>

#include "set.h"

/**
 * @brief Set
 *
 * This struct stores the ids of a set and the number of ids
 */
struct _Set
{
    int n_ids;         /*!< The number of the ids in the set*/
    Id ids[MAX_IDS];   /*!< The array of the ids in the set*/
};

/* It creates a new set, allocating memory*/
Set *set_create()
{
    int i;
    Set *set = NULL;

    /* Allocs the memory for the set*/
    if (!(set = (Set *)malloc(sizeof(Set))))
    {
        return NULL;
    }

    /* Initializates all the ids of the set to NO_ID*/
    for (i = 0; i < MAX_IDS; i++)
    {
        set->ids[i] = NO_ID;
    }

    /* Initializates the number of the ids of the set to 0*/
    set->n_ids = 0;

    return set;
}

/* It destroys a set,freeing the allocating memory*/
Status set_destroy(Set *set)
{
    /* Control error*/
    if (!set)
    {
        return ERROR;
    }

    /* Free the allocated memory*/
    free(set);

    return OK;
}

/* It adds an id to the set*/
Status set_add_id(Set *set, Id id)
{
    /* Control error*/
    if (!set || id == NO_ID || set->n_ids >= MAX_IDS)
    {
        return ERROR;
    }

    /* Add the pass id*/
    set->ids[set->n_ids] = id;

    /* Increments the number of ids*/
    set->n_ids++;

    return OK;
}

/* It deletes an id of the set*/
Status set_del_id(Set *set, Id id)
{
    int i, position_in_array = -1;

    /* Control error*/
    if (!set || id == NO_ID)
    {
        return ERROR;
    }

    /* Find the pass id in the array*/
    for (i = 0; i < set->n_ids; i++)
    {
        if (set->ids[i] == id)
        {
            position_in_array = i;
        }
    }

    /* If the pass id isn't in the set*/
    if (position_in_array == -1)
    {
        return ERROR;
    }

    /* In the position of the pass id, puts the last id of the array*/
    set->ids[position_in_array] = set->ids[--(set->n_ids)];

    /* Puts the last id of the array to NO_ID*/
    set->ids[set->n_ids] = NO_ID;

    return OK;
}

/* It prints all the information of the set*/
Status set_print(Set *set)
{
    int i;

    /* Control error*/
    if (!set)
    {
        return ERROR;
    }

    
    fprintf(stdout, "Set: \n");

    /* Prints all the ids of the set*/
    for (i = 0; i < set->n_ids; i++)
    {
        fprintf(stdout, "%d. id:%ld\n", i + 1, set->ids[i]);
    }

    return OK;
}
