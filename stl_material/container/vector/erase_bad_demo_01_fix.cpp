#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
 
using namespace std;
template<typename T>
void print_vector(const std::vector<T> &v) { 
    std::cout<<"{ " ;
    for(vector<int>::const_iterator iter=v.begin(); iter!=v.end(); iter++) {
        std::cout<<*iter << "\t";
    }
    std::cout<<" }" <<std::endl;
}
int main()
{
    vector<int> veci;
    veci.push_back(1);
    veci.push_back(2);
    veci.push_back(3);
    veci.push_back(4);
    veci.push_back(5);
    veci.push_back(3);
    veci.push_back(2);
    veci.push_back(3);
    print_vector(veci);
     
    for(vector<int>::iterator iter=veci.begin(); iter!=veci.end(); /* iter++ */) {
        if( *iter == 3)
            iter = veci.erase(iter); 
        else iter ++;
    }
    print_vector(veci);
    return 0;
}
