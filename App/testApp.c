/*!
 * @file    testApp.c
 * @brief   Test Application for Library testing
 *
 * @Created on: 27-Sep-2020
 * @Author: sanjay suthar
 */

#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

int main() {

    slist_t *list1 = create_new_slist();
    int arr[] = { 2, 5, 7, 9, 10 , 11};
    int i, ret, arr_size = (sizeof(arr)/sizeof(arr[0]));

    /* To test adding node in front of list */
    for (i = 0; i < arr_size; i++) {
        ret = insert_node_in_front(list1,(&arr[i]));
        if (ret < 0)
            return -1;
    }

    /*Print the list */
    if (print_list(list1) < 0)
        return -1;

    {
        int a = 15;
        if (insert_node_in_end(list1,&a) < 0)
            return -1;

        /*Print the list */
        if (print_list(list1) < 0)
            return -1;
    }

    {
        if (delete_node_in_front(list1) < 0)
            return -1;

        /*Print the list */
        if (print_list(list1) < 0)
            return -1;
    }

    {
        if (delete_node_in_end(list1) < 0)
            return -1;

        /*Print the list */
        if (print_list(list1) < 0)
            return -1;
    }

    /* Free the list */
    if( free_list(list1) < 0)
        return -1;

    if( print_list(list1) < 0)
        return -1;

    return 0;
}
