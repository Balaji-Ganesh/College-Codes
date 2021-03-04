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

// Node Schematic..
struct Node
{
    int empid;
    char empname[10], empsalary[10];
    struct Node*link;
}*head=NULL;

// Global function declarations..
void create_node();
void display_list();

int main()
{
    int num_nodes=0;
    printf("Enter no of nodes\n");
    scanf("%d", &num_nodes);
    
    // Create the nodes..
    while(num_nodes--)
        create_node();
    
    // Display the list created...
    display_list();
}

// Globally declared function's definitions..
void create_node ()
{
    struct Node *temp;
    if ( (temp=(struct Node *)malloc(sizeof(struct Node))) == NULL ){
        printf("Sorry..!! Not enough memory space, try later...");
        exit(EXIT_FAILURE);
    }
    // Control here, means node is successfully created..
    // Take the data from the user and fill the node..
    temp->link = head;
    printf("Enter Employee Id\n");
    scanf("%d", &temp->empid);
    printf("Enter Employee Name\n");
    scanf("%s", temp->empname);
    printf("Enter Employee Salary\n");
    scanf("%s", temp->empsalary);
    
    // Place the created node in the appropriate position in the list..
    if (head == NULL) // Means, list is empty..
        temp->link=head=temp;
    else                // List contains atleast 1 element...
    {
        //temp->link=head; -- unnecessary as done above..
        // Go till the last node of the list, and update its value with the address of newly inserted node..
        struct Node *traversal = head->link;
        while(traversal->link != head) traversal=traversal->link;
        traversal->link=temp;
        head=temp;
    }
}

void display_list()
{
    struct Node * temp = head;
    while (temp->link!=head)
    {
        printf("||%d,%s,%s||->", temp->empid, temp->empname, temp->empsalary);
        temp = temp -> link;
    }
    printf("||%d,%s,%s||->|| %s ||\n", temp->empid, temp->empname, temp->empsalary, head->empname);
    printf("CIRCULAR LIST IS ACHIEVED");
}