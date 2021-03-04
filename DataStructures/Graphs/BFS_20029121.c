#include <stdio.h>

/*  ------  Global Declarations ----*/ 
int adj_matrix[20][20]={}, visited[20]={}, queue[20]={}, front=0, rear=0, n=0;

void BFS(int node);
void fill_matrix();
void visited_nodes_status();

int main()
{
    fill_matrix();
    int root_node=0;
    printf ("Enter the root node: ");
    scanf ("%d", &root_node);

    visited[root_node ] = 1;
    //printf ("Before call to the BFS\n");
    //visited_nodes_status();
    printf ("%3d", root_node);
    BFS(root_node);
    //printf ("After call to the BFS\n");
    //visited_nodes_status();
}

/* -- Definition of Globally declared functions -- */
void fill_matrix()
{
    int node_degree=0, temp_val=0;
    printf("Enter the size of the matrix: ");
    scanf ("%d", &n);
    for (int i=0; i<n; i++)
    {
        printf ("Degree of node-%d: ", i);
        scanf ("%d", &node_degree);
        for (int j=0; j<node_degree; j++)
        {
            printf ("  - Element-%d of %d: ", j, i);
            scanf ("%d", &temp_val);
            adj_matrix[i][temp_val] = 1;
        }
    }

    printf("Filled matrix as: \n");
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            printf(" %2d ", adj_matrix[i][j]);
        printf ("\n");
    }
}

void visited_nodes_status()
{
    int k=0;
    printf("Status of the Visited nodes: \n ---idx---|--Status--\n");

    for(int k=0; k<n; k++)
        printf (" ----%d----|--%d--\n", k, visited[k]);
}

void BFS(int root_node)
{
    // Explore all the nodes of the nodeValue  i.e., Traverse along the all the columns of the rown named 'nodeValue'
    for (int i=0; i<n; i++)
    {
        //printf ("adj_matrix[%d][%d] = %d -- visited[%d]=%d\n", root_node, i, adj_matrix[root_node][i], i, visited[i]);
        if (adj_matrix[root_node][i] == 1 && visited[i] == 0)
        {
            // Print that element..
            printf("-- \t%3d--\t\n", i);
            // Mark as visited..
            visited[i] = 1;
            // Push its adjacents to the queue..
            queue[rear++] = i;
            //printf ("Added %2d to the queue (Status: queue[rear(%2d)]=%3d)\n", i, rear, queue[rear]);
        }
    }
    // Now when done with the SINGLE ROW i.e., single element..
    // Repeat the same task with the other rows too..
    if (front <= rear) // Until the queue becomes empty (Logically as per the queue's front and rear pointers)
        BFS(queue[front++]);
}
