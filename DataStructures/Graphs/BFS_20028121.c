/*
Write a C program to implement BFS using adjacency matrix            

Test Case :

Enter the number of vertices:5                                                                                          
Enter graph data in matrix form:        
    0 1 2 3 4    Deg
    ---------   -----
0 | 0 1 0 0 1     2                                                                                                          
1 | 1 0 1 1 1     4                                                                                                          
2 | 0 1 0 1 0     2                                                                                                          
3 | 0 1 1 0 1     3                                                                                                          
4 | 1 1 0 1 0     3                                                                                                          
Enter the starting vertex:0                                                                                             
BFS traversal is:                                                                                                       
0   1  4  2  3                                                                                                          
	

*/
#include<stdio.h>

int a[5][5] = {
                {0, 1, 0, 0, 1},                                                                                                              
                {1, 0, 1, 1, 1},                                                                                                               
                {0, 1, 0, 1, 0},                                                                                                               
                {0, 1, 1, 0, 1},                                                                                                               
                {1, 1, 0, 1, 0}
            };
int q[20]={},visited[20]={},n,f=-1,r=-1;

void visitedNodes_status()
{
    printf("Status of Visted Nodes: \n");
    for(int i=0; i<n; i++)
        printf("\t* %d -- %d\n", i, visited[i]);
}

void bfs(int nodeValue) 
{
    visitedNodes_status();

    // Explore all the nodes of the nodeValue  i.e., Traverse along the all the columns of the rown named 'nodeValue'
   for (int i=0; i<n; i++)
   {
        printf("Searching a[%d][%d] = %d ", nodeValue, i, a[nodeValue][i]);
        printf (" and visited[%d]=%d\n, ", nodeValue, visited[nodeValue]);
        if(a[nodeValue][i] == 1 && visited[nodeValue] == 0) // i.e., Adjacent node to the nodeValue and it is not yet visited till now..
        {
            // mark as visited..
            visited[nodeValue] = 1;
            // Print that element..
            printf("%d ", nodeValue);
            // Add its adjacent nodes to the queue..
            q[r++] = i;
            printf ("Currently inserted element of queue at rear(%d) is: %2d", r, q[r-1]);
        }
   }
   printf ("Currently element queue\'s at rear(%d) is: %2d\n", r, q[r-1]);
    // Now when done with the SINGLE ROW i.e., single element..
    // Repeat the same task with the other rows too..
    //if (r <= f) // Until the queue becomes empty (Logically as per the queue's front and rear pointers)
    //    bfs(q[f++]);      
}
int main()
{
    int v,i,j;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("Before filling 0\'s\n");
    visitedNodes_status();
    for (i=0;i<n;i++)                  
    {
        visited[i]=0;
    }
    printf("After filling 0\'s\n");
    //visitedNodes_status();

    // Clear the visited-array as by default, it gets initiailized -- done above as visited[20]={}

    printf("Enter graph data in matrix form:\n");
    //for (i=0;i<n;i++)
    //    for (j=0;j<n;j++)
    //        scanf("%d",&a[i][j]);
    printf("Enter the starting vertex:");
    scanf("%d",&v);
    f=r=0;
    q[r]=v;
    printf("BFS traversal is:\n");
    visited[v] = 1;                                     
    printf("%d   ",v);
   
    printf("Before calling BFS: (visited status)\n");
    visitedNodes_status();


    bfs(v);
    printf ("Rear is at: %d, front is at: %2d\n", r, f);
    if(r != n-1)
        printf("BFS is not possible");
    
    printf("\nStatus of the Queue: \n");
    for (int i=0; i<=20; i++)
        printf("\t * %d - %d\n", i, q[i]);    
}
