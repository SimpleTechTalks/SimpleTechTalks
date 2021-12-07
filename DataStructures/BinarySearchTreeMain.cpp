#include <iostream>

using namespace std;

#include "BinarySearchTreeDefine.h"

void check_bst_simple ()
{
    BinarySearchTree<int>* root = new BinarySearchTree<int> (33);
    insert_element_in_bst (20, root);
    insert_element_in_bst (10, root);
    insert_element_in_bst (30, root);
    insert_element_in_bst (40, root);
    insert_element_in_bst (50, root);
    insert_element_in_bst (43, root);
    insert_element_in_bst (77, root);
    insert_element_in_bst (69, root);
    insert_element_in_bst (25, root);
    insert_element_in_bst (11, root);
    insert_element_in_bst (10, root);
    insert_element_in_bst (5, root);
    insert_element_in_bst (18, root);
    insert_element_in_bst (67, root);
    insert_element_in_bst (88, root);
    insert_element_in_bst (99, root);
    insert_element_in_bst (65, root);
    insert_element_in_bst (58, root);
    insert_element_in_bst (51, root);
    insert_element_in_bst (77, root);
    print_tree (root);
    search_element_in_bst (57, root);
    search_element_in_bst (20, root);
    search_element_in_bst (50, root);
    BinarySearchTree<int>* min = find_minimum_element_in_bst_using_iteration (root);
    BinarySearchTree<int>* max = find_maximum_element_in_bst_using_iteration (root);
    cout << " Minimum element in BST: " << min -> m_data << endl;
    cout << " Maximum element in BST: " << max -> m_data << endl;
    root = delete_element_in_bst (20, root);
    print_tree (root);
    root = delete_element_in_bst (33, root);
    print_tree (root);
    root = delete_element_in_bst (10, root);
    print_tree (root);
    root = delete_element_in_bst (77, root);
    print_tree (root);
    root = delete_element_in_bst (135, root);
    print_tree (root);
    delete_all_nodes (root);
}

void check_bst_simple_recursive ()
{
    BinarySearchTree<int>* root = new BinarySearchTree<int> (33);
    insert_element_in_bst_recursive (20, root);
    insert_element_in_bst_recursive (10, root);
    insert_element_in_bst_recursive (30, root);
    insert_element_in_bst_recursive (40, root);
    insert_element_in_bst_recursive (50, root);
    insert_element_in_bst_recursive (43, root);
    insert_element_in_bst_recursive (77, root);
    insert_element_in_bst_recursive (69, root);
    insert_element_in_bst_recursive (25, root);
    insert_element_in_bst_recursive (11, root);
    insert_element_in_bst_recursive (10, root);
    insert_element_in_bst_recursive (5, root);
    insert_element_in_bst_recursive (18, root);
    insert_element_in_bst_recursive (67, root);
    insert_element_in_bst_recursive (88, root);
    insert_element_in_bst_recursive (99, root);
    insert_element_in_bst_recursive (65, root);
    insert_element_in_bst_recursive (58, root);
    insert_element_in_bst_recursive (51, root);
    insert_element_in_bst_recursive (77, root);
    print_tree (root);
    search_element_in_bst_recursive (57, root);
    search_element_in_bst_recursive (20, root);
    search_element_in_bst_recursive (50, root);
    BinarySearchTree<int>* min = find_minimum_element_in_bst_using_recursion (root);
    BinarySearchTree<int>* max = find_maximum_element_in_bst_using_recursion (root);
    cout << " Minimum element in BST: " << min -> m_data << endl;
    cout << " Maximum element in BST: " << max -> m_data << endl;
    int count = 0;
    int k = 4;
    BinarySearchTree<int>* k_min = find_kth_minimum_element_in_bst (root, k, &count);
    cout << k << "th Minimum element in BST: " << k_min -> m_data << endl;
    count = 0;
    k = 10;
    BinarySearchTree<int>* k_max = find_kth_maximum_element_in_bst (root, k, &count);
    cout << k << "th Maximum element in BST: " << k_max -> m_data << endl;

    BinarySearchTree<int>* low = search_element_in_bst_recursive (18, root);
    BinarySearchTree<int>* high = search_element_in_bst_recursive (30, root);
    BinarySearchTree<int>* lca = find_least_common_ancestor_in_bst (root, low, high);
    cout << " LCA node of " << low -> m_data << " and " << high -> m_data << " is: " << lca -> m_data << endl;

    low = search_element_in_bst_recursive (51, root);
    high = search_element_in_bst_recursive (77, root);
    lca = find_least_common_ancestor_in_bst (root, low, high);
    cout << " LCA node of " << low -> m_data << " and " << high -> m_data << " is: " << lca -> m_data << endl;

    low = search_element_in_bst_recursive (40, root);
    high = search_element_in_bst_recursive (99, root);
    lca = find_least_common_ancestor_in_bst (root, low, high);
    cout << " LCA node of " << low -> m_data << " and " << high -> m_data << " is: " << lca -> m_data << endl;

    print_tree (root);
    cout << "is above tree Binary Search Tree ? Answer -- " << isBst (root) << "-"
            << isBstCorrect (root) << endl;

    BinarySearchTree<int>* parent = NULL;
    root = delete_element_in_bst_recursive (20, root, parent);
    print_tree (root);
    root = delete_element_in_bst_recursive (33, root, parent);
    print_tree (root);
    root = delete_element_in_bst_recursive (10, root, parent);
    print_tree (root);
    root = delete_element_in_bst_recursive (77, root, parent);
    print_tree (root);
    root = delete_element_in_bst_recursive (135, root, parent);
    print_tree (root);
    delete_all_nodes (root);
}



int main ()
{
    check_bst_simple ();
    cout << "================New function=======================" << endl;
    check_bst_simple_recursive ();
}