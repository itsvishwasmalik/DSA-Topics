#include <bits/stdc++.h>
using namespace std;

class minHeap {
public:
    vector<int> myElements;
    
    minHeap() {}

    void heapifyUp(int currentIndex) {
        int parentIndex = (currentIndex - 1) / 2;
        while (currentIndex > 0 && myElements[parentIndex] > myElements[currentIndex]) {
            swap(myElements[parentIndex], myElements[currentIndex]);
            currentIndex = parentIndex;
            parentIndex = (currentIndex - 1) / 2;
        }
    }

    void insertValue(int newValue) {
        myElements.push_back(newValue);
        heapifyUp(myElements.size() - 1);
    }

    void heapifyDown(int currentIndex) {
        int smallestIndex = currentIndex;
        int leftChildIndex = 2 * currentIndex + 1;
        int rightChildIndex = 2 * currentIndex + 2;

        if (leftChildIndex < myElements.size() && myElements[leftChildIndex] < myElements[smallestIndex])
            smallestIndex = leftChildIndex;
        
        if (rightChildIndex < myElements.size() && myElements[rightChildIndex] < myElements[smallestIndex])
            smallestIndex = rightChildIndex;
        
        if (smallestIndex != currentIndex) {
            swap(myElements[currentIndex], myElements[smallestIndex]);
            heapifyDown(smallestIndex);
        }
    }

    void removeMinimum() {
        if (myElements.empty()) {
            cout << "The heap is empty\n";
            return;
        }
        myElements[0] = myElements.back();
        myElements.pop_back();
        heapifyDown(0);
    }

    void display() const {
        for (const auto& element : myElements) {
            cout << element << " ";
        }
        cout << endl;
    }
};

int main() {
    minHeap myHeap;
    int userChoice = 0;

    cout << "1 to insert\n";
    cout << "2 to delete\n";
    cout << "3 to display\n";
    cout << "4 to exit\n"; 

    while (true) {
        cout << "Enter your choice: ";
        cin >> userChoice;

        if (userChoice == 1) {
            int newValue;
            cout << "Enter a value: ";
            cin >> newValue;
            myHeap.insertValue(newValue);
        } else if (userChoice == 2) {
            myHeap.removeMinimum();
        } else if (userChoice == 3) {
            myHeap.display();
        } else {
            break;
        }
    }

    return 0;
}
