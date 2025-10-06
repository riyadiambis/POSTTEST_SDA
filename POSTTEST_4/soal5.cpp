#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next; // Pointer ke node selanjutnya
    Node* prev; // Pointer ke node sebelumnya
};


void exchangeHeadAndTail(Node *&head_ref) {
    if (head_ref == nullptr || head_ref->next == head_ref) { // Hanya berjalan jika ada 2 node atau lebih
        return;
    }
    
    Node* head = head_ref; // Simpan head 
    Node* tail = head_ref->prev;  // Tail adalah prev dari head
    
    // Kalau cuma ada dua node, cukup tukar koneksi antar keduanya
    if (head->next == tail) {
        // Menukar koneksi antara head dan tail
        head->next = tail;
        head->prev = tail;
        tail->next = head;
        tail->prev = head;
        head_ref = tail;  // Update head_tail 
        return;
    }
    
    // Simpan node tetangga dekat head dan tail
    Node* head_next = head->next; // node setelah head
    Node* tail_prev = tail->prev; // node sebelum tail

    tail->next = head_next; // Tail mwenunjuk ke node setelah head
    head_next->prev = tail; // Node setelah head menunjuk ke tail
    tail->prev = head->prev; // Tail sekarang menunjuk ke node sebelum head

    head->prev = tail_prev; // Head menunjuk ke node sebelum tail
    tail_prev->next = head; // Node sebelum tail nyambung ke head   
    head->next = tail; // Head menunjuk ke tail

    head_ref = tail;  // Tail sekarang menjadi head
}
void printList(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }
    
    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

void insertEnd(Node *&head_ref, int data) {
    Node *newNode = new Node{data, nullptr, nullptr};
    
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }
    
    // Kalau sudah ada isinya, tambahkan di bagian akhir
    Node *tail = head_ref->prev; 
    newNode->next = head_ref; // Node baru menunjuk ke head
    newNode->prev = tail; 
    head_ref->prev = newNode; // Head menunjuk ke node baru sebagai prev
    tail->next = newNode; // node terakhir menunjuk ke node baru
}

int main() {
    Node *head = nullptr;
    
    // Buat list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);
    
    cout << "List sebelum exchange: ";
    printList(head);
    
    exchangeHeadAndTail(head);
    
    cout << "List setelah exchange head dan tail: ";
    printList(head);
    
    return 0;
}