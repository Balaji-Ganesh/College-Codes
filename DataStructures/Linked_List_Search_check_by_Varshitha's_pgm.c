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
#include<stdio.h>
#include<stdlib.h>
struct Emp 
{
    int id,value;
    char name[10],sal[10];
    struct Emp *next;
}*head=NULL;
void create();
void display();
void search(int value);
void main()
{
    int n,value;
    printf("no of records to be create\n");
    scanf("%d",&n);
    while(n--)
    create();
    printf("Enter Employee Id TO Be Searched\n");
    scanf("%d",&value);
    search(value);
}
void create()
{
    struct Emp *temp=(struct Emp*)malloc(sizeof(struct Emp));
    if(!temp)
    printf("\nmemory not allocated\n");
    else
    {
        printf("Enter Employee Id\n");
        scanf("%d",&temp->id);
        printf("Enter Employee Name\n");
        scanf("%s",temp->name);
        printf("Enter Employee salary\n");
        scanf("%s",temp->sal);
        if(head==NULL)
        {
            temp->next=NULL;
            head=temp;
        }
        else
        {
            temp->next=head;
            head=temp;
        }
    }
}
void search(int value)
{
    int flag=0;
    struct Emp *dtemp=head;
    while(dtemp!=NULL)
    {
        if(value==dtemp->id)
        {
            flag++;
            break;
        }
        else
        {
            flag=0;
        }
        dtemp=dtemp->next;
    }
    if(flag!=0)
    {
        printf("Successful Search And Details Are\n||%d,%s,%s||",dtemp->id,dtemp->name,dtemp->sal);
    }
    else
    {
        printf("Employee Record Not Found");
    }
}
