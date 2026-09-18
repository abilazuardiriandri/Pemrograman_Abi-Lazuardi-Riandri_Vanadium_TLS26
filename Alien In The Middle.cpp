#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string pesan_asli;
    cout << "Masukkan pesan asli: ";
    cin >> pesan_asli;

    string pesan_sandi = "";

    if (!pesan_asli.empty()) {
        // Huruf pertama tidak mengalami perubahan
        pesan_sandi += toupper(pesan_asli[0]);

        // Proses setiap huruf berikutnya mulai dari indeks ke-1
        for (size_t i = 1; i < pesan_asli.length(); ++i) {
            char char_skrg = toupper(pesan_asli[i]);
            char char_sebelumnya = toupper(pesan_asli[i - 1]);

            // Hitung posisi huruf dalam alfabet (A = 1, B = 2, ..., Z = 26)
            int val_skrg = char_skrg - 'A' + 1;
            int val_sebelumnya = char_sebelumnya - 'A' + 1;

            // Pergeseran berdasarkan nilai huruf asli sebelumnya
            int val_baru = val_skrg + val_sebelumnya;

            // Jika nilai melebihi Z (26), perhitungan kembali dari A
            if (val_baru > 26) {
                val_baru -= 26;
            }

            // Kembalikan posisi angka ke karakter huruf C++
            char huruf_baru = 'A' + (val_baru - 1);
            pesan_sandi += huruf_baru;
        }
    }

    cout << "Pesan ter-sandi: " << pesan_sandi << endl;

    return 0;
}