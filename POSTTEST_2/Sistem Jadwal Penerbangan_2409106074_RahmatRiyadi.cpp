#include <iostream>
#include <string>
#include <limits>
#include <iomanip> 

using namespace std;

struct TanggalWaktu { 
    int tanggal;
    int bulan;
    int tahun;
    string waktuBerangkat;
};

// Data Jadwal Penerbangan 
struct InfoPenerbangan {
    string kodeTerbang;
    string asalKota;
    string tujuanAkhir;
    TanggalWaktu jadwalWaktu; 
    string maskapai; 
    string statusTerakhir;
    InfoPenerbangan* nextFlight;
};

// Bagian Head
InfoPenerbangan* daftarPenerbangan = nullptr;

void tambahJadwalAwal();
void tambahJadwalAkhir();
void tampilkanSemuaJadwal();

const string NIM_MAHASISWA = "2409106074";

int DuaDigitNIM() {
    string strNIM = NIM_MAHASISWA;
    string duaDigitStr = strNIM.substr(strNIM.length() - 4, 2);
    return stoi(duaDigitStr);
}

int DigitTerakhirNIM() {
    string strNIM = NIM_MAHASISWA;
    char digitChar = strNIM.back();
    return digitChar - '0';
}

string buatKodePenerbangan() {
    static int hitungKode = 0;
    int angka = 74 - hitungKode;
    string angkaStr;
    
    if (angka < 10) {
        angkaStr = "00" + to_string(angka);
    } else if (angka < 100) {
        angkaStr = "0" + to_string(angka);
    } else {
        angkaStr = to_string(angka);
    }
    
    hitungKode++;
    return "JT-" + angkaStr;
}

void inputDetailJadwal(InfoPenerbangan* jadwalBaru) {
    cout << "------------------------------------------" << endl;
    cout << "  Input Detail Jadwal Penerbangan Baru    " << endl;
    cout << "------------------------------------------" << endl;

    cout << "Masukkan Kota Asal: ";
    getline(cin, jadwalBaru->asalKota);

    cout << "Masukkan Tujuan Penerbangan: ";
    getline(cin, jadwalBaru->tujuanAkhir);

    cout << "--- Jadwal Keberangkatan ---" << endl;
    cout << "Tanggal (DD): ";
    cin >> jadwalBaru->jadwalWaktu.tanggal;
    cout << "Bulan (MM): ";
    cin >> jadwalBaru->jadwalWaktu.bulan;
    cout << "Tahun (YYYY): ";
    cin >> jadwalBaru->jadwalWaktu.tahun;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Waktu Berangkat (HH:MM, contoh 10:30): ";
    getline(cin, jadwalBaru->jadwalWaktu.waktuBerangkat);

    cout << "Masukkan Nama Maskapai: ";
    getline(cin, jadwalBaru->maskapai);

    cout << "Masukkan Status Penerbangan (contoh: Tepat Waktu, Terlambat, Naik Pesawat): ";
    getline(cin, jadwalBaru->statusTerakhir);
}

void tambahJadwalBaru() {
    int pilihan;
    cout<< "\n == Tambah Data Jadwal Penerbangan ==\n"
        << " 1. Tambah di awal\n"
        << " 2. Tambah di akhir\n"
        << " 0. Kembali\n"
        << " Masukan pilihan : ";
    cin >> pilihan;

    switch(pilihan) {
        case 1:
            tambahJadwalAwal();
            break;
        case 2:
            tambahJadwalAkhir();
            break;
        case 0:
            return;
        default:
            cout << "\n Pilihan tidak valid!\n";
            break;
    }
}

void tambahJadwalAwal() {
    InfoPenerbangan* jadwalBaru = new InfoPenerbangan();
    jadwalBaru->kodeTerbang = buatKodePenerbangan();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    inputDetailJadwal(jadwalBaru);

    jadwalBaru->nextFlight = daftarPenerbangan;
    daftarPenerbangan = jadwalBaru;
    cout << "Jadwal penerbangan " << jadwalBaru->kodeTerbang << " berhasil ditambahkan di awal!" << endl;
}

void tambahJadwalAkhir() {
    InfoPenerbangan* jadwalBaru = new InfoPenerbangan();
    jadwalBaru->kodeTerbang = buatKodePenerbangan();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    inputDetailJadwal(jadwalBaru);

    jadwalBaru->nextFlight = nullptr;

    if (daftarPenerbangan == nullptr) {
        daftarPenerbangan = jadwalBaru;
    } else {
        InfoPenerbangan* penunjukSementara = daftarPenerbangan;
        while (penunjukSementara->nextFlight != nullptr) {
            penunjukSementara = penunjukSementara->nextFlight;
        }
        penunjukSementara->nextFlight = jadwalBaru;
    }
    cout << "Jadwal penerbangan " << jadwalBaru->kodeTerbang << " berhasil ditambahkan di akhir!" << endl;
}

void sisipkanJadwalDiTengah() {
    if (daftarPenerbangan == nullptr) {
        cout << "\nDaftar masih kosong! Tidak bisa menyisipkan data.\n" << endl;
        return;
    }

    cout << "\nDaftar Jadwal Penerbangan Saat Ini:\n";
    tampilkanSemuaJadwal();

    int jumlahData = 0;
    InfoPenerbangan* temp = daftarPenerbangan;
    while (temp != nullptr) {
        jumlahData++;
        temp = temp->nextFlight;
    }

    int posisi;
    cout << "\nMasukkan nomor urutan setelah data ke berapa data baru akan disisipkan (1-" << jumlahData << "): ";
    cin >> posisi;

    if (posisi < 1 || posisi > jumlahData) {
        cout << "\nPosisi tidak valid! Harus antara 1 sampai " << jumlahData << endl;
        return;
    }

    // Buat node
    InfoPenerbangan* jadwalBaru = new InfoPenerbangan();
    jadwalBaru->kodeTerbang = buatKodePenerbangan();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    inputDetailJadwal(jadwalBaru);

    jadwalBaru->nextFlight = nullptr;

    InfoPenerbangan* penunjukSementara = daftarPenerbangan;
    for (int i = 1; i < posisi && penunjukSementara != nullptr; ++i) {
        penunjukSementara = penunjukSementara->nextFlight;
    }

    if (penunjukSementara != nullptr) {
        jadwalBaru->nextFlight = penunjukSementara->nextFlight;
        penunjukSementara->nextFlight = jadwalBaru;
        cout<< "\nJadwal penerbangan " << jadwalBaru->kodeTerbang 
            << " berhasil disisipkan setelah data ke-" << posisi << "." << endl;
    } else {
        cout << "\nTerjadi kesalahan saat menyisipkan data." << endl;
        delete jadwalBaru;
    }
}

void hapusJadwalTerdepan() {
    if (daftarPenerbangan == nullptr) {
        cout << "Daftar jadwal kosong, tidak ada yang bisa dihapus." << endl;
        return;
    }
    InfoPenerbangan* yangDihapus = daftarPenerbangan;
    daftarPenerbangan = daftarPenerbangan->nextFlight;
    cout << "Jadwal penerbangan " << yangDihapus->kodeTerbang << " (" << yangDihapus->tujuanAkhir << ") berhasil dihapus dari awal." << endl;
    delete yangDihapus;
}

void perbaruiStatusPenerbangan() {
    if (daftarPenerbangan == nullptr) {
        cout << "Daftar jadwal kosong, tidak ada yang bisa diupdate." << endl;
        return;
    }

    string kodeUntukDicari;
    cout << "Masukkan Kode Penerbangan yang ingin diupdate: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, kodeUntukDicari);

    InfoPenerbangan* penunjukCari = daftarPenerbangan;
    bool sudahDitemukan = false;
    while (penunjukCari != nullptr) {
        if (penunjukCari->kodeTerbang == kodeUntukDicari) {
            string statusBaru;
            cout << "Jadwal ditemukan. Masukkan Status Baru (contoh: Delayed, On Time, Boarding): ";
            getline(cin, statusBaru);
            penunjukCari->statusTerakhir = statusBaru;
            cout << "Status penerbangan untuk " << kodeUntukDicari << " berhasil diperbarui menjadi: " << statusBaru << endl;
            sudahDitemukan = true;
            break;
        }
        penunjukCari = penunjukCari->nextFlight;
    }

    if (!sudahDitemukan) {
        cout << "Kode penerbangan " << kodeUntukDicari << " tidak ditemukan." << endl;
    }
}

void tampilkanSemuaJadwal() {
    if (daftarPenerbangan == nullptr) {
        cout << "Tidak ada jadwal penerbangan yang tersedia." << endl;
        return;
    }
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                            DAFTAR JADWAL PENERBANGAN                                                  |" << endl;
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "| Kode Penerbangan | Asal Kota      | Tujuan                  | Tanggal    | Waktu | Maskapai        | Status           |" << endl;
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;
    InfoPenerbangan* penunjukTampil = daftarPenerbangan;
    while (penunjukTampil != nullptr) {
        string tanggalFormatted = to_string(penunjukTampil->jadwalWaktu.tanggal);
        if (penunjukTampil->jadwalWaktu.tanggal < 10) tanggalFormatted = "0" + tanggalFormatted;
        string bulanFormatted = to_string(penunjukTampil->jadwalWaktu.bulan);
        if (penunjukTampil->jadwalWaktu.bulan < 10) bulanFormatted = "0" + bulanFormatted;

        string tanggalLengkap = tanggalFormatted + "/" + bulanFormatted + "/" + to_string(penunjukTampil->jadwalWaktu.tahun);

        cout<< "| " << left << setw(17) << penunjukTampil->kodeTerbang
            << "| " << left << setw(15) << penunjukTampil->asalKota
            << "| " << left << setw(24) << penunjukTampil->tujuanAkhir
            << "| " << left << setw(11) << tanggalLengkap
            << "| " << left << setw(6) << penunjukTampil->jadwalWaktu.waktuBerangkat
            << "| " << left << setw(16) << penunjukTampil->maskapai
            << "| " << left << setw(17) << penunjukTampil->statusTerakhir << "|" << endl;
        penunjukTampil = penunjukTampil->nextFlight;
    }
    cout << "+-----------------------------------------------------------------------------------------------------------------------+" << endl;}

void tampilkanMenuUtama() {
    cout << "+------------------------------------------------------------+" << endl;
    cout << "|                 SISTEM JADWAL PENERBANGAN                  |" << endl;
    cout << "|               [Rahmat Riyadi]  [2409106074]                |" << endl;
    cout << "+------------------------------------------------------------+" << endl;
    cout << "| 1. Tambah Jadwal Penerbangan                               |" << endl;
    cout << "| 2. Sisipkan Jadwal Penerbangan                             |" << endl;
    cout << "| 3. Hapus Jadwal Paling Awal                                |" << endl;
    cout << "| 4. Update Status Penerbangan                               |" << endl;
    cout << "| 5. Tampilkan Semua Jadwal                                  |" << endl;
    cout << "| 0. Keluar                                                  |" << endl;
    cout << "+------------------------------------------------------------+" << endl;
    cout << "Pilih menu: ";
}

int main() {
    int pilihanMenu;
    do {
        tampilkanMenuUtama();
        cin >> pilihanMenu;

        switch (pilihanMenu) {
            case 1:
                tambahJadwalBaru();
                break;
            case 2:
                sisipkanJadwalDiTengah();
                break;
            case 3:
                hapusJadwalTerdepan();
                break;
            case 4:
                perbaruiStatusPenerbangan();
                break;
            case 5:
                tampilkanSemuaJadwal();
                break;
            case 0:
                cout << "Terima kasih telah menggunakan sistem jadwal penerbangan." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
        cout << endl;
    } while (pilihanMenu != 0);

    InfoPenerbangan* hapus = daftarPenerbangan;
    while (hapus != nullptr) {
        InfoPenerbangan* penerbanganBerikutnya = hapus->nextFlight;
        delete hapus;
        hapus = penerbanganBerikutnya;
    }

    return 0;
}