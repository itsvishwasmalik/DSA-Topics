#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    bool isWord;
    vector<TrieNode*> child;

    TrieNode() : isWord(false), child(26, nullptr) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() : root(new TrieNode()) {}

    void insert(const string& word) {
        TrieNode* temp = root;
        for (char c : word) {
            int idx = c - 'a';
            if (temp->child[idx] == nullptr)
                temp->child[idx] = new TrieNode();
            temp = temp->child[idx];
        }
        temp->isWord = true;
    }

    bool search(const string& word) {
        TrieNode* temp = root;
        for (char c : word) {
            int idx = c - 'a';
            if (temp->child[idx] == nullptr)
                return false;
            temp = temp->child[idx];
        }
        return temp->isWord;
    }

    bool isEmpty(TrieNode* node) {
        for (TrieNode* child : node->child) {
            if (child != nullptr)
                return false;
        }
        return true;
    }

    TrieNode* remove(TrieNode* node, const string& key, int depth = 0) {
        if (!node)
            return nullptr;

        if (depth == key.size()) {
            if (node->isWord)
                node->isWord = false;

            if (isEmpty(node)) {
                delete node;
                return nullptr;
            }
            return node;
        }

        int idx = key[depth] - 'a';
        node->child[idx] = remove(node->child[idx], key, depth + 1);

        if (isEmpty(node) && !node->isWord) {
            delete node;
            return nullptr;
        }

        return node;
    }
};

int main() {
    Trie trie;
    int choice = 0;
    string word;

    cout << "1 to insert" << endl;
    cout << "2 to search" << endl;
    cout << "3 to delete" << endl;
    cout << "4 to exit" << endl;

    while (true) {
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter word to insert: ";
                cin >> word;
                trie.insert(word);
                break;
            case 2:
                cout << "Enter word to search: ";
                cin >> word;
                if (trie.search(word))
                    cout << "Word found" << endl;
                else
                    cout << "Word not found" << endl;
                break;
            case 3:
                cout << "Enter word to delete: ";
                cin >> word;
                trie.root = trie.remove(trie.root, word);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
