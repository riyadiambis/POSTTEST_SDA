#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

struct Jadwal {
    string kodePenerbangan;
    string tujuan;
    string status;
};

struct Node {
    Jadwal data;
    Node* next;
    Node* prev; 
};

Node* head = nullptr;
Node* tail = nullptr;
string NIM = "074";

string buatKodePenerbangan() {
    static int counter = 0;
    string kode = "JT-" + NIM;
    if (counter > 0) kode += "-" + to_string(counter);
    counter++;
    return kode;
}

int hitungNode() {
    int jumlah = 0;
    Node* temp = head;
    while (temp != nullptr) {
        jumlah++;
        temp = temp->next;
    }
    return jumlah;
}

void tampilkan() {
    if (head == nullptr) {
        cout << ">> Jadwal kosong <<" << endl;
        return;
    }
    Node* temp = head;
    cout << "\n=== Daftar Jadwal Penerbangan (Depan -> Belakang) ===\n";
    int i = 1;
    while (temp != nullptr) {
        cout << i++ << ". Kode   : " << temp->data.kodePenerbangan << endl;
        cout << "   Tujuan : " << temp->data.tujuan << endl;
        cout << "   Status : " << temp->data.status << endl;
        cout << "-------------------------------\n";
        temp = temp->next;
    }
}

void tampilkanDariBelakang() {
    if (tail == nullptr) {
        cout << ">> Jadwal kosong <<" << endl;
        return;
    }
    Node* temp = tail;
    cout << "\n=== Daftar Jadwal Penerbangan (Belakang -> Depan) ===\n";
    int i = hitungNode();
    while (temp != nullptr) {
        cout << i-- << ". Kode   : " << temp->data.kodePenerbangan << endl;
        cout << "   Tujuan : " << temp->data.tujuan << endl;
        cout << "   Status : " << temp->data.status << endl;
        cout << "-------------------------------\n";
        temp = temp->prev;
    }
}

void tampilkanDetail(string kodeCari) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.kodePenerbangan == kodeCari) {
            cout << "\n--- Detail Jadwal Penerbangan ---\n";
            cout << "Kode   : " << temp->data.kodePenerbangan << endl;
            cout << "Tujuan : " << temp->data.tujuan << endl;
            cout << "Status : " << temp->data.status << endl;
            cout << "---------------------------------\n";
            return;
        }
        temp = temp->next;
    }
    cout << ">> Jadwal dengan kode " << kodeCari << " tidak ditemukan. <<\n";
}

void tambahAwal(string tujuan, string status) {
    Node* baru = new Node;
    baru->data.kodePenerbangan = buatKodePenerbangan();
    baru->data.tujuan = tujuan;
    baru->data.status = status;
    baru->prev = nullptr; 

    baru->next = head;
    if (head != nullptr) {
        head->prev = baru; 
    }
    head = baru;
    if (tail == nullptr) {
        tail = baru; 
    }
}

void sisipOtomatis(string tujuan, string status) {
    int digitTerakhirNIM = 4;
    int posisi = digitTerakhirNIM + 1;

    Node* temp = head;
    int hitung = 1;
    while (temp != nullptr && hitung < posisi - 1) {
        temp = temp->next;
        hitung++;
    }

    Node* baru = new Node;
    baru->data.kodePenerbangan = buatKodePenerbangan();
    baru->data.tujuan = tujuan;
    baru->data.status = status;

    baru->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = baru; 
    }
    temp->next = baru;
    baru->prev = temp; 

    if (baru->next == nullptr) {
        tail = baru; 
    }

    cout << "\n>> Jadwal berhasil disisipkan pada posisi " << posisi << ".\n";
}

void hapusAwal() {
    if (head == nullptr) {
        cout << "Tidak ada jadwal untuk dihapus.\n";
        return;
    }
    Node* hapus = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr; 
    } else {
        tail = nullptr; 
    }
    cout << "Jadwal " << hapus->data.kodePenerbangan << " dihapus.\n";
    delete hapus;
}

void hapusAkhir() {
    if (tail == nullptr) {
        cout << "Tidak ada jadwal untuk dihapus.\n";
        return;
    }
    Node* hapus = tail;
    tail = tail->prev;
    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr; 
    }
    cout << "Jadwal " << hapus->data.kodePenerbangan << " dihapus.\n";
    delete hapus;
}

void updateStatus(string kodeCari, string statusBaru) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.kodePenerbangan == kodeCari) {
            temp->data.status = statusBaru;
            cout << "Status penerbangan " << kodeCari << " diperbarui.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Kode penerbangan tidak ditemukan.\n";
}

void tampilkanID() {
    if (head == nullptr) {
        cout << ">> Jadwal kosong <<" << endl;
        return;
    }
    Node* temp = head;
    cout << "\n=== Daftar Kode Penerbangan ===\n";
    int i = 1;
    while (temp != nullptr) {
        cout << i++ << ". " << temp->data.kodePenerbangan << endl;
        temp = temp->next;
    }
    cout << "=============================\n";
}

int main() {
    int pilih;
    do {
        clearScreen();
        cout << "+---------------------------------------------------+\n";
        cout << "|           SISTEM JADWAL PENERBANGAN               |\n";
        cout << "|        [Rahmat Riyadi [2409106074                 |\n";
        cout << "+---------------------------------------------------+\n";
        cout << "| 1. Tambah Jadwal Awal                             |\n";
        cout << "| 2. Sisipkan Jadwal di posisi 5                    |\n";
        cout << "| 3. Hapus Jadwal Paling Awal                       |\n";
        cout << "| 4. Update Status Penerbangan                      |\n";
        cout << "| 5. Tampilkan Semua Jadwal (Original)              |\n";
        cout << "| 6. Tampilkan Semua Jadwal (Belakang ke Depan)     |\n";
        cout << "| 7. Tampilkan Detail Jadwal                        |\n";
        cout << "| 8. Hapus Jadwal Paling Akhir                      |\n";
        cout << "| 0. Keluar                                         |\n";
        cout << "+---------------------------------------------------+\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        string tujuan, status, kode;
        switch (pilih) {
            case 1:
                cout << "Tujuan: "; getline(cin, tujuan);
                cout << "Status: "; getline(cin, status);
                tambahAwal(tujuan, status);
                break;
            case 2:
                if (hitungNode() < 4) {
                    cout << "Tidak dapat menyisipkan data karena panjang data kurang dari 4 (sisip di 4)\n";
                    cout << "Silakan tambahkan lebih banyak jadwal terlebih dahulu.\n";
                } else {
                    cout << "Tujuan: "; getline(cin, tujuan);
                    cout << "Status: "; getline(cin, status);
                    sisipOtomatis(tujuan, status);
                }
                break;
            case 3:
                hapusAwal();
                break;
            case 4:
                tampilkan();
                cout << "Kode penerbangan yang ingin diupdate: ";
                getline(cin, kode);
                cout << "Status baru: ";
                getline(cin, status);
                updateStatus(kode, status);
                break;
            case 5:
                tampilkan();
                break;
            case 6:
                tampilkanDariBelakang();
                break;
            case 7:
                tampilkanID();
                cout << "Masukkan kode penerbangan untuk melihat detail: ";
                getline(cin, kode);
                tampilkanDetail(kode);
                break;
            case 8:
                hapusAkhir();
                break;
            case 0:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
        if (pilih != 0) {
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.get();
        }
    } while (pilih != 0);
    return 0;
}