class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: detect cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Step 2: move fast to head
                fast = head;

                // Step 3: move both one step
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow; // start of cycle
            }
        }

        return NULL; // no cycle
    }
};