// created by lioncfliu on 2020/05/09.
//

#include <iostream>
#include <assert.h>
#include <vector>

struct ListNode
{
    int val;
    ListNode * next;
};

// v 0.1 : go througth list twice. 
ListNode * ReverseListAndFindKthNode(ListNode * src_list, const int k, int & kthVal)
{
    
    // index starts from 1 
    if (! src_list || k < 1 ) { 
        // log invalid param
        return nullptr;  
    }
    
    // 1. reverse first.
    // 2. then find kth value.
    
    ListNode *current = src_list;
    ListNode *slice = nullptr; 
    int len = 0;

    while (current) {
        ++len;
        if (! slice) { //head of reverse
            slice = current;
            current = current->next;
            slice->next = nullptr;
        } else {
            ListNode *tmp = current;
            current = current->next;
            tmp->next = slice;
            slice = tmp;
        }    
    } 

    if (k > len) { //out of range
        // do not modify kthVal
        return nullptr;
    }    

    current = slice;
    int i = 0;
    while (current) {
        ++i;
        if (k == i) {
            kthVal = current->val;
            std::cout<< "found "<< k <<"'th element:"<< kthVal <<std::endl;
            break;
        }
        current = current->next;
    }

    return slice;
}

// v 0.2  go through once 
ListNode * ReverseListAndFindKthNodePlus(ListNode * src_list, const int k, int & kthVal)
{
    
    // index starts from 1 
    if (! src_list || k < 1 ) { 
        // log invalid param
        return nullptr;  
    }
    
    // 1. reverse and find kth value on the same time.
    
    // 
    // distance between first and second equal k - 1 
    // a. nit status:
    // [- - - - ... - k - ... - - -]
    // ^ first
    // ^ second
    //
    // b. forward first througth distance
    // [- - - - ... - k - ... - - -]
    // ^ first -->  ^ first
    // ^ second
    // 
    // c. step by step forward tow ptr on same time until fisrt got tail of list
    // final status:
    // [- - - - ... - k - ... - - -]
    //                            ^ first
    //                ^ second(found kthVal)
    //

    ListNode * first = src_list, *second = src_list;
    ListNode *current = src_list;
    ListNode *slice = nullptr; 
    int distance = k - 1;
    
    for (int i = 0; i < distance; i++) {
        if (first->next) first = first->next;
        else return nullptr; // out of range
    }

    bool found_k = false;
    while (current) {
        // find kthVal 
        if (first->next) {
            first = first->next;
            second = second->next; 
        } else if (! found_k) {
            // found kthVal
            found_k = true;
            kthVal = second->val;
            std::cout<< "found "<< k <<"'th element:"<< kthVal <<std::endl;
        }

        // reverse list
        if (! slice) { //head of reverse
            slice = current;
            current = current->next;
            slice->next = nullptr;
        } else {
            ListNode *tmp = current;
            current = current->next;
            tmp->next = slice;
            slice = tmp;
        }    
    } 

    return slice;
}

ListNode *create_node(const int &val) 
{
    ListNode *n = new ListNode;
    n->val = val;
    n->next = nullptr;
    return n;
}

ListNode * create_list(const std::vector<int> &list) 
{
    if (list.empty()) return nullptr;

    ListNode *l = nullptr, *current = nullptr;
    for (auto &e : list) {
        ListNode *n = create_node(e);
        if (! l) {
            l = n;
            current = l;
        }
        else { 
            current->next = n;
            current = current->next ;
        }
    }
    
    return l;
}


void destroy_list(ListNode *l) 
{
    while (l) {
        ListNode *tmp = l;
        l = l->next;
        delete tmp;
    }
}

void print_list(ListNode *l) 
{
    int i = 0;
    while (l) {
        ++i;
        std::cout<<l->val<<"@["<<i<< "]";
        if (l->next)  std::cout<<"->";
        l = l->next;
    }
    std::cout<<std::endl;
}

void TEST_case_01_ok() 
{
    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode *l = create_list(v);
    int k = 4;
    int kthVal = -999; 

    print_list(l);
    ListNode *rl = ReverseListAndFindKthNodePlus(l, k, kthVal);
    print_list(rl);
    assert(rl != nullptr);
    assert(kthVal == 6);
    destroy_list(rl);
}

void TEST_case_01_null_list() 
{
    int k = 4;
    int kthVal = -999; 

    ListNode *rl = ReverseListAndFindKthNodePlus(nullptr, k, kthVal);
    assert(rl == nullptr);
    assert(kthVal == -999);
}

void TEST_case_01_bad_k_less_zero() 
{
    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode *l = create_list(v);
    int k = -1;
    int kthVal = -999; 

    ListNode *rl = ReverseListAndFindKthNodePlus(l, k, kthVal);
    assert(rl == nullptr);
    assert(kthVal == -999);
    destroy_list(l);
}

void TEST_case_01_bad_k_gt_len() 
{
    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode *l = create_list(v);
    int k = 99;
    int kthVal = -999; 

    ListNode *rl = ReverseListAndFindKthNodePlus(l, k, kthVal);
    assert(rl == nullptr);
    assert(kthVal == -999);
    destroy_list(l);
}

int main(int argc, char* argv[]) 
{
    TEST_case_01_ok();
    TEST_case_01_null_list();
    TEST_case_01_bad_k_less_zero();
    TEST_case_01_bad_k_gt_len();
    return 0;
}
