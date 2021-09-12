/*
 * BST Implementation - Insertion, Deletion, Search
 * BST find minimum and maximum
 * 
 * 
 * 
 * 
 */
#ifndef _PRACTICE_BINARY_SEARCH_TREE_H_
#define _PRACTICE_BINARY_SEARCH_TREE_H_

template <typename T>
class BinarySearchTree
{
    public:
        T m_data;
        BinarySearchTree* m_left;
        BinarySearchTree* m_right;

        BinarySearchTree (T data);
        virtual ~BinarySearchTree ();
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(T data): m_data(data),
                                            m_left (NULL),
                                            m_right (NULL)
{}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree ()
{}

template <typename T>
void print_binary_tree_inorder (BinarySearchTree<T>* root)
{
    if (root -> m_left)
        print_binary_tree_inorder (root -> m_left);
    cout << " " << root -> m_data;
    if (root -> m_right)
        print_binary_tree_inorder (root -> m_right);
}

template <typename T>
void print_tree (BinarySearchTree<T>* root)
{
    cout << "Binary tree contents: ";
    print_binary_tree_inorder (root);
    cout << endl;
}

template <typename T>
void insert_element_in_bst (T data, BinarySearchTree<T>* root)
{
    BinarySearchTree<T>* new_node = new BinarySearchTree<T> (data);

    insert_node_in_bst (new_node, root);
}

template <typename T>
void insert_node_in_bst (BinarySearchTree<T>* new_node, BinarySearchTree<T>* root)
{
    BinarySearchTree<T>* temp = root;

    if (!temp)
    {
        cout << "BST is empty !!!" << endl;
        return;
    }
    
    while (temp)
    {
        if (new_node -> m_data > temp -> m_data)
        {
            if (!temp -> m_right)
            {
                temp -> m_right = new_node;
                break;
            }
            temp = temp -> m_right;
        }
        else
        {
            if (!temp -> m_left)
            {
                temp -> m_left = new_node;
                break;
            }
            temp = temp -> m_left;
        }
        
    }
}

template <typename T>
void search_element_in_bst (T data, BinarySearchTree<T>* root)
{
    BinarySearchTree<T>* temp = root;

    while (temp)
    {
        if (temp -> m_data == data)
        {
            cout << "Data: " << data << " found in BST !!!" << endl;
            return;
        }
        else if (temp -> m_data > data)
        {
            temp = temp -> m_left;
        }
        else
        {
            temp = temp -> m_right;
        }
        
    }
    cout << "Data: " << data << " not found in BST !!!" << endl;
}

template <typename T>
BinarySearchTree<T>* delete_element_in_bst (T data, BinarySearchTree<T>* root)
{
    BinarySearchTree<T>* temp = root;
    BinarySearchTree<T>* parent = NULL;

    while (temp)
    {
        if (temp -> m_data == data)
        {
            cout << "Data: " << data << " found in BST, node will be deleted now !!!" << endl;
            BinarySearchTree<T>* left_child = temp -> m_left;
            BinarySearchTree<T>* new_root = root;

            if (parent)
            {
                if (parent -> m_left == temp)
                {
                    parent -> m_left = temp -> m_right;
                    insert_node_in_bst (left_child, parent -> m_left);
                }
                else
                {
                    parent -> m_right = temp -> m_right;
                    insert_node_in_bst (left_child, parent -> m_right);
                }
            }
            else
            {
                /* Deleted node is root node */
                new_root = temp -> m_right;
                insert_node_in_bst (temp -> m_left, new_root);
            }
            delete temp;
            return new_root;
        }
        else
        {
            parent = temp;
            if (temp -> m_data > data)
            {
                temp = temp -> m_left;
            }
            else
            {
                temp = temp -> m_right;
            }
            
        }
        
    }
    cout << "Data: " << data << " not found in BST !!!" << endl;
    return root;
}

template <typename T>
void delete_all_nodes (BinarySearchTree<T>* root)
{
    if (!root)
        return;
    if (root -> m_left)
    {
        delete_all_nodes (root -> m_left);
    }
    if (root -> m_right)
    {
        delete_all_nodes (root -> m_right);
    }
    delete root;
}

template <typename T>
void insert_element_in_bst_recursive (T data, BinarySearchTree<T>* root)
{
    BinarySearchTree<T>* new_node = new BinarySearchTree<T> (data);

    insert_node_in_bst_recursive (new_node, root);
}

template <typename T>
void insert_node_in_bst_recursive (BinarySearchTree<T>* new_node, BinarySearchTree<T>* root)
{
    BinarySearchTree<T>* temp = root;

    if (!temp)
    {
        cout << "BST is empty !!!" << endl;
        return;
    }
    
    if (new_node -> m_data > temp -> m_data)
    {
        if (!temp -> m_right)
        {
            temp -> m_right = new_node;
            return;
        }
        insert_node_in_bst_recursive (new_node, temp -> m_right);
    }
    else
    {
        if (!temp -> m_left)
        {
            temp -> m_left = new_node;
            return;
        }
        insert_node_in_bst_recursive (new_node, temp -> m_left);
    }
}

template <typename T>
BinarySearchTree<T>* search_element_in_bst_recursive (T data, BinarySearchTree<T>* root)
{
    BinarySearchTree<T>* temp = root;

    if (!temp)
    {
        cout << "Data: " << data << " not found in BST !!!" << endl;
        return NULL;
    }
    
    if (temp -> m_data == data)
    {
        cout << "Data: " << data << " found in BST !!!" << endl;
        return temp;
    }
    else if (temp -> m_data > data)
    {
        return search_element_in_bst_recursive (data, temp -> m_left);
    }
    else
    {
        return search_element_in_bst_recursive (data, temp -> m_right);
    }
}

template <typename T>
BinarySearchTree<T>* delete_element_in_bst_recursive (T data, BinarySearchTree<T>* root, BinarySearchTree<T>* parent)
{
    BinarySearchTree<T>* temp = root;
    BinarySearchTree<T>* new_root = NULL;

    if (!temp)
    {
        cout << "Data: " << data << " not found in BST !!!" << endl;
        return parent;
    }

    if (temp -> m_data == data)
    {
        cout << "Data: " << data << " found in BST, node will be deleted now !!!" << endl;
        BinarySearchTree<T>* left_child = temp -> m_left;

        if (parent)
        {
            if (parent -> m_left == temp)
            {
                parent -> m_left = temp -> m_right;
                insert_node_in_bst (left_child, parent -> m_left);
            }
            else
            {
                parent -> m_right = temp -> m_right;
                insert_node_in_bst (left_child, parent -> m_right);
            }
        }
        else
        {
            /* Deleted node is root node */
            new_root = temp -> m_right;
            insert_node_in_bst (temp -> m_left, new_root);
        }
        delete temp;
        return new_root;
    }
    else
    {
        if (temp -> m_data > data)
        {
            new_root = delete_element_in_bst_recursive (data, temp -> m_left, temp);
        }
        else
        {
            new_root = delete_element_in_bst_recursive (data, temp -> m_right, temp);
        }
    }

    return root;
}

template <typename T>
BinarySearchTree<T>* find_minimum_element_in_bst_using_iteration (BinarySearchTree<T>* root)
{
    if (!root)
    {
        cout << "BST tree is empty !!!" << endl;
        return NULL;
    }

    BinarySearchTree<T>* temp = root;

    while (temp)
    {
        if (temp -> m_left)
        {
            temp = temp -> m_left;
        }
        else
        {
            return temp;
        }
    }
}

template <typename T>
BinarySearchTree<T>* find_maximum_element_in_bst_using_iteration (BinarySearchTree<T>* root)
{
    if (!root)
    {
        cout << "BST tree is empty !!!" << endl;
        return NULL;
    }

    BinarySearchTree<T>* temp = root;

    while (temp)
    {
        if (temp -> m_right)
        {
            temp = temp -> m_right;
        }
        else
        {
            return temp;
        }
    }
}

template <typename T>
BinarySearchTree<T>* find_minimum_element_in_bst_using_recursion (BinarySearchTree<T>* root)
{
    if (!root)
    {
        cout << "BST tree is empty !!!" << endl;
        return NULL;
    }

    if (root -> m_left)
    {
        return find_minimum_element_in_bst_using_recursion (root -> m_left);
    }
    else
    {
        return root;
    }
}

template <typename T>
BinarySearchTree<T>* find_maximum_element_in_bst_using_recursion (BinarySearchTree<T>* root)
{
    if (!root)
    {
        cout << "BST tree is empty !!!" << endl;
        return NULL;
    }

    if (root -> m_right)
    {
        return find_maximum_element_in_bst_using_recursion (root -> m_right);
    }
    else
    {
        return root;
    }
}

template <typename T>
BinarySearchTree<T>* find_kth_minimum_element_in_bst (BinarySearchTree<T>* root, int k, int* count)
{
    if (!root)
        return NULL;

    BinarySearchTree<T>* temp = find_kth_minimum_element_in_bst (root -> m_left, k, count);

    if (temp)
        return temp;
    ++(*count);
    if (*count == k)
        return root;
    return find_kth_minimum_element_in_bst (root -> m_right, k, count);
}

template <typename T>
BinarySearchTree<T>* find_kth_maximum_element_in_bst (BinarySearchTree<T>* root, int k, int* count)
{
    if (!root)
        return NULL;

    BinarySearchTree<T>* temp = find_kth_maximum_element_in_bst (root -> m_right, k, count);

    if (temp)
        return temp;
    ++(*count);
    if (*count == k)
        return root;
    return find_kth_maximum_element_in_bst (root -> m_left, k, count);
}

template <typename T>
BinarySearchTree<T>* find_least_common_ancestor_in_bst (BinarySearchTree<T>* root, BinarySearchTree<T>* low, BinarySearchTree<T>* high)
{
    if (root -> m_data >= low -> m_data && root -> m_data <= high -> m_data)
        return root;
    else if (root -> m_data >= high -> m_data)
        return find_least_common_ancestor_in_bst (root -> m_left, low, high);
    else
        return find_least_common_ancestor_in_bst (root -> m_right, low, high);
}

template <typename T>
bool isBst (BinarySearchTree<T>* root)
{
    if (!root)
        return true;

    if (root -> m_right && root -> m_data > root -> m_left -> m_data)
        return false;

    if (root -> m_left && root -> m_data < root -> m_left -> m_data)
        return false;

    return (isBst (root -> m_left) && isBst (root -> m_right));
}

#endif /* _PRACTICE_BINARY_SEARCH_TREE_H_ */