class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // Step 1: check if k nodes exist
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (temp == NULL) return head;
            temp = temp->next;
        }

        // Step 2: reverse k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        int count = 0;
        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Step 3: connect with next part
        head->next = reverseKGroup(curr, k);

        // Step 4: return new head
        return prev;
    }
};