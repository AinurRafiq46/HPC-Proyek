#include <iostream>
#include <vector>
#include <chrono>
#include <mpi.h>

using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    const int N = 200000000;
    int local_N = N / size;

    vector<int> A, B, C, local_A(local_N), local_B(local_N), local_C(local_N, 0);
    
    if (rank == 0) {
        A.assign(N, 1);
        B.assign(N, 2);
        C.resize(N);
    }

    auto start = chrono::high_resolution_clock::now();

    // Waktu pengiriman data raksasa
    MPI_Scatter(rank == 0 ? A.data() : NULL, local_N, MPI_INT, local_A.data(), local_N, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(rank == 0 ? B.data() : NULL, local_N, MPI_INT, local_B.data(), local_N, MPI_INT, 0, MPI_COMM_WORLD);

    for (int i = 0; i < local_N; ++i) {
        local_C[i] = local_A[i] + local_B[i];
    }

    MPI_Gather(local_C.data(), local_N, MPI_INT, rank == 0 ? C.data() : NULL, local_N, MPI_INT, 0, MPI_COMM_WORLD);

    auto end = chrono::high_resolution_clock::now();
    if (rank == 0) {
        chrono::duration<double, std::milli> duration = end - start;
        cout << "Waktu Vektor (MPI C++ 4 Proses): " << duration.count() << " ms\n";
    }

    MPI_Finalize();
    return 0;
}
