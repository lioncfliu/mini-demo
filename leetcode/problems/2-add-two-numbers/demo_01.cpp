#include <iostream>
#include <vector>

using namespace std;
/**
 * Definition for singly-linked list.
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        if (! l1)  return l2;
        if (! l2)  return l1;
         
        ListNode *result = NULL, *current = NULL, *rest = NULL;
        int forward = 0;


        while ( l1 && l2) {
            int sum = l1->val + l2->val + forward;
            forward = sum / 10;

            ListNode *tmp = new ListNode(sum % 10);
            if (! result)  { 
                result = tmp; 
                current = result;
            }
            else { 
                current->next = tmp; 
                current = current->next;
            }  
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if (l1) rest = l1;
        if (l2) rest = l2;

        while (rest) {
            int sum  = rest->val + forward;
            forward = sum / 10;
            ListNode *tmp = new ListNode(sum % 10);
            
            current->next = tmp;
            current = current->next;

            rest  = rest->next;
        }
        if ( forward > 0) {
            ListNode *tmp = new ListNode( forward % 10);
            current->next = tmp;
        }

        return result;
    }
     
};

ListNode *create_node(int val) 
{
    ListNode *n = new ListNode(val);
    n->next = NULL;
}

ListNode * create_list(vector<int> &list) 
{
    if (list.empty()) return NULL;

    ListNode *l = NULL, *current = NULL;
    for (int i = 0; i < list.size(); i++) {
        ListNode *n = create_node(list[i]);
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


ListNode *init_l1() 
{
    vector<int> list;
    list.push_back(2);
    list.push_back(4);
    list.push_back(6);
    return create_list(list);
}

ListNode *init_l2() 
{
    vector<int> list;
    list.push_back(5);
    list.push_back(6);
    list.push_back(4);
    list.push_back(9);
    return create_list(list);
}


void print_list(ListNode *l) 
{
    while (l) {
        cout<<l->val;
        if (l->next)  cout<<"->";
        l = l->next;
    }
    cout<<std::endl;
}

void destroy_list(ListNode *l) 
{
    while (! l) {
        ListNode *tmp = l;
        l = l->next;
        if (tmp) { 
            delete tmp; 
            tmp = NULL;
        }
    }
}
int main(int argc, char* argv[]) 
{
    ListNode *l1 = init_l1();
    ListNode *l2 = init_l2();
    print_list(l1);
    print_list(l2);
    
    Solution s;
    ListNode *result = s.addTwoNumbers(l1, l2);
    print_list(result);

    destroy_list(l1);
    destroy_list(l2);
    destroy_list(result);
}
