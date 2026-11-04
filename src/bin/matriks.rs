use std::time::Instant;

fn main() {
    let n = 2048;
    
    // Inisialisasi awal
    let a = vec![1u32; n * n];
    let b = vec![2u32; n * n];
    let mut c = vec![0u32; n * n];

    let start = Instant::now();

    // Loop i-k-j yang dioptimasi untuk Cache RAM
    for i in 0..n {
        for k in 0..n {
            let r = a[i * n + k];
            for j in 0..n {
                c[i * n + j] += r * b[k * n + j];
            }
        }
    }

    println!("Waktu Matriks (Sekuensial Rust): {:?}", start.elapsed());
}
