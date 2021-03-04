
/*write a C++ program to evaluate value of a postfix expression 
Test case:
i/p: 231*+9- 
o/p: -4
*/
#include <iostream> 
#include <stack>
//#include <sstream>
using namespace std; 

stack <int> evaluation_stack;


int main() 
{ 
    string postfix_expr;
    cin >> postfix_expr;
    int temp=0, operand1=0, operand2=0;
    for (int i=0; i<postfix_expr.length(); i++)
    {
        if ( !(postfix_expr[i] == '+' || postfix_expr[i] == '-' || postfix_expr[i] == '*' || postfix_expr[i] == '/'))
        {
            //stringstream intVal(postfix_expr[i]);
            //intVal >> temp;
            //snprintf(temp, "%d", postfix_expr[i]);
            temp = postfix_expr[i] - '0';
            //cout << temp << endl;
            evaluation_stack.push(temp);
        }
        else
        {
            operand2 = evaluation_stack.top();
            evaluation_stack.pop();
            operand1 = evaluation_stack.top();
            evaluation_stack.pop();
            
            switch (postfix_expr[i])
            {
                case '+': evaluation_stack.push(operand1+operand2);
                          break;
                case '-': evaluation_stack.push(operand1-operand2);
                          break;
                case '*': evaluation_stack.push(operand1*operand2);
                          break;
                case '/': evaluation_stack.push(operand1/operand2);
                          break;
            }
        }
    }
	cout << evaluation_stack.top();
	evaluation_stack.pop();
   	return 0;
}

