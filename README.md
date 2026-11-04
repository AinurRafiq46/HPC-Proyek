# HPC Proyek - Baseline Sekuensial

Proyek High Performance Computing (HPC) ini bertujuan untuk membandingkan waktu eksekusi algoritma perkalian matriks dan penjumlahan vektor menggunakan C/C++ dan Rust. Repositori ini berisi Fase 1: Implementasi Sekuensial (Baseline).

## Prasyarat Sistem
Pastikan perangkat lunak berikut sudah terinstal di sistem Anda sebelum menguji kode:
* **C++ Compiler**: `g++` (Linux/WSL) atau MinGW/MSVC (Windows)
* **Rust & Cargo**: Toolchain pengembangan bahasa Rust
* **Git**: Untuk mengunduh repositori dari GitHub

## Cara Instalasi

### Untuk Pengguna Debian/Ubuntu/WSL
1. Buka terminal dan instal *compiler* C++ serta Git:
   ```bash
   sudo apt update && sudo apt install build-essential git -y
   ```
2. Instal lingkungan Rust dan Cargo:
   ```bash
   curl --proto '=https' --tlsv1.2 -sSf [https://sh.rustup.rs](https://sh.rustup.rs) | sh
   ```
3. Unduh (clone) repositori ini ke komputer Anda:
   ```bash
   git clone [https://github.com/AinurRafiq46/HPC-Proyek.git](https://github.com/AinurRafiq46/HPC-Proyek.git)
   ```
4. Masuk ke dalam direktori proyek:
   ```bash
   cd HPC-Proyek
   ```

### Untuk Pengguna Windows
1. Unduh dan instal Git dari [git-scm.com](https://git-scm.com/).
2. Unduh penginstal Rust dari [rustup.rs](https://rustup.rs/) dan pastikan menginstal *C++ Build Tools* bawaan Windows saat diminta.
3. Buka Git Bash atau Command Prompt, lalu jalankan perintah berikut untuk mengunduh repositori:
   ```bash
   git clone [https://github.com/AinurRafiq46/HPC-Proyek.git](https://github.com/AinurRafiq46/HPC-Proyek.git)
   ```
4. Masuk ke dalam direktori proyek:
   ```bash
   cd HPC-Proyek
   ```

## Cara Menjalankan Program (Sekuensial)

Jalankan perintah berikut di dalam direktori `HPC-Proyek` untuk melakukan kompilasi dan melihat waktu eksekusinya:

**1. Penjumlahan Vektor (Rust)**
```bash
cargo run --release --bin vektor
```

**2. Perkalian Matriks (Rust)**
```bash
cargo run --release --bin matriks
```

**3. Penjumlahan Vektor (C++)**
```bash
g++ vektor.cpp -O3 -o vektor_cpp && ./vektor_cpp
```

**4. Perkalian Matriks (C++)**
```bash
g++ matriks.cpp -O3 -o matriks_cpp && ./matriks_cpp
```

# Proyek HPC: Sekuensial vs Paralel (MPI)

Repositori ini berisi implementasi algoritma Perkalian Matriks dan Penjumlahan Vektor menggunakan pendekatan sekuensial dan paralel (Message Passing Interface/MPI) dalam bahasa C++ dan Rust. 

Proyek ini bertujuan untuk menganalisis perbandingan waktu eksekusi (*speedup*) dan efisiensi memori (optimasi *Cache Locality*).

## Prasyarat Lingkungan
- OS: Linux / WSL2 Debian
- C++: `g++` dan OpenMPI (`mpic++`, `mpirun`)
- Rust: `cargo`, `rustc`, dan *crate* `mpi`

## Cara Menjalankan Program

### 1. Perkalian Matriks (C++)
- **Sekuensial:** `g++ matriks.cpp -O3 -o matriks_cpp && ./matriks_cpp`
- **MPI (4 Proses):** `mpic++ matriks_mpi.cpp -O3 -o matriks_mpi && mpirun -np 4 ./matriks_mpi`

### 2. Perkalian Matriks (Rust)
- **Sekuensial:** `cargo run --release --bin matriks`
- **MPI (4 Proses):** `cargo build --release --bin matriks_mpi && mpirun -np 4 target/release/matriks_mpi`

## Catatan Hasil (Minggu 2)
Implementasi perkalian matriks ukuran masif ($N=2048$) dengan optimasi urutan loop `i-k-j` (*Cache Locality*) menghasilkan *speedup* lebih dari 2x lipat pada program MPI dibandingkan sekuensial, baik di C++ maupun Rust.
