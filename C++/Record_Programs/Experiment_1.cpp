/*Write a C++ Program to display Names, Roll No., and grades of 3 students who have appeared in the examination. Declare the class of name, Roll No. and grade. Create an array of class objects. Read and display the contents of the array.
Output:
Enter no of students :3                                                         
Enter rollno, name & 3 subject marks         
501                                           
ram                                                                             
78 75 72        
502                                                                     
sam                                                                             
85 89 93    
503                                                                        
gita                                                                            
76 80 84  	
Rollno Name GPA
501 ram 7.5                                                                    
502 sam 8.9                                                                         
503 gita 8    

What to do?
    * Create a class that groups the required variables and functions to handle those variables.
    * Create those no. of objects as requested by the user to create.
    * Use appropriate functions at the appropriate time and give the required output.
*/                        

#include <iostream>
using namespace std;

class Student
{
    string name;
    int rollno, marks[3];
    double GPA;
    public:
        void get_data();
        void print_data();
};

void Student :: get_data()
{
    cin >> rollno >> name >> marks[0] >> marks[1] >> marks[2];
    GPA = ((marks[0] + marks[1] + marks[2]) / 3)/10;
    printf("%f", GPA);
}

void Student :: print_data()
{
    cout << rollno << " " << name << " " << GPA << endl;
}

int main()
{
    int num=0;
    cout << "Enter no of students :";
    cin >> num;
    cout << "Enter rollno, name & 3 subject marks  " << endl;
    Student students[num];
    
    for (int i=0; i<num; i++)
        students[i].get_data();
    
    cout << "Rollno Name GPA" << endl;
    for (int i=0; i<num; i++)
        students[i].print_data();
}
