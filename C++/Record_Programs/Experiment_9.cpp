/*Write a C++ program to create multilevel inheritance. (Hint: Classes A1, A2, A3)
OUTPUT:
enter Roll no and Name                                                                                                  
12                                                                                                                      
laxmi                                                                                                                   
enter three subject marks                                                                                               
11                                                                                                                      
40                                                                                                                      
60                                                                                                                      
Roll NO:12                                                                                                              
name : laxmi                                                                                                            
subject 1:11                                                                                                            
 subject 2 : 40                                                                                                         
subject 3:60                                                                                                            
total = 111                                                                                                             
per  = 37                                                                                                               
div = third  
*/

#include <iostream>
using namespace std;

class A1
{
    protected:
        int rollno, m1, m2, m3;
        string name;
};
class A2: public A1 
{
    public:
        void get_roll_name()
        {
            cout << "enter Roll no and Name" << endl;
            cin >> rollno >> name;
        }
        void get_marks()
        {
            cout << "enter three subject marks" << endl;
            scanf (" %d %d %d", &m1, &m2, &m3);
            //cin >> m1 >> m2 >> m3;
        }
};

class A3:public A2
{
    public:
        void display_details()
        {
            cout << "Roll NO: "<<rollno << endl                                                                                                           
                 << "name : " << name << endl
                 << "subject 1:"<<m1 << endl
                 << "subject 2 :" << m2 << endl
                 << "subject 3:" << m3 << endl
                 << "total = " << (m1 + m2 + m3)   << endl
                 << "per  ="<< (m1 + m2 + m3)/3 << endl
                 << "div = third  " << endl;
        }
};

int main()
{
    A3 obj;
    obj.get_roll_name();
    obj.get_marks();
    
    obj.display_details();
}
