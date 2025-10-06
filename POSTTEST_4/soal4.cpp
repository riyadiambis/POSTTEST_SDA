#include <iostream>
using namespace std;

// Struktur node Circular Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;
};

//Mengurutkan node baru secara ascending
void sortedInsert(Node *&head_ref, int data) {
    // Membuat node baru
    Node* newNode = new Node{data, nullptr, nullptr};

    // Kode di jalankan jika List masih kosong
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    // Ketika data baru lebih kecil dari head maka ia akan menjadi head baru
    if (data < head_ref->data) {
        newNode->next = head_ref;
        newNode->prev = head_ref->prev;
        head_ref->prev->next = newNode;
        head_ref->prev = newNode;
        head_ref = newNode;
        return;
    }

    // Mencari posisi yang tepat untuk menyisipkan node baru
    Node* current = head_ref;
    while (current->next != head_ref && current->next->data < data) {
        current = current->next;
    }

    // Sisipkan newNode setelah current
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

//Menampilkan isi list
void printList(Node *head_ref) {
    if (head_ref == nullptr)
    {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

int main() {
    Node *head = nullptr;

    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "Circular Doubly Linked List (sorted): ";
    printList(head);

    return 0;
}