#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    vector<int>& arr;
    int n;

    void buildTree(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            buildTree(2 * node, start, mid);
            buildTree(2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query(int node, int start, int end, int left, int right) {
        if (left > end || right < start) {
            return 0; // Out of range
        }
        if (left <= start && right >= end) {
            return tree[node]; // Completely within range
        }
        int mid = (start + end) / 2;
        int sumLeft = query(2 * node, start, mid, left, right);
        int sumRight = query(2 * node + 1, mid + 1, end, left, right);
        return sumLeft + sumRight;
    }

    void update(int node, int start, int end, int index, int newValue) {
        if (start == end) {
            tree[node] = newValue;
            arr[index] = newValue;
        } else {
            int mid = (start + end) / 2;
            if (index >= start && index <= mid) {
                update(2 * node, start, mid, index, newValue);
            } else {
                update(2 * node + 1, mid + 1, end, index, newValue);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

public:
    SegmentTree(vector<int>& input) : arr(input) {
        n = input.size();
        tree.resize(4 * n);
        buildTree(1, 0, n - 1);
    }

    int rangeSum(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }

    void change(int index, int newValue) {
        if (index < 0 || index >= arr.size()) {
            cout << "Invalid index\n";
        } else {
            update(1, 0, n - 1, index, newValue);
            cout << "Value at index " << index << " changed to " << newValue << endl;
        }
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree segmentTree(arr);
    int choice = 0;

    cout << "1 Build" << endl;
    cout << "2 RangeSum" << endl;
    cout << "3 Change" << endl;
    cout << "4 exit" << endl;

    while (true) {
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Segment Tree Built" << endl;
        } else if (choice == 2) {
            int left, right;
            cout << "Enter left and right indices: ";
            cin >> left >> right;
            if (left < 0 || right >= arr.size() || left > right) {
                cout << "Invalid range\n";
            } else {
                int sum = segmentTree.rangeSum(left, right);
                cout << "Sum of elements in range [" << left << ", " << right << "]: " << sum << endl;
            }
        } else if (choice == 3) {
            int index, newValue;
            cout << "Enter index and new value: ";
            cin >> index >> newValue;
            segmentTree.change(index, newValue);
        } else {
            break;
        }
    }

    return 0;
}
