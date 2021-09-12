class LinkedList
{
    public:
        int data;
        LinkedList* next;
        LinkedList (int data);
        ~LinkedList ();
};

LinkedList::LinkedList (int data): data (data),
                                   next (NULL)
{
}

LinkedList::~LinkedList ()
{
}

void insert_at_begining (LinkedList** start, int new_data)
{
    LinkedList* temp = new LinkedList(new_data);
    temp -> next = *start;
    *start = temp;
}

void insert_after_certain_element (LinkedList* start, int new_data, int search_data)
{
    LinkedList* temp = start;
    LinkedList* prev = start;

    cout << "Inserting node " << new_data << endl;
    if (!temp)
    {
        LinkedList* n = new LinkedList (new_data);
        start = n;
        return;
    }

    while (temp)
    {
        if (temp -> data == search_data)
        {
            // This is the first element
            LinkedList* n = new LinkedList (new_data);
            n -> next = temp -> next;
            temp -> next = n;
            return;
        }
        prev = temp;
        temp = temp -> next;
    }
    cout << "Searched data not found, hence putting new node at the end" << endl;
    LinkedList* n = new LinkedList (new_data);
    n -> next = prev -> next;
    prev -> next = n;
    return;
}

bool search_element (LinkedList* start, int searched_data)
{
    LinkedList* temp = start;

    while (temp)
    {
        if (temp -> data == searched_data)
        {
            cout << "Found the searched data: " << searched_data << endl;
            return true;
        }
        temp = temp -> next;
    }
    cout << "Did not find the searched data: " << searched_data << endl;
    return false;
}

void delete_start_node (LinkedList** start)
{
    if (!start)
    {
        cout << "Nothing to delete" << endl;
        return;
    }
    LinkedList* temp = *start;
    *start = (*start) -> next;
    delete temp;
}

bool delete_searched_node (LinkedList** start, int searched_data)
{
    LinkedList* temp = *start;
    LinkedList* parent = *start;

    while (temp)
    {
        if (temp -> data == searched_data)
        {
            cout << "Node found, going to delete" << endl;
            parent -> next = temp -> next;
            delete temp;
            return true;
        }
        parent = temp;
        temp = temp -> next;
    }
    cout << "Node not found, ignoring delete" << endl;
    return false;
}

void delete_all_node (LinkedList** start)
{
    LinkedList* temp = *start;
    while (temp)
    {
        LinkedList* next = temp -> next;
        delete temp;
        temp = next;
    }
    *start = NULL;
}

void print_linked_list (LinkedList* start)
{
    if (!start)
    {
        cout << "Linked list is null, nothing to print" << endl;
        return;
    }

    LinkedList* temp = start;
    while (temp)
    {
        cout << " " << temp -> data;
        temp = temp -> next;
    }
    cout << endl;
}

LinkedList* reverse_linked_list_using_iteration (LinkedList* start)
{
    LinkedList* prev = NULL;
    LinkedList* cur = start;
    LinkedList* next = NULL;

    while (cur)
    {
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

LinkedList* reverse_linked_list_using_recursion (LinkedList* node, LinkedList* parent)
{
    if (!node)
        return NULL;
    LinkedList* next = node -> next;
    node -> next = parent;
    if (!next)
        return node;
    return reverse_linked_list_using_recursion (next, node);
}

LinkedList* reverse_linked_list (LinkedList* start, bool isUsingRecursion)
{
    if (isUsingRecursion)
    {
        cout << "Reversing linked list using recursion" << endl;
        return reverse_linked_list_using_recursion (start, NULL);
    }
    else
    {
        cout << "Reversing linked list using iteration" << endl;
        return reverse_linked_list_using_iteration (start);
    }
}

int length_of_linked_list_using_recursion (LinkedList* start)
{
    if (!start)
        return 0;
    return 1 + length_of_linked_list_using_recursion (start -> next);
}

int length_of_linked_list_using_iteration (LinkedList* start)
{
    LinkedList* temp = start;
    int count = 0;

    while (temp)
    {
        count++;
        temp = temp -> next;
    }
    return count;
}

void find_nth_node_from_end (LinkedList* start, int n)
{
    LinkedList* fast = start;
    LinkedList* slow = start;

    int count = 0;

    while (fast)
    {
        ++count;
        if (count == n)
            slow = start;
        else if (count > n)
            slow = slow -> next;
        fast = fast -> next;
    }
    if (count >= n)
        cout << "Node found: " << slow -> data << " nth place: " << n << endl;
    else
        cout << "Not enough node present, length: " << count << " nth Node searched: " << n << endl;
}

LinkedList* find_loop_in_linked_list (LinkedList* start)
{
    LinkedList* slow = start;
    LinkedList* fast = start;

    while (fast)
    {
        slow = slow -> next;
        if (!fast -> next)
            break;
        fast = fast -> next -> next;
        if (slow == fast)
        {
            cout << "Loop found " << endl;
            return slow;
        }
    }
    cout << "Loop not found" << endl;
    return NULL;
}

int count_loop_length (LinkedList* loop_node)
{
    LinkedList* temp = loop_node;

    int count = 1;
    while (temp -> next != loop_node)
    {
        temp = temp -> next;
        count++;
    }
    cout << count << endl;
    return count;
}

LinkedList* return_node_creating_loop (LinkedList* start, int loop_len)
{
    LinkedList* fast = start;
    LinkedList* slow = start;

    int count = 0;
    while (count != loop_len)
    {
        count++;
        fast = fast -> next;
    }

    while (fast != slow)
    {
        fast = fast -> next;
        slow = slow -> next;
    }
    return fast;
}

/* This function will create a loop in Linked List */
void insert_at_end_to_create_loop (LinkedList* start, int new_data, int search_data)
{
    LinkedList* temp = start;
    LinkedList* prev = start;
    LinkedList* searched_node = NULL;

    cout << "Inserting node " << new_data << endl;

    while (temp)
    {
        if (temp -> data == search_data)
        {
            searched_node = temp;
        }
        prev = temp;
        temp = temp -> next;
    }

    LinkedList* n = new LinkedList (new_data);
    n -> next = searched_node;
    prev -> next = n;
    return;
}

void break_loop_in_linked_list (LinkedList* loop_node, LinkedList* node_at_loop)
{
    LinkedList* temp = loop_node;

    while (temp -> next != node_at_loop)
    {
        temp = temp -> next;
    }
    temp -> next = NULL;
}

LinkedList* alternate_method_to_find_starting_node (LinkedList* start, LinkedList* loop_node)
{
    LinkedList* fast = start;
    LinkedList* slow = loop_node;

    while (fast != slow)
    {
        fast = fast -> next;
        slow = slow -> next;
    }
    return fast;
}

void find_loop_and_print_node (LinkedList* start)
{
    LinkedList* loop_node = find_loop_in_linked_list (start);
    if (loop_node)
    {
        cout << "There is a loop in passed Linked List, loop node: " << loop_node -> data << endl;
        int len = count_loop_length (loop_node);
        cout << "Length of loop: " << len << endl;
        LinkedList* node_at_loop = return_node_creating_loop (start, len);
        cout << "Node at which loop occurs: " << node_at_loop -> data << endl;
        LinkedList* node_at_loop_2 = alternate_method_to_find_starting_node (start, loop_node);
        cout << "Node at which loop occurs: " << node_at_loop_2 -> data << endl;
        break_loop_in_linked_list (loop_node, node_at_loop);
        print_linked_list (start);
        return;
    }
    cout << "No Loop found in passed Linked List" << endl;
}

void print_looped_linked_list (LinkedList* start)
{
    if (!start)
    {
        cout << "Linked list is null, nothing to print" << endl;
        return;
    }

    LinkedList* temp = start;
    int count = 0;
    while (temp)
    {
        count++;
        cout << " " << temp -> data;
        temp = temp -> next;

        if (count > 15)
            break;
    }
    cout << endl;
}

LinkedList* pair_wise_swap_linked_list_recursion (LinkedList* start)
{
    LinkedList* temp = NULL;

    if (start && start -> next)
    {
        temp = start -> next;
        start -> next = start -> next -> next;
        temp -> next = start;
        start = temp;
        start -> next -> next = pair_wise_swap_linked_list_recursion (start -> next -> next);
    }
    return start;
}

LinkedList* pair_wise_swap_linked_list_iteration (LinkedList* start)
{
    LinkedList* itr = start;

    while (itr && itr -> next)
    {
        int data = itr -> data;
        itr -> data = itr -> next -> data;
        itr -> next -> data = data;
        itr = itr -> next -> next;
    }
    return start;
}

LinkedList* return_kth_node (LinkedList* node, int k)
{
    LinkedList* temp = node;
    int counter = 0;
    while (temp && counter < k)
    {
        temp = temp -> next;
        counter++;
    }
    return temp;
}

LinkedList* swap_k_node_linked_list_iteration (LinkedList* node, int k)
{
    int counter = 0;
    LinkedList* kth_node = return_kth_node (node, k);
    if (!kth_node)
        return node;

    LinkedList* newHead = return_kth_node (node, k-1);
    LinkedList* prev = NULL;
    LinkedList* cur = node;
    LinkedList* next = NULL;
    LinkedList* tempHead = NULL;
 
    while (cur && kth_node)
    {
        counter = 0;
        prev = return_kth_node (cur, k);
        if (tempHead)
            tempHead -> next = kth_node;
        tempHead = cur;
        while (counter < k)
        {
            counter++;
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        kth_node = return_kth_node (cur, k-1);
    }
    return newHead;
}

LinkedList* swap_k_nodes_using_recursion (LinkedList* start, int k)
{
    LinkedList* prev = NULL;
    LinkedList* cur = start;
    LinkedList* next = NULL;
    int counter = 0;

    while (cur && counter < k)
    {
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
        counter++;
    }
    if (next)
        start -> next = swap_k_nodes_using_recursion (next, k);
    return prev;
}

LinkedList* find_intersection_node (LinkedList* list1, LinkedList* list2)
{
    int len_1 = length_of_linked_list_using_recursion (list1);
    int len_2 = length_of_linked_list_using_recursion (list2);

    LinkedList* temp_l1 = list1;
    LinkedList* temp_l2 = list2;

    if (len_1 > len_2)
    {
        temp_l1 = return_kth_node (list1, (len_1 - len_2));
    }
    else
    {
        temp_l2 = return_kth_node (list2, (len_2 - len_1));
    }
    
    while (temp_l1 && temp_l2)
    {
        if (temp_l1 == temp_l2)
        {
            cout << "Found Intersection Node: " << temp_l2 -> data << endl;
            return temp_l2;
        }
        temp_l2 = temp_l2 -> next;
        temp_l1 = temp_l1 -> next;
    }
    return NULL;
}