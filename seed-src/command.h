/**
 * @brief It defines the command interpreter interface
 *
 * @file command.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"

#define N_CMDT 2
#define N_CMD 7


/**
 * @brief It defines the two types of commands: short or long.
 */
typedef enum
{
    CMDS,
    CMDL
} CommandType;

/**
 * @brief It defines the different codes of the commands.
 */
typedef enum
{
    NO_CMD = -1,
    UNKNOWN,
    EXIT,
    NEXT,
    BACK,
    TAKE,
    DROP
} CommandCode;

typedef struct _Command Command;

/**
 * @brief It initializes the command to NULL
 * @author Profesores PPROG
 *
 * @return the pointer to command received is empty
 */
Command *command_create();

/**
 * @brief It free the command
 * @author Profesores PPROG
 *
 * @param command a pointer to a struct Command that has the code information
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status command_destroy(Command *command);

/**
 * @brief It sets a code to an especific command
 * @author Profesores PPROG
 *
 * @param command a pointer to the command chosen
 * @param code an enumeration with a value
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status command_set_code(Command *command, CommandCode code);

/**
 * @brief It gets the information of the command
 * @author Profesores PPROG
 *
 * @param commando a pointer of that estructure that has a value of the information that will proceed
 * @return it return the numeric value of command
 */
CommandCode command_get_code(Command *command);

/**
 * @brief It realize the command chosen
 * @author Profesores PPROG
 *
 * @param commando a pointer of that estructure that has a value of the information that will proceed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status command_get_user_input(Command *command);

#endif
