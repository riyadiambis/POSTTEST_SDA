#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    float ipk;
};

int main() {
    const int jumlahMhs = 4;
    Mahasiswa mhs[jumlahMhs];

    for (int i = 0; i < jumlahMhs; i++) {
        cout << "Masukkan data mahasiswa ke-" << (i + 1) << ":" << endl;
        
        cout << "Nama: ";
        cin >> mhs[i].nama;
        
        cout << "NIM: ";
        cin >> mhs[i].nim;
        
        cout << "IPK: ";
        cin >> mhs[i].ipk;
    }

    // Mengurutkan IPK
    for (int i = 0; i < jumlahMhs - 1; i++) {
        for (int j = 0; j < jumlahMhs - i - 1; j++) {
            if (mhs[j].ipk > mhs[j + 1].ipk) {
                Mahasiswa temp = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = temp;
            }
        }
    }

    cout << "\nData IPK ascending:" << endl;
    for (int i = 0; i < jumlahMhs; i++) {
        cout << "\nMahasiswa ke-" << (i + 1) << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "NIM: " << mhs[i].nim << endl;
        cout << "IPK: " << mhs[i].ipk << endl;
    }
    
    return 0;
}