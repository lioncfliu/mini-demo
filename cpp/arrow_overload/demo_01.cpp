/**
 * @brief overload `->`, how dose it work .
 * Referrence to http://blog.chinaunix.net/uid-28541347-id-4209641.html
 * 
 * */

#include <iostream>

class A 
{
public:
    void action() { std::cout<<"Action in class A !" <<std::endl; }    
};


class B
{
public:
    void action() { std::cout<<"Action in class B !" <<std::endl; }
    A* operator->() { return &a; }
private:
    A a;
};

class C 
{
public:
    void action() { std::cout<<"Action in class C !" <<std::endl; }
    B operator->() { return b; }
private:
    B b;
};


int main(int argc, char* argv[]) 
{
    C *c_ptr = new C;
    c_ptr->action(); //ptr,  default, call C::action()
    
    C c;
    c->action();  //  obj, -> override, call C::operator->()

    delete c_ptr;
    c_ptr = NULL;
    return 0;
}
