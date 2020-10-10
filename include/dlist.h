#ifndef _D_LIST_H
#define _D_LIST_H

#include <stdlib.h>
/*
 * copyright <TODO>
 */

/*!
 * @file    dlist.h
 * @brief   Implement doubly link list
 */

/* Data structure for double link list node */
typedef struct _dll_node {
	struct _dll_node *left;
    struct _dll_node *right;
} dll_node_t;

/* Data structure for single link list */
typedef struct _dlist {
	dll_node_t *head;
	unsigned int offset;
} dlist_t;

#define dlist_node_init(dll_node)   \
    dll_node->left = NULL;          \
    dll_node->right = NULL;

/* Iterative macro to Iterate Over dlist */
#define DLIST_ITERATE_BEGIN(lstptr, struct_type, ptr)               \
{                                                                   \
    dll_node_t *_dllnode = NULL, *_next = NULL;                     \
    for(_dllnode = lstptr->head; _dllnode; _dllnode = _next) {      \
        _next = _dllnode->right;                                    \
        ptr = (struct_type *)((char*)_dllnode - lstptr->offset);

#define DLIST_ITERATE_END   }}

#define offsetof(struct_name, field_name)   \
    ((unsigned int)&((struct_name *)0)->field_name)

        /* @function : Initialize a doubly linked list
 *
 * @param : pointer to list
 * @param : offset of field in object
 * */
void init_dlist(dlist_t *dlist, unsigned int offset);

/* @function : Add node to the list.
 *
 * @param : pointer to list
 * @param : node to be inserted
 * */
void dlist_add(dlist_t *dlist, dll_node_t *dll_node);

/* @function : Remove node to the list.
 *
 * @param : pointer to list
 * @param : node to be removed
 * */
void dlist_remove(dlist_t *dlist, dll_node_t *dll_node);



#endif
