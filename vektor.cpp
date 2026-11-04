#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int main() {
    const int N = 200000000; // 200 Juta data
    
    // Alokasi memori raksasa
    vector<int> A(N, 1), B(N, 2), C(N, 0);

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < N; ++i) {
        C[i] = A[i] + B[i];
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;
    cout << "Waktu Vektor (Sekuensial C++): " << duration.count() << " ms\n";
    return 0;
}
