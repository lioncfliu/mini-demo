#include <iostream>
#include <list>
#include <algorithm>


int main() 
{
    std::list<int> l = {7, 5, 16, 8};
    
    l.push_front(25);

    l.push_back(13);
    
    auto iter = std::find(l.begin(), l.end(), 16);
    if (iter != l.end()) {  l.insert(iter, 42); }
    
    for (auto &e : l) {
        std::cout<< e <<std::endl;
    }
}
