#ifndef SET_H
#define SET_H

#include "types.h"

#define MAX_IDS 10

typedef struct _Set Set;

Set *set_create();

Status set_destroy(Set *set);

Status set_add_id(Set *set, Id id);

Status set_del_id(Set *set, Id id);

Status set_print(Set *set);

#endif