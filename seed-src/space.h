/**
 * @brief It defines the space module interface
 *
 * @file space.h
 * @author Profesores PPROG
 * @version 1
 * @date 1-03-2025
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"

typedef struct _Space Space;

/**
 * @brief It creates a new space, allocating memory and initializing its members
 * @author Héctor García Pérez
 *
 * @param id the identification number for the new space
 * @return a new space, initialized
 */
Space *space_create(Id id);

/**
 * @brief It destroys a space, freeing the allocated memory
 * @author Héctor García Pérez
 *
 * @param space a pointer to the space that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_destroy(Space *space);

/**
 * @brief It gets the id of a space
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return the id of space
 */
Id space_get_id(Space *space);

/**
 * @brief It sets the name of a space
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_name(Space *space, char *name);

/**
 * @brief It gets the name of a space
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return  a string with the name of the space
 */
const char *space_get_name(Space *space);

/**
 * @brief It sets the id of the space located at the north
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @param id the id number of the space located at the north
 * @return OK, if everything goes well or ERROR if there was some mistake
 */

Status space_set_north(Space *space, Id id);

/**
 * @brief It gets the id of the space located at the north
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return the id number of the space located at the north
 */
Id space_get_north(Space *space);

/**
 * @brief It sets the id of the space located at the south
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @param id the id number of the space located at the south
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_south(Space *space, Id id);

/**
 * @brief It gets the id of the space located at the south
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return the id number of the space located at the south
 */
Id space_get_south(Space *space);

/**
 * @brief It sets the id of the space located at the east
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @param id the id number of the space located at the east
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_east(Space *space, Id id);

/**
 * @brief It gets the id of the space located at the east
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return the id number of the space located at the east
 */
Id space_get_east(Space *space);

/**
 * @brief It sets the id of the space located at the west
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @param id the id number of the space located at the west
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_west(Space *space, Id id);

/**
 * @brief It gets the id of the space located at the west
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return the id number of the space located at the west
 */
Id space_get_west(Space *space);

/**
 * @brief It adds an object to the space
 * @author Héctor García Pérez
 *
 * @param space a pointer to the space
 * @param object the id of the object we want to set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_add_object(Space *space, Id object);

/**
 * @brief It finds if the pass object is in the space
 * @author Héctor García Pérez
 *
 * @param space a pointer to the space
 * @param object the id of the object we want to set
 * @return TRUE, if the object is in the space or FALSE if the object isn't in the space or there was an error
 */
Bool space_find_object(Space *space, Id object);

/**
 * @brief It removes an object from the space
 * @author Héctor García Pérez
 *
 * @param space a pointer to the space
 * @param object the id of the object we want to delete
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_remove_object(Space *space, Id object);

/**
 * @brief It gets the objects of the space
 * @author Héctor García Pérez
 *
 * @param space a pointer to the space
 * @return the set of the space
 */
const Set *space_get_objects(Space *space);

/**
 * @brief It prints the space information
 * @author Héctor García Pérez
 *
 * This fucntion shows the id and name of the space, the spaces that surrounds it and wheter it has an object or not.
 * @param space a pointer to the space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_print(Space *space);

#endif
