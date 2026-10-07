#include <iostream>
#include <string>
using namespace std;

int const MAX_SISWA = 100;
int const MAX_HARI = 30;

// Deklarasi fungsi
void tampilanMenu();
void tambahSiswa(int npm[], string nama[], int &jumlahSiswa);
void tampilkanDataSiswa(int npm[], string nama[], int jumlahSiswa);
void catatAbsensi(string nama[], int absensi[][MAX_HARI], int jumlahSiswa, int hari);
void rekapAbsensi(int npm[], string nama[], int absensi[][MAX_HARI], int jumlahSiswa, int hari);
void urutkanNPM(int npm[], string nama[], int absensi[][MAX_HARI], int jumlahSiswa, int hari);

void tampilanMenu() {
  cout << "=================================\n";
  cout << "0. Keluar\n";
  cout << "1. Tambah Data Siswa\n";
  cout << "2. Tampilkan Data Siswa\n";
  cout << "3. Absensi\n";
  cout << "4. Rekap Absensi\n";
  cout << "5. Urutkan Data Siswa Berdasarkan NPM\n";
  cout << "=================================\n";
  cout << "Masukan Pilihan Menu (0-5) : ";
}

void tambahSiswa(int npm[], string nama[], int &jumlahSiswa) {
    if (jumlahSiswa >= MAX_SISWA) {
    cout << "Kapasitas siswa penuh!\n";
    return;
  }

  cout << "Masukkan npm siswa: ";
  cin >> npm[jumlahSiswa];

  cin.ignore();
  cout << "Masukkan nama siswa: ";
  getline(cin, nama[jumlahSiswa]);

  jumlahSiswa++;
  cout << "Data siswa berhasil ditambahkan!\n";
}

void tampilkanDataSiswa(int npm[], string nama[], int jumlahSiswa) {
  if (jumlahSiswa == 0) {
    cout << "Belum ada data siswa!\n";
    return;
  }
  for (int i = 0; i < jumlahSiswa; i++) {
    cout << "NPM: " << npm[i] << ", \tNama: " << nama[i] << endl;
  }
}

void catatAbsensi(string nama[],int absensi[][MAX_HARI], int jumlahSiswa, int hari) {
    
    cout << "Masukkan data Absensi" << endl;

    if (jumlahSiswa == 0) {
        cout << "Belum ada data Siswa" << endl;
        return;
    }

     if (hari >= MAX_HARI) {
    cout << "Batas maksimum pencatatan hari (" << MAX_HARI << " hari) telah tercapai!\n";
    return;
  }

    cout << "Absensi hari ke-" << hari + 1 << endl;
    cout << "1 = Hadir\n";
    cout << "2 = Izin\n";
    cout << "3 = Sakit\n";
    cout << "4 = Alpa\n\n";

for (int i = 0; i < jumlahSiswa; i++) {
    int statusAbsensi;

  // Validasi input status absensi
    do {
        cout << "Masukkan status absensi untuk " << nama[i] << ": ";
        cin >> statusAbsensi;

        if (statusAbsensi < 1 || statusAbsensi > 4) {
            cout << "Input tidak valid! Silakan masukkan angka antara 1 hingga 4.\n";
        }
    } while (statusAbsensi < 1 || statusAbsensi > 4);
 

    // Simpan data setelah input dipastikan benar
    absensi[i][hari] = statusAbsensi;
  }
  cout << "Absensi hari ke-" << (hari + 1) << " berhasil disimpan!\n";
}

// Fungsi untuk menampilkan rekap absensi
void rekapAbsensi(int npm[], string nama[], int absensi[][MAX_HARI], int jumlahSiswa, int hari) {
  if (jumlahSiswa == 0) {
    cout << "Belum ada data siswa!\n";
    return;
  }

  if (hari == 0) {
    cout << "Belum ada data absensi yang dicatat!\n";
    return;
  }

  cout << "Rekap Absensi Siswa:\n";
  cout << "NPM\tNama\t\tHadir\tIzin\tSakit\tAlpa\n";

  for (int i = 0; i < jumlahSiswa; i++) {
    int hadir = 0, izin = 0, sakit = 0, alpa = 0;

    for (int j = 0; j < hari; j++) {
      switch (absensi[i][j]) {
        case 1: hadir++; break;
        case 2: izin++; break;
        case 3: sakit++; break;
        case 4: alpa++; break;
      }
    }

    cout << npm[i] << "\t" << nama[i] << "\t\t" << hadir << "\t" << izin << "\t" << sakit << "\t" << alpa << endl;
  }
}

//mengurutkan data absensi berdasarkan npm
void urutkanNPM(int npm[], string nama[], int absensi[][MAX_HARI], int jumlahSiswa, int hari) {
  if (jumlahSiswa == 0) {
    cout << "Belum ada data siswa untuk diurutkan!\n";
    return;
  }

  if (jumlahSiswa == 1) {
    cout << "Hanya ada satu siswa, tidak perlu diurutkan.\n";
    return;
  }

  // Algoritma Bubble Sort
  for (int i = 0; i < jumlahSiswa - 1; i++) {
    for (int j = 0; j < jumlahSiswa - i - 1; j++) {
      if (npm[j] > npm[j + 1]) {
        // 1. Tukar posisi NPM
        int tempNPM = npm[j];
        npm[j] = npm[j + 1];
        npm[j + 1] = tempNPM;

        // 2. Tukar posisi Nama (agar tetap sinkron dengan NPM)
        string tempNama = nama[j];
        nama[j] = nama[j + 1];
        nama[j + 1] = tempNama;

        // 3. Tukar posisi riwayat absensi harian (Array 2D)
        for (int h = 0; h < hari; h++) {
          int tempAbsen = absensi[j][h];
          absensi[j][h] = absensi[j + 1][h];
          absensi[j + 1][h] = tempAbsen;
        }
      }
    }
  }

  cout << "Data siswa berhasil diurutkan berdasarkan NPM!\n";
}

int main() {

  int jumlahSiswa = 0;
  int npm[MAX_SISWA];
  string nama[MAX_SISWA];
  int hari = 0;
  int absensi[MAX_SISWA][MAX_HARI];

  int pilihan;
  do {
    tampilanMenu();
    cin >> pilihan;

    switch (pilihan) {
    case 0:
      cout << "Keluar dari program. Terima kasih!\n";
      break;
    case 1:
      tambahSiswa(npm, nama, jumlahSiswa);
      break;
    case 2:
      tampilkanDataSiswa(npm, nama, jumlahSiswa);
      break;
    case 3:
      if (jumlahSiswa == 0) {
          cout << "Belum ada data Siswa!\n";
      } else if (hari < MAX_HARI) {
          catatAbsensi(nama, absensi, jumlahSiswa, hari);
          hari++; 
      } else {
          cout << "Batas maksimum pencatatan hari telah tercapai!\n";
      }
      break;
    case 4:
      rekapAbsensi(npm, nama, absensi, jumlahSiswa, hari);
      break;
    case 5:
      urutkanNPM(npm, nama, absensi, jumlahSiswa, hari); // Memanggil fungsi sorting
      break;
    default:
      cout << "Pilihan tidak valid!\n";
    }
  } while (pilihan != 0);

  return 0;
}
