/*
Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of
islands.

An island is surrounded by water and is formed by connecting adjacent lands 
horizontally or vertically. You may assume all four edges of the grid are all 
surrounded by water.



Input:
Enter Grid size                                                                                                         
4 5                                                                                                                     
Enter Grid  
1 1 1 1 0                                                                                                               
1 1 0 1 0                                                                                                               
1 1 0 0 0                                                                                                               
0 0 0 0 0 
Output: 1
input=
Enter Grid size                                                                                                         
4 5                                                                                                                     
Enter Grid                                                                                                              
1 1 0 0 0                                                                                                               
1 1 0 0 0                                                                                                               
0 0 1 0 0                                                                                                               
0 0 0 1 1                                                                                                               
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

Currently assuming a fact that, if can go from Island A to island B, then reverse is also true. -- this makes the idea of using the square matrix..

*/
#include<iostream>
#include<vector>
using namespace std;

/////////// Global variables..
int disconnected_islands = 0;       // To store no of disconnected islands in the given earth portion..
int max_size=0;                          // To store the max_size of rows and cols
int land_water[10][10];               // To store the matrix.. of lands and water..
bool visited[10];
int rows=10, cols=10;       

int is_visited_fill();
void DFS(int vertex);
int main()
{
    // ///////////////////////////// Setting up the things..///////////////////////
    //vector<vector> land_water;
    cout << "Enter Grid size " << endl;
    cin >> rows >> cols;
    //land_water =  new int[rows][cols];
    
    cout << "Enter Grid "<< endl;
    
    for (int i=0; i<rows; i++)
        for (int j=0; j<cols; j++)
            cin >> land_water[i][j];
     /////////////////////////////////////// done setting up the things.../////////////////
     
    //////// Now start with the logic...
    /// Take the visited list..
    max_size = rows>cols? rows:cols;
    //visited = new bool[max_size];
    for (int i=0; i<max_size; i++)
        visited[i] = false;
    
    ////////////////////////////////////////
    int node=0;
    while (true)
    {
        node = is_visited_fill();       // If got -1 means all are visited.. so stop and print the disconnected_subgraphs count..
        if (node == -1)        
            break;
        else                            // Do the DFS/BFS and try to fill the visited.. and each time we take a new DFS, it means that there is another sub-graph which is disconnected, else by 1 round of DFS would have filled the visited..right..??
        {
            cout << "Doing DFS on "<< node << " as it found to be disconnected " << endl;
            visited[node] = true;
            DFS(node);
            disconnected_islands++;
        }
    }
    cout << "Disonnected sub-Graphs(islands) are: " << disconnected_islands << endl;
}

int is_visited_fill()
{
    /*
        Theme of operation:
            Checks whether the whole visiting is done or not...
            If got any node as un-visited returns that un-visted node value..
            if in case whole array was visited, -1 is returned..
    */
    //bool done_visiting = true;
    for (int i=0; i<max_size; i++)
    {
        if(visited[i] == false)
        {
            // It might so happen that.. if a node is unvisited.. it need not be visited..(as per the given matrix). So idea is, check the row of the unvisited node, if all are zeroes, then it need not be visited..

            //done_visiting = false
            return i;   // Returning the first encountered un-visited vertex...
        }
    }
    return -1;      // Using -1 for whole array visit...
}

void DFS(int vertex)
{
    // If recursion doesn't work out, create by trying expliit stac..
    //visited[j] = true;
    for (int j=0; j<cols; j++)
    {
        if (land_water[vertex][j] == 1 && visited[j] == 0)
        {
            visited[j] = true;
            DFS(j);
        }
    }
}

