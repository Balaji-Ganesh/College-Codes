#include <iostream>
using namespace std;

class B
{
    public:
         void function ()
        {
            cout << "B:function" << endl;
        }
};

class C: public B
{
    public:
        virtual void function()
        {
            cout << "C:function" << endl;
        }
};

class D: public B
{
    public:
        virtual void function()
        {
            cout << "D:function" << endl;
        }

};

int main()
{
    B b, *bptr;
    C c;
    D d;

    bptr = &d;
        bptr->function();
    bptr = &c; 
        bptr->function();
    bptr = &b;
        bptr->function();
}