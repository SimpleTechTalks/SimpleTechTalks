#include <iostream>

using namespace std;

#include "AVLTreeDefine.h"

void check_bst_is_avl ()
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

    cout << "Binary Search Tree is AVL: " << isAVL (root) << endl;
    delete_all_nodes (root);

    root = NULL;
    root = new BinarySearchTree<int> (33);
    insert_element_in_bst (20, root);
    insert_element_in_bst (10, root);
    insert_element_in_bst (77, root);
    print_tree (root);
    cout << "Binary Search Tree is AVL: " << isAVL (root) << endl;
    delete_all_nodes (root);
}

template <typename T>
void print_binary_tree_preorder (BinarySearchTree<T>* root)
{
    cout << " " << root -> m_data;
    if (root -> m_left)
        print_binary_tree_preorder (root -> m_left);
    if (root -> m_right)
        print_binary_tree_preorder (root -> m_right);
}

template <typename T>
void print_tree_preorder (BinarySearchTree<T>* root)
{
    cout << "Binary tree contents in preorder: ";
    print_binary_tree_preorder (root);
    cout << endl;
}

void create_avl_tree ()
{
    AVL<int>* root = new AVL<int> (33);
    root = insert_in_avl (root, new AVL<int> (24));
    print_tree_preorder (root);
    cout << "Binary Search Tree is AVL: " << isAVL (root) << endl;

    root = insert_in_avl (root, new AVL<int> (21));
    print_tree_preorder (root);
    cout << "Binary Search Tree is AVL: " << isAVL (root) << endl;

    root = insert_in_avl (root, new AVL<int> (12));
    print_tree_preorder (root);
    cout << "Binary Search Tree is AVL: " << isAVL (root) << endl;

    root = insert_in_avl (root, new AVL<int> (23));
    print_tree_preorder (root);
    cout << "Binary Search Tree is AVL: " << isAVL (root) << endl;

    root = insert_in_avl (root, new AVL<int> (37));
    print_tree_preorder (root);
    cout << "Binary Search Tree is AVL: " << isAVL (root) << endl;

    root = insert_in_avl (root, new AVL<int> (31));
    print_tree_preorder (root);
    cout << "Binary Search Tree is AVL: " << isAVL (root) << endl;

    root = delete_in_avl (root, 37);
    print_tree_preorder (root);
    cout << "Binary Search Tree is AVL: " << isAVL (root) << endl;
    
    root = delete_in_avl (root, 24);
    print_tree_preorder (root);
    cout << "Binary Search Tree is AVL: " << isAVL (root) << endl;

    root = delete_in_avl (root, 23);
    print_tree_preorder (root);
    cout << "Binary Search Tree is AVL: " << isAVL (root) << endl;

    root = delete_in_avl (root, 31);
    print_tree_preorder (root);
    cout << "Binary Search Tree is AVL: " << isAVL (root) << endl;

    delete_all_nodes (root);
}

int main ()
{
    //check_bst_is_avl ();
    create_avl_tree ();
}