/*
    What is added in this version-2?
        * Tried by checking some unrelated catch blocks in the functions where the parent function of the exception(throw) is raised.
        * let's see what will happen now.. and record those observations..

*/

#include <iostream>
#include <stdexcept>    // As using the standard errors - "runtime_error"
using namespace std;

void function3 ()
{
    cout << "function3: Inside the function-3 .. throwing an exception ..." << endl;
    try
    {
        throw runtime_error ("function-3 throwing the runtime error..");
    }
    catch (int excep)
    {
        cout << "function3: \"int\" type exception has caught.." << endl;
    }
    cout << "After \"throw\" in function3.." << endl;                   // Will not get executed..
}

void function2()
{
    cout << "function2: Calling function-3 .." << endl;
    try
    {
        function3 ();
    }
    catch (float excep)
    {
        cout << "function2: \"float\" type exception has caught.,," << endl;
    }
    cout << "function2: Termination from the function-2..." << endl;    // Will not get executed..
}

void function1()
{
    cout << "function1: Calling function-2.." << endl;
    try
    {
        function2();
    }
    catch (string excep)
    {
        cout << "function1: \"string\" type exception is been caught";
    }
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
        * The same happens in this case too..as happened in the default version (i.e., version-1)
*/