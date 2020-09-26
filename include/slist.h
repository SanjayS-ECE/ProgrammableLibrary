#ifndef _S_LIST_H
#define _S_LIST_H

#include <stdlib.h>
/*
 * copyright <TODO>
 */

/*!
 * @file    slist.h
 * @brief   Implement singly link list
 */

/* Data structure for single link list node */
typedef struct _sll_node {
	struct _sll_node *next;
	void *data;
}sll_node_t;

typedef struct _slist_t {
	sll_node_t *head;
} slist_t;


/* @function : create a singly linked list
 *
 * @returns : A pointer to the list or NULL on failure
 * */
slist_t * create_new_slist();

/* @function : Insert node in the front of a list.
 *
 * @param : pointer to list
 * @param : data to be inserted
 * @returns : 0 for success and -1 for failure
 * */
int insert_node_in_front(slist_t *slist, void *data);

/* @function : Insert node in the end of a list.
 *
 * @param : pointer to list
 * @param : data to be inserted
 * @returns : 0 for success and -1 for failure
 * */
int insert_node_in_end(slist_t *slist, void *data);


/* @function : delete node in the front of a list.
 *
 * @param : pointer to list
 * @param : data to be inserted
 * @returns : 0 for success and -1 for failure
 * */
int * delete_node_in_front(slist_t *list, void *data);

/* @function : Insert node in the end of a list.
 *
 * @param : pointer to list
 * @param : data to be inserted
 * @returns : 0 for success and -1 for failure
 * */
int * delete_node_in_end(slist_t *list, void *data);

/* @function : print the list.
 *
 * @param : pointer to list
 * */
void print_list(slist_t *list);


/* @function : print the list.
 *
 * @param : pointer to list
 * */
int free_list(slist_t *list);








#endif
