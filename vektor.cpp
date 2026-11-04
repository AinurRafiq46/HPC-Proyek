#include <iostream>
#include <vector>
#include <chrono>

int main() {
    int n = 1000000;
    std::vector<double> a(n, 1.0), b(n, 2.0), c(n, 0.0);

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Waktu eksekusi Penjumlahan Vektor (C++): " << duration.count() << " ms\n";
    return 0;
}
