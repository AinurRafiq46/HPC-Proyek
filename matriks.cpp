#include <iostream>
#include <vector>
#include <chrono>

int main() {
    int n = 256;
    std::vector<double> a(n * n, 1.0), b(n * n, 2.0), c(n * n, 0.0);

    auto start = std::chrono::high_resolution_clock::now();
    // Urutan iterasi i-k-j untuk optimalisasi cache memory
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                c[i * n + j] += a[i * n + k] * b[k * n + j];
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Waktu eksekusi Perkalian Matriks (C++): " << duration.count() << " ms\n";
    return 0;
}
