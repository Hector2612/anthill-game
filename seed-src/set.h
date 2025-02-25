/**
 * @brief It defines the sets module interface
 *
 * @file set.h
 * @author Héctor García Pérez
 * @version 0
 * @date 18-02-2025
 * @copyright GNU Public License
 */

#ifndef SET_H
#define SET_H

#include "types.h"

/* Maximum number of ids in a set*/
#define MAX_IDS 10

typedef struct _Set Set;

/**
 * @brief It creates a new set, allocating memory
 * @author Héctor García Pérez
 *
 * @return a new set, initialized
 */
Set *set_create();

/**
 * @brief It destroys a set,freeing the allocating memory
 * @author Héctor García Pérez
 *
 * @param set a pointer to the set we want to destroy
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status set_destroy(Set *set);

/**
 * @brief It adds an id to the set
 * @author Héctor García Pérez
 *
 * @param set a pointer to the set
 * @param id the id we want to add
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status set_add_id(Set *set, Id id);

/**
 * @brief It deletes an id of the set
 * @author Héctor García Pérez
 *
 * @param set a pointer to the set
 * @param id the id we want to delete
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status set_del_id(Set *set, Id id);

/**
 * @brief It prints all the information of the set
 * @author Héctor García Pérez
 *
 * @param set a pointer to the set we want to print
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status set_print(Set *set);

/**
 * @brief It finds if an id is in the set
 * @author Héctor García Pérez
 *
 * @param set a pointer to the set we want to print
 * @param id the id we want to find in the set
 * @return the position of the id in the array, it returns -1 if it isn't in the array or if there is an error
 */
Bool set_find_id(Set *set, Id id);

/**
 * @brief It gets the number of ids of the set
 * @author Héctor García Pérez
 *
 * @param set a pointer to the set we want to print
 * @return the number of ids, or -1 if there is an error
 */
int set_get_number_ids(Set *set);

#endif