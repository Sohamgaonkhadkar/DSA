#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    
    vector<int> heap;

public:

    // Initialize Heap
    void initializeHeap() {
        heap.clear();
    }

    // Return heap size
    int heapSize() {
        return heap.size();
    }

    // Check if heap is empty
    bool isEmpty() {
        return heap.empty();
    }

    // Get minimum element
    int getMin() {
        if(heap.empty()) return -1;
        return heap[0];
    }
   
    // Insert element
    void insert(int x) {

        heap.push_back(x);

        int index = heap.size() - 1;

        // Heapify Up
        while(index > 0) {

            int parent = (index - 1) / 2;

            if(heap[parent] > heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    // Heapify Down
    void heapify(int index) {

        int n = heap.size();

        while(true) {

            int left = 2 * index + 1;
            int right = 2 * index + 2;

            int smallest = index;

            if(left < n && heap[left] < heap[smallest]) {
                smallest = left;
            }

            if(right < n && heap[right] < heap[smallest]) {
                smallest = right;
            }
            
            if(smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            }
            else {
                break;
            }
        }
    }
    // Remove minimum element
    void extractMin() {

        if(heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();

        if(!heap.empty()) {
            heapify(0);
        }
    }

    // Change value at index
    void changeKey(int ind, int val) {

        if(ind < 0 || ind >= heap.size()) return;

        int oldValue = heap[ind];
        heap[ind] = val;

        // If value decreased -> Heapify Up
        if(val < oldValue) {

            while(ind > 0) {

                int parent = (ind - 1) / 2;

                if(heap[parent] > heap[ind]) {
                    swap(heap[parent], heap[ind]);
                    ind = parent;
                }
                else {
                    break;
                }
            }
        }

        // If value increased -> Heapify Down
        else {
            heapify(ind);
        }
    }

    // Print Heap
    void printHeap() {

        for(int x : heap) {
            cout << x << " ";
        }

        cout << endl;
    }
};

int main() {

    MinHeap h;

    h.initializeHeap();

    h.insert(10);
    h.insert(5);
    h.insert(20);
    h.insert(2);

    h.printHeap();

    cout << "Min Element: " << h.getMin() << endl;

    h.extractMin();

    h.printHeap();

    h.changeKey(1, 1);

    h.printHeap();

    cout << "Heap Size: " << h.heapSize() << endl;

    cout << "Is Empty: " << h.isEmpty() << endl;

    return 0;
}