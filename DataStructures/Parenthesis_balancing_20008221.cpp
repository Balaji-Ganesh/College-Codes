/* C++ program to check an expression is balanced or not
Test case 1:
Enter expression
(){()}{}
expression is balanced

Test case 2:
Enter expression
({){}()
expression is not balanced
*/

#include<iostream> 
#include <stack>
using namespace std; 

stack<char> balance_stack;
bool is_balanced = false;

int main()
{
    // Get the string data from the user..
    string expr="";
    cout << "Enter a string to check for the balancing of parenthisis: ";
    cin >> expr;

    // Now parse the string (expression)..
    // Push when encountered { or (  or [ ..
    // When encountered } or ) or ], should get its respetive opening. If cannot means some unbalanceness is in the entered expression..
    char temp;
    
    // Parse the entered expresssion and perform appropriate action..
    for (int i=0; i<expr.length(); i++)
    {
        if (expr[i] == '{' || expr[i] == '(' || expr[i] == '[')     // If open parenthesis, push to the stack..
        {
            balance_stack.push(expr[i]);
        }
        if (expr[i] == '}' || expr[i] == ')' || expr[i] == ']')
        {
            temp = balance_stack.top();
            balance_stack.pop();
            switch(expr[i])     // check whether the exact matching is encountered or not
            {
                case '}': if (temp == '{')
                             is_balanced=true;
                          break;
                case ')': if (temp == '(')
                            is_balanced=true;
                          break;
                case ']': if (temp == '[')
                            is_balanced=false;
            }
        }
    }
    
    if (balance_stack.empty() && is_balanced == true)
        cout << "expression is balanced";
    else
        cout << "expression is not balanced";
    return 0;    
}
