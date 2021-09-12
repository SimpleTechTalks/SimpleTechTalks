#ifndef _PRACTICE_HASHING_QUADRATIC_PROBING_H
#define _PRACTICE_HASHING_QUADRATIC_PROBING_H

#include "Hashing.h"

class HashingQuadraticProbing: public Hashing
{
	public:
		HashingQuadraticProbing (int size);
		~HashingQuadraticProbing ();
		int quadratic_probing (int index, int loop);
		void insert_data (int data);
		void delete_data (int data);
		bool search_data (int data);
};

HashingQuadraticProbing::HashingQuadraticProbing (int size): Hashing (size)
{}

HashingQuadraticProbing::~HashingQuadraticProbing ()
{}

int HashingQuadraticProbing::quadratic_probing (int index, int loop)
{
	return (index + (loop * loop)) % get_size ();
}

void HashingQuadraticProbing::insert_data (int data)
{
	if (get_entries () >= get_size ()) {
		cout << "No space to insert, Hash table is full!!" << endl;
	}
	int index = hash_function (data);
	int loop = 1;
	while (m_hash_table[index] != 0) {
		index = quadratic_probing (index, loop);
		loop++;
	}
	m_hash_table[index] = data;
	m_entries++;
}

void HashingQuadraticProbing::delete_data (int data)
{
	int index = hash_function (data);
	int loop = 1;
	while (m_hash_table[index] != 0) {
		if (m_hash_table[index] == data) {
			m_hash_table[index] = 0;
			m_entries--;
			cout << "Data " << data << " Found in hash table, deleting !!!" << endl;
			return;
		}
		index = quadratic_probing (index, loop);
		loop++;
	}
	cout << "Data " << data << " Not Found in hash table, nothing to delete !!!" << endl;
}

bool HashingQuadraticProbing::search_data (int data)
{
	int index = hash_function (data);
	int loop = 1;
	while (m_hash_table[index] != 0) {
		if (m_hash_table[index] == data) {
			cout << "Data " << data << " Found in hash table !!!" << endl;
			return true;
		}
		index = quadratic_probing (index, loop);
		loop++;
	}
	cout << "Data " << data << " Not Found in hash table !!!" << endl;
	return false;
}

#endif /* _PRACTICE_HASHING_QUADRATIC_PROBING_H */