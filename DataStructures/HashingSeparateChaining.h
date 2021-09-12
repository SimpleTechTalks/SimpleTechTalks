#include <iostream>
//#include "LinkedList.h"
#include "LinkedListDefine.h"

using namespace std;
#define HASHING_SEPARATE_CHAINING_MAX_ENTRIES 10
class HashingSeparateChaining
{
	private:
		LinkedList* m_hash_table[HASHING_SEPARATE_CHAINING_MAX_ENTRIES];
		int m_entries;
		int m_size;
		int hash_function (int key);
		
	public:
		HashingSeparateChaining ();
		~HashingSeparateChaining ();
		int get_size ();
		int get_entries ();
		int get_load_factor ();
		
		void insert_data (int data);
		void delete_data (int data);
		bool search_data (int data);
		void print_element ();
};

HashingSeparateChaining::HashingSeparateChaining (): m_entries(0), m_size(HASHING_SEPARATE_CHAINING_MAX_ENTRIES)
{
	for (int i = 0; i < HASHING_SEPARATE_CHAINING_MAX_ENTRIES; i++)
	{
		m_hash_table[i] = NULL;
	}
}

HashingSeparateChaining::~HashingSeparateChaining ()
{
	for (int i = 0; i < HASHING_SEPARATE_CHAINING_MAX_ENTRIES; i++)
	{
		if (m_hash_table[i]) {
			delete_all_node (&m_hash_table[i]->next);
		}
		m_hash_table[i] = NULL;
	}
}

int HashingSeparateChaining::get_size ()
{
	return m_size;
}

int HashingSeparateChaining::get_entries ()
{
	return m_entries;
}

int HashingSeparateChaining::get_load_factor ()
{
	cout << "For Separate Chaining Load factor is not applicable !!" << endl;
	return 0;
}

int HashingSeparateChaining::hash_function (int key)
{
	return (key % get_size ());
}

void HashingSeparateChaining::insert_data (int data)
{
	int index = hash_function (data);
	if (m_hash_table[index]) {
		cout << "collision occured for key " << data << ", handling it !!!" << endl;
	}
	insert_at_begining (&m_hash_table[index], data);
	m_entries++;
}

void HashingSeparateChaining::delete_data (int data)
{
	int index = hash_function (data);
	if (!m_hash_table[index]) {
		cout << "key " << data << " not present in hash map, nothing to delete !!!" << endl;
		return;
	}
	if (delete_searched_node (&m_hash_table[index], data)) {
		cout << "key " << data << " present in hash map, deleted !!!" << endl;
		m_entries--;
	}
}

bool HashingSeparateChaining::search_data (int data)
{
	int index = hash_function (data);
	if (!m_hash_table[index]) {
		cout << "key " << data << " not present in hash map!!!" << endl;
		return false;
	}
	if (search_element (m_hash_table[index], data)) {
		cout << "key " << data << " present in hash map!!!" << endl;
		return true;
	}
	return false;
}

void HashingSeparateChaining::print_element ()
{
	cout << "Printing Hash elements, size: " << get_size () << 
			" Entries: " << get_entries () << " Load factor: " << get_load_factor () << "%" << endl;
	
	int size = get_size ();
	for (int i = 0; i < size; i++)
	{
		if (m_hash_table[i]) {
			print_linked_list (m_hash_table[i]);
		} else {
			cout << "NULL" << endl;
		}
	}
	cout << endl;
}