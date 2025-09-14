#include <iostream>
using namespace std;

bool isPrima(int angka){
    if (angka < 2) return false;
    for (int i = 2; i < angka; i++){
        if (angka % i == 0) return false;
    }
    return true;
}

void balikArray(int *array, int size){
    for(int i = 0; i < size/2; i++){
        int sementara = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = sementara;
    }
}

void tampilArray(int array[], int ukuran){
    for (int i = 0; i < ukuran; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(){
    const int jumlahData = 7;
    int data[jumlahData];

    cout << "......Sedang mengisi array dengan 7 bilangan prima" << endl;
    cout << "LOADING......" << endl;

    for (int index = 0; index < jumlahData; index++){
        int hitung = 0;
        int angkaNow = 2;

        while (hitung < index + 1){
            if (isPrima(angkaNow)){
                hitung++;
            }
            angkaNow++;
        }
        data[index] = angkaNow - 1;
    }

    cout << endl;
    cout << "Array Awal (7 bilangan prima pertama): ";
    tampilArray(data, jumlahData);

    balikArray(data, jumlahData);

    cout << "Array Setelah Dibalik: ";
    tampilArray(data, jumlahData);
    
    return 0;
}