/*
 * Let numbers are being represented by Two Linked List.
 * Sum the Two Linked List and save the result in third Linked List.
 */

#include "iostream"

using namespace std;
#include "../DataStructures/LinkedListDefine.h"

LinkedList* add_number (LinkedList* l1, int l1_len, LinkedList* l2, int l2_len, int* carry)
{
	if (!l1 & !l2)
		return NULL;
	LinkedList* l3 = NULL;
	LinkedList* temp = NULL;
	int sum = 0;
	if (l1_len > l2_len)
	{
		temp = add_number (l1->next, l1_len - 1, l2, l2_len, carry);
		sum = l1->data + *carry;
	}
	else if (l2_len = l1_len)
	{
		temp = add_number (l1->next, l1_len - 1, l2->next, l2_len - 1, carry);
		sum = l1->data + l2->data + *carry;
	}
	*carry = sum / 10;
	insert_at_begining (&l3, sum % 10);
	l3 -> next = temp;
	return l3;
}

LinkedList* add_list (LinkedList* l1, LinkedList* l2)
{
	int l1_len = length_of_linked_list_using_iteration (l1);
	int l2_len = length_of_linked_list_using_iteration (l2);
	cout << "List 1 length: " << l1_len << "\nList 2 length: " << l2_len << endl;
	int carry = 0;
	LinkedList* l3 = NULL;
	LinkedList* temp = NULL;
	if (l1_len > l2_len)
		temp = add_number (l1, l1_len, l2, l2_len, &carry);
	else
		temp = add_number (l2, l2_len, l1, l1_len, &carry);
	if (carry)
	{
		insert_at_begining (&l3, carry);
		l3 -> next = temp;
	}
	else
	{
		l3 = temp;
	}
	return l3;
}

int main ()
{
	LinkedList* list1 = NULL;
	insert_at_begining (&list1, 7);
	insert_after_certain_element (list1, 8, 7);
	insert_after_certain_element (list1, 4, 8);
	insert_after_certain_element (list1, 6, 8);
	LinkedList* list2 = NULL;
	insert_at_begining (&list2, 6);
	insert_after_certain_element (list2, 8, 6);
	insert_after_certain_element (list2, 4, 8);
	insert_after_certain_element (list2, 6, 4);
	insert_after_certain_element (list2, 6, 6);
	cout << "Number 1: ";
	print_linked_list (list1);
	cout << "Number 2: ";
	print_linked_list (list2);

	LinkedList* sum = add_list (list1, list2);
	cout << "Final Sum: ";
	print_linked_list (sum);

	delete_all_node (&list1);
	delete_all_node (&list2);
}
/*  Version 2 -- most significant digit at the end --

class ListNode {
	public:
      	int val;
      	ListNode *next;
     	ListNode() : val(0), next(nullptr) {}
      	ListNode(int x) : val(x), next(nullptr) {}
      	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbersWithCarry (ListNode* l1, ListNode* l2, int carry)
{
	if (!l1 && !l2) {
		if (carry) {
			return new ListNode (carry);
		}
		return NULL;
	}
	int sum = 0;
	if (!l1) {
		sum = l2 -> val + carry;
		return new ListNode (sum % 10, addTwoNumbersWithCarry (l1, l2->next, sum / 10));
	} else if (!l2) {
		sum = l1 -> val + carry;
		return new ListNode (sum % 10, addTwoNumbersWithCarry (l1->next, l2, sum / 10));
	} else {
		sum = l1 -> val + l2 -> val + carry;
		return new ListNode (sum % 10, addTwoNumbersWithCarry (l1->next, l2->next, sum / 10));
	}
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	return addTwoNumbersWithCarry (l1, l2, 0);
}
*/