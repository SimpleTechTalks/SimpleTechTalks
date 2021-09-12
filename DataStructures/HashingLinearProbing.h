#ifndef _PRACTICE_HASHING_LINEAR_PROBING_H
#define _PRACTICE_HASHING_LINEAR_PROBING_H

#include "Hashing.h"

class HashingLinearProbing: public Hashing
{
	public:
		HashingLinearProbing (int size);
		~HashingLinearProbing ();
		int linear_probing (int index);
		void insert_data (int data);
		void delete_data (int data);
		bool search_data (int data);
};

HashingLinearProbing::HashingLinearProbing (int size): Hashing (size)
{}

HashingLinearProbing::~HashingLinearProbing ()
{}

int HashingLinearProbing::linear_probing (int index)
{
	return (index + 1) % get_size ();
}

void HashingLinearProbing::insert_data (int data)
{
	if (get_entries () >= get_size ()) {
		cout << "No space to insert, Hash table is full!!" << endl;
	}
	int index = hash_function (data);
	while (m_hash_table[index] != 0) {
		index = linear_probing (index);
	}
	m_hash_table[index] = data;
	m_entries++;
}

void HashingLinearProbing::delete_data (int data)
{
	int index = hash_function (data);
	while (m_hash_table[index] != 0) {
		if (m_hash_table[index] == data) {
			m_hash_table[index] = 0;
			m_entries--;
			cout << "Data " << data << " Found in hash table, deleting !!!" << endl;
			return;
		}
		index = linear_probing (index);
	}
	cout << "Data " << data << " Not Found in hash table, nothing to delete !!!" << endl;
}

bool HashingLinearProbing::search_data (int data)
{
	int index = hash_function (data);
	while (m_hash_table[index] != 0) {
		if (m_hash_table[index] == data) {
			cout << "Data " << data << " Found in hash table !!!" << endl;
			return true;
		}
		index = linear_probing (index);
	}
	cout << "Data " << data << " Not Found in hash table !!!" << endl;
	return false;
}

#endif /* _PRACTICE_HASHING_LINEAR_PROBING_H */