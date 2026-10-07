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
  cout << "5. Urutkan Data Siswa Berdasarkan NPM\n";
  cout << "Masukan Pilihan Menu (0-5) : ";
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
    cout << "NPM: " << npm[i] << ", \tNama: " << nama[i] << endl;
  }
}

void catatAbsensi(string nama[],int absensi[][MAX_HARI], int jumlahSiswa, int hari) {
    
    cout << "Masukkan data Absensi" << endl;

    if (jumlahSiswa == 0) {
        cout << "Belum ada data Siswa" << endl;
    }

    cout << "Absensi hari ke-" << hari + 1 << endl;
    cout << "1 = Hadir\n";
    cout << "2 = Izin\n";
    cout << "3 = Sakit\n";
    cout << "4 = Alpa\n\n";

    for (int i = 0; i < jumlahSiswa; i++) {
        cout << "Nama: " << nama[i] << ", Absensi: ";
        cin >> absensi[i][hari];

    }
    cout << "Absensi berhasil disimpan!\n";
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
        cout<<"Keluar";
        break;
    case 1:
      tambahSiswa(npm, nama, jumlahSiswa);
      break;
    case 2:
      tampilkanDataSiswa(npm, nama, jumlahSiswa);
      break;
    case 3:
        catatAbsensi(nama, absensi, jumlahSiswa, hari);
        hari++;
        break;
    case 4:

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
