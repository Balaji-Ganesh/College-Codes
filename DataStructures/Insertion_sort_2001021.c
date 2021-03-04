/* Write a program that implements the Insertion sort to sort a given list of integers in ascending order
Sample Test Case:

Enter number of elements
5
Enter 5 integers
98 32 5 12 54
Sorted list :
5 12 32 54 98
*/

#include <stdio.h>
 
int main()
{
  int n, array[100], i, d, temp;
 
  printf("Enter number of elements\n");
  scanf("%d", &n);
 
  printf("Enter %d integers\n", n);
 
  for (int i=0; i<n; i++)
        scanf ("%d", &array[i]);
    
    for (int i=0; i<n; i++)
    {
        temp = array[i+1];
        for (int j=i; j>=0; j--)
        {
            if (array[j+1] < array[j])
            {
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
    printf ("Sorted list :\n");
    for (int i=0; i<n; i++)
        printf ("%d ", array[i]);
 
  return 0;
}
