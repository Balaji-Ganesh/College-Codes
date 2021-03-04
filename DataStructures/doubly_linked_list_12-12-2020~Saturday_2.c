/*Ritiesh has learned new techniques of impementing the data structures for
linked list .As a part of this he started desing set of nodes with some infromation
where we can either pick the previous information or the pick the next information
if the node is last it has nothing to pick up at previous or next
now lets help ritish to solve this problem by using best Data Structure*/
/*Design a code which solves ritish query*/
/*SAMPLE INPUT AND OUTPUT*/
/*input:
Enter No Of Nodes To Be Created                                                                                         
5                                                                                                                       
Enter Data                                                                                                              
GoodMorning!!!                                                                                                          
Enter Data                                                                                                              
James                                                                                                                   
Enter Data                                                                                                              
Mr.                                                                                                                     
Enter Data                                                                                                              
!                                                                                                                       
Enter Data                                                                                                              
Hello    
output
NULL<-Hello ! Mr. James GoodMorning!!! ->NULL 
*/

#include <stdio.h>
#include <stdlib.h>

// Node Schematic..
struct Node
{
    char data[20];
    struct Node * prev, *next;
}*head=NULL;

// Global prototyping of functions..
void insert_node();
void display_list();

int main()
{
    int num_nodes=0;
    printf("Enter No Of Nodes To Be Created \n");
    scanf("%d", &num_nodes);
    
    // Place the nodes in the list..    
    while(num_nodes --)
        insert_node();
    
    // Display the list created..
    display_list();
}

// Definition of globally prototyped functions..
void insert_node()
{
    struct Node *temp = (struct Node*)calloc(1, sizeof(struct Node));
    if(!temp){
        printf("Unable to create node due to insufficient storage, Please try later...!!");
        exit(EXIT_FAILURE);
    }
    // Program Control here.... means node has successfully created..
    // Take the data from the user and place it in the node created..
    printf("Enter Data\n");
    scanf("%s", temp->data);
    temp->next = temp->prev = NULL;
    
    // Place the node in the appropriate position..
    if(head == NULL)            // Means, list is empty..
        head = temp;
    else                        // ... List has atleast 1 node..
    {
        temp->next = head;      // Establishing link b/w the newly node created and the currently 1st  node of the list..
        head->prev = temp;      // ...                       currently 1st node of the list to the newly created node..
        head = temp;            // Making the head to point to the newly created node. Now the newly created node becomes the 1st node of the list..
    }
}

void display_list()
{
    struct Node* temp = head;
    printf("NULL<-");
    while(temp!=NULL)
    {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("->NULL");
}