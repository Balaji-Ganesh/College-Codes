/*Write a C++ program to allocate memory using new operator.
INPUT:
Enter total number of students: 2                                                                                       
Enter GPA of students.                                                                                                  
Student1: 12                                                                                                            
Student2: 13                                                                                                            
 OUTPUT:                                                                                                                       
Displaying GPA of students.                                                                                             
Student1 :12                                                                                                            
Student2 :13
*/

#include <iostream>
using namespace std;

int main()
{
    int num=0, *student1 = new int, *student2 = new int, temp;
    cout << "Enter total number of students:";
    cin >> num;
    cout << "Enter GPA of students." << endl <<"Student1: ";
    cin >> temp;
    *student1 = temp;
    cout << "Student2: " ;
    cin >> temp;
    *student2 = temp;
    
    cout << "Displaying GPA of students. " << endl;
    cout << "Student1 :" << *student1 << endl
         << "Student2 :" << *student2 << endl;
}