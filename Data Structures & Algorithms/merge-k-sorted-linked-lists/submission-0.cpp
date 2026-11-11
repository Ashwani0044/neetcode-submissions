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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> cheat;

        for(ListNode* h : lists) {
            while(h != NULL) {
                cheat.push_back(h->val);
                h = h->next;
            }
        }

        sort(cheat.begin(), cheat.end());

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        for(auto& n : cheat) {
            ListNode* x = new ListNode(n);
            temp->next = x;
            temp = temp->next;
        }

        return dummy->next;
    }
};
