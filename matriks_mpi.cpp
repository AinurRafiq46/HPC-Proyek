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

    const int N = 2048;
    int local_N = N / size;

    vector<int> A, B(N * N, 2), C, local_A(local_N * N), local_C(local_N * N, 0);
    if (rank == 0) {
        A.assign(N * N, 1);
        C.assign(N * N, 0);
    }

    auto start = chrono::high_resolution_clock::now();

    // Distribusi memori ke tiap prosesor
    MPI_Bcast(B.data(), N * N, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(rank == 0 ? A.data() : NULL, local_N * N, MPI_INT, local_A.data(), local_N * N, MPI_INT, 0, MPI_COMM_WORLD);

    // Loop i-k-j yang dioptimasi untuk Cache RAM
    for (int i = 0; i < local_N; ++i) {
        for (int k = 0; k < N; ++k) {
            int r = local_A[i * N + k];
            for (int j = 0; j < N; ++j) {
                local_C[i * N + j] += r * B[k * N + j];
            }
        }
    }

    // Mengumpulkan kembali hasil dari tiap prosesor
    MPI_Gather(local_C.data(), local_N * N, MPI_INT, rank == 0 ? C.data() : NULL, local_N * N, MPI_INT, 0, MPI_COMM_WORLD);

    auto end = chrono::high_resolution_clock::now();
    if (rank == 0) {
        chrono::duration<double, std::milli> duration = end - start;
        cout << "Waktu Matriks (MPI C++ 4 Proses): " << duration.count() << " ms\n";
    }

    MPI_Finalize();
    return 0;
}
