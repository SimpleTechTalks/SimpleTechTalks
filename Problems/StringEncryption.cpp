/**********************************************************************************************
 * 
 * Given a string ‘s’ and a number ‘n’, write a function that returns a string with each 
 * character in s replaced with another character that is ‘n’ positions down the alphabet. 
 * 
 * If n is 1, A is replaced with B, B is replaced with C and so on. 
 * If n is 2, A is replaced with C, B is replaced with D and so on.    
 * 
 *********************************************************************************************/

#include "iostream"
#include "string.h"

using namespace std;
void string_encoder (const char* input, int n, char* output)
{
    int len = strlen (input);

    if (len == 0) {
        cout << "Empty String Received !!" << endl;
    }

    int mod_n = n % 26;
    for (int i = 0; i < len; i++) {
        output[i] = input[i] + mod_n;
        if (output[i] > 'Z') {
            output[i] = output[i] - 'Z' + 'A' - 1;
        }
    }
}

void string_decoder (const char* output, int n)
{
    int len = strlen (output);

    if (len == 0) {
        cout << "Empty String Received !!" << endl;
    }

    int mod_n = n % 26;
    for (int i =0; i < len; i++) {
        char c = output[i] - mod_n;
        if (c < 'A') {
            c = 'Z' - ('A' - c) + 1;
        }
        cout << c;
    }
    cout << endl;
}

int main ()
{
    char str[50] = {0};
    char output[50] = {0};
    int n = 0;
    cout << "Input String " << endl;
    cin >> str;
    cout << "Input value of n" << endl;
    cin >> n;

    cout << "Input  String: " << str << endl;
    string_encoder (&str[0], n, &output[0]);
    cout << "Encoded String: " << output << endl;
    cout << "Decoded String: " ;
    string_decoder (output, n);
}

/*
Input String 
ACF
Input value of n
1
Input  String: ACF
Encoded String: BDG
Decoded String: ACF

Input String 
AXZ
Input value of n
1
Input  String: AXZ
Encoded String: BYA
Decoded String: AXZ

Input String 
AGI
Input value of n
26
Input  String: AGI
Encoded String: AGI
Decoded String: AGI

Input String 
AXY
Input value of n
27
Input  String: AXY
Encoded String: BYZ
Decoded String: AXY
*/