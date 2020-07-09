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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (! head || n < 1) return nullptr;
        
        /// if length of list equals 1
        if (head->next == nullptr && n >= 1) {
            delete head;
            head = nullptr;
            return head;
        }
        ListNode *fast = head;
        ListNode *slow = head;

        while(n && fast->next) { 
            fast = fast->next; 
            --n;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }


        /// delete the fist one
        if (head == slow && n > 0) {
            head = head->next;
            delete slow;
            slow = nullptr;
            return head;
        }
      
        fast = slow->next;
        slow->next = fast->next;
        delete fast;
        fast = nullptr;
        

        return head;
    }
};
