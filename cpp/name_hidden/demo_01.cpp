#include <iostream>


class Base 
{
public:
    void func() {}
};


class Derived: public Base
{
public:
    void func(int a) {}
};

int main(int argc, char* argv[]) 
{

    Derived d;
    d.func(); //compile error, Derived::func(int) hides Base::func(), then params dose not match , need `int` but void was given
    d.func(1); // OK
    return 0;
}
