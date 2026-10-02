Node* deleteTail(Node* head) {
    // Case 1: empty list
    if (head == nullptr) return nullptr;

    // Case 2: only one node
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;

    // reach second last node
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    // delete last node
    delete temp->next;

    // make second last node point to NULL
    temp->next = nullptr;

    return head;
}
 