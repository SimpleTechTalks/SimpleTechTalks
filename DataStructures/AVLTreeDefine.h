/* AVL Tree implementation
 * Insertion
 * Deletion
 * isAVL
 * 
 * 
 * 
 */

#ifndef _PRACTICE_AVL_TREE_DEFINE_H_
#define _PRACTICE_AVL_TREE_DEFINE_H_

#include "BinarySearchTreeDefine.h"

template <typename T>
class AVL: public BinarySearchTree<T>
{
    public:
        int m_height;
        AVL (T data);
        ~AVL ();
};

template <typename T>
AVL<T>::AVL (T data):BinarySearchTree<T> (data), m_height (0)
{}

template <typename T>
AVL<T>::~AVL ()
{}

template <typename T>
int height_of_node (BinarySearchTree<T>* root)
{
    if (!root)
        return 0;

    int left = height_of_node (root -> m_left);
    int right = height_of_node (root -> m_right);

    if (left > right)
        return 1 + left;
    else
        return 1 + right;
}

template <typename T>
bool isAVL (BinarySearchTree<T>* root)
{
    if (!root)
    {
        return true;
    }

    int left = height_of_node (root -> m_left);
    int right = height_of_node (root -> m_right);

    int diff = (left > right) ? left - right: right - left;

    if (diff <= 1 && isAVL (root -> m_left) && isAVL (root -> m_right))
        return true;
    return false;
}

/* Balaning of AVL Tree */
/* Left Rotate 
 *          x                      z
 *         / \                    / \
 *        y   z                  x   b
 *           / \     ---->      / \   \
 *          a   b              y   a   c
 *               \
 *                c
*/
template <typename T>
AVL<T>* left_rotate (AVL<T>* node_to_be_balanced)
{
    AVL<T>* temp = dynamic_cast<AVL<T>*> (node_to_be_balanced -> m_right);
    AVL<T>* left_child = dynamic_cast<AVL<T>*> (node_to_be_balanced -> m_right -> m_left);
    temp -> m_left = node_to_be_balanced;
    node_to_be_balanced -> m_right = left_child;
    
    node_to_be_balanced -> m_height = height_of_node (node_to_be_balanced);
    temp -> m_height = height_of_node (temp);
    return temp;
}

/* Right Rotate 
 *          x                      y
 *         / \                    / \
 *        y   z                  b   x
 *       / \         ---->      /   / \
 *      b   a                  c   a    z
 *     /        
 *    c         
*/
template <typename T>
AVL<T>* right_rotate (AVL<T>* node_to_be_balanced)
{
    AVL<T>* temp = dynamic_cast<AVL<T>*> (node_to_be_balanced -> m_left);
    AVL<T>* right_child = dynamic_cast<AVL<T>*> (temp -> m_right);
    temp -> m_right = node_to_be_balanced;
    node_to_be_balanced -> m_left = right_child;
    
    node_to_be_balanced -> m_height = height_of_node (node_to_be_balanced);
    temp -> m_height = height_of_node (temp);
    return temp;
}

/* Left Right Rotate
 *            x                    x                      z
 *           / \                  / \                    / \
 *          y   a                z   a                  y   x
 *         / \        ----->    / \         ----->     /   / \
 *        b   z                y   c                  b   c   a
 *             \              /
 *              c            b 
 *               
 */
template <typename T>
AVL<T>* left_right_rotate (AVL<T>* node_to_be_balanced)
{
    node_to_be_balanced -> m_left = left_rotate (dynamic_cast<AVL<T>*> (node_to_be_balanced -> m_left));
    return right_rotate (node_to_be_balanced);
}

/* Right Left Rotate
 *            x                    x                      z
 *           / \                  / \                    / \
 *          a   y                a   z                  x   y
 *             / \        ----->      \         -----> /   / \
 *            z   b                    y              a    c   b
 *             \                      / \
 *              c                    c   b
 *               
 */
template <typename T>
AVL<T>* right_left_rotate (AVL<T>* node_to_be_balanced)
{
    node_to_be_balanced -> m_right = right_rotate (dynamic_cast<AVL<T>*> (node_to_be_balanced -> m_right));
    return left_rotate (node_to_be_balanced);
}

template <typename T>
AVL<T>* insert_in_avl (AVL<T>* node, AVL<T>* new_node)
{
    if (!node)
        return new_node;

    if (node -> m_data > new_node -> m_data)
    {
        if (node -> m_left)
            node -> m_left = insert_in_avl (dynamic_cast<AVL<T>*> (node -> m_left), new_node);
        else
        {
            node -> m_left = new_node;
        }
    }
    else
    {
        if (node -> m_right)
            node -> m_right = insert_in_avl (dynamic_cast<AVL<T>*> (node -> m_right), new_node);
        else
            node -> m_right = new_node;
    }
    
    node -> m_height = height_of_node (node);

    int height_balance = height_of_node (node -> m_left) - height_of_node (node -> m_right);

    if (height_balance <= 1 && height_balance >= -1)
        return node;

    /* Left subtree is higher and new node went into left subtree of the left child */
    if (height_balance > 1 && new_node -> m_data < node -> m_left -> m_data)
        return right_rotate (node);

    /* Left subtree is higher and new node went into right subtree of the left child */
    if (height_balance > 1 && new_node -> m_data > node -> m_left -> m_data)
        return left_right_rotate (node);

    /* Right subtree is higher and new node went into right subtree of the right child */
    if (height_balance < -1 && new_node -> m_data > node -> m_right -> m_data)
        return left_rotate (node);

    /* Right subtree is higher and new node went into left subtree of the right child */
    if (height_balance < -1 && new_node -> m_data < node -> m_right -> m_data)
        return right_left_rotate (node);

    return node;
}

template <typename T>
AVL<T>* delete_in_avl (AVL<T>* node, T data)
{
    if (!node)
        return node;

    if (node -> m_data < data)
        node -> m_right = delete_in_avl (dynamic_cast<AVL<T>*> (node -> m_right), data);
    else if (node -> m_data > data)
        node -> m_left = delete_in_avl (dynamic_cast<AVL<T>*> (node -> m_left), data);
    else
    {
        if (node -> m_left)
        {
            AVL<T>* temp = NULL;
            if (node -> m_right)
            {
                temp = dynamic_cast<AVL<T>*> (node -> m_right);
                temp = insert_in_avl (temp, dynamic_cast<AVL<T>*> (node -> m_left));
            }
            else
            {
                temp = dynamic_cast<AVL<T>*> (node -> m_left);
            }
            delete node;
            node = temp;
        }
        else
        {
            if (node -> m_right)
            {
                AVL<T>* temp = dynamic_cast<AVL<T>*> (node -> m_right);
                delete node;
                node = temp; 
            }
            else
            {
                delete node;
                return NULL;
            }
        }
    }
    
    node -> m_height = height_of_node (node);

    int height_balance = height_of_node (node -> m_left) - height_of_node (node -> m_right);

    if (height_balance <= 1 && height_balance >= -1)
        return node;

    if (height_balance > 1 && height_of_node (node -> m_left) >= 0)
        return right_rotate (node);
    if (height_balance > 1 && height_of_node (node -> m_left) < 0)
        return left_right_rotate (node);
    if (height_balance < -1 && height_of_node (node -> m_right) <= 0)
        return left_rotate (node);
    if (height_balance < -1 && height_of_node (node -> m_right) > 0)
        return right_left_rotate (node);

    return node;
}

#endif /* _PRACTICE_AVL_TREE_DEFINE_H_ */