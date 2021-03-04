/*Write a C++ program to read the data of N employee and compute Net salary of each employee (DA=52% of Basic and Income Tax (IT) =30% of the gross salary).

Output:
Enter the number of employees
2
Enter employee name
Sruthi
Enter employee basic salary
60000
Enter employee name
Kruthi
Enter employee basic salary
50000
Employee Details
Emp_Num NAME    Basic salary    DA      Gross salary    Net sal
1       Sruthi          60000   31200           91200   63840
2       Kruthi          50000   26000           76000   53200 */
#include <iostream>  
#include <stdlib.h>  
 using namespace std;  
 class employee  
 {  
 private:  
     char name[10];  
     float da,sal,it,net_sal,gross_sal;  
 public:void read();  
     void display();  
     void calnet_sal();  
     };  
  void employee::read()  
  {  
 cout<<"Enter employee name\n";  
  cin>>name;  
  cout<<"Enter employee basic salary\n";  
  cin>>sal;  
  }  
  void employee::calnet_sal()  
  {  
    da=0.52 * sal;  
    gross_sal=da + sal;  
    it=0.3 * gross_sal;  
    net_sal=gross_sal - it;  
    }  
    void employee::display()  
    {  
    static int count;  
    count=count+1;  
    cout<<count<<"\t"<<name<<"\t\t"<<sal<<"\t"<<da<<"\t\t"<<gross_sal<<"\t"<<net_sal<<endl;  
     }  
 int main()  
 {  
  employee emp[10];  
  int i,n;  
  cout<<"Enter the number of employees\n";  
  cin>>n;  
  for(i=0;i<n;i++)  
  {  
  emp[i].read();  
  emp[i].calnet_sal();  
  }  
  cout<<"Employee Details\n";  
  cout<<"Emp_Num\tNAME\tBasic salary\tDA\tGross salary\tNet sal\n";  
  for(i=0;i<n;i++)  
  {  
  emp[i].display();  
  }  
    //system("PAUSE");  
    return 0;  
 }  