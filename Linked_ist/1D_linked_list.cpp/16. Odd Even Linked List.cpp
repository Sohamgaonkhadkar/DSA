class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even != NULL && even->next != NULL) {
            odd->next = even->next;   // link odd
            odd = odd->next;

            even->next = odd->next;   // link even
            even = even->next;
        }

        odd->next = evenHead; // attach even list

        return head;
    }
};