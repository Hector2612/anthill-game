/**
 * @brief It defines the object modules interface
 *
 * @file object.h
 * @author Héctor García Pérez
 * @version 0
 * @date 7-02-2025
 * @copyright GNU Public License
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

typedef struct _Object Object;

/**
 * @brief It creates a new object, allocating memory
 * @author Héctor García Pérez
 *
 * @param id the identification number for the new object
 * @return a new object, initialized
 */
Object *object_create(Id id);

/**
 * @brief It destroys an object, freeing the allocated memory
 * @author Héctor García Pérez
 *
 * @param space a pointer to the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_destroy(Object *object);

/**
 * @brief It gets the id of an object
 * @author Héctor García Pérez
 *
 * @param space a pointer to the object
 * @return the id of the object
 */
Id object_get_id(Object *object);

/**
 * @brief It gets the name of an object
 * @author Héctor García Pérez
 *
 * @param space a pointer to the object
 * @return a pointer to the name of the object
 */
const char *object_get_name(Object *object);

/**
 * @brief It sets the name of an object
 * @author Héctor García Pérez
 *
 * @param space a pointer to the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_set_name(Object *object, const char *name);

/**
 * @brief It prints the information of the object
 * @author Héctor García Pérez
 *
 * @param space a pointer to the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_print(Object *object);

#endif