#ifndef _PRACTICE_HASHING_DOUBLE_HASHING_H
#define _PRACTICE_HASHING_DOUBLE_HASHING_H

#include "Hashing.h"

class HashingDoubleHashing: public Hashing
{
	public:
		bool disable_log;
		HashingDoubleHashing (int size);
		HashingDoubleHashing (int size, bool log);
		~HashingDoubleHashing ();
		int second_hash_function (int key);
		void insert_data (int data);
		void delete_data (int data);
		bool search_data (int data);
};

HashingDoubleHashing::HashingDoubleHashing (int size): Hashing (size), disable_log (false)
{}

HashingDoubleHashing::HashingDoubleHashing (int size, bool log): Hashing (size), disable_log (log)
{}

HashingDoubleHashing::~HashingDoubleHashing ()
{}

int HashingDoubleHashing::second_hash_function (int key)
{
	return (key % (get_size () - 3));
}

void HashingDoubleHashing::insert_data (int data)
{
	int index = hash_function (data);
	if (m_hash_table[index] != 0) {
		int index_start = index;
		int index_second = second_hash_function (data);
		int count = 1;
		while (m_hash_table[index] != 0) {
			index = (index_start + index_second * count) % get_size ();
			count++;
		}
	}
	m_hash_table[index] = data;
	m_entries++;
}

void HashingDoubleHashing::delete_data (int data)
{
	int index = hash_function (data);
	if (m_hash_table[index] != 0) {
		int index_start = index;
		int index_second = second_hash_function (data);
		int count = 1;
		while (m_hash_table[index] != 0) {
			if (m_hash_table[index] == data) {
				if (!disable_log)
					cout << "Data " << data << " Found in hash table, deleting !!!" << endl;
				m_hash_table[index] = 0;
				m_entries--;
				return;
			}
			index = (index_start + index_second * count) % get_size ();
			count++;
		}
	}
	if (!disable_log)
		cout << "Data " << data << " Not Found in hash table, nothing to delete !!!" << endl;
	return;
}

bool HashingDoubleHashing::search_data (int data)
{
	int index = hash_function (data);
	if (m_hash_table[index] != 0) {
		int index_start = index;
		int index_second = second_hash_function (data);
		int count = 1;
		while (m_hash_table[index] != 0) {
			if (m_hash_table[index] == data) {
				if (!disable_log)
					cout << "Data " << data << " Found in hash table !!!" << endl;
				return true;
			}
			index = (index_start + index_second * count) % get_size ();
			count++;
		}
	}
	if (!disable_log)
		cout << "Data " << data << " Not Found in hash table !!!" << endl;
	return false;
}

#endif /* _PRACTICE_HASHING_DOUBLE_HASHING_H */