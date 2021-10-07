#include <iostream>
#include <string>
#include <map>
#include <string_view>
using namespace std;

int main()
{
    // Read the input..
    string str;
    cin >> str;

    // Logic..
    map<char, int> m;
    int longest_palindrome_len=0, odds_freq=0;
    for(char ch: str)       // Place the chars in map
       m[ch]++;

    // Consider the evens directly (as evens are palindromes)
    for(const auto& [key, value]: m)
        if(value%2==0)
            longest_palindrome_len+=value;
        else{
            odds_freq++;
            //if(value >1) -- not required..
            longest_palindrome_len+=value-1;
        }
    // consider 1 of the odd-freq one to place in the center..
    if(odds_freq>0)
        longest_palindrome_len++;  // Increment it by 1..
    
    // Print the obtained result..
    cout << longest_palindrome_len;

    //Printing map for reference..
    //for(const auto & [key, value]: m)
    //    cout << key <<": " << value << endl;
}

/*
CodingProficiency_practises-EasyLvl

+------------------------------+
|  8 tests run/ 8 tests passed |
+------------------------------+

NOTE: This works if compiler uses = -std=c++17 standard (specify as g++ -stdc++17 value...).
    like: $ g++ -std=c++17 solution.cpp -o solution && ./solution
If of c++14, then no need to specify the flag while compiling.
    and..
            for (auto& t : myMap)
                cout << t.first << " " 
                        << t.second.first << " ";
            fashion for the for-each loop.
*/