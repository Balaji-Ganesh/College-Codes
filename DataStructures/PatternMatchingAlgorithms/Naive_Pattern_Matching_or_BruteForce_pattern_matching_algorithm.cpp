#include <iostream>
#include <cstring>
using namespace std;

// Global declaration of the functions..
void bruteforce_match(string text, string pattern);

int main()
{
    string text, pattern;
    
    // Get the text..
    cout << "Enter the TEXT: ";
    getline(cin, text);
    // Get the pattern..
    cout << "Enter the PATTERN to be matched: ";
    getline(cin, pattern);

    cout << pattern[3];

    bruteforce_match(text, pattern);
}

// Definition of the Globally declared functions..
void bruteforce_match(string text, string pattern)
{
    int text_length = text.length();
    int pattern_length = pattern.length();
    int j=0;

    cout <<"Length of the T string: "<< text_length <<endl
         << "Length of the Pattern string: " << pattern_length << endl;

    for (int i=0; i<= text_length-pattern_length; i++)
    {
        j=0;
        //cout << "i = " << i+j << "  j = " << j<< "  " << text[i+j] << " == " << pattern[j] << " = "<<(text[i+j] == pattern[j]) << endl;
        //if (text[i+j] == pattern[j++])             /// Here 1st character checking of the pattern happens.. if matched, enters body and searches for
        //{
            while (j<pattern_length && text[i+j] == pattern[j++]) 
            {
               // cout << "---i = " << i+j << " j = " << j<< "  " << text[i+j] << " == " << pattern[j] << " = "<<(text[i+j] == pattern[j]) << endl;
               ;
            }
            //cout << "Checking for text[i-pattern_length] == pattern[0]" << text[i-pattern_length] << " == " << pattern[0] << (text[i-pattern_length] == pattern[0]) << endl;
            if (text[(i+j)-pattern_length] == pattern[0])
                cout << "Pattern found at index: " << i<< endl;
        //}
    }
}d