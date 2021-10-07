/*
There are N persons in the room, each person is paired with other person except one.
Every person is identified with an ID number, and every pair will have same ID number.

You will be given the ID's of N persons as a list[].
Your task is to find the person ID, who is not paired with anyone in the room.

Can you solve this problem in O(N) time complexity?


Input Format:
-------------
Line-1: An odd integer N, number of people.
Line-2: N space separated integers, the list[].

Output Format:
--------------
Print an integer result.


Sample Input-1:
---------------
5
5 3 4 5 3

Sample Output-1:
----------------
4


Sample Input-2:
---------------
7
8 2 6 8 3 2 6

Sample Output-2:
----------------
3

*/


import java.util.*;
class Solution{
    public static void main(String [] args)
    {
        // Dealing with the input section..
        Scanner scanner= new Scanner(System.in);
        int num = scanner.nextInt();
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        int temp;
        for(int i=0; i<num; i++){
            temp = scanner.nextInt();
            map.put(temp, (int)(map.getOrDefault(temp, 0))+1);
        }
        
        // Logic..
        //System.out.println(map);
        for(Map.Entry<Integer, Integer> e: map.entrySet())
            if(e.getValue() == 1)
                System.out.println(e.getKey()); // Get the key having value(occurances)=1
    }
}

/*
Summary of tests

+------------------------------+
|  8 tests run/ 8 tests passed |
+------------------------------+

*/
