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

// Fungsi buat nyari angka paling gede di dalam tree
int findMaxValue(Node* root) {
    // Kalo tree-nya kosong, balikin -1 aja
    if (root == nullptr) {
        return -1;
    }

    // Bikin 'penunjuk' namanya current, mulai dari root
    Node* current = root;

    // Kebalikannya dari cari nilai terkecil. Angka terbesar itu ada di paling kanan
    // Jadi kita jalan terus ke kanan selama masih ada jalan (anak kanan nya ga kosong)
    while (current->right != nullptr) {
        current = current->right; // Pindahin 'current' ke anak kanannya
    }

    // Kalo udah mentok, balikin datanya
    return current->data;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);

    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl;
    return 0;
}