#include <iostream>
#include "TrieDefine.h"

using namespace std;

int main ()
{
	char keys[][20] = {"this", "is", "sparta", "these", "thief", "there"};

	Trie* root = new Trie ();

	int entries = sizeof (keys)/ sizeof (keys[0]);
	cout << entries << " " << keys[0][1] << " " << keys[1] << endl;
	for (int i = 0; i < entries; i++) {
		insert (root, keys[i]);
	}
	cout << "Search key: this, found " << search (root, "this") << endl;
	cout << "Search key: is, found " << search (root, "is") << endl;
	cout << "Search key: madness, found " << search (root, "madness") << endl;
	cout << "Search key: sparta, found " << search (root, "sparta") << endl;
	auto_suggestion (root, "th");
}