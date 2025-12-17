#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index != 0 && heap[parent(index)] < heap[index]) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int l = left(index);
        int r = right(index);

        if (l < heap.size() && heap[l] > heap[largest])
            largest = l;
        if (r < heap.size() && heap[r] > heap[largest])
            largest = r;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
        cout << "Inserted " << value << " into the priority queue.\n";
    }

    void deleteMax() {
        if (heap.empty()) {
            cout << "Heap is empty. Cannot delete.\n";
            return;
        }
        cout << "Deleted max element: " << heap[0] << "\n";
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void display() {
        if (heap.empty()) {
            cout << "Heap is empty.\n";
            return;
        }
        cout << "Priority Queue (Max Heap): ";
        for (int val : heap)
            cout << val << " ";
        cout << "\n";
    }

    void search(int value) {
        auto it = find(heap.begin(), heap.end(), value);
        if (it != heap.end())
            cout << "Value " << value << " found at index " << it - heap.begin() << ".\n";
        else
            cout << "Value " << value << " not found in the priority queue.\n";
    }

    void heapSort() {
        vector<int> tempHeap = heap;
        vector<int> sorted;

        while (!tempHeap.empty()) {
            sorted.push_back(tempHeap[0]);
            tempHeap[0] = tempHeap.back();
            tempHeap.pop_back();

            // Re-heapify
            int i = 0, size = tempHeap.size();
            while (true) {
                int largest = i, l = 2 * i + 1, r = 2 * i + 2;
                if (l < size && tempHeap[l] > tempHeap[largest]) largest = l;
                if (r < size && tempHeap[r] > tempHeap[largest]) largest = r;
                if (largest == i) break;
                swap(tempHeap[i], tempHeap[largest]);
                i = largest;
            }
        }

        cout << "Sorted (Descending Order): ";
        for (int val : sorted)
            cout << val << " ";
        cout << "\n";
    }
};

int main() {
    MaxHeap pq;
    int choice, value;

    do {
        cout << "\n--- Priority Queue Menu (Max Heap) ---\n";
        cout << "1. Insert\n2. Delete\n3. Display\n4. Search\n5. Sort (Heap Sort)\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.insert(value);
                break;
            case 2:
                pq.deleteMax();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                pq.search(value);
                break;
            case 5:
                pq.heapSort();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
