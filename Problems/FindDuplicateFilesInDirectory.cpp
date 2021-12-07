#include <iostream>
#include <map>

using namespace std;

char files[][80][80] = {{"1.txt", "abcd"},
						{"2.txt", "efgh"},
						{"3.txt", "efgh"},
						{"4.txt", "abcd"},
						{"5.txt", "efgh"},
						{"6.txt", "efgh"},
						{"7.txt", "xyz"}
					   };

int main ()
{
	int size = sizeof(files)/sizeof(files[0]);
	cout << "Size: " << size << endl;
	for (int i = 0; i < size; i++) {
		printf ("%s -- %s\n", files[i][0], files[i][1]);
	}
	map <size_t, string> file_content;
	for (int i = 0; i < size; i++) {
		size_t hash_id = hash<string>{} (files[i][1]);

		map <size_t, string>::iterator it = file_content.find (hash_id);
		if (it != file_content.end ()) {
			cout << "Duplicate file found: " << files[i][0] << " and " << it->second << endl;
			continue;
		}
		file_content.insert ({hash_id, files[i][0]});
	}
}