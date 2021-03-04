/*Write a C++ to illustrate the concepts of console I/O operations.\
Output:
Enter Number
12
Enter Character
a
Enter String
asdf
*/

#include <iostream>
using namespace std;

int main()
{
    int num;
    char ch;
    string str;
    cout << "Enter Number" << endl;
    cin >> num;
    cout << "Enter Character" << endl;
    cin >> ch;
    cout << "Enter String" << endl;
    cin >> str;
}  