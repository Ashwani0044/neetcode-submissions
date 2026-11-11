/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head; // Quick optimization

        ListNode* dummy = new ListNode(0, head);
        ListNode* temp = dummy;

        while (temp != NULL) {
            ListNode *x = temp;
            bool val = true;

            // Check if there are at least k nodes available to reverse
            for (int i = 0; i < k; i++) {
                if (!x || !x->next) {
                    val = false;
                    break;
                }
                x = x->next;
            }

            if (!val) break; 

            ListNode* groupNext = x->next; 
            ListNode* groupStart = temp->next; 

            // Isolate the group to reverse it cleanly
            x->next = NULL;

            ListNode* prev = NULL;
            ListNode* curr = groupStart;
            ListNode* next = NULL;

            while (curr != NULL) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            temp->next = prev;        
            groupStart->next = groupNext; 

            temp = groupStart; 
        }

        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};
