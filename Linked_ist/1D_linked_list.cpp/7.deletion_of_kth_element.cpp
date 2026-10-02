Node* removeK(Node* head, int k) {
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