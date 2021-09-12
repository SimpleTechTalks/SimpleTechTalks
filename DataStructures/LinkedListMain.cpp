#include <iostream>

using namespace std;

#include "LinkedListDefine.h"

void check_searched_items_log()
{
    LinkedList* start = NULL;
    print_linked_list (start);
    insert_at_begining (&start, 3);
    insert_after_certain_element (start, 5, 6);
    insert_after_certain_element (start, 7, 5);
    insert_after_certain_element (start, 9, 8);
    insert_after_certain_element (start, 11, 10);
    insert_after_certain_element (start, 16, 11);
    insert_after_certain_element (start, 2, 9);
    insert_after_certain_element (start, 3, 2);
    cout << "Length of linked list: " << length_of_linked_list_using_iteration (start) << endl;
    int searched_data = 5;
    cout << "Searching element in linked list: " << searched_data << endl;
    search_element (start, searched_data);
    print_linked_list (start);
    cout << "End check_searched_items_log" << endl;
}

void check_delete_items_log()
{
    LinkedList* start = NULL;
    print_linked_list (start);
    insert_at_begining (&start, 3);
    insert_after_certain_element (start, 5, 6);
    insert_after_certain_element (start, 7, 5);
    insert_after_certain_element (start, 9, 8);
    insert_after_certain_element (start, 11, 10);
    insert_after_certain_element (start, 16, 11);
    insert_after_certain_element (start, 2, 9);
    insert_after_certain_element (start, 3, 2);
    cout << "Length of linked list: " << length_of_linked_list_using_iteration (start) << endl;
    int searched_data = 5;
    cout << "Searching element in linked list: " << searched_data << endl;
    search_element (start, searched_data);
    print_linked_list (start);
    cout << "Deleting Head Node " << endl;
    delete_start_node (&start);
    print_linked_list (start);
    cout << "Deleting Node 11" << endl;
    delete_searched_node (&start, 11);
    print_linked_list (start);
    cout << "Deleting all Nodes" << endl;
    delete_all_node (&start);
    print_linked_list (start);
    cout << "End check_delete_items_log" << endl;
}

void check_reversal_log()
{
    LinkedList* start = NULL;
    print_linked_list (start);
    insert_at_begining (&start, 3);
    insert_after_certain_element (start, 5, 6);
    insert_after_certain_element (start, 7, 5);
    insert_after_certain_element (start, 9, 8);
    insert_after_certain_element (start, 11, 10);
    insert_after_certain_element (start, 16, 11);
    insert_after_certain_element (start, 2, 9);
    insert_after_certain_element (start, 3, 2);
    print_linked_list (start);
    start = reverse_linked_list_using_iteration (start);
    print_linked_list (start);
    start = reverse_linked_list_using_recursion (start, NULL);
    print_linked_list (start);
    cout << "Deleting Head Node " << endl;
    delete_start_node (&start);
    print_linked_list (start);
    cout << "Deleting Node 11" << endl;
    delete_searched_node (&start, 11);
    print_linked_list (start);
    cout << "Deleting all Nodes" << endl;
    delete_all_node (&start);
    print_linked_list (start);
    cout << "End check_delete_items_log" << endl;
}

void check_length_log()
{
    LinkedList* start = NULL;
    print_linked_list (start);
    insert_at_begining (&start, 3);
    insert_after_certain_element (start, 5, 6);
    insert_after_certain_element (start, 7, 5);
    insert_after_certain_element (start, 9, 8);
    insert_after_certain_element (start, 11, 10);
    insert_after_certain_element (start, 16, 11);
    insert_after_certain_element (start, 2, 9);
    insert_after_certain_element (start, 3, 2);
    cout << "Length of linked list: " << length_of_linked_list_using_iteration (start) << endl;
    cout << "Length of linked list: " << length_of_linked_list_using_recursion (start) << endl;
    int searched_data = 5;
    cout << "Searching element in linked list: " << searched_data << endl;
    search_element (start, searched_data);
    print_linked_list (start);
    cout << "Deleting Head Node " << endl;
    delete_start_node (&start);
    print_linked_list (start);
    cout << "Deleting Node 11" << endl;
    delete_searched_node (&start, 11);
    print_linked_list (start);
    cout << "Deleting all Nodes" << endl;
    delete_all_node (&start);
    print_linked_list (start);
    cout << "Length of linked list: " << length_of_linked_list_using_iteration (start) << endl;
    cout << "Length of linked list: " << length_of_linked_list_using_recursion (start) << endl;
    cout << "End check_length_log" << endl;
}

void check_nth_node_log()
{
    LinkedList* start = NULL;
    print_linked_list (start);
    insert_at_begining (&start, 3);
    insert_after_certain_element (start, 5, 6);
    insert_after_certain_element (start, 7, 5);
    insert_after_certain_element (start, 9, 8);
    insert_after_certain_element (start, 11, 10);
    insert_after_certain_element (start, 16, 11);
    insert_after_certain_element (start, 2, 9);
    insert_after_certain_element (start, 3, 2);
    print_linked_list (start);
    find_nth_node_from_end (start, 1);
    find_nth_node_from_end (start, 3);
    find_nth_node_from_end (start, 7);
    find_nth_node_from_end (start, 11);
    cout << "Deleting Head Node " << endl;
    delete_start_node (&start);
    print_linked_list (start);
    cout << "Deleting Node 11" << endl;
    delete_searched_node (&start, 11);
    print_linked_list (start);
    cout << "Deleting all Nodes" << endl;
    delete_all_node (&start);
    print_linked_list (start);
    cout << "End check_nth_node_log" << endl;
}

void check_loop_log()
{
    LinkedList* start = NULL;
    print_linked_list (start);
    insert_at_begining (&start, 3);
    insert_after_certain_element (start, 5, 6);
    insert_after_certain_element (start, 7, 5);
    insert_after_certain_element (start, 9, 8);
    insert_after_certain_element (start, 11, 10);
    insert_after_certain_element (start, 16, 11);
    insert_after_certain_element (start, 2, 9);
    insert_after_certain_element (start, 15, 2);
    print_linked_list (start);

    /* We are creating a loop here, don't print linked list now */
    insert_at_end_to_create_loop (start, 20, 9);
    find_loop_and_print_node (start);
    /* Loop is broken now */
    print_linked_list (start);

    cout << "Deleting Head Node " << endl;
    delete_start_node (&start);
    print_linked_list (start);
    cout << "Deleting Node 11" << endl;
    delete_searched_node (&start, 11);
    print_linked_list (start);
    cout << "Deleting all Nodes" << endl;
    delete_all_node (&start);
    print_linked_list (start);
    cout << "End check_loop_log" << endl;
}

void check_swap_pairwise_log()
{
    LinkedList* start = NULL;
    print_linked_list (start);
    insert_at_begining (&start, 3);
    insert_after_certain_element (start, 5, 6);
    insert_after_certain_element (start, 7, 5);
    insert_after_certain_element (start, 9, 8);
    insert_after_certain_element (start, 11, 10);
    insert_after_certain_element (start, 16, 11);
    insert_after_certain_element (start, 2, 9);
    insert_after_certain_element (start, 15, 2);
    insert_after_certain_element (start, 21, 2);
    insert_after_certain_element (start, 23, 3);
    insert_after_certain_element (start, 35, 5);
    insert_after_certain_element (start, 1, 11);
    print_linked_list (start);

    cout << "Swapping Pairwise Linked List Using Recursion" << endl;
    start = pair_wise_swap_linked_list_recursion (start);
    print_linked_list (start);
    cout << "Swapping Pairwise Linked List Using Iteration" << endl;
    start = pair_wise_swap_linked_list_iteration (start);
    print_linked_list (start);
    start = swap_k_node_linked_list_iteration (start, 3);
    print_linked_list (start);
    start = swap_k_nodes_using_recursion (start, 3);
    print_linked_list (start);

    cout << "Deleting Head Node " << endl;
    delete_start_node (&start);
    print_linked_list (start);
    cout << "Deleting Node 11" << endl;
    delete_searched_node (&start, 11);
    print_linked_list (start);
    cout << "Deleting all Nodes" << endl;
    delete_all_node (&start);
    print_linked_list (start);
    cout << "End check_swap_pairwise_log" << endl;
}

void check_swap_k_nodes_log()
{
    LinkedList* start = NULL;
    print_linked_list (start);
    insert_at_begining (&start, 3);
    insert_after_certain_element (start, 5, 6);
    insert_after_certain_element (start, 7, 5);
    insert_after_certain_element (start, 9, 8);
    insert_after_certain_element (start, 11, 10);
    insert_after_certain_element (start, 16, 11);
    insert_after_certain_element (start, 2, 9);
    insert_after_certain_element (start, 15, 2);
    insert_after_certain_element (start, 21, 2);
    insert_after_certain_element (start, 23, 3);
    insert_after_certain_element (start, 35, 5);
    insert_after_certain_element (start, 1, 11);
    print_linked_list (start);

    cout << "Swapping Pairwise Linked List Using Iteration" << endl;
    start = swap_k_node_linked_list_iteration (start, 3);
    print_linked_list (start);
    cout << "Swapping Pairwise Linked List Using Recursion" << endl;
    start = swap_k_nodes_using_recursion (start, 3);
    print_linked_list (start);

    cout << "Deleting Head Node " << endl;
    delete_start_node (&start);
    print_linked_list (start);
    cout << "Deleting Node 11" << endl;
    delete_searched_node (&start, 11);
    print_linked_list (start);
    cout << "Deleting all Nodes" << endl;
    delete_all_node (&start);
    print_linked_list (start);
    cout << "End check_swap_k_nodes_log" << endl;
}

/* This function will point last node of list1 Linked List to
 * list2 Linked List kth place node
 */
void merge_two_lists(LinkedList* list1, LinkedList* list2, int k)
{
    LinkedList* end_list1 = list1;

    /* Finding last node of list1 */
    while (end_list1 -> next)
    {
        end_list1 = end_list1 -> next;
    }

    /* Finding kth node of list2 */
    int count = 0;
    LinkedList* k_node_list2 = list2;

    while (k_node_list2 -> next && count < k)
    {
        count++;
        k_node_list2 = k_node_list2 -> next;
    }

    end_list1 -> next = k_node_list2;
}

void check_merging_point_of_two_linked_list ()
{
    LinkedList* start = NULL;
    print_linked_list (start);
    insert_at_begining (&start, 3);
    insert_after_certain_element (start, 5, 6);
    insert_after_certain_element (start, 7, 5);
    insert_after_certain_element (start, 9, 8);
    insert_after_certain_element (start, 11, 10);
    insert_after_certain_element (start, 16, 11);
    insert_after_certain_element (start, 2, 9);
    insert_after_certain_element (start, 15, 2);
    insert_after_certain_element (start, 21, 2);
    insert_after_certain_element (start, 23, 3);
    insert_after_certain_element (start, 35, 5);
    insert_after_certain_element (start, 1, 11);
    print_linked_list (start);

    LinkedList* start_2 = NULL;
    print_linked_list (start_2);
    insert_at_begining (&start_2, 30);
    insert_after_certain_element (start_2, 50, 60);
    insert_after_certain_element (start_2, 70, 50);
    insert_after_certain_element (start_2, 90, 80);
    insert_after_certain_element (start_2, 110, 100);
    insert_after_certain_element (start_2, 160, 110);
    insert_after_certain_element (start_2, 20, 90);
    insert_after_certain_element (start_2, 150, 20);
    insert_after_certain_element (start_2, 210, 20);
    insert_after_certain_element (start_2, 230, 30);
    insert_after_certain_element (start_2, 350, 50);
    insert_after_certain_element (start_2, 10, 110);
    print_linked_list (start_2);

    merge_two_lists (start, start_2, 5);
    cout << "After Merging Lists are" << endl;
    print_linked_list (start);
    print_linked_list (start_2);

    LinkedList* intersection_point = find_intersection_node (start, start_2);
    delete_all_node (&start);
    delete_all_node (&start_2);
}

int main ()
{
    check_merging_point_of_two_linked_list();
    //check_swap_k_nodes_log();
    //check_reversal_log();
    //check_searched_items_log ();
    //check_delete_items_log ();
    /*
    LinkedList* start = NULL;
    print_linked_list (start);
    insert_at_begining (&start, 3);
    print_linked_list (start);
    find_nth_node_from_end (start, 5);
    cout << "Length of linked list: " << length_of_linked_list_using_recursion (start) << endl;

    insert_after_certain_element (start, 5, 6);
    print_linked_list (start);
    find_nth_node_from_end (start, 2);
    cout << "Length of linked list: " << length_of_linked_list_using_iteration (start) << endl;
    insert_after_certain_element (start, 7, 5);
    print_linked_list (start);
    cout << "Length of linked list: " << length_of_linked_list_using_recursion (start) << endl;
    insert_after_certain_element (start, 9, 8);
    insert_after_certain_element (start, 11, 10);
    insert_after_certain_element (start, 16, 11);
    insert_after_certain_element (start, 2, 9);
    insert_after_certain_element (start, 3, 2);
    print_linked_list (start);
    start = pair_wise_swap_linked_list (start);
    print_linked_list (start);
    start = pair_wise_swap_linked_list (start);
    print_linked_list (start);
    find_nth_node_from_end (start, 3);
    cout << "Length of linked list: " << length_of_linked_list_using_iteration (start) << endl;

    cout << "Searching element 5 in linked list status: " << search_element (start, 5) << endl;

    print_linked_list (start);
    cout << "Length of linked list: " << length_of_linked_list_using_recursion (start) << endl;
    delete_start_node (&start);
    print_linked_list (start);
    cout << "Length of linked list: " << length_of_linked_list_using_iteration (start) << endl;
    delete_start_node (&start);
    print_linked_list (start);
    delete_searched_node (&start, 11);
    delete_searched_node (&start, 21);
    print_linked_list (start);
    cout << "Reversing linked list using iteration" << endl;
    start = reverse_linked_list (start, false);
    print_linked_list (start);
    cout << "Length of linked list: " << length_of_linked_list_using_recursion (start) << endl;
    cout << "Reversing linked list using recursion" << endl;
    start = reverse_linked_list (start, true);
    print_linked_list (start);
    cout << "Length of linked list: " << length_of_linked_list_using_iteration (start) << endl;
    find_loop_in_linked_list (start);
    start = pair_wise_swap_linked_list (start);
    print_linked_list (start);*/
}
