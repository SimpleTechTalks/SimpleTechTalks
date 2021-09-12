#ifndef _PRACTICE_HASHING_BASIC_H
#define _PRACTICE_HASHING_BASIC_H
#include <iostream>

using namespace std;

class Hashing
{
	public:
		int* m_hash_table;
		int m_entries;
		int m_size;
		int hash_function (int key);

		Hashing (int size);
		~Hashing ();
		int get_size ();
		int get_entries ();
		int get_load_factor ();
		
		void insert_data (int data);
		void delete_data (int data);
		bool search_data (int data);
		void print_element ();
};

Hashing::Hashing (int size): m_entries(0), m_size (size)
{
	m_hash_table = new int[size];
	for (int i = 0; i < size; i++)
	{
		m_hash_table[i] = 0;
	}
}

Hashing::~Hashing ()
{
	if (m_hash_table) {
		delete[] m_hash_table;
	}
}

int Hashing::get_size ()
{
	return m_size;
}

int Hashing::get_entries ()
{
	return m_entries;
}

int Hashing::get_load_factor ()
{
	return ((float)m_entries / get_size ()) * 100;
}

int Hashing::hash_function (int key)
{
	return (key % get_size ());
}

/* In case of collision, we are rejecting key insertion in Hash table */
void Hashing::insert_data (int data)
{
	int index = hash_function (data);
	if (m_hash_table[index] != 0) {
		cout << "collision occured for key " << data << " !!!" << endl;
	} else {
		m_hash_table[index] = data;
		m_entries++;
	}
}

/* Since no collision is present in hash table, hence we can directly delete
 * the entry if it is present */
void Hashing::delete_data (int data)
{
	int index = hash_function (data);
	if (m_hash_table[index] == 0) {
		cout << "key " << data << " not present in hash map, nothing to delete !!!" << endl;
	} else {
		m_hash_table[index] = 0;
		m_entries--;
	}
}

/* Since no collision is present in hash table, hence we can directly return
 * success, if hash code index is occupied */
bool Hashing::search_data (int data)
{
	int index = hash_function (data);
	if (m_hash_table[index] == 0) {
		cout << "key " << data << " not present in hash map, search fails !!!" << endl;
		return false;
	}
	cout << "key " << data << " present in hash map, search successful !!!" << endl;
	return true;
}

void Hashing::print_element ()
{
	cout << "Printing Hash elements, size: " << get_size () << 
			" Entries: " << get_entries () << " Load factor: " << get_load_factor () << "%" << endl;
	
	int size = get_size ();
	for (int i = 0; i < size; i++)
	{
		if (i % 10 == 0)
			cout << endl;
		cout << m_hash_table[i] << "  ";
	}
	cout << endl;
}

#endif /* _PRACTICE_HASHING_BASIC_H */