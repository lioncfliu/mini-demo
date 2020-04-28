#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
 
using namespace std;
 
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
     
    for(vector<int>::iterator iter=veci.begin(); iter!=veci.end(); iter++) {
        if( *iter == 3)
            veci.erase(iter); // here is unsafe operation, iter may be dangling ptr.
    }
    
    return 0;
}
