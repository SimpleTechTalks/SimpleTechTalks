#include <iostream>

using namespace std;
#include "stdio.h"
#include "BinaryTreeDefine.h"

void print_tree (BinaryTree* root)
{
    cout << "Binary tree contents: ";
    print_binary_tree (root);
    cout << endl;
}

void check_binary_tree ()
{
    cout << "Inside check_binary_tree " << endl;
    BinaryTree* root = new BinaryTree(20);

    insert_after_certain_element (root, 10, 20);
    insert_after_certain_element (root, 30, 20);
    insert_after_certain_element (root, 40, 20);
    insert_after_certain_element (root, 1, 40);
    insert_after_certain_element (root, 50, 30);
    insert_after_certain_element (root, 60, 20);
    print_tree (root);
    root = delete_node (root, 20);
    print_tree (root);
    root = delete_node (root, 40);
    print_tree (root);
    root = delete_node (root, 100);
    
    if (search_node_in_binary_tree (root, 1))
    {
        cout << "Searched data: 1 found in binary tree" << endl;
    }
    else
    {
        cout << "Searched data: 1 not found" << endl;
    }
    delete_all_nodes (root);
}

void check_traversal ()
{
    BinaryTree* node1 = new BinaryTree (1);
    BinaryTree* node2 = new BinaryTree (2);
    BinaryTree* node3 = new BinaryTree (3);
    BinaryTree* node4 = new BinaryTree (4);
    BinaryTree* node5 = new BinaryTree (5);
    BinaryTree* node6 = new BinaryTree (6);
    BinaryTree* node7 = new BinaryTree (7);
    BinaryTree* node8 = new BinaryTree (8);
    BinaryTree* node9 = new BinaryTree (9);
    BinaryTree* node10 = new BinaryTree (10);

    /* Set node5 as root node */
    BinaryTree* root = node5;
    node5 -> m_left = node3;
    node3 -> m_left = node2;
    node3 -> m_right = node4;
    node2 -> m_left = node1;

    node5 -> m_right = node7;
    node7 -> m_left = node6;
    node7 -> m_right = node9;
    node9 -> m_right  = node10;
    node9 -> m_left = node8;
    print_tree (root);
    cout << " Inorder Traversal: ";
    inorder_traversal (root);
    cout << endl;
    cout << " Preorder Traversal: ";
    preorder_traversal (root);
    cout << endl;
    cout << " Postorder Traversal: ";
    postorder_traversal (root);
    cout << endl;
    cout << " LevelOrder Traversal: ";
    levelorder_traversal (root);
    cout << endl;
    delete_all_nodes (root);
}

void check_maximum ()
{
    BinaryTree* root = new BinaryTree(20);

    insert_after_certain_element (root, 10, 20);
    insert_after_certain_element (root, 30, 20);
    insert_after_certain_element (root, 40, 20);
    insert_after_certain_element (root, 1, 40);
    insert_after_certain_element (root, 50, 30);
    insert_after_certain_element (root, 60, 20);
    print_tree (root);
    BinaryTree* max = get_maximum (root);
    if (max)
    {
        cout << "Maximum node value: " << max -> m_data << endl;
    }
    else
    {
        cout << "Binary tree is empty" << endl;
    }

    BinaryTree* min = get_minimum (root);
    if (min)
    {
        cout << "Minimum node value: " << min -> m_data << endl;
    }
    else
    {
        cout << "Binary tree is empty" << endl;
    }
    
    delete_all_nodes (root);
}

void check_height ()
{
    BinaryTree* node1 = new BinaryTree (1);
    BinaryTree* node2 = new BinaryTree (2);
    BinaryTree* node3 = new BinaryTree (3);
    BinaryTree* node4 = new BinaryTree (4);
    BinaryTree* node5 = new BinaryTree (5);
    BinaryTree* node6 = new BinaryTree (6);
    BinaryTree* node7 = new BinaryTree (7);
    BinaryTree* node8 = new BinaryTree (8);
    BinaryTree* node9 = new BinaryTree (9);
    BinaryTree* node10 = new BinaryTree (10);

    /* Set node5 as root node */
    BinaryTree* root = node5;
    node5 -> m_left = node3;
    node3 -> m_left = node2;
    node3 -> m_right = node4;
    node2 -> m_left = node1;

    node5 -> m_right = node7;
    node7 -> m_left = node6;
    node7 -> m_right = node9;
    node9 -> m_right  = node10;
    node9 -> m_left = node8;
    print_tree (root);
    cout << "Height of Binary Tree: " << get_height (root) << endl;
    delete_all_nodes (root);
}

void check_leafs ()
{
    BinaryTree* node1 = new BinaryTree (1);
    BinaryTree* node2 = new BinaryTree (2);
    BinaryTree* node3 = new BinaryTree (3);
    BinaryTree* node4 = new BinaryTree (4);
    BinaryTree* node5 = new BinaryTree (5);
    BinaryTree* node6 = new BinaryTree (6);
    BinaryTree* node7 = new BinaryTree (7);
    BinaryTree* node8 = new BinaryTree (8);
    BinaryTree* node9 = new BinaryTree (9);
    BinaryTree* node10 = new BinaryTree (10);

    /* Set node5 as root node */
    BinaryTree* root = node5;
    node5 -> m_left = node3;
    node3 -> m_left = node2;
    node3 -> m_right = node4;
    node2 -> m_left = node1;

    node5 -> m_right = node7;
    node7 -> m_left = node6;
    node7 -> m_right = node9;
    node9 -> m_right  = node10;
    node9 -> m_left = node8;
    print_tree (root);
    cout << "Number of Leafs in Binary Tree: " << get_number_of_leaves (root) << endl;
    cout << "Number of Leafs in Binary Tree: " << get_number_of_leaves_using_iteration (root) << endl;
    delete_all_nodes (root);
}

void check_mirror ()
{
    BinaryTree* node1 = new BinaryTree (1);
    BinaryTree* node2 = new BinaryTree (2);
    BinaryTree* node3 = new BinaryTree (3);
    BinaryTree* node4 = new BinaryTree (4);
    BinaryTree* node5 = new BinaryTree (5);
    BinaryTree* node6 = new BinaryTree (6);
    BinaryTree* node7 = new BinaryTree (7);
    BinaryTree* node8 = new BinaryTree (8);
    BinaryTree* node9 = new BinaryTree (9);
    BinaryTree* node10 = new BinaryTree (10);

    /* Set node5 as root node */
    BinaryTree* root = node5;
    node5 -> m_left = node3;
    node3 -> m_left = node2;
    node3 -> m_right = node4;
    node2 -> m_left = node1;

    node5 -> m_right = node7;
    node7 -> m_left = node6;
    node7 -> m_right = node9;
    node9 -> m_right  = node10;
    node9 -> m_left = node8;
    print_tree (root);
    get_mirror (root);
    print_tree (root);
    get_mirror (root);
    print_tree (root);
    get_mirror_using_iteration (root);
    print_tree (root);
    get_mirror_using_iteration (root);
    print_tree (root);
    delete_all_nodes (root);
}

BinaryTree* construct_binary_tree (int inorder[], int preorder[], int length, int inorder_index_start, int inorder_index_end)
{
    static int preorder_index = 0;
    if (inorder_index_start > inorder_index_end)
        return NULL;
    BinaryTree* newNode = new BinaryTree(preorder[preorder_index]);

    preorder_index++;
    /* All node Processed */
    if (inorder_index_end == inorder_index_start)
        return newNode;

    /* find above node place in inorder list */
    int index = 0;
    for (int i = 0; i < length; i++)
    {
        if (inorder[i] == newNode -> m_data)
        {
            index = i;
            break;
        }
    }

    /* Inorder list items present in left side of index is in left subtree while rest of them are in right subtree */
    newNode -> m_left = construct_binary_tree (inorder, preorder, length, inorder_index_start, index - 1);
    newNode -> m_right = construct_binary_tree (inorder, preorder, length, index + 1, inorder_index_end);
    return newNode;
}

void check_construct ()
{
    int preorder[] = {5, 3, 2, 1, 4, 7, 6, 9, 8, 10};
    int inorder[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BinaryTree* root = construct_binary_tree (inorder, preorder, 10, 0, 9);
    print_tree (root);
}

BinaryTree* construct_binary_tree_2 (int inorder[], int postorder[], int length, int inorder_index_start, int inorder_index_end)
{
    static int postorder_index = length - 1;
    if (inorder_index_start > inorder_index_end)
        return NULL;
    BinaryTree* newNode = new BinaryTree(postorder[postorder_index]);

    postorder_index--;
    /* All node Processed */
    if (inorder_index_end == inorder_index_start)
        return newNode;

    /* find above node place in inorder list */
    int index = 0;
    for (int i = 0; i < length; i++)
    {
        if (inorder[i] == newNode -> m_data)
        {
            index = i;
            break;
        }
    }

    /* Inorder list items present in left side of index is in left subtree while rest of them are in right subtree */
    newNode -> m_right = construct_binary_tree_2 (inorder, postorder, length, index + 1, inorder_index_end);
    newNode -> m_left = construct_binary_tree_2 (inorder, postorder, length, inorder_index_start, index - 1);
    return newNode;
}

void check_construct_2 ()
{
    int postorder[] = {1, 2, 4, 3, 6, 8, 10, 9, 7, 5};
    int inorder[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BinaryTree* root = construct_binary_tree_2 (inorder, postorder, 10, 0, 9);
    print_tree (root);
}

void check_inorder_successor_helper (BinaryTree* root, int searched_data)
{
    BinaryTree* searched_node = search_node_in_binary_tree (root, searched_data);
    if (searched_node)
    {
        BinaryTree* inorder_successor = find_inorder_successor (root, searched_node);
        if (inorder_successor)
        {
            cout << "Inorder successor of " << searched_data << " is " << inorder_successor -> m_data << endl;
        }
        else
        {
            cout << "Inorder successor of " << searched_data << " is None" << endl;
        }
    }
}

void check_inorder_successor ()
{
    BinaryTree* node1 = new BinaryTree (1);
    BinaryTree* node2 = new BinaryTree (2);
    BinaryTree* node3 = new BinaryTree (3);
    BinaryTree* node4 = new BinaryTree (4);
    BinaryTree* node5 = new BinaryTree (5);
    BinaryTree* node6 = new BinaryTree (6);
    BinaryTree* node7 = new BinaryTree (7);
    BinaryTree* node8 = new BinaryTree (8);
    BinaryTree* node9 = new BinaryTree (9);
    BinaryTree* node10 = new BinaryTree (10);

    /* Set node5 as root node */
    BinaryTree* root = node5;
    node5 -> m_left = node3;
    node3 -> m_left = node2;
    node3 -> m_right = node4;
    node2 -> m_left = node1;

    node5 -> m_right = node7;
    node7 -> m_left = node6;
    node7 -> m_right = node9;
    node9 -> m_right  = node10;
    node9 -> m_left = node8;
    print_tree (root);
    cout << " Inorder Traversal: ";
    inorder_traversal (root);
    cout << endl;
    check_inorder_successor_helper (root, 7);
    check_inorder_successor_helper (root, 3);
    check_inorder_successor_helper (root, 5);
    check_inorder_successor_helper (root, 10);
}


void check_preorder_successor_helper (BinaryTree* root, int searched_data)
{
    BinaryTree* searched_node = search_node_in_binary_tree (root, searched_data);
    if (searched_node)
    {
        BinaryTree* preorder_successor = find_preorder_successor (root, searched_node);
        if (preorder_successor)
        {
            cout << "Preorder successor of " << searched_data << " is " << preorder_successor -> m_data << endl;
        }
        else
        {
            cout << "Preorder successor of " << searched_data << " is None" << endl;
        }
    }
}

void check_preorder_successor ()
{
    BinaryTree* node1 = new BinaryTree (1);
    BinaryTree* node2 = new BinaryTree (2);
    BinaryTree* node3 = new BinaryTree (3);
    BinaryTree* node4 = new BinaryTree (4);
    BinaryTree* node5 = new BinaryTree (5);
    BinaryTree* node6 = new BinaryTree (6);
    BinaryTree* node7 = new BinaryTree (7);
    BinaryTree* node8 = new BinaryTree (8);
    BinaryTree* node9 = new BinaryTree (9);
    BinaryTree* node10 = new BinaryTree (10);

    /* Set node5 as root node */
    BinaryTree* root = node5;
    node5 -> m_left = node3;
    node3 -> m_left = node2;
    node3 -> m_right = node4;
    node2 -> m_left = node1;

    node5 -> m_right = node7;
    node7 -> m_left = node6;
    node7 -> m_right = node9;
    node9 -> m_right  = node10;
    node9 -> m_left = node8;
    print_tree (root);
    cout << " Preorder Traversal: ";
    preorder_traversal (root);
    cout << endl;
    check_preorder_successor_helper (root, 1);
    check_preorder_successor_helper (root, 2);
    check_preorder_successor_helper (root, 3);
    check_preorder_successor_helper (root, 4);
    check_preorder_successor_helper (root, 5);
    check_preorder_successor_helper (root, 6);
    check_preorder_successor_helper (root, 7);
    check_preorder_successor_helper (root, 8);
    check_preorder_successor_helper (root, 9);
    check_preorder_successor_helper (root, 10);
}

void check_postorder_successor_helper (BinaryTree* root, int searched_data)
{
    BinaryTree* searched_node = search_node_in_binary_tree (root, searched_data);
    if (searched_node)
    {
        BinaryTree* postorder_successor = find_postorder_successor (root, searched_node);
        if (postorder_successor)
        {
            cout << "Postorder successor of " << searched_data << " is " << postorder_successor -> m_data << endl;
        }
        else
        {
            cout << "Postorder successor of " << searched_data << " is None" << endl;
        }
    }
}

void check_postorder_successor ()
{
    BinaryTree* node1 = new BinaryTree (1);
    BinaryTree* node2 = new BinaryTree (2);
    BinaryTree* node3 = new BinaryTree (3);
    BinaryTree* node4 = new BinaryTree (4);
    BinaryTree* node5 = new BinaryTree (5);
    BinaryTree* node6 = new BinaryTree (6);
    BinaryTree* node7 = new BinaryTree (7);
    BinaryTree* node8 = new BinaryTree (8);
    BinaryTree* node9 = new BinaryTree (9);
    BinaryTree* node10 = new BinaryTree (10);

    /* Set node5 as root node */
    /*
                5
            3       7
        2      4  6     9
    1                 8      10
    */
    BinaryTree* root = node5;
    node5 -> m_left = node3;
    node3 -> m_left = node2;
    node3 -> m_right = node4;
    node2 -> m_left = node1;

    node5 -> m_right = node7;
    node7 -> m_left = node6;
    node7 -> m_right = node9;
    node9 -> m_right  = node10;
    node9 -> m_left = node8;
    print_tree (root);
    cout << " Postorder Traversal: ";
    postorder_traversal (root);
    cout << endl;
    check_postorder_successor_helper (root, 1);
    check_postorder_successor_helper (root, 2);
    check_postorder_successor_helper (root, 3);
    check_postorder_successor_helper (root, 4);
    check_postorder_successor_helper (root, 5);
    check_postorder_successor_helper (root, 6);
    check_postorder_successor_helper (root, 7);
    check_postorder_successor_helper (root, 8);
    check_postorder_successor_helper (root, 9);
    check_postorder_successor_helper (root, 10);
    cout << "Binary Tree is symmetric ? - " << is_binary_tree_symmetric (root, root) << endl;
    BinaryTree* lca = least_common_ancestor (root, 8, 9);
    cout << "LCA for node 8,9 is " << (lca ? lca->m_data: 0) << endl;
    lca = least_common_ancestor (root, 1, 10);
    cout << "LCA for node 1,10 is " << (lca ? lca->m_data: 0) << endl;
    lca = least_common_ancestor (root, 1, 3);
    cout << "LCA for node 1,3 is " << (lca ? lca->m_data: 0) << endl;
    lca = least_common_ancestor (root, 8, 19);
    cout << "LCA for node 8,19 is " << (lca ? lca->m_data: 0) << endl;
    boundary_traversal (root);
    cout << "==== Postorder successor end ====" << endl;
}

void check_symmetric ()
{
    BinaryTree* node1 = new BinaryTree (1);
    BinaryTree* node2 = new BinaryTree (2);
    BinaryTree* node3 = new BinaryTree (3);
    BinaryTree* node4 = new BinaryTree (4);
    BinaryTree* node5 = new BinaryTree (5);
    BinaryTree* node6 = new BinaryTree (1);
    BinaryTree* node7 = new BinaryTree (2);
    BinaryTree* node8 = new BinaryTree (3);
    BinaryTree* node9 = new BinaryTree (4);

    /* Set node5 as root node */
    /*
                5
            3       3
        2      4   4     2 
    1                       1
    */
    BinaryTree* root = node5;
    node5 -> m_left = node3;
    node3 -> m_left = node2;
    node3 -> m_right = node4;
    node2 -> m_left = node1;

    node5 -> m_right = node8;
    node8 -> m_right = node7;
    node8 -> m_left = node9;
    node7 -> m_right = node6;

    //print_tree (root);
    //cout << "Binary Tree is symmetric ? - " << is_binary_tree_symmetric (root, root) << endl;
    print_tree (root);
    cout << "Binary Tree is sum tree ? - " << is_binary_tree_sum_tree (root) << endl;
    print_tree (root);
    convert_tree_to_sum_tree (root);
    print_tree (root);
    cout << "Binary Tree is sum tree ? - " << is_binary_tree_sum_tree (root) << endl;
}

void check_sumtree ()
{
    BinaryTree* node1 = new BinaryTree (1);
    BinaryTree* node2 = new BinaryTree (1);
    BinaryTree* node3 = new BinaryTree (6);
    BinaryTree* node4 = new BinaryTree (4);
    BinaryTree* node5 = new BinaryTree (24);
    BinaryTree* node6 = new BinaryTree (1);
    BinaryTree* node7 = new BinaryTree (1);
    BinaryTree* node8 = new BinaryTree (6);
    BinaryTree* node9 = new BinaryTree (4);

    /* Set node5 as root node */
    /*
                24
            6       6
        1      4   4     1 
    1                       1
    */
    BinaryTree* root = node5;
    node5 -> m_left = node3;
    node3 -> m_left = node2;
    node3 -> m_right = node4;
    node2 -> m_left = node1;

    node5 -> m_right = node8;
    node8 -> m_right = node7;
    node8 -> m_left = node9;
    node7 -> m_right = node6;

    print_tree (root);
    cout << "Binary Tree is symmetric ? - " << is_binary_tree_symmetric (root, root) << endl;
    cout << "Binary Tree is sum tree ? - " << is_binary_tree_sum_tree (root) << endl;
}

int main ()
{
    //check_binary_tree ();
    //check_traversal ();
    //check_maximum ();
    //check_height ();
    //check_leafs ();
    //check_mirror ();
    //check_construct ();
    //check_construct_2 ();
    //check_inorder_successor ();
    //check_preorder_successor ();
    check_postorder_successor ();
    //check_symmetric ();
    //check_sumtree ();
}