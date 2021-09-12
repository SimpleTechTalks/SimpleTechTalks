/**********************************************************************
 * 
 * Given an input string of characters write a function that returns 
 * another string that has the frequency of each consecutive character
 * followed by the character itself.
 * eg:
 * aabbbbbzzzzzzzzzz
 * 2a5b10z
 * 
 * *******************************************************************/
#include "iostream"
#include "string.h"

using namespace std;
void string_compression (const char* input, char* output)
{
    int len = strlen (input);
    if (len == 0) {
        cout << "Empty String received !!" << endl;
        return;
    }

    int index = 0;
    int count = 1;
    for (int i = 0; i < len; i++)
    {
        if (input[i+1] == '\0') {
            cout << input[i] << count << endl;
            output[index++] = input[i];
            output[index++] = count + '0';
        }
        else if (input[i] == input[i+1]) {
            count++;
        } else {
            cout << input[i] << count;
            output[index++] = input[i];
            output[index++] = count + '0';
            count = 1;
        }
    }
}

void string_compression_reversal (const char* output)
{
    int len = strlen (output);
    if (len == 0) {
        cout << "Empty String received !!" << endl;
        return;
    }

    int index = 0;
    while (output[index] != '\0') {
        char c = output[index++];
        int count = output[index++] - '0';
        while (count != 0) {
            cout << c;
            count--;
        }
    }
    cout << endl;
}

int main ()
{
    char str[50] = {0};
    char output[100] = {0};
    cout << "Input String " << endl;
    cin >> str;

    cout << "Input  String: " << str << endl;
    cout << "Output String: ";
    string_compression (&str[0], &output[0]);
    cout << "Saved Compressed String: " << output << endl;
    cout << "Regenerated String: " ;
    string_compression_reversal (output);
}

/* Sample Output

Input String 
aaabbffffggay
Input  String: aaabbffffggay
Output String: a3b2f4g2a1y1
Saved Compressed String: a3b2f4g2a1y1
Regenerated String: aaabbffffggay

Input String 
aggggggggg
Input  String: aggggggggg
Output String: a1g9
Saved Compressed String: a1g9
Regenerated String: aggggggggg

Input String 
abcdefgh
Input  String: abcdefgh
Output String: a1b1c1d1e1f1g1h1
Saved Compressed String: a1b1c1d1e1f1g1h1
Regenerated String: abcdefgh

*/