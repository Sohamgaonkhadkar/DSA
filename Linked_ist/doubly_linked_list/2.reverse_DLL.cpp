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

// Reverse DLL using stack
Node* reverseDLL(Node* head) {
    if (head == NULL) return NULL;

    stack<int> st;
    Node* temp = head;

    // Step 1: Push all values
    while (temp != NULL) {
        st.push(temp->data);
        temp = temp->next;
    }

    // Step 2: Replace values
    temp = head;
    while (temp != NULL) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

//-2
// Reverse DLL using pointer swapping
Node* reverseDLL(Node* head) {
    if (head == NULL) return NULL;

    Node* temp = NULL;
    Node* curr = head;

    while (curr != NULL) {
        // Swap next and back
        temp = curr->back;
        curr->back = curr->next;
        curr->next = temp;

        // Move to next node (which is previous originally)
        curr = curr->back;
    }

    // Fix new head
    if (temp != NULL) {
        head = temp->back;
    }

    return head;
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    Node* head = convertArr2DLL(arr);

    cout << "Original: ";
    print(head);

    head = reverseDLL(head);

    cout << "Reversed: ";
    print(head);

    return 0;
}