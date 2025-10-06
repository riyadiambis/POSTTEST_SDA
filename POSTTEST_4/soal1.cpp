#include <iostream>
#include <string>
using namespace std;

//Digunakan untuk menyimpan data
struct Node
{
    char data;
    Node *next;
};

//Menambahkan data ke dalam stack
void push(Node *&top, char data) 
{
    Node *newNode = new Node{data, top}; //Mengarahkan data ke node sebelumnya
    top = newNode; //Node baru ditambahkan ke atas
}

//Mengeluarkan data dari stack
char pop(Node *&top)
{
    if (top == nullptr)
        return '\0'; // Jika nilai stack kosong maka akan di return null
    Node *temp = top; //Menyimpan data di atas tapi sementara dulu
    char poppedValue = temp->data; // baru di geser ke noode berikutnya, sehingga kode selanjutnya akan menggeser dan kemudian variabel penggantinya di hapus
    top = top->next; 
    delete temp;
    return poppedValue;
}

//Menbalik string menggunakan stack
string reverseString(string s)
{
    Node *newStack = nullptr; //Stack baru sebagai penampung
    string reversed = "";

    for (char ch : s){ //masukkan semuanya ke sini, satu persatu
        push(newStack, ch); 
    }
    while (newStack != nullptr) { //Mengecek apakah stacknya apakah enggak kosong
        reversed += pop(newStack); // Ambil karakter dari atas stack dan tambahkan ke string hasil
    }

    return reversed; //Kembalikan hasil pembalikan
}

int main()
{
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl; // Output: ataD rukurts
    return 0;
}



