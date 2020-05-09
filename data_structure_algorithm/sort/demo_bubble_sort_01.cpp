
#include <iostream>

template<class Record>
void swap(Record *array, int i, int j) 
{
    if (! array) return ; 

    Record tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}


template<class Record>
void bubble_sort(Record array[], int n) 
{
    bool no_swap;
    int i, j;

    for (i =0; i < n ; i++) {
        no_swap = true;
        for (j = n-1; j > i; j--) {
            if (array[j] < array[j-1]) {
                swap(array, j, j-1);
                no_swap = false;
            }
        }
        if (no_swap) return;
    }
}


int main(int argc, char* argv[]) 
{
    int array[]= { 9,8, 4, 3, 2, 7 ,6, 7, 0, 33};
    int len = sizeof(array) / sizeof(int);
    
    std::cout<<"before sort" <<std::endl;
    for (auto &e : array) std::cout<<e <<std::endl;
    std::cout<<"after sort" <<std::endl;
    bubble_sort(array, len);
    for (auto &e : array) std::cout<<e <<std::endl;

    return 0;
    
}
