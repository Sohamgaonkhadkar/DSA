int findLength(Node* slow, Node* fast) {
    int cnt = 1;
    fast = fast->next;

    while (slow != fast) {
        cnt++;
        fast = fast->next;
    }

    return cnt;
}

int lengthOfLoop(Node *head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return findLength(slow, fast);
        }
    }

    return 0;
}