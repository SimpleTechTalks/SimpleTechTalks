#ifndef _PRACTICE_TRIE_DEFINE_H_
#define _PRACTICE_TRIE_DEFINE_H_

#include <iostream>
#include <string.h>

#define LETTER_LENGTH 26
class Trie
{
	public:
		Trie* m_ptr[LETTER_LENGTH];
		bool is_word_complete;
	
	public:
		Trie ();
};

Trie::Trie ()
{
	for (int i = 0; i < LETTER_LENGTH; i++)
	{
		m_ptr[i] = NULL;
	}
}

void insert (Trie* root, char* key)
{
	Trie* temp = root;

	for (int i = 0; i < strlen (key); i++)
	{
		int index = key[i] - 'a';
		if (temp->m_ptr[index]) {
			temp = temp->m_ptr[index];
		} else {
			Trie* next = new Trie();
			temp->m_ptr[index] = next;
			temp = next;
		}
	}
	temp->is_word_complete = true;
}

bool search (Trie* root, const char* key)
{
	Trie* temp = root;

	for (int i = 0; i < strlen (key); i++) {
		if (!temp->m_ptr[(key[i] - 'a')]) {
			return false;
		}
		temp = temp->m_ptr[(key[i] - 'a')];
	}
	return temp->is_word_complete;
}

void print_trie (Trie* root, char* str)
{
	if (root->is_word_complete) {
		std::cout << str << std::endl;
	}

	for (int i = 0; i < LETTER_LENGTH; i++) {
		if (root->m_ptr[i]) {
			char t[40] = {'\0'};
			snprintf (t, sizeof(str)+1, "%s%c", str, (char)('a' + i));
			print_trie (root->m_ptr[i], t);
		}
	}
}

void auto_suggestion (Trie* root, const char* key)
{
	Trie* temp = root;

	for (int i = 0; i < strlen (key); i++) {
		if (!temp->m_ptr[(key[i] - 'a')]) {
			std::cout << "No suggestion found" << std::endl;
			return;
		}
		temp = temp->m_ptr[(key[i] - 'a')];
	}
	if (temp) {
		printf ("Suggestion for %s are: ", key);
		char str[40] = {'\0'};
		snprintf (str, sizeof(key), "%s", key);
		print_trie (temp, str);
	} else {
		std::cout << "No suggestion found" << std::endl;
	}
}
#endif /* _PRACTICE_TRIE_DEFINE_H_ */