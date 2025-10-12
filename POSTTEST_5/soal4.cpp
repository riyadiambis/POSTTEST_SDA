#include <iostream>

using namespace std;

// Kerangka sebuah node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi untuk memasukkan node baru.
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

// Fungsi buat nampilin isi tree dengan urutan "Post-order"
// Urutannya itu: KIRI -> KANAN -> ROOT
void postOrderTraversal(Node* root) {
    // Kalo nodenya kosong, yaudah stop, gausah ngapa-ngapain
    if (root == nullptr) {
        return;
    }
    // 1. Beresin dulu semua yang di sebelah kiri
    postOrderTraversal(root->left);

    // 2. Kalo kiri udah beres, sekarang beresin semua yang di sebelah kanan
    postOrderTraversal(root->right);

    // 3. Kalo kiri dan kanan udah beres, baru cetak nilai node yang sekarang
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Post-order traversal dari tree adalah: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}