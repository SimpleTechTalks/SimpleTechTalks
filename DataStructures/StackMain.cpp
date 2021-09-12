#include <iostream>

using namespace std;

#include "StackDefine.h"
#include "LinkedListDefine.h"

void check_balanced_symbol ()
{
    char expr[100] = "";
    cout << "Enter the Expression" << endl;
    cin >> expr ;
    if (check_balanced_symbols (expr))
    {
        cout << "Expression " << expr << " is balanced " << endl;
    }
    else
    {
        cout << "Expression " << expr << " is not balanced " << endl;
    }
    
}

void check_infix_to_postfix ()
{
    char expr[100] = "";
    cout << "Enter the Expression" << endl;
    cin >> expr ;
    convert_infix_to_postfix (expr);    
}

void check_postfix_evaluate ()
{
    char expr[100] = "";
    cout << "Enter the Expression" << endl;
    cin >> expr ;
    evaluate_postfix_expression (expr);    
}

void check_stack_generic ()
{
    StackGeneric<int> s(5);
    cout << "Stack size: " << s.maxSize () << " entries present: " << s.entries () << endl;
    cout << "Stack Pop: " << s.pop () << endl;
    cout << "Stack Push 1 Status: " << s.push (1) << endl;
    cout << "Stack Push 2 Status: " << s.push (2) << endl;
    cout << "Stack size: " << s.maxSize () << " entries present: " << s.entries () << endl;
    cout << "Stack Push 3 Status: " << s.push (3) << endl;
    cout << "Stack Push 4 Status: " << s.push (4) << endl;
    cout << "Stack Pop: " << s.pop () << endl;
    cout << "Stack Push 5 Status: " << s.push (5) << endl;
    cout << "Stack Push 6 Status: " << s.push (6) << endl;
    cout << "Stack Push 7 Status: " << s.push (7) << endl;
    cout << "Stack size: " << s.maxSize () << " entries present: " << s.entries () << endl;
    cout << "Stack Push 8 Status: " << s.push (8) << endl;
    cout << "Stack Push 9 Status: " << s.push (9) << endl;
    cout << "Stack Pop: " << s.pop () << endl;
    cout << "Stack Push 10 Status: " << s.push (10) << endl;
    cout << "Stack Pop: " << s.pop () << endl;
    cout << "Stack Pop: " << s.pop () << endl;
    cout << "Stack Pop: " << s.pop () << endl;
    cout << "Stack size: " << s.maxSize () << " entries present: " << s.entries () << endl;
    cout << "Stack Pop: " << s.pop () << endl;
    cout << "Stack Pop: " << s.pop () << endl;
}

void check_stack_minimum ()
{
    StackMinimum s (20);
    s.push (5);
    s.push (8);
    s.push (4);
    s.push (7);
    s.push (3);
    s.push (9);
    s.push (2);
    s.push (12);
    s.push (1);
    s.size ();

    cout << "At the begining minimum value is: " << s.getMinimum () << endl;
    while (s.entries () > 0)
    {
        cout << "After Poping element: " << s.pop () << " New minimum value is: " << s.getMinimum () << endl;
    }
}

void check_stack_minimum_modified ()
{
    StackMinimum s (20);
    s.push_modified (5);
    s.push_modified (8);
    s.push_modified (4);
    s.push_modified (7);
    s.push_modified (3);
    s.push_modified (9);
    s.push_modified (2);
    s.push_modified (12);
    s.push_modified (1);
    s.size ();

    cout << "At the begining minimum value is: " << s.getMinimum () << endl;
    while (s.entries () > 0)
    {
        cout << "After Poping element: " << s.pop_modified () << " New minimum value is: " << s.getMinimum () << endl;
    }
}

LinkedList* create_non_palindrome_linked_list ()
{
    LinkedList* start = NULL;
    insert_at_begining (&start, 1);
    insert_at_begining (&start, 2);
    insert_at_begining (&start, 3);
    insert_at_begining (&start, 4);
    insert_at_begining (&start, 5);
    insert_at_begining (&start, 6);
    insert_at_begining (&start, 7);
    insert_at_begining (&start, 8);
    insert_at_begining (&start, 9);
    cout << "Length of linked list: " << length_of_linked_list_using_iteration (start) << endl;
    print_linked_list (start);
    return start;
}

LinkedList* create_palindrome_linked_list ()
{
    LinkedList* start = NULL;
    insert_at_begining (&start, 1);
    insert_at_begining (&start, 2);
    insert_at_begining (&start, 3);
    insert_at_begining (&start, 4);
    insert_at_begining (&start, 5);
    insert_at_begining (&start, 4);
    insert_at_begining (&start, 3);
    insert_at_begining (&start, 2);
    insert_at_begining (&start, 1);
    cout << "Length of linked list: " << length_of_linked_list_using_iteration (start) << endl;
    print_linked_list (start);
    return start;
}

void check_palindrome (LinkedList* start)
{
    Stack s(20);
    LinkedList* temp = start;
    while (temp)
    {
        s.push (temp -> data);
        temp = temp -> next;
    }

    temp = start;
    bool isPalindrome = true;
    while (temp)
    {
        if (temp -> data == s.atTop ())
        {
            temp = temp -> next;
            s.pop ();
        }
        else
        {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome)
        cout << "Linked List is Palindrome" << endl;
    else
        cout << "Linked List is not Palindrome" << endl;
}

void check_linked_list_palindrome ()
{
    LinkedList* start = create_non_palindrome_linked_list ();
    check_palindrome (start);
    delete_all_node (&start);
    start = create_palindrome_linked_list ();
    check_palindrome (start);
    delete_all_node (&start);
}

void check_stack_reverse ()
{
    Stack s (20);
    s.push (5);
    s.push (8);
    s.push (4);
    s.push (7);
    s.push (3);
    s.push (9);
    s.push (2);
    s.push (12);
    s.push (1);
    s.printContent ();

    reverse_stack_data (&s);
    s.printContent ();
}

void check_double_stack ()
{
    DoubleStack d(10);
    d.push (10, true);
    d.push (20, true);
    d.push (30, false);
    d.push (40, true);
    d.push (50, false);
    d.push (60, true);
    d.push (70, true);
    d.printContent ();
    d.push (100, true);
    d.push (200, false);
    d.push (300, false);
    d.push (400, true);
    d.printContent ();
    d.pop(true);
    d.pop(false);
    d.printContent ();
    d.push (300, false);
    d.push (400, true);
    d.printContent ();
}

int main ()
{
    //check_stack_generic();
    //check_balanced_symbol();
    //check_infix_to_postfix ();
    //check_postfix_evaluate ();
    //check_stack_minimum ();
    //check_stack_minimum_modified ();
    //check_linked_list_palindrome ();
    //check_stack_reverse ();
    check_double_stack ();
    /*
    Stack s(5);
    cout << "Stack size: " << s.maxSize () << " entries present: " << s.entries () << endl;
    cout << "Stack Pop: " << s.pop () << endl;
    cout << "Stack Push 1 Status: " << s.push (1) << endl;
    cout << "Stack Push 2 Status: " << s.push (2) << endl;
    cout << "Stack size: " << s.maxSize () << " entries present: " << s.entries () << endl;
    cout << "Stack Push 3 Status: " << s.push (3) << endl;
    cout << "Stack Push 4 Status: " << s.push (4) << endl;
    cout << "Stack Pop: " << s.pop () << endl;
    cout << "Stack Push 5 Status: " << s.push (5) << endl;
    cout << "Stack Push 6 Status: " << s.push (6) << endl;
    cout << "Stack Push 7 Status: " << s.push (7) << endl;
    cout << "Stack size: " << s.maxSize () << " entries present: " << s.entries () << endl;
    cout << "Stack Push 8 Status: " << s.push (8) << endl;
    cout << "Stack Push 9 Status: " << s.push (9) << endl;
    cout << "Stack Pop: " << s.pop () << endl;
    cout << "Stack Push 10 Status: " << s.push (10) << endl;
    cout << "Stack Pop: " << s.pop () << endl;
    cout << "Stack Pop: " << s.pop () << endl;
    cout << "Stack Pop: " << s.pop () << endl;
    cout << "Stack size: " << s.maxSize () << " entries present: " << s.entries () << endl;
    cout << "Stack Pop: " << s.pop () << endl;
    cout << "Stack Pop: " << s.pop () << endl;*/
}
