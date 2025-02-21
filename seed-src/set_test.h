/**
 * @brief It declares the tests for the set module
 *
 * @file set_test.h
 * @author Héctor García Pérez
 * @version 0.0
 * @date 21-02-2025
 * @copyright GNU Public License
 */

#ifndef SET_TEST_H
#define SET_TEST_H

/**
 * @test Test set creation
 * @post Non NULL pointer to set
 */
void test1_set_create();

/**
 * @test Test set creation
 * @post Number of elements of the set == 0
 */
void test2_set_create();

/**
 * @test Test set add an id
 * @pre The id we want to add to the set
 * @post Output == OK
 */
void test1_set_add_id();

/**
 * @test Test set add an id
 * @pre The id we want to add and a set already full
 * @post Output == ERROR
 */
void test2_set_add_id();

/**
 * @test Test set add an id
 * @pre The id is NO_ID
 * @post Output == ERROR
 */
void test3_set_add_id();

/**
 * @test Test set add an id
 * @pre The pointer to set is NULL
 * @post Output == ERROR
 */
void test4_set_add_id();

/**
 * @test Test set add an id
 * @pre An id that is already in the set
 * @post Output == ERROR
 */
void test5_set_add_id();

/**
 * @test Test set add an id
 * @pre The id we want to add to the set
 * @post Find the add id in the set and increments the number of ids
 */
void test6_set_add_id();

/**
 * @test Test set delete an id
 * @pre The id we want to deletee
 * @post Output == OK
 */
void test1_set_del_id();

/**
 * @test Test set delete an id
 * @pre An id that isn't in the set
 * @post Output == ERROR
 */
void test2_set_del_id();

/**
 * @test Test set delete an id
 * @pre A pointer to set == NULL
 * @post Output == ERROR
 */
void test3_set_del_id();

/**
 * @test Test set delete an id
 * @pre The id == NO_ID
 * @post Output == ERROR
 */
void test4_set_del_id();

/**
 * @test Test set delete an id
 * @pre The id we want to delete
 * @post Decrements the number of ids and we cannot find the delete id
 */
void test5_set_del_id();

/**
 * @test Test set find id
 * @pre The ids we want to find
 * @post Output == position of each id in set
 */
void test1_set_find_id();

/**
 * @test Test set find id
 * @pre A pointer to set == NULL
 * @post Output == -1
 */
void test2_set_find_id();

/**
 * @test Test set find id
 * @pre The id == NO_ID
 * @post Output == ERROR
 */
void test3_set_find_id();

/**
 * @test Test set find id
 * @pre The ids we want to find isn't in set
 * @post Output == -1
 */
void test4_set_find_id(); 

/**
 * @test Test set get number of ids
 * @pre A pointer to the set
 * @post Output == number of ids we added
 */
void test1_set_get_number_ids();

/**
 * @test Test set get number of ids
 * @pre A pointer to the set == NULL
 * @post Output == -1
 */
void test2_set_get_number_ids();

#endif