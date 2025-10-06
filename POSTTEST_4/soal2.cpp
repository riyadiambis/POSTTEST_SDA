#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk stack kita
struct Node {
    char data;
    Node* next;
};

// Menambahkan elemen ke stack
void push(Node*& top, char value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Fungsi untuk menghapus elemen dari stack
char pop(Node*& top) {
    if (top == nullptr) {
        return '\0'; // Null character sebagai indikator stack kosong
    }
    char data = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return data;
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Node* top) {
    return top == nullptr;
}

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;
    for (char c : expr) {
        // Jika karakter adalah kurung buka maka push ke stack
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        // Jika karakter adalah kurung tutup maka cek ini
        else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(stackTop)) { //Stacknya kosong maka return false
                return false;
            }
            // Pop stack dan cek apakah kurung cocok
            char openBracket = pop(stackTop);
            if ((c == ')' && openBracket != '(') ||
                (c == '}' && openBracket != '{') ||
                (c == ']' && openBracket != '[')) {
                return false; //Kalau tidak cocok maka return false
            }
        }
    }
    
    // Setelah loopnya selesai cek apakah stack kosong
    return isEmpty(stackTop);
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;    
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;
    
    return 0;
}