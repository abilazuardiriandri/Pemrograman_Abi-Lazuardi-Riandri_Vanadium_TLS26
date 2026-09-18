#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    
    cout << "Masukkan jumlah astronot (N): ";
    if (!(cin >> N) || N <= 0) {
        cout << "Input tidak valid." << endl;
        return 0;
    }
    
    cout << "Masukkan nilai K awal: ";
    if (!(cin >> K) || K <= 0) {
        cout << "Input tidak valid." << endl;
        return 0;
    }

    // Inisialisasi daftar astronot dari 1 hingga N
    vector<int> astronot;
    for (int i = 1; i <= N; ++i) {
        astronot.push_back(i);
    }

    int idx = 0; // Menandai titik awal perhitungan
    cout << "\nUrutan astronot yang dieliminasi:\n";
    
    // Proses eliminasi hingga menyisakan 1 astronot
    while (astronot.size() > 1) {
        // Tentukan indeks astronot yang dieliminasi
        int target_idx = (idx + K - 1) % astronot.size();
        int eliminated_id = astronot[target_idx];

        cout << "Astronot " << eliminated_id << " dieliminasi.\n";

        // Hapus astronot dari lingkaran
        astronot.erase(astronot.begin() + target_idx);
        
        // Perhitungan berikutnya dimulai dari posisi astronot tepat setelahnya
        idx = target_idx;
        if (idx >= astronot.size()) {
            idx = 0;
        }

        // Aturan perubahan nilai K
        if (eliminated_id % 2 == 0) {
            K += 2; // Jika nomor astronot genap, K bertambah 2
        } else {
            K -= 1; // Jika nomor astronot ganjil, K berkurang 1
        }

        // K tidak boleh kurang dari 2
        if (K < 2) {
            K = 2;
        }
    }

    // Astronot yang tersisa
    cout << "\nAstronot terakhir yang bertahan: astronot " << astronot[0] << endl;

    return 0;
}