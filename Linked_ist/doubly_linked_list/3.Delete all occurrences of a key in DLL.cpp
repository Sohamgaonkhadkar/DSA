Node* deleteAllOccurrences(Node* head, int key) {
    Node* curr = head;

    while (curr != NULL) {

        if (curr->data == key) {

            // Case 1: deleting head
            if (curr == head) {
                head = curr->next;
                if (head) head->prev = NULL;
            } 
            else {
                // connect prev and next
                Node* prevNode = curr->prev;
                Node* nextNode = curr->next;

                prevNode->next = nextNode;
                if (nextNode) nextNode->prev = prevNode;
            }

            Node* temp = curr;
            curr = curr->next;
            delete temp;
        } 
        else {
            curr = curr->next;
        }
    }

    return head;
}