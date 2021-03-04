/*Create an Employee Record with employee name,employee id ,employee sal and implement it
using Circular Single Linked List*/
//SAMPLE INPUT OUTPUT TEST CASES
/*INPUT=
Enter no of nodes
3
Enter Employee Id
12
Enter Employee Name
James
Enter Employee Salary
123$
Enter Employee Id
23
Enter Employee Name
John
Enter Employee Salary
23$
Enter Employee Id
67
Enter Employee Name
Jack
Enter Employee Salary
2345$
OUTPUT=
||67,Jack,2345$||->||23,John,23$||->||12,James,123$||->|| Jack ||
 CIRCULAR LIST IS ACHEIVED
*/
#include<stdio.h>
#include<stdlib.h>
struct Emp
{
    int id;
    char name[100],sal[100];
    struct Emp *next;
}*head=NULL,*temp=NULL;
void create();
void display();
void main()
{
    int n;
    printf("Enter no of nodes\n");
    scanf("%d",&n);
    while(n--)
    create();
    display();
}
void create()
{
    struct Emp *ptr=(struct Emp*)malloc(sizeof(struct Emp));
    if(!ptr)
    printf("\nmemory not allocated\n");
    else
    {
        printf("Enter Employee Id\n");
        scanf("%d",&ptr->id);
        printf("Enter Employee Name\n");
        scanf("%s",ptr->name);
        printf("Enter Employee Salary\n");
        scanf("%s",ptr->sal);
        ptr->next=NULL;
    if(head==NULL)
    {
        head=ptr;
        temp=ptr;
        ptr->next=ptr;
    }
    else
    {
        ptr->next=head;
        temp->next=ptr;
        head=ptr;
    }
    }
}
void display()
{
    struct Emp *dtemp;
    dtemp=head;
    while(dtemp!=temp)
    {
        printf("||%d,%s,%s||->",dtemp->id,dtemp->name,dtemp->sal);
        dtemp=dtemp->next;
    }
    printf("||%d,%s,%s||->",dtemp->id,dtemp->name,dtemp->sal);
    dtemp=dtemp->next;
    printf("||%s||",dtemp->name);
    printf("\nCIRCULAR LIST IS ACHEIVED");
}
