/* Programs to write
 *
 * 1. Binary tree operations -- Done
 * 2. Binary tree inorder -- Done
 * 3. Binary tree preorder -- Done
 * 4. Binary tree postorder -- Done
 * 5. Binary tree levelorder -- Done
 * 6. find maximum element in binary tree -- done
 * 7. find height/depth of a binary tree -- done
 * 8. find number of leaves in a binary tree -- done
 * 9. convert a tree to its mirror -- done
 * 10. construct binary tree from inorder and preorder traversal -- done
 * 11. construct binary tree from inorder and postorder traversal -- done
 * 12. find inorder successor -- done
 * * 12. find preorder successor -- done
 * * 12. find postorder successor -- done
 * 
 */

#ifndef _PRACTICE_BINARY_TREE_H_
#define _PRACTICE_BINARY_TREE_H_

class BinaryTree
{
    public:
        int m_data;
        BinaryTree* m_left;
        BinaryTree* m_right;
        BinaryTree (int data);
        BinaryTree (int data, BinaryTree* left, BinaryTree* right);
        ~BinaryTree ();
};

BinaryTree::BinaryTree (int data): m_data(data),
                                   m_left(NULL),
                                   m_right(NULL)
{}

BinaryTree::BinaryTree (int data, BinaryTree* left, BinaryTree* right): m_data (data),
                                                                        m_left (left),
                                                                        m_right (right)
{}

BinaryTree::~BinaryTree ()
{}

BinaryTree* search_node_in_binary_tree (BinaryTree* root, int searchData)
{
    if (!root)
    {
        return NULL;
    }
    if (root -> m_data == searchData)
        return root;
    else
    {
        BinaryTree* temp = search_node_in_binary_tree (root -> m_left, searchData);
        if (temp)
            return temp;
        return search_node_in_binary_tree (root -> m_right, searchData);
    }
}

bool insert_at_first_available_place (BinaryTree* parent, BinaryTree* newNode)
{
    if (!parent)
        return false;
    if (!parent -> m_left)
    {
        parent -> m_left = newNode;
        return true;
    }
    else if (!parent -> m_right)
    {
        parent -> m_right = newNode;
        return true;
    }
    else
    {
        if(!insert_at_first_available_place (parent -> m_left, newNode))
        {
            return insert_at_first_available_place (parent -> m_right, newNode);
        }
        return true;
    }
}

/* New node will be added as a child/grandchild of the searched node.
 * If searched node is not found then first available node will be found
 * from root and new node will be placed there */
void insert_after_certain_element (BinaryTree* root, int newData, int searchData)
{
    BinaryTree* temp = new BinaryTree (newData);
    if (!root)
    {
        cout << "Empty Binary Tree, Adding new node as Root node" << endl; 
    }

    BinaryTree* searched_node = search_node_in_binary_tree (root, searchData);
    if (!searched_node)
    {
        searched_node = root;
    }
    if (!insert_at_first_available_place (searched_node, temp))
    {
        cout << "Inserting new element in Binary Tree failed !!!" << endl;
    }
}

BinaryTree* find_parent_node (BinaryTree* root, int searchData)
{
    if (!root)
    {
        return NULL;
    }
    if ((root -> m_left && root -> m_left -> m_data == searchData) || (root -> m_right && root -> m_right -> m_data == searchData))
    {
        return root;
    }
    BinaryTree* temp = find_parent_node (root -> m_left, searchData);
    if (!temp)
    {
        return find_parent_node (root -> m_right, searchData);
    }
    return temp;
}

void delete_node_and_rebalance (BinaryTree** root, BinaryTree* parent, int searchData)
{
    if (!parent)
    {
        /* Root node needs to be deleted */
        BinaryTree* newRoot = NULL;
        if (root)
        {
            if ((*root) -> m_left)
            {
                newRoot = (*root) -> m_left;
                if ((*root) -> m_right)
                {
                    insert_at_first_available_place (newRoot, (*root) -> m_right);
                }
            }
            else
            {
                newRoot = (*root) -> m_left;
            }
            delete (*root);
            *root = newRoot;
            return;
        }
        cout << "Root and Parent both not set !!!" << endl;
        return;
    }

    if (parent -> m_right -> m_data == searchData)
    {
        BinaryTree* temp = parent -> m_right;
        parent -> m_right = NULL;
        insert_at_first_available_place (*root, temp -> m_left);
        insert_at_first_available_place (*root, temp -> m_right);
        delete temp;
    }
    else
    {
        BinaryTree* temp = parent -> m_left;
        parent -> m_left = NULL;
        insert_at_first_available_place (*root, temp -> m_left);
        insert_at_first_available_place (*root, temp -> m_right);
        delete temp;
    }
    return;
}

BinaryTree* delete_node (BinaryTree* root, int searchData)
{
    if (!root)
    {
        cout << "Empty Binary Tree, Nothing to Delete !!!" << endl;
    }
    if (root -> m_data == searchData)
    {
        delete_node_and_rebalance (&root, NULL, searchData);
        return root;
    }
    BinaryTree* parent_node = find_parent_node (root, searchData);
    if (!parent_node)
    {
        cout << "Searched node: " << searchData << " not found, Nothing to Delete !!!" << endl;
    }
    else
    {
        delete_node_and_rebalance (&root, parent_node, searchData);
    }
    return root;
}

void print_binary_tree (BinaryTree* root)
{
    cout << " " << root -> m_data;
    if (root -> m_left)
        print_binary_tree (root -> m_left);
    if (root -> m_right)
        print_binary_tree (root -> m_right);
}

void delete_all_nodes (BinaryTree* root)
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

/* order of accessing nodes in inorder traversal is 
 * Left - Parent - Right
 */
void inorder_traversal (BinaryTree* root)
{
    if (!root)
        return;
    if (root -> m_left)
        inorder_traversal (root -> m_left);
    cout << " " << root -> m_data;
    if (root -> m_right)
        inorder_traversal (root -> m_right);
}

/* order of accessing nodes in preorder traversal is 
 * Parent - Left - Right
 */
void preorder_traversal (BinaryTree* root)
{
    if (!root)
        return;
    cout << " " << root -> m_data;
    if (root -> m_left)
        preorder_traversal (root -> m_left);
    if (root -> m_right)
        preorder_traversal (root -> m_right);
}

/* order of accessing nodes in preorder traversal is 
 * Left - Right - parent
 */
void postorder_traversal (BinaryTree* root)
{
    if (!root)
        return;
    if (root -> m_left)
        postorder_traversal (root -> m_left);
    if (root -> m_right)
        postorder_traversal (root -> m_right);
    cout << " " << root -> m_data;
}

class Queue
{
    private:
        int m_front;
        int m_rear;
        int m_entries;
        int m_max_size;

        BinaryTree** m_queue;

    public:
        Queue (int max);
        ~Queue ();
        int size ();
        int maxSize ();
        BinaryTree* enqueue (BinaryTree* entry);
        BinaryTree* dequeue ();
        bool isEmpty ();
        BinaryTree* atFront ();

        void print_content ()
        {
            int temp = m_rear;
            while (temp != m_front)
            {
                cout << (m_queue[temp]) -> m_data << " ";
                temp = (temp + 1) % m_max_size;
            }
            cout << endl;
        }
};

Queue::Queue (int max): m_front(0),
                        m_rear (0),
                        m_entries (0),
                        m_max_size (max)
{
    m_queue = new BinaryTree*[max];

    if (!m_queue)
    {
        cout << "Queue initialization failed" << endl;
        return;
    }
}

Queue::~Queue ()
{
    if (!m_queue)
    {
        cout << "Queue is not initializaed" << endl;
        return;
    }
    delete [] m_queue;
}

int Queue::size ()
{
    return m_entries;
}

int Queue::maxSize ()
{
    return m_max_size;
}

BinaryTree* Queue::atFront ()
{
    if (!m_queue)
    {
        cout << "Queue is not initializaed" << endl;
        return NULL;
    }

    if (m_entries == 0)
    {
        cout << "Queue is empty !!!" << endl;
        return NULL;
    }
    return m_queue[m_rear];
}

BinaryTree* Queue::enqueue (BinaryTree* entry)
{
    if (!m_queue)
    {
        cout << "Queue is not initializaed" << endl;
        return NULL;
    }

    if (m_entries == m_max_size)
    {
        cout << "Queue is full... can't take more entries!!" << endl;
        return NULL;
    }

    m_queue[m_front] = entry;
    m_front = (m_front + 1) % m_max_size;
    m_entries++;
    return entry;
}

BinaryTree* Queue::dequeue ()
{
    if (!m_queue)
    {
        cout << "Queue is not initializaed" << endl;
        return NULL;
    }

    if (m_entries == 0)
    {
        cout << "Queue is empty !!!" << endl;
        return NULL;
    }

    BinaryTree* temp = m_queue[m_rear];
    --m_entries;
    m_rear = (m_rear + 1) % m_max_size;
    return temp;
}

bool Queue::isEmpty ()
{
    return !m_entries;
}


void levelorder_traversal (BinaryTree* root)
{
    if (!root)
        return;
    Queue q(20);
    BinaryTree* temp = root;
    while (temp)
    {
        cout << " " << temp -> m_data;
        if (temp -> m_left)
            q.enqueue (temp -> m_left);
        if (temp -> m_right)
            q.enqueue (temp -> m_right);
        if (!q.isEmpty ())
            temp = q.dequeue ();
        else
            temp = NULL;        
    }
}

BinaryTree* get_maximum (BinaryTree* root)
{
    if (!root)
        return NULL;
    BinaryTree* max = root;
    BinaryTree* max_left = get_maximum (root -> m_left);
    BinaryTree* max_right = get_maximum (root -> m_right);
    if (max_left)
    {
        if (max_left -> m_data > max -> m_data)
        {
            max = max_left;
        }
    }
    if (max_right)
    {
        if (max_right -> m_data > max -> m_data)
        {
            max = max_right;
        }
    }
    return max;
}

BinaryTree* get_minimum (BinaryTree* root)
{
    if (!root)
        return NULL;
    BinaryTree* min = root;
    BinaryTree* min_left = get_minimum (root -> m_left);
    BinaryTree* min_right = get_minimum (root -> m_right);
    if (min_left)
    {
        if (min_left -> m_data < min -> m_data)
        {
            min = min_left;
        }
    }
    if (min_right)
    {
        if (min_right -> m_data < min -> m_data)
        {
            min = min_right;
        }
    }
    return min;
}

int get_maximum_height (BinaryTree* root)
{
    if (!root)
        return 0;
    int level_left = 0;
    int level_right = 0;
    if (root -> m_left)
        level_left = get_maximum_height (root -> m_left);
    if (root -> m_right)
        level_right = get_maximum_height (root -> m_right);
    return (level_right > level_left ? (1 + level_right) : (1 + level_left));
}

int get_height (BinaryTree* root)
{
    return (get_maximum_height (root) - 1);
}

int get_number_of_leaves (BinaryTree* root)
{
    if (!root)
        return 0;
    if (!root -> m_left && !root -> m_right)
        return 1;
    int max_left = get_number_of_leaves (root -> m_left);
    int max_right = get_number_of_leaves (root -> m_right);

    return (max_left + max_right);
}

int get_number_of_leaves_using_iteration (BinaryTree* root)
{
    if (!root)
        return 0;

    Queue q (10);
    int count = 0;

    BinaryTree* temp = NULL;
    q.enqueue (root);

    while (!q.isEmpty ())
    {
        temp = q.dequeue ();

        if (temp -> m_left)
        {
            q.enqueue (temp -> m_left);
        }
        if (temp -> m_right)
        {
            q.enqueue (temp -> m_right);
        }
        if (!temp -> m_right && !temp -> m_left)
        {
            count++;
        }
    }
    return count;
}

void get_mirror (BinaryTree * root)
{
    if (!root)
        return;
    BinaryTree* temp = root -> m_left;
    root -> m_left = root -> m_right;
    root -> m_right = temp;
    get_mirror (root -> m_left);
    get_mirror (root -> m_right);
}

void get_mirror_using_iteration (BinaryTree * root)
{
    if (!root)
        return;
    BinaryTree* temp = NULL;
    Queue q (10);
    q.enqueue (root);
    while (!q.isEmpty ())
    {
        temp = q.dequeue ();
        BinaryTree* t = temp -> m_left;
        temp -> m_left = temp -> m_right;
        temp -> m_right = t;
        if (temp -> m_left)
            q.enqueue (temp -> m_left);
        if (temp -> m_right)
            q.enqueue (temp -> m_right);
    }
}

BinaryTree* find_inorder_successor (BinaryTree* root, BinaryTree* node)
{
    if (!root)
    {
        return NULL;
    }
    if (!node)
    {
        return NULL;
    }
    if (node -> m_right)
    {
        BinaryTree* temp = node -> m_right;
        while (temp -> m_left)
        {
            temp = temp -> m_left;
        }
        return temp;
    }
    else
    {
        return NULL;
    }
    
}

BinaryTree* find_preorder_successor (BinaryTree* root, BinaryTree* node)
{
    if (!root)
    {
        return NULL;
    }
    if (!node)
    {
        return NULL;
    }
    if (node -> m_left)
    {
        return node -> m_left;
    }
    if (node -> m_right)
    {
        return node -> m_right;
    }
    BinaryTree* parent_node = find_parent_node (root, node -> m_data);
    if (parent_node && node == parent_node -> m_left)
    {
        while (parent_node)
        {
            if (parent_node -> m_right)
                return parent_node -> m_right;
            parent_node = find_parent_node (root, parent_node -> m_data);
        }
        return parent_node;
    }
    else
    {
        /* node is right child of parent node. */
        BinaryTree* cur = node;
        while (parent_node)
        {
            if (cur == parent_node -> m_left && parent_node -> m_right)
                return parent_node -> m_right;
            cur = parent_node;
            parent_node = find_parent_node (root, parent_node -> m_data);
        }
    }
    return NULL;
}

BinaryTree* find_postorder_successor (BinaryTree* root, BinaryTree* node)
{
    if (!root)
    {
        return NULL;
    }
    if (!node)
    {
        return NULL;
    }
    BinaryTree* parent_node = find_parent_node (root, node -> m_data);

    if (!parent_node)
    {
        return NULL;
    }

    if (node == parent_node -> m_right)
    {
        return parent_node;
    }
    /* node is left child of the parent */
    if (parent_node -> m_right)
    {
        BinaryTree* temp = parent_node -> m_right;
        while (temp -> m_left)
        {
            temp = temp -> m_left;
        }
        return temp;
    }
    return parent_node;
}
#endif /* _PRACTICE_BINARY_TREE_H_ */