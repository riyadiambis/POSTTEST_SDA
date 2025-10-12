#include <iostream>

using namespace std;

// kerangka untuk sebuah node
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

// Fungsi buat nyari angka paling kecil di dalam tree
int findMinValue(Node* root) {
    // Cek dulu, kalo tree-nya emang kosong dari awal, ya balikin -1
    if (root == nullptr) {
        return -1;
    }
    
    // Bikin 'penunjuk' namanya current, mulai dari root
    Node* current = root;
    
    // Di BST, angka terkecil itu pasti ada di paling kiri
    // Jadi, kita jalan terus ke kiri selama masih ada jalan (anak kiri nya ga kosong)
    while (current->left != nullptr) {
        current = current->left; // Pindahin 'current' ke anak kirinya
    }
    
    // Kalo udah mentok paling kiri, balikin data di node itu
    return current->data;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    cout << "Nilai terkecil dalam tree adalah: " << findMinValue(root) << endl;
    return 0;
}