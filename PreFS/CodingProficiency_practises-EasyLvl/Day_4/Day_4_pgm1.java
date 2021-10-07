/*
Subrahmanyam is working with numbers
He is given a list of numbers, his task is to find the priority number. 
The priority number is the number that occured more than 'list.length/2' times.

You may assume that the list is non-empty 
and the priority number always exist in the list.

Input Format:
-------------
line-1: an integer N, list size.
line-2: N space separated integers, numbers in the list[].

Output Format:
--------------
An integer, the priority number of the set.


Sample Input-1:
---------------
2
3 2 3

Sample Output-1:
----------------
3


Sample Input-2:
---------------
7
2 2 1 1 1 2 2

Sample Output-2:
----------------
2
*/

import java.util.*;

class Solution{
    public static void main(String [] args)
    {
        Scanner scanner = new Scanner(System.in);
        int length = scanner.nextInt();

        // Elegant solution of O(n)-- Said by sir
        int dominant=0, count=1, temp=0;
        for(int i=0; i<length; i++)
            if(i==0)
                dominant=scanner.nextInt();
            else
            {
                temp = scanner.nextInt();
                if(dominant==temp)
                    count++;
                else if(count==0){
                    dominant=temp;
                    count=1;
                }
                else    // When count>1..
                    count--;
            }
        System.out.println(dominant);
    }
}

/*
via external data-structure.. Takes logn() or nlogn() solution based on internal implementation...
HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
int temp;
for(int i=0; i<length; i++)
{
    temp = scanner.nextInt();
    map.put(temp, map.getOrDefault(temp, 0)+1);
}

//System.out.println(map +"" +(length/2));
for(Map.Entry<Integer, Integer> entry : map.entrySet())
    if(entry.getValue() >= (length/2)+1)
    {
        System.out.println(entry.getKey());
        break;
    }

*/
