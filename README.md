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
