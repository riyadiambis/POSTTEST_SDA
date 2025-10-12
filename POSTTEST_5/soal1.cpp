#include <iostream>

using namespace std;

// Ini struktur buat bikin satu node
// Setiap node punya data (angka), dan penunjuk ke anak kiri & kanan
struct Node {
    int data;
    Node* left;
    Node* right;

    // Ini constructor, bakal berjalan pas kita bikin node baru
    Node(int val) {
        data = val;
        left = nullptr; // Awalnya, anak kiri dan kanan dibikin kosong (nullptr)
        right = nullptr;
    }
};

// Fungsi buat nambahin data baru ke dalam tree
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val); // Kalo tree-nya kosong, node baru jadi root
    }
    // Kalo angka yg mau dimasukin lebih kecil, taro di kiri
    if (val < root->data) {
        root->left = insert(root->left, val);
    // Kalo lebih besar, taro di kanan
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

// Fungsi buat ngitung ada berapa banyak node di tree kita
int countNodes(Node* root) {
    // Kalo nodenya kosong (udah mentok di ujung), berarti ga ada yg diitung, balikin 0
    if (root == nullptr) {
        return 0;
    }
    // Kalo ada nodenya, kita hitung 1,
    // terus ditambahin sama total node di sebelah kiri dan total node di sebelah kanan
    // Fungsi ini manggil dirinya sendiri buat ngitung anak-anaknya (rekursi)
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);

    cout << "Jumlah total node dalam tree adalah: " << countNodes(root) << endl;
    return 0;
}