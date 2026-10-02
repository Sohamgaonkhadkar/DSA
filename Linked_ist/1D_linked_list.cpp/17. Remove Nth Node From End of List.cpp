class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return head;

    // delete head
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        cnt++;

        if (cnt == k) {
            prev->next = temp->next;
            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
    }
};

//-2
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Step 1: move fast n steps
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If deleting head
        if (fast == NULL) {
            return head->next;
        }

        // Step 2: move both
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 3: delete node
        slow->next = slow->next->next;

        return head;
    }
};