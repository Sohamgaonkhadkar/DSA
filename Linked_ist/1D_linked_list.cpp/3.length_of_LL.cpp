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

Node* convertArr2LL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void printLL(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int lengthOfLL(Node* head) {
    int cnt = 0;
    Node* temp = head;

    while(temp) {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

int main() {
    vector<int> arr = {12, 5, 8, 7};

    Node* head = convertArr2LL(arr);

    printLL(head);
    cout << endl;

    cout << "Length: " << lengthOfLL(head);

    return 0;
}

