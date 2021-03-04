/*Given that an EMPLOYEE class contains following members: data members: Employee number, Employee name, Basic, DA, IT, Net Salary and print data members.  
Output:
Enter employee number: 100
Enter employee name: sunny
Enter employee basic: 25000
Enter employee da: 4000
Enter employee IT: 6000

Details of   :  sunny
Employee number:      100
Basic salary     :  25000
Employee DA      :  4000
Income Tax       :  6000
Net Salary       :  23000 */
#include<iostream>
//#include<conio.h>
using namespace std;
class Employee
{
	int   emp_num;
	char  emp_name[20];
	float emp_basic;
	float emp_da;
	float emp_it;
	float net_sal;
	public:

		void get_details();
		void find_net_sal();
		void show_emp_details();
};

void Employee :: get_details()
{
	cout<<"Enter employee number: ";
	cin>>emp_num;
	cout<<"Enter employee name: ";
	cin>>emp_name;
	cout<<"Enter employee basic: ";
	cin>>emp_basic;
	cout<<"Enter employee da: ";
	cin>>emp_da;
	cout<<"Enter employee IT: ";
	cin>>emp_it;
}

void Employee :: show_emp_details()
{
	cout<<"\n\n\nDetails of   :  "<<emp_name;
	cout<<"\n\nEmployee number:      "<<emp_num;
	cout<<"\nBasic salary     :  "<<emp_basic;
	cout<<"\nEmployee DA      :  "<<emp_da;
	cout<<"\nIncome Tax       :  "<<emp_it;
	net_sal=(emp_basic+emp_da)-emp_it;
	cout<<"\nNet Salary       :  "<<net_sal;
}

int main()
{
    	Employee emp;
	emp.get_details();
	emp.show_emp_details();
	//getch();
	return 0;
}



