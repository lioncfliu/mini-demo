#include <iostream>

class Base
{
public:
    virtual void func() { std::cout<<"Base::func()" <<std::endl; }
};


class Derived1: public Base 
{
public:
    // note: func(int ) will hide Base::func()
    void func(int a) { std::cout<<"Derived1::func(int)" <<std::endl; }
    
    // here is Base::func() inherited from Base.
};


class Derived2: public Derived1
{
public:
    // note: func(int ) will hide Derived1::func(int) 
    void fun(int a) { std::cout<<"Derived2::func(int)" <<std::endl; }
    
    // override Base::func()
    void func() { std::cout<<"Derived2::func()" <<std::endl; }
    
};

int main(int argc, char* argv[]) 
{

    Base b;
    Derived1 d1;
    Derived2 d2;

    Base *pb1 = &b;
    Base *pb2 = &d1;
    Base *pb3 = &d2;

    pb1->func(); // Base::func()
    pb2->func(); // Base::func()
    pb3->func(); // Derived2::func()
    return 0;
}
