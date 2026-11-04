#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int main() {
    const int N = 2048;
    // Inisialisasi awal
    vector<int> A(N * N, 1), B(N * N, 2), C(N * N, 0);

    auto start = chrono::high_resolution_clock::now();

    // Loop i-k-j yang dioptimasi untuk Cache RAM
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < N; ++k) {
            int r = A[i * N + k];
            for (int j = 0; j < N; ++j) {
                C[i * N + j] += r * B[k * N + j];
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;
    cout << "Waktu Matriks (Sekuensial C++): " << duration.count() << " ms\n";
    return 0;
}
