#include <iostream>                         // Memasukkan library iostream
using namespace std;                        // Menghilangkan kebutuhan untuk menambahkan std:: disetiap objek namespace c++
int main(){                                 // Main function
    long long CardNumber;                   // Variable penampung inputan numcard (Menggunakan long long agar dpt menampung ke-16 digit tsb)
    cout << "Masukkan Angka Kartu : ";      // Meminta user memasukkan CardNumber
    cin >> CardNumber;                     // Menerima input user sebagai CardNumber
    cout << "Nomor Kartu Anda : " << CardNumber;       // Menampilkan CardNumber yang telah diinput user

    int Mastercard  = CardNumber / 100000000000000;     // Menggunakan 15 Digit untuk mengecek tipe kartu mastercard yang berdigit total 16 dan angka penentu adalah 2 digit didepan
    int VisaLong    = CardNumber / 1000000000000000;    // Menggunakan 16 digit untuk mengecek tipe kartu Visa yang berdigit total 16 dan angka penentu adalah digit pertama
    int VisaShort   = CardNumber / 1000000000000;       // Menggunakan 13 digit untuk mengecek tipe kartu Visa yang berdigit total 13 dan angka penentu adalah digit pertama 
    int plusNumber = 0;                                 // Variable ruang penyimpanan penjumlahan digit CardNumber
    
    // Algoritma Luhn
    do{                                                        // Lakukan
        int lastNumber = CardNumber % 10;                      // Mengambil digit terakhir dari CardNumber
        plusNumber += lastNumber;                              // Menambahkan digit terakhir tadi ke variable plusNumber
        CardNumber /= 10;                                      // Menghapus digit terakhir dari CardNumber
        int multipleLastNum = (CardNumber % 10) * 2;           // Mengambil digit terakhir dan dikali 2
        if(multipleLastNum >= 10){                             // Jika digit terakhir yg dikali 2 lebih besar atau sama dengan 10
            multipleLastNum = (multipleLastNum % 10) + 1;      // Ambil digit terakhirnya dan tambah dengan 1
        }
        plusNumber += multipleLastNum;                         // Menambahkan angka yg sudah diolah diatas
        CardNumber /= 10;                                      // Menghapus digit terakhir dari CardNumber
    } while(CardNumber != 0);                                  // Kerjakan program diatas ketika CardNumber tidak sama dengan 0

    // Menenetukan tipe kartu
    if(plusNumber % 10 == 0){                                  //  Jika hasil penjumlahan pada algoritma luhn mod 10 sama dengan 0
        if(Mastercard == 51 || Mastercard == 52 || Mastercard == 53 || Mastercard == 54 || Mastercard == 55){
            cout << "\nTipe Kartu Anda : Mastercard";          // Jika 2 digit awal pada CardNumber bernilai 51-55, cetak ini 
        }
        else if(VisaLong == 4 || VisaShort == 4){
            cout << "\nTipe Kartu Anda : Visa";                // Atau, jika digit pertama pada CardNumber bernilai 4, cetak ini
        }
        else{
            cout << "\nTipe Kartu Anda : Tidak Diketahui";     // Selain 2 kriteria di atas, cetak ini
        }
    }
    else{
        cout << "\nTipe Kartu Anda : Tidak Valid";            // Jika hasil penjumlahan pada algoritma luhn mod 10 tidak sama dengan 0, cetak ini
    }
    cout << "\nChecksum : " << plusNumber;                     // Tampilkan hasil penjumlahan pada algoritma luhn mod 10
}
