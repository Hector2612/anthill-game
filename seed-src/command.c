/**
 * @brief It implements the command interpreter
 *
 * @file command.c
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "command.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define CMD_LENGHT 30

char *cmd_to_str[N_CMD][N_CMDT] = {{"", "No command"}, {"", "Unknown"}, {"e", "Exit"}, {"n", "Next"}, {"b", "Back"}, {"t", "Take"}, {"d", "Drop"}};

/**
 * @brief Command
 *
 * This struct stores all the information related to a command.
 */
struct _Command
{
    CommandCode code; /*!< Name of the command */
};

/* It initializes the command to NULL*/
Command *command_create()
{
    Command *newCommand = NULL;

    /* Allocates memory for the new command*/
    newCommand = (Command *)malloc(sizeof(Command));
    if (newCommand == NULL) /* Control errors*/
    {
        return NULL;
    }

    /* Initialization of an empty command*/
    newCommand->code = NO_CMD;

    return newCommand;
}

/* It free the command*/
Status command_destroy(Command *command)
{
    /* Control error*/
    if (!command)
    {
        return ERROR;
    }

    /* Free the allocated memory*/
    free(command);

    return OK;
}

/* It sets a code to an especific command*/
Status command_set_code(Command *command, CommandCode code)
{
    /* Control error*/
    if (!command)
    {
        return ERROR;
    }

    /* set the code*/
    command->code = code;

    return OK;
}

/* It gets the information of the command*/
CommandCode command_get_code(Command *command)
{
    /* Control error*/
    if (!command)
    {
        return NO_CMD;
    }

    return command->code;
}

/* It realize the command chosen*/
Status command_get_user_input(Command *command)
{
    char input[CMD_LENGHT] = "", *token = NULL;
    int i = UNKNOWN - NO_CMD + 1; /* Initializate to 2*/
    CommandCode cmd;

    /* Control error*/
    if (!command)
    {
        return ERROR;
    }

    /* Read the user input, and make sure that it exist*/
    if (fgets(input, CMD_LENGHT, stdin))
    {
        /* Takes the input before ' ' and '\n*/
        token = strtok(input, " \n");
        if (!token)
        {
            return command_set_code(command, UNKNOWN);
        }

        /* initializates cmd to Unknown and the loop don't stop until it changes or if we reach the max num of commands*/
        cmd = UNKNOWN;
        while (cmd == UNKNOWN && i < N_CMD)
        {
            /* It compares with the commands from exit*/
            if (!strcasecmp(token, cmd_to_str[i][CMDS]) || !strcasecmp(token, cmd_to_str[i][CMDL]))
            {
                cmd = i + NO_CMD;
            }
            else
            {
                i++;
            }
        }

        return command_set_code(command, cmd);
    }
    else
        return command_set_code(command, EXIT); /* There was an error*/
}
