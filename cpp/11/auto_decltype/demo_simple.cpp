#include <iostream>
#include <vector>

void demo_auto_01() 
{
    auto a = 0; // int
    auto b = 'a'; // char
    auto c = 0.4f;
    auto d = 0.5; //double
    auto e = 1400000000000LL; // long long
    
    std::cout<<"a:" << a <<std::endl;
    std::cout<<"b:" << b <<std::endl;
    std::cout<<"c:" << c <<std::endl;
    std::cout<<"d:" << d <<std::endl;
    std::cout<<"e:" << e <<std::endl;

    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); iter ++) {
    //    //todo ... 
    //}

    for (auto &e : v ) {
        std::cout<<e <<std::endl;
    }
}


void demo_decltype_01() 
{
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    typedef decltype (v.begin()) vector_iter;  
    vector_iter iter = v.begin();
    for ( ; iter != v.end(); iter ++) {
        std::cout<<*iter <<std::endl;
    }
}

int main(int argc, char* argv[]) 
{
    demo_auto_01();
    demo_decltype_01();
    
    return 0;
}
