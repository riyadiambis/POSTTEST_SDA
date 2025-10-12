#include <iostream>

using namespace std;

// Kerangka node
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

// Fungsi untuk memasukkan node baru
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

// Fungsi buat nampilin isi tree dengan urutan "Pre-order"
// Urutannya itu: ROOT (diri sendiri) -> KIRI -> KANAN
void preOrderTraversal(Node* root) {
    // Kalo nodenya kosong, stop.
    if (root == nullptr) {
        return;
    }
    // 1. Begitu sampai di node, langsung cetak nilainya
    cout << root->data << " ";
    
    // 2. Setelah itu, baru urus semua yang di sebelah kiri
    preOrderTraversal(root->left);
    
    // 3. Kalo yang kiri udah beres, terakhir urus semua yang di sebelah kanan
    preOrderTraversal(root->right);
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

    cout << "Pre-order traversal dari tree adalah: ";
    preOrderTraversal(root);
    cout << endl;

    return 0;
}