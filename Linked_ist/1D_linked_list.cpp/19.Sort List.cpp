class Solution {
public:

    // Find middle of linked list
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Merge two sorted linked lists
    ListNode* merge(ListNode* left, ListNode* right) {
        if (!left) return right;
        if (!right) return left;

        if (left->val < right->val) {
            left->next = merge(left->next, right);
            return left;
        } else {
            right->next = merge(left, right->next);
            return right;
        }
    }

    // Main merge sort function
    ListNode* sortList(ListNode* head) {
        // Base case
        if (!head || !head->next) return head;

        // Step 1: Find mid
        ListNode* mid = findMid(head);

        // Step 2: Split list
        ListNode* rightHead = mid->next;
        mid->next = NULL;

        // Step 3: Recursively sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        // Step 4: Merge
        return merge(left, right);
    }
};
