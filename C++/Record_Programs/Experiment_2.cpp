/*Write a C++ program to declare Struct. Initialize and display contents of member variables.

Output:
Enter Full name: Ram                                                                                        
Enter age: 15                                                                                               
Enter salary: 200000                                                                                        
 output                                                                                                   
Displaying Information.                                                                                     
Name: Ram                                                                                                   
Age: 15                                                                                                     
Salary: 200000 */

#include <iostream>
using namespace std;

struct Person
{
    char name[50];
    int age;
    float salary;
};

void displayData(Person);   // Function declaration

int main()
{
    Person p;

    cout << "Enter Full name: ";
    cin.get(p.name, 50);
    cout << "Enter age: ";
    cin >> p.age;
    cout << "Enter salary: ";
    cin >> p.salary;
    displayData(p);
    return 0;
}

void displayData(Person p)
{
    cout << "\nDisplaying Information." << endl;
    cout << "Name: " << p.name << endl;
    cout <<"Age: " << p.age << endl;
    cout << "Salary: " << p.salary;
}
