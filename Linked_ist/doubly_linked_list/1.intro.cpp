#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* back;

    Node(int val) {
        data = val;
        next = nullptr;
        back = nullptr;
    }
};

// Convert array → DLL
Node* convertArr2DLL(vector<int>& arr) {
    if (arr.empty()) return NULL;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }
    return head;
}

// Print DLL
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Delete Head
Node* deleteHead(Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    Node* temp = head;
    head = head->next;

    head->back = NULL;
    temp->next = NULL;

    delete temp;
    return head;
}

// Delete Tail
Node* deleteTail(Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    Node* prev = temp->back;

    prev->next = NULL;
    temp->back = NULL;

    delete temp;
    return head;
}

// Delete K-th Node
Node* removeKthElement(Node* head, int k) {
    if (head == NULL) return NULL;

    Node* temp = head;
    int cnt = 1;

    // Move to k-th node
    while (temp != NULL && cnt < k) {
        temp = temp->next;
        cnt++;
    }

    // If k is greater than length
    if (temp == NULL) return head;

    Node* prev = temp->back;
    Node* front = temp->next;

    // Case 1: Only one node
    if (prev == NULL && front == NULL) {
        delete temp;
        return NULL;
    }
    // Case 2: Delete head
    else if (prev == NULL) {
        return deleteHead(head);
    }
    // Case 3: Delete tail
    else if (front == NULL) {
        return deleteTail(head);
    }

    // Case 4: Middle node
    prev->next = front;
    front->back = prev;

    temp->next = NULL;
    temp->back = NULL;

    delete temp;

    return head;
}

// Delete given node (NOT head pointer given, only node)
void deleteNode(Node* temp) {
    Node* prev = temp->back;
    Node* front = temp->next;

    // If deleting tail
    if (front == NULL) {
        prev->next = NULL;
        temp->back = NULL;
        delete temp;
        return;
    }

    // If deleting middle node
    prev->next = front;
    front->back = prev;

    temp->next = NULL;
    temp->back = NULL;

    delete temp;
}

Node* insertBeforeHead(Node* head, int val) {
    Node* newHead = new Node(val, head, nullptr);
    if (head != NULL) head->back = newHead;
    return newHead;
}

/ Insert before tail
Node* insertBeforeTail(Node* head, int val) {
    // If list is empty or has one node → insert at head
    if (head == NULL || head->next == NULL) {
        Node* newHead = new Node(val, head, NULL);
        if (head != NULL) head->back = newHead;
        return newHead;
    }

    Node* tail = head;

    // Move to last node
    while (tail->next != NULL) {
        tail = tail->next;
    }

    Node* prev = tail->back;

    Node* newNode = new Node(val, tail, prev);

    prev->next = newNode;
    tail->back = newNode;

    return head;
}
Node* insertAtKth(Node* head, int k, int val) {

    // Case 1: insert at head
    if (k == 1) {
        return insertBeforeHead(head, val);
    }

    Node* temp = head;
    int cnt = 1;

    // Move to k-th node
    while (temp != NULL && cnt < k) {
        temp = temp->next;
        cnt++;
    }

    // Case 2: insert before tail (i.e., at end)
    if (temp == NULL) {
        return insertBeforeTail(head, val);
    }

    // Case 3: insert before k-th node (middle)
    Node* prev = temp->back;

    Node* newNode = new Node(val, temp, prev);

    prev->next = newNode;
    temp->back = newNode;

    return head;
}
int main() {
    vector<int> arr = {12, 8, 7, 5};

    Node* head = convertArr2DLL(arr);

    cout << "Original: ";
    print(head);

    head = removeKthElement(head, 2); // delete 2nd node
    cout << "After deleting 2nd node: ";
    print(head);

    // Delete node with value 8 (head->next)
    deleteNode(head->next);

    head = insertBeforeHead(head, 10);

    print(head);

    head = insertBeforeTail(head, 10);

    print(head);

    cout << "After deleting 8: ";
    print(head);


    return 0; 
}