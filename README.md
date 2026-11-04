# HPC Proyek: Sekuensial vs Paralel (MPI)
Repositori ini berisi implementasi algoritma Perkalian Matriks dan Penjumlahan Vektor menggunakan pendekatan sekuensial dan paralel (Message Passing Interface/MPI) dalam bahasa C++ dan Rust.

## Prasyarat & Instalasi

Sistem yang disarankan adalah Linux/WSL2 (Debian/Ubuntu). Pastikan Anda telah menginstal komponen berikut:

**1. C++ dan OpenMPI**
`sudo apt update && sudo apt install build-essential libopenmpi-dev openmpi-bin git -y`

**2. Rust & Cargo**
`curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh`

## Cara Menjalankan Program

Jalankan perintah berikut di dalam direktori proyek untuk melakukan kompilasi dan eksekusi:

### Perkalian Matriks (N = 2048)
**C++**
- **Sekuensial:** `g++ matriks.cpp -O3 -o matriks_cpp && ./matriks_cpp`
- **MPI (4 Proses):** `mpic++ matriks_mpi.cpp -O3 -o matriks_mpi && mpirun -np 4 ./matriks_mpi`

**Rust**
- **Sekuensial:** `cargo run --release --bin matriks`
- **MPI (4 Proses):** `cargo build --release --bin matriks_mpi && mpirun -np 4 target/release/matriks_mpi`

### Penjumlahan Vektor (N = 200 Juta)
**C++**
- **Sekuensial:** `g++ vektor.cpp -O3 -o vektor_cpp && ./vektor_cpp`
- **MPI (4 Proses):** `mpic++ vektor_mpi.cpp -O3 -o vektor_mpi && mpirun -np 4 ./vektor_mpi`

**Rust**
- **Sekuensial:** `cargo run --release --bin vektor`
- **MPI (4 Proses):** `cargo build --release --bin vektor_mpi && mpirun -np 4 target/release/vektor_mpi`
