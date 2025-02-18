#include <stdio.h>
#include <stdlib.h>

#include "set.h"

struct _Set
{
    int n_ids;
    Id ids[MAX_IDS];
};

Set *set_create()
{
    int i;
    Set *set = NULL;

    if (!(set = (Set *)malloc(sizeof(Set))))
    {
        return NULL;
    }

    for (i = 0; i < MAX_IDS; i++)
    {
        set->ids[i] = NO_ID;
    }

    set->n_ids = 0;

    return set;
}

Status set_destroy(Set *set)
{
    if (!set)
    {
        return ERROR;
    }

    free(set);

    return OK;
}

Status set_add_id(Set *set, Id id)
{
    if (!set || id == NO_ID || set->n_ids >= MAX_IDS)
    {
        return ERROR;
    }

    set->ids[set->n_ids] = id;

    set->n_ids++;

    return OK;
}

Status set_del_id(Set *set, Id id)
{
    int i, position_in_array = -1;

    if (!set || id == NO_ID)
    {
        return ERROR;
    }

    for (i = 0; i < set->n_ids; i++)
    {
        if (set->ids[i] == id)
        {
            position_in_array = i;
        }
    }

    if (position_in_array == -1)
    {
        return ERROR;
    }

    set->ids[position_in_array] = set->ids[--(set->n_ids)];

    set->ids[set->n_ids] = NO_ID;

    return OK;
}

Status set_print(Set *set)
{
    int i;

    if (!set)
    {
        return ERROR;
    }

    fprintf(stdout, "Set: \n");

    for (i = 0; i < set->n_ids; i++)
    {
        fprintf(stdout, "%d. id:%ld\n", i+1, set->ids[i]);
    }

    return OK;
}
