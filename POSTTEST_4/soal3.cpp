#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};
    
    // Jika queue kosong, maka jadikan front dan rear jadi newNode
    if (front == nullptr) {
        front = rear = newNode;
    } 
    // Kalau tidak kosong, koneksikan rear->next ke newNode, lalu update
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) 
        return ""; // Queue kosong
    string document = front->document; //Menyimpa data dari depan

    Node* temp = front;
    front = front->next; // Menggeser front ke node setelahnya
    
    if (front == nullptr) { //Jika frontnya null maka rear juga di set menjadi null
        rear = nullptr;
    }
    
    delete temp; //Hapus temp dan kembali kan dokumen
    return document;
}

void processAllDocuments(Node*& front, Node*& rear) {
    while (front != nullptr) { // Selama queue tidak kosong,keluarkan dokumen dalam antrian
        string document = dequeue(front, rear);
        cout << "Memproses: " << document << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;
    
    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");
    
    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);
    
    return 0;
}