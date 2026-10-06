#include <iostream>
#include <string>
using namespace std;

int const MAX_SISWA = 100;
int const MAX_HARI = 30;

void tampilanMenu() {
  cout << "=================================\n";

  cout << "0. Keluar\n";
  cout << "1. Tambah Data Siswa\n";
  cout << "2. Tampilkan Data Siswa\n";
  cout << "3. Absensi\n";
  cout << "4. Rekab Absensi\n";
}

void tambahSiswa(int npm[], string nama[], int &jumlahSiswa) {
  cout << "Masukkan npm siswa: ";
  cin >> npm[jumlahSiswa];
  cout << "Masukkan nama siswa: ";
  cin >> nama[jumlahSiswa];

  jumlahSiswa++;
}

void tampilkanDataSiswa(int npm[], string nama[], int jumlahSiswa) {
  for (int i = 0; i < jumlahSiswa; i++) {
    cout << "NPM: " << npm[i] << ", Nama: " << nama[i] << endl;
  }
}

// void catatAbsensi(string nama[],int absensi[][MAX_HARI], int jumlahSiswa, int hari) {
//     cout << "Masukkan data Absensi" << endl;
//
//     if (jumlahSiswa == 0) {
//         cout << "Belum ada data Siswa" << endl;
//     }
//
//     cout << "Absensi hari ke-" << hari + 1 << endl;
//     cout << "1 = Hadir\n";
//     cout << "2 = Izin\n";
//     cout << "3 = Sakit\n";
//     cout << "4 = Alpa\n\n";
//
//     for (int i = 0; i < jumlahSiswa; i++) {
//         cout << "Nama: " << nama[i] << ", Absensi: " << endl;
//         cin >> absensi[i][hari];
//
//     }
//     cout << "Absensi berhasil disimpan!\n";
// }

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
    case 1:
      tambahSiswa(npm, nama, jumlahSiswa);
      break;
    case 2:
      tampilkanDataSiswa(npm, nama, jumlahSiswa);
      break;
    case 3:
        // catatAbsensi(nama, absensi, jumlahSiswa, hari);
        hari++;
        break;
    case 4:

      break;
    default:
      cout << "Pilihan tidak valid!\n";
    }

  } while (pilihan != 0);

  return 0;
}
