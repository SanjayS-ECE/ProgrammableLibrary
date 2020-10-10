/*!
 * @file    dlist.h
 * @brief   Implement doubly linked list
 *
 * @Created on: 29-Sep-2020
 * @Author: sanjay suthar
 */

#include "dlist.h"

/* Helper Functions */

/*Private function to add a new_node right after curr_node*/
static void _dlist_add_next(dll_node_t *curr_node, dll_node_t *new_node) {

    if (!curr_node->right) {
        curr_node->right = new_node;
        new_node->left = curr_node;
        return;
    }

    dll_node_t * temp = curr_node->right;
    curr_node->right = new_node;
    new_node->left = curr_node;
    new_node->right = temp;
    temp->left = new_node;
}

static void _remove_dll_node(dll_node_t *node) {

    if (!node->left) {
        if (node->right) {
            node->right->left = NULL;
            node->right = NULL;
            return;
        }
        return;
    }

    if (!node->right) {
        node->left->right = NULL;
        node->left = NULL;
        return;
    }

    node->left->right = node->right;
    node->right->left = node->left;
    node->left = NULL;
    node->right = NULL;
}
/* @function : Initialize a doubly linked list
 *
 * @param : pointer to list
 * @param : offset of field in object
 * */
void init_dlist(dlist_t *dlist, unsigned int offset) {
    dlist->head = NULL;
    dlist->offset = offset;
}
/* @function : Add node to the list at first postion.
 *
 * @param : pointer to list
 * @param : node to be inserted
 * */
void dlist_add(dlist_t *dlist, dll_node_t *dll_node) {
    dll_node->left = NULL;
    dll_node->right = NULL;

    if (!dlist->head) {
        dlist->head = dll_node;
        return;
    }
    dll_node_t *head = dlist->head;
    _dlist_add_next(dll_node, head);
    dlist->head = dll_node;
}

/* @function : Remove node to the list.
 *
 * @param : pointer to list
 * @param : node to be removed
 * */
void dlist_remove(dlist_t *dlist, dll_node_t *dll_node) {

    dll_node_t *head = dlist->head;

    /*If the node being removed is the head node itself,
     * then update the head*/
    if (head == dll_node) {
        dlist->head = head->right;
    }
    _remove_dll_node(dll_node);
}
