class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;
        
        // Count total nodes
        while (temp) {
            temp = temp->next;
            size++;
        }
        
        // If we need to remove the head node
        if (n == size) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        // Traverse to the node just before the one to be deleted
        int target = size - n;
        ListNode* curr = head;
        for (int i = 1; i < target; i++) {
            curr = curr->next;
        }
        
        ListNode* nodeToDelete = curr->next;
        curr->next = curr->next->next;
        delete nodeToDelete;
        
        return head;
    }
};
