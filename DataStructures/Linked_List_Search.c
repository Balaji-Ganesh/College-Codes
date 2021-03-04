/*
#include <stdio.h>

int main()
{
	printf("Hello world");
	return 0;
}*/
/*Program to read an employee data base and find whether employee is existing or not
if empid exist print details of an employee*/
//SAMPLE INPUT AND OUTPUT
/*INPUT=
no of records to be  create
3
Enter Employee Id
12
Enter Employee Name
Alice
Enter Employee Salary
123$
Enter Employee Id
45
Enter Employee Name
Bob
Enter Employee Salary
345$
Enter Employee Id
1
Enter Employee Name
James
Enter Employee Salary
3456$
Enter Employee Id TO Be Searched
45
OUTPUT=
Successful Search And Details Are
||45,Bob,345$||
SAMPLE 2:
INPUT=
no of records to be  create
2
Enter Employee Id
12
Enter Employee Name
watson
Enter Employee Salary
123$
Enter Employee Id
45
Enter Employee Name
Peeter
Enter Employee Salary
234$
Enter Employee Id TO Be Searched
2
OUTPUT=
Employee Record Not Found
*/

#include <stdio.h>
#include <stdlib.h>

// Node Schematic..
struct Node
{
    int empid;
    char salary[10], name[10];
    struct Node *link;
}*head=NULL;

// Global function declarations..
void create_node();
void search_employee_id(int);

int main()
{
    int num_employees=0, empid=0;
    printf("no of records to be  create\n");
    scanf("%d", &num_employees);
    
    // Create those many nodes as said by the user..
    while(num_employees -- )
        create_node();
    
    // Search for an employee based on his/her empid..
    printf("Enter Employee Id To Be Searched\n");
    scanf("%d", &empid);
    search_employee_id(empid);
    
    return 0;
}


// Definitions of Globally declared functions...
void create_node()
{
    struct Node * temp;
    if ( (temp=(struct Node*) malloc(sizeof(struct Node))) == NULL ){
        printf("Not enough storage to create node, please try again later..!!!\n");
        exit(EXIT_FAILURE);
    }
    // Control here, means nod successfully created...
    // Get the data to be filled in the node from the user..
    printf("Enter Employee Id\n");
    scanf("%d", &temp->empid);
    printf("Enter Employee Name\n");
    scanf("%s", temp->name);
    printf("Enter Employee Salary\n");
    scanf("%s", temp->salary);
    
    //temp->link = NULL;
    
    // Now place the node in the list at beg..
    temp->link = head;
    head = temp;
}

void search_employee_id(int empid)
{
    struct Node * temp = head;
    
    while (temp!= NULL)
    {
        if (temp->empid == empid)
        {
            printf("Successfull Search And Details Are\n||%d,%s,%s||", temp->empid, temp->name, temp->salary);
            return;
        }
        temp = temp->link;
    }
    printf("Employee Record Not Found");
}

