#include <iostream>
using namespace std;

int main(){
    const int baris = 3;
    const int kolom = 3;
    int matrix[baris][kolom];

    cout << "Masukkan nilai untuk matrix 3x3:" << endl;
    for (int i = 0; i < baris; i++){
        for (int j = 0; j < kolom; j++){
            cout << "Elemen [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nMatrix 3x3:" << endl;
    for (int i = 0; i < baris; i++){
        for (int j = 0; j < kolom; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int jumlahBarisGenap = 0;
    for (int i = 0; i < baris; i++) {
        if (i % 2 == 0) { 
            for (int j = 0; j < kolom; j++) {
                jumlahBarisGenap += matrix[i][j];
            }
        }
    }

    cout << endl;
    cout << "Hasil Penjumlahan diagonal yang nilainya genap:\n " << jumlahBarisGenap<< endl;

    return 0;
}