#include <iostream>
#include <stdexcept>    // As using the standard errors - "runtime_error"
using namespace std;

void function3 ()
{
    cout << "function3: Inside the function-3 .. throwing an exception ..." << endl;
    throw runtime_error ("function-3 throwing the runtime error..");
    cout << "After \"throw\" in function3.." << endl;                   // Will not get executed..
}

void function2()
{
    cout << "function2: Calling function-3 .." << endl;
    function3 ();
    cout << "function2: Termination from the function-2..." << endl;    // Will not get executed..
}

void function1()
{
    cout << "function1: Calling function-2.." << endl;
    function2();
    cout << "fucntion1: Termination from the function-1" << endl;   // will not get executed..
}


int main()
{
    try
    {

        cout << "Calling the function1 from the main.." << endl;
        function1();
        cout << "After the call of the function1" << endl;          // Will not get executed....
    }
    catch (runtime_error excep)
    {
        cout << "Caught the runtime exception in the main.." << endl;
        cout << "ERROR-MSG: " << excep.what() << endl;
    }
}

/*

        Output:
    ---------------
        Calling the function1 from the main..
        function1: Calling function-2..
        function2: Calling function-3 ..
        function3: Inside the function-3 .. throwing an exception ...
        Caught the runtime exception in the main..
        ERROR-MSG: function-3 throwing the runtime error..
    --
        Observe..!!
        ------------
        * Can notice that, after "throw" in the function-3, other statements which are in the function-3 are not executed..
            the same story repeated for the function1(), function2(), function3() and even main()
*/