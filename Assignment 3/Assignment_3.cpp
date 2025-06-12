#include <iostream>
#include <vector>
using namespace std;

void heapifyUpMin(vector<int>& heap, int index) {
    while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void heapifyDownMin(vector<int>& heap, int index) {
    int size = heap.size();
    while (true) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

void insertMinHeap(vector<int>& heap, int val) {
    heap.push_back(val);
    heapifyUpMin(heap, heap.size() - 1);
}

void deleteRootMinHeap(vector<int>& heap) {
    if (heap.empty()) return;
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDownMin(heap, 0);
}

void printHeap(const vector<int>& heap) {
    for (int v : heap) cout << v << " ";
    cout << "\n";
}

int main() {
    vector<int> data = {50, 10, 30, 20, 60, 70};
    vector<int> minHeap;

    cout << "Building Min-Heap:\n";
    for (int val : data) {
        insertMinHeap(minHeap, val);
        printHeap(minHeap);
    }

    cout << "Deleting two nodes from Min-Heap:\n";
    for (int i = 0; i < 2; ++i) {
        deleteRootMinHeap(minHeap);
        printHeap(minHeap);
    }

    return 0;
}
