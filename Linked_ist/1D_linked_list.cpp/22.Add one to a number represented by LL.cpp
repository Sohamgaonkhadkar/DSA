class Solution {
public:

    // Reverse linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* addOne(ListNode* head) {

        // Step 1: reverse
        head = reverse(head);

        ListNode* curr = head;
        int carry = 1;

        // Step 2: add 1
        while (curr && carry) {
            int sum = curr->val + carry;
            curr->val = sum % 10;
            carry = sum / 10;

            if (carry && curr->next == NULL) {
                curr->next = new ListNode(0);
            }

            curr = curr->next;
        }

        // Step 3: reverse back
        return reverse(head);
    }
};