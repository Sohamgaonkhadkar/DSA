class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: 0 or 1 node
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // delete middle node
        prev->next = slow->next;

        return head;
    }
};111,010,011