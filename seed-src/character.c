/**
 * @brief It implements the character module
 *
 * @file player.c
 * @author Jaime Luna Lavela
 * @version 0
 * @date 09-02-2025

 */

#include "character.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Character
 *
 * This struct stores all the information of a character.
 */
struct _Character
{
    Id id;                       /*!< Id of the character*/
    char name[WORD_SIZE + 1];    /*!< Name of the character */
    char gdesc[TAMGDESC + 1];    /*!< Graphic character description*/
    int health;                  /*!< Quantity of life points*/
    Bool friendly;               /*!< Wether the character is a friend or an enemy*/
    char message[WORD_SIZE + 1]; /*!< Message of the character*/
};

/* It creates a new player, allocating memory and initializing its members*/
Character *character_create(Id id)
{
    Character *new_character = NULL;

    /* Control error*/
    if (id == NO_ID)
    {
        return NULL;
    }

    /* Allocates memory*/
    new_character = (Character *)malloc(sizeof(Character));
    if (new_character == NULL)
    {
        return NULL;
    }

    /* Initialize the character*/
    new_character->id = id;
    new_character->name[0] = '\0';
    new_character->gdesc[0] = '\0';
    new_character->health = CHARACTER_HEALTH;
    new_character->message[0] = '\0';
    new_character->friendly = TRUE;

    return new_character;
}

/* It destroys a character, freeing the allocated memory*/
Status character_destroy(Character *character)
{
    /* Control error*/
    if (!character)
    {
        return ERROR;
    }

    /* Free the allocated memory*/
    free(character);

    return OK;
}

/* It gets the id of a character*/
Id character_get_id(Character *character)
{
    /* Control error*/
    if (!character)
    {
        return NO_ID;
    }

    return character->id;
}

/* It sets the name of a character*/
Status character_set_name(Character *character, const char *name)
{
    /* Control error*/
    if (!character || !name || strlen(name) > WORD_SIZE)
    {
        return ERROR;
    }

    /* Copy the pass name*/
    if (!strcpy(character->name, name))
    {

        return ERROR;
    }

    return OK;
}

/* It gets the name of a character*/
char *character_get_name(Character *character)
{
    /* Control error*/
    if (!character)
    {
        return NULL;
    }

    return character->name;
}

/* It sets the description of a character*/
Status character_set_gdesc(Character *character, const char *gdesc)
{
    /* Control errror*/
    if (!character || !gdesc || strlen(gdesc) > TAMGDESC)
    {
        return ERROR;
    }

    /* Copy the graphic description*/
    if (!strcpy(character->gdesc, gdesc))
    {

        return ERROR;
    }

    return OK;
}

/* It gets the description of a character*/
char *character_get_gdesc(Character *character)
{
    /* Control error*/
    if (!character)
    {
        return NULL;
    }

    return character->gdesc;
}

/* It sets the health of a character*/
Status character_set_health(Character *character, int health)
{
    /* Control errror*/
    if (!character || health < 0)
    {
        return ERROR;
    }

    /* Sets the character health*/
    character->health = health;

    return OK;
}

/* It gets the health of a character*/
int character_get_health(Character *character)
{
    /* Control error*/
    if (!character)
    {
        return -1;
    }

    return character->health;
}

/* It sets if the character is either friend or enemy*/
Status character_set_friendly(Character *character, Bool friend)
{
    /* Control error*/
    if (!character || (friend != TRUE && friend != FALSE))
    {
        return ERROR;
    }

    /* Sets the friendly status*/
    character->friendly = friend;

    return OK;
}

/* It gets wheter the characther is friend or not*/
Bool character_get_friendly(Character *character)
{
    /* Control error*/
    if (!character)
    {
        return FALSE;
    }

    return character->friendly;
}

/* It sets the message of the character*/
Status character_set_message(Character *character, const char *message)
{
    /* Control error*/
    if (!character || !message || strlen(message) > WORD_SIZE)
    {
        return ERROR;
    }

    /* Sets the message of the character*/
    if (!strcpy(character->message, message))
    {
        return ERROR;
    }

    return OK;
}

/* It gets the message of a character*/
char *character_get_message(Character *character)
{
    /* Control error*/
    if (!character)
    {
        return NULL;
    }

    return character->message;
}

/* It prints the character information*/
Status character_print(Character *character)
{
    /* Control error*/
    if (!character)
    {
        return ERROR;
    }

    /* 1. Print the id , the name and health of the character */
    fprintf(stdout, "--> %s (Id: %ld; Name: %s; (%d))\n", character->gdesc, character->id, character->name, character->health);

    /* 2. Print if the character is enemy or friend and if he must say a message*/
    if (character->friendly == TRUE)
    {
        fprintf(stdout, "--> friend");
        fprintf(stdout, "--> %s", character->message);
    }
    else
    {
        fprintf(stdout, "--> enemy");
    }

    return OK;
}