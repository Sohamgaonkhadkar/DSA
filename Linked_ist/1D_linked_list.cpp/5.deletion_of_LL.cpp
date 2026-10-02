Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;

    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
}