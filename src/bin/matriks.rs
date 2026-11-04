use std::time::Instant;

fn main() {
    let n = 256; 
    let a = vec![1.0f64; n * n];
    let b = vec![2.0f64; n * n];
    let mut c = vec![0.0f64; n * n];

    let start = Instant::now();
    // Menggunakan urutan loop i-k-j untuk optimalisasi cache CPU (standar HPC)
    for i in 0..n {
        for k in 0..n {
            for j in 0..n {
                c[i * n + j] += a[i * n + k] * b[k * n + j];
            }
        }
    }
    let duration = start.elapsed();

    println!("Waktu eksekusi Perkalian Matriks: {:?}", duration);
}
