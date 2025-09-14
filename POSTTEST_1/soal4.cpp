#include <iostream>
using namespace std;

void tukarNilai(int &a, int &b) {
    int sementara = a;
    a = b;
    b = sementara;
}

int main() {
    int angka1, angka2;

    cout << "Masukkan nilai pertama: ";
    cin >> angka1;
    cout << "Masukkan nilai kedua: ";
    cin >> angka2;
    
    cout << endl;
    cout << "SEBELUM DITUKAR:" << endl;
    cout << "Nilai pertama = " << angka1 << endl;
    cout << "Nilai kedua = " << angka2 << endl;
    
    tukarNilai(angka1, angka2);
    
    cout << endl;
    cout << "SETELAH DITUKAR:" << endl;
    cout << "Nilai pertama = " << angka1 << endl;
    cout << "Nilai kedua = " << angka2 << endl;
    
    return 0;
}