/**
 * @brief It tests set module
 *
 * @file set_test.c
 * @author Héctor García Pérez
 * @version 0.0
 * @date 21-02-2025
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>

#include "set.h"
#include "set_test.h"
#include "types.h"
#include "test.h"

#define MAX_TESTS 19

/** @brief Main function for SET unit tests.
*
* You may execute ALL or a SINGLE test
*   1.- No parameter -> ALL test are executed
*   2.- A number means a particular test (the one identified by that number)
*       is executed
*
*/
int main(int argc, char **argv)
{
    int test = 0;
    int all = 1;

    if (argc < 2)
    {
        printf("Running all test for module Space:\n");
    }
    else
    {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 && test > MAX_TESTS)
        {
            printf("Error: unknown test %d\t", test);
            exit(EXIT_SUCCESS);
        }
    }

    if (all || test == 1)
        test1_set_create();
    if (all || test == 2)
        test2_set_create();
    if (all || test == 3)
        test1_set_add_id();
    if (all || test == 4)
        test2_set_add_id();
    if (all || test == 5)
        test3_set_add_id();
    if (all || test == 6)
        test4_set_add_id();
    if (all || test == 7)
        test5_set_add_id();
    if (all || test == 8)
        test6_set_add_id();
    if (all || test == 9)
        test1_set_del_id();
    if (all || test == 10)
        test2_set_del_id();
    if (all || test == 11)
        test3_set_del_id();
    if (all || test == 12)
        test4_set_del_id();
    if (all || test == 13)
        test5_set_del_id();
    if (all || test == 14)
        test1_set_find_id();
    if (all || test == 15)
        test2_set_find_id();
    if (all || test == 16)
        test3_set_find_id();
    if (all || test == 17)
        test4_set_find_id();
    if (all || test == 18)
        test1_set_get_number_ids();
    if (all || test == 19)
        test2_set_get_number_ids();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_set_create()
{
    Set *set = NULL;
    int result;

    set = set_create();

    result = set != NULL;

    PRINT_TEST_RESULT(result);

    set_destroy(set);
}

void test2_set_create()
{
    Set *set = NULL;

    set = set_create();

    PRINT_TEST_RESULT(!set_get_number_ids(set));
    set_destroy(set);
}

void test1_set_add_id()
{
    Set *set = NULL;

    set = set_create();

    PRINT_TEST_RESULT(set_add_id(set, 5) == OK);
    set_destroy(set);
}

void test2_set_add_id()
{
    Set *set = NULL;
    int i;

    set = set_create();

    for (i = 0; i < MAX_IDS; i++)
    {
        set_add_id(set, i);
    }

    PRINT_TEST_RESULT(set_add_id(set, i) == ERROR);
    set_destroy(set);
} /* Set lleno*/

void test3_set_add_id()
{
    Set *set = NULL;

    set = set_create();

    PRINT_TEST_RESULT(set_add_id(set, NO_ID) == ERROR);

    set_destroy(set);
} /* le paso NO_ID*/

void test4_set_add_id()
{
    Set *set = NULL;

    PRINT_TEST_RESULT(set_add_id(set, 5) == ERROR);
} /* puntero null*/

void test5_set_add_id()
{
    Set *set = NULL;

    set = set_create();

    set_add_id(set, 5);

    PRINT_TEST_RESULT(set_add_id(set, 5) == ERROR);
    set_destroy(set);
} /* id ya está en el set*/

void test6_set_add_id()
{
    Set *set = NULL;

    set = set_create();
    set_add_id(set, 5);

    PRINT_TEST_RESULT((set_find_id(set, 5) == 0) && set_get_number_ids(set) == 1);
    set_destroy(set);
}

void test1_set_del_id()
{
    Set *set = NULL;

    set = set_create();

    set_add_id(set, 5);
    set_add_id(set, 6);

    PRINT_TEST_RESULT(set_del_id(set, 5) == OK);
    set_destroy(set);
}

void test2_set_del_id()
{
    Set *set = NULL;

    set = set_create();

    PRINT_TEST_RESULT(set_del_id(set, 5) == ERROR);
    set_destroy(set);
} /* si id no en set*/

void test3_set_del_id()
{
    Set *set = NULL;

    PRINT_TEST_RESULT(set_del_id(set, 5) == ERROR);
} /* puntero null*/

void test4_set_del_id()
{
    Set *set = NULL;

    set = set_create();

    PRINT_TEST_RESULT(set_del_id(set, NO_ID) == ERROR);
    set_destroy(set);
} /* id es NO_ID*/

void test5_set_del_id()
{
    Set *set = NULL;

    set = set_create();

    set_add_id(set, 5);
    set_add_id(set, 6);
    set_del_id(set, 5);

    PRINT_TEST_RESULT((set_find_id(set, 5) == -1) && set_get_number_ids(set) == 1);
    set_destroy(set);
}

void test1_set_find_id()
{
    Set *set = NULL;

    set = set_create();
    set_add_id(set, 5);
    set_add_id(set, 6);
    set_add_id(set, 7);

    PRINT_TEST_RESULT(((set_find_id(set, 5) == 0) && (set_find_id(set, 6) == 1) && (set_find_id(set, 7) == 2)));
    set_destroy(set);
} /* comprueba que encuentra bien con un id*/

void test2_set_find_id()
{
    Set *set = NULL;

    PRINT_TEST_RESULT((set_find_id(set, 5) == -1));
} /* puntero NULL*/
void test3_set_find_id()
{
    Set *set = NULL;

    set = set_create();
    set_add_id(set, 5);

    PRINT_TEST_RESULT((set_find_id(set, NO_ID)) == -1);
    set_destroy(set);
} /* No_id*/
void test4_set_find_id()
{
    Set *set = NULL;

    set = set_create();
    set_add_id(set, 5);

    PRINT_TEST_RESULT((set_find_id(set, 6)) == -1);
    set_destroy(set);
} /* no esta en el array*/

void test1_set_get_number_ids()
{
    Set *set = NULL;

    set = set_create();
    set_add_id(set, 5);
    set_add_id(set, 6);
    set_add_id(set, 7);
    set_del_id(set, 5);

    PRINT_TEST_RESULT(set_get_number_ids(set) == 2);
    set_destroy(set);
} /* cuenta bien*/

void test2_set_get_number_ids()
{
    Set *set = NULL;

    PRINT_TEST_RESULT(set_get_number_ids(set) == -1);

} /* puntero null*/