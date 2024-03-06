#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    vector<int> elements;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && elements[parent] < elements[index]) {
            swap(elements[parent], elements[index]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int maxIndex = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < elements.size() && elements[leftChild] > elements[maxIndex])
            maxIndex = leftChild;

        if (rightChild < elements.size() && elements[rightChild] > elements[maxIndex])
            maxIndex = rightChild;

        if (maxIndex != index) {
            swap(elements[index], elements[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

public:
    MaxHeap() {}

    void insert(int value) {
        elements.push_back(value);
        heapifyUp(elements.size() - 1);
    }

    void removeMax() {
        if (elements.empty()) {
            cout << "MaxHeap is empty\n";
            return;
        }
        elements[0] = elements.back();
        elements.pop_back();
        heapifyDown(0);
    }

    void print() const {
        for (const auto& element : elements) {
            cout << element << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap heap;
    int choice = 0;

    cout << "1 to insert\n";
    cout << "2 to delete\n";
    cout << "3 to print\n";
    cout << "4 to exit\n";

    while (true) {
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int value;
            cout << "Enter value: ";
            cin >> value;
            heap.insert(value);
        } else if (choice == 2) {
            heap.removeMax();
        } else if (choice == 3) {
            heap.print();
        } else {
            break;
        }
    }

    return 0;
}
