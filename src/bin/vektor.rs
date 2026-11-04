use std::time::Instant;

fn main() {
    let n = 200_000_000;
    
    let a = vec![1u32; n];
    let b = vec![2u32; n];
    let mut c = vec![0u32; n];

    let start = Instant::now();

    for i in 0..n {
        c[i] = a[i] + b[i];
    }

    println!("Waktu Vektor (Sekuensial Rust): {:?}", start.elapsed());
}
