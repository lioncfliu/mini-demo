#include <iostream>
#include <algorithm>

int main(int argc, char* argv[])
{
    char s[] = "Hellow World !";
    int uppercase_counter = 0;
    std::for_each( s, s + sizeof(s), [&uppercase_counter](char c){
        if (isupper(c)) uppercase_counter ++;
        });
    std::cout<<"upper case count:"<<uppercase_counter<<std::endl;
    
    return 0;
}
    
