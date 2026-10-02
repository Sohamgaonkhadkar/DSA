#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }

    Node(int val, Node* nextNode) {
        data = val;
        next = nextNode;
    }
};

// Insert at tail
Node* insertTail(Node* head, int val) {
    if (head == NULL) return new Node(val);

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new Node(val);
    return head;
}

// Convert array to linked list
Node* convertArr2LL(vector<int>& arr) {
    Node* head = NULL;
    for (int x : arr) {
        head = insertTail(head, x);
    }
    return head;
}

// Insert at position k (1-based index)
Node* insertPosition(Node* head, int el, int k) {
    if (head == NULL) {
        if (k == 1) return new Node(el);
        else return head;
    }

    if (k == 1) {
        return new Node(el, head);
    }

    int cnt = 0;
    Node* temp = head;

    while (temp != NULL) {
        cnt++;
        if (cnt == k - 1) {
            Node* x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }

    return head;
}

// Print list
void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    vector<int> arr = {12, 5, 8, 7};

    Node* head = convertArr2LL(arr);

    head = insertPosition(head, 100, 3); // insert 100 at position 3

    print(head);

    return 0;
}