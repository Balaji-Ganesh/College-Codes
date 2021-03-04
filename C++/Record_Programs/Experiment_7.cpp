/*Write a C++ program to use scope resolution operator.
 Display the various values of the same variables declared at different scope levels.
 OutPUT:
    Local variables  a: 100, b: 200
    Global variables a: 10, b: 20*/

#include <iostream>
using namespace std;
int a=10, b=20;

int main()
{
    int a=100, b=200;
    cout << "Local variables  a: "<<a <<", b: " << b << endl;
    cout << "Global variables a: "<<::a << ", b: " << ::b;
}