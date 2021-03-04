#include <stdio.h>
#include <stdlib.h>

// Global function declarations..
int * divide_and_conquer(int *array, int left, int right);
int * conquer(int *array, int left, int mid, int right);
void displayArray(int array[]);

// main function starts from here..
int main(int argc, char ** argv[])
{
    /* Take the size of the array to be created.. */
    int size=0, *array=NULL, temp=0;
    // Get the size of the array..
    printf ("Enter the size of the array to be created: ");
    scanf ("%d", &size);
    // Create the array of the required size..
    array = (int *) malloc(size * sizeof(int));

    // Get the array elements..
    for (int i=0; i<size; i++)
    {
        printf("Element-%d: ", i+1);
        scanf("%d", &temp);
        *(array+i) = temp;
    }

    // Sort the array..
    array = divide_and_conquer(array, 0, size-1);

    // Display the sorted array..
    for (int i=0; i<size; i++)
        printf ("%3d", *(array+i));

    printf("\nThanks for utilizing our service.. !! Have a good day..");
}

// Definition of the Globally declared functions....
int * divide_and_conquer(int *array, int left, int right)
{
    if (left != right)  // Base condition of the recursion..
    {
        /*  PHASE-1: Divide the array.. */
        // Get the mid-index of the array to divide into half..
        int mid = (left+right)/2;
        //printf ("left = %d, mid=%d, right=%d\n", left, mid, right);
        //scanf("%d");
        //printf("....\n");
        // Start Dividing the left part..
        divide_and_conquer(array, left, mid);       // Further divide the LEFT-PART..
        divide_and_conquer(array, mid+1, right);    // Further divide the RIGHT-PART..
        
        // Display the sorted array..
        printf("---Elements in the array: (L:%d, R:%d) ", left, right);
        for (int i=left; i<right; i++)
            printf ("%3d", *(array+i));
        printf("\n ---   - - - - -         -------\n");

        // PHASE-2: Conquer the array..
        conquer(array, left, mid, right);

        // Return the sorted array.. (Can be either partially-sorted array or the completely sorted array)
        return array;
    }
}

int * conquer(int *array, int left, int mid, int right)
{
    // Create the temporary to store the elements..
    int * temp_arr  =malloc(sizeof(int)*(right-mid));
    // Temporary pointer holders to keep track of the progress in both left, right and temporary arrays..
    int i=left, j=mid, k=0;

    while (i<=mid && j<=right)              // FOCUS -- Used LOGICAL-AND, which gets failed, either any one array has completed...
    {
        if(array[i] <= array [j])
            *(temp_arr+k++) = array[i++];
        else
            *(temp_arr+k++) = array[j++];
    }
    printf("In conquer: i=%d, j=%d, k=%d\n", i, j, k);
    // If in case any array has left over... if no one, then no while loop executes...
    while (i<=mid)          // If in case, Left array has not completed.. Simply dump the elements of this array to the temp_array as it is already sorted..
        *(temp_arr+k++) = array[i++];
    while (j<=right)        //  ... .... . right ..  .            . . . ........
        *(temp_arr+k++) = array[j++];   
    
    return temp_arr;        // Return the sorted array..
}