/*!
 * @file    slist.h
 * @brief   Implement singly link list
 *
 * @Created on: 24-Sep-2020
 * @Author: sanjay suthar
 */

#include "slist.h"
#include <stdio.h>
#include <stdlib.h>

/* Helper Function */

sll_node_t * create_slist_node(void * data) {

    sll_node_t * new_node = (sll_node_t *) calloc(1, sizeof(sll_node_t));

    if (!new_node)
        return NULL;

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

/* @function : create a new slist
 *
 * @param : pointer to list
 * @param : data to be inserted
 *
 * @returns : A pointer to the head of the list or NULL on failure
 * */
slist_t * create_new_slist(void *data) {

    /* declare a list */
    slist_t *list;

    /* Allocate memory for list*/
    list = (slist_t *) calloc(1, sizeof(slist_t));

    if (!list)
        return NULL;

    list->head = NULL;

    return list;
}

/* @function : Insert node in the front of a list.
 *
 * @param : pointer to list
 * @param : data to be inserted
 * @returns : 0 for success and -1 for failure
 * */
int insert_node_in_front(slist_t *slist, void *data) {

    sll_node_t *new_node;

    if (!slist || !data)
        return -1;

    new_node = (sll_node_t *)create_slist_node(data);

    if (!slist->head) {
        slist->head = new_node;
        return 0;
    }

    sll_node_t *first_node = slist->head;
    new_node->next = first_node;
    slist->head = new_node;

    return 0;
}

/* @function : Insert node in the end of a list.
 *
 * @param : pointer to list
 * @param : data to be inserted
 * @returns : 0 for success and -1 for failure
 * */
int insert_node_in_end(slist_t *slist, void *data) {

    sll_node_t *new_node;

    if (!slist || !data)
        return -1;

    new_node = (sll_node_t *)create_slist_node(data);

    if (!slist->head) {
        slist->head = new_node;
        return 0;
    }

    sll_node_t *temp = slist->head;

    /* Traversing the list to get the end of list */
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;

    return 0;
}


/* @function : delete node in the front of a list.
 *
 * @param : pointer to list
 *
 * @returns : 0 for success and -1 for failure
 * */
int delete_node_in_front(slist_t *slist) {

    if (!slist || !slist->head)
        return -1;

    sll_node_t *temp = slist->head;

    slist->head = slist->head->next;
    free(temp);

    return 0;
}

/* @function : delete node in the end of a list.
 *
 * @param : pointer to list
 *
 * @returns : 0 for success and -1 for failure
 * */
int delete_node_in_end(slist_t *slist) {

    if (!slist || !slist->head)
        return -1;

    sll_node_t *temp = slist->head;
    sll_node_t *prev = NULL;

    /* Traversing the list to get the end of list */
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    };

    prev->next = NULL;
    free(temp);

    return 0;
}

/* @function : print the list.
 *
 *TBD : Make it generic
 *
 * @param : pointer to list
 * */
int print_list(slist_t *slist) {

    sll_node_t *temp = slist->head;

    if (!slist || !slist->head) {
        return -1;
    }
    printf("\nList elements are : ");
    while (temp != NULL) {
        printf("%d ", *((int*)temp->data));
        temp = temp->next;
    }

    return 0;
}


/* @function : print the list.
 *
 * @param : pointer to list
 * */
int free_list(slist_t *slist) {

    slist_t *listptr = slist;

    if (!slist || !slist->head)
        return -1;

    sll_node_t *temp = slist->head;
    while (!temp->next) {
        free(temp);
    }

    free(listptr);
    listptr->head = NULL;

    return 0;
}
