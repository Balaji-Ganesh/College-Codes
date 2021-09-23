/*
Suman is given two words W1 and W2. 
His task is to derive W2 from W1, with the following operations:
	- Replace all the occurrences of a letter in W1 with any other letter.
	- Repeat the above step to derive  W2 from W1.
	
Your task is to check whether W2 can be derived from W1 or not.
If yes, print 'true', Otherwise print 'false'.

NOTE: You may assume both W1 and W2 have the same length.

Sample Input-1:
-------------------
paper 
title

Sample Output-1:
---------------------
true

Explanation:
----------------
'p' is replaced with 't', 'a' is with 'i', 'e' is with 'l', and 'r' with 'e'.


Sample Input-2:
-------------------
memo 
demo

Sample Output-2:
---------------------
false
*/

/*Braces can be removed to reduce the count of lines, but it helps in understanding in a short go..*/
import java.util.*;

class Solution
{
    static boolean solve(String str1, String str2)
    {
        int len1=str1.length();
        int len2=str2.length();
        HashMap<Character, Character>map = new HashMap<Character, Character>();

        //Logic..
        if(len1!=len2)
            return false;  // If both are of not same length then replacement surely not possible
        else {
            // Rail on both strings.. char by char..
            for(int idx=0; idx<len1; idx++)
            {   // When same... Some probabilty..
                if(map.containsKey(str1.charAt(idx))) // validate existing mapping..
                {
                    if(map.get(str1.charAt(idx)) != str2.charAt(idx))
                       return false;
                }
                else        // for a new char..(to which no mapping done earlier)
                    map.put(str1.charAt(idx), str2.charAt(idx));
            }
        }
        return true;
    }
    public static void main(String ... args)
    {
        Scanner scanner = new Scanner(System.in);
        String str1 = scanner.next();
        String str2 = scanner.next();
        System.out.println(solve(str1, str2));
    }
}
