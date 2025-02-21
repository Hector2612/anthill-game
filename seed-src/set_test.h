#ifndef SET_TEST_H
#define SET_TEST_H

void test1_set_create(); /* todo bien*/
void test2_set_create(); /* inicializa sin elementos*/
void test1_set_add_id(); /* Todo bien*/
void test2_set_add_id(); /* Set lleno*/
void test3_set_add_id(); /* le paso NO_ID*/
void test4_set_add_id(); /* puntero null*/
void test5_set_add_id(); /* id ya está en el set*/
void test1_set_del_id(); /* si id no en set*/
void test2_set_del_id(); /* todo bien*/
void test3_set_del_id(); /* puntero null*/
void test4_set_del_id(); /* id es NO_ID*/
void test1_set_find_id(); /* comprueba que encuentra bien con un id*/
void test2_set_find_id(); /* puntero NULL*/
void test3_set_find_id(); /* No_id*/
void test4_set_find_id(); /* no esta en el array*/
void test1_set_get_number_ids(); /* cuenta bien*/
void test2_set_get_number_ids(); /* puntero null*/

#endif