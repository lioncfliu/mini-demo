/**
 * Brief test size of  `enum`
 * Referrence to http://blog.chinaunix.net/uid-28541347-id-4267427.html 
 * */

#include <iostream>
enum ResponseCode 
{
    kOk                 = 0,
    kError              = 1,
    kErrorBadParam      = 2,
    kErrorNoAuth        = 3,
    
    kErrorOther         = 0x7fffffff
};

#pragma pack(1)
enum A 
{
    kAa = 1
};
#pragma pack()

int main(int argc, char* argv[]) 
{
    
    std::cout<<"sizeof of enum ResponseCode::kOk:" <<sizeof(kOk) <<std::endl;
    std::cout<<"sizeof of enum A::kAa:" <<sizeof(kAa) <<std::endl;
    return 0;
}
