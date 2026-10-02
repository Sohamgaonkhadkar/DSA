Node* removeel (Node* head, int el) {
    if (head == NULL) return head;

    // delete head
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        
        if (temp->data == el) {
            prev->next = temp->next;
            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}
