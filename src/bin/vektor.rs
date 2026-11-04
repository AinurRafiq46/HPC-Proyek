use std::time::Instant;

fn main() {
    let n = 1_000_000; 
    let a = vec![1.0f64; n]; // Vektor A berisi angka 1.0
    let b = vec![2.0f64; n]; // Vektor B berisi angka 2.0
    let mut c = vec![0.0f64; n]; // Vektor C untuk hasil

    let start = Instant::now();
    for i in 0..n {
        c[i] = a[i] + b[i];
    }
    let duration = start.elapsed();

    println!("Waktu eksekusi Penjumlahan Vektor: {:?}", duration);
}
