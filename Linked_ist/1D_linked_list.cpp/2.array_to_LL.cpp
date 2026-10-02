#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// function to convert array to linked list
Node* convertArr2LL(vector<int>& arr) {
    if (arr.size() == 0) return nullptr;
    
    // create head
    Node* head = new Node(arr[0]);
    Node* mover = head;

    // create remaining nodes
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

int main() {
    vector<int> arr = {12, 5, 6, 8};

    Node* head = convertArr2LL(arr);

    // print linked list
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}