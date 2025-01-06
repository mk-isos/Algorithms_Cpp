#include <iostream>
using namespace std;

// 노드 정의
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// BST 탐색 함수
Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    
    int key = 6;
    Node* result = search(root, key);
    if (result) {
        cout << "Key " << key << " found in the BST." << endl;
    } else {
        cout << "Key " << key << " not found." << endl;
    }
    return 0;
}
