/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (! head) return nullptr;

        ListNode *k_head = head, *k_tail = head;
        ListNode *k_reverse_head = head, *k_reverse_tail = head;
        ListNode *rest_list = head;
        ListNode *curr = head;
        bool reversed = false;
        int step_counter = 0;

        while (rest_list) {
            k_head = rest_list;
            k_tail = rest_list;
            curr = rest_list;
            step_counter = 1;
            while (curr && step_counter < k) {
                // try to move forward k steps
                curr = curr->next;
                ++step_counter;
            }
            
            if (curr && step_counter == k) {
                // reverse 
                // 1---->2---->3---->4---->5
                // ^           ^    ^  
                // |k_head     |k_tail
                //             |curr
                //                  |rest_list
                rest_list = curr->next;
                k_tail = curr;
                k_tail->next = nullptr;
                ListNode *pos = k_head;
                while (pos != nullptr && pos != k_tail) {
                    ListNode *tmp = pos;
                    pos = pos->next;
                    tmp->next = k_tail->next;
                    k_tail->next = tmp;
                }
                if (! reversed) {
                    k_reverse_head = k_tail;
                    reversed = true;
                } else {
                    k_reverse_tail->next = k_tail;
                }
                k_reverse_tail = k_head;
                k_reverse_tail->next = nullptr;
            } else {
                k_reverse_tail->next = rest_list;
                break;
            }
            
        }
        if (step_counter >= 1) {
            if (! reversed) {
                return head;
            } else {
                k_reverse_tail->next = rest_list;
            }
        }
        
        return k_reverse_head;
    }
};

int main(int argc, char* argv[]) 
{
    return 0;
}
