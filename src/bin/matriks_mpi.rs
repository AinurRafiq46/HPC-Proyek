use mpi::traits::*;
use std::time::Instant;

fn main() {
    let universe = mpi::initialize().unwrap();
    let world = universe.world();
    let size = world.size() as usize;
    let rank = world.rank();

    let n = 2048;
    let local_n = n / size;

    let a = if rank == 0 { vec![1u32; n * n] } else { vec![] };
    let mut b = vec![2u32; n * n];
    let mut c = if rank == 0 { vec![0u32; n * n] } else { vec![] };

    let mut local_a = vec![0u32; local_n * n];
    let mut local_c = vec![0u32; local_n * n];

    let root = world.process_at_rank(0);
    let start = Instant::now();

    // Distribusi memori ke tiap prosesor
    root.broadcast_into(&mut b[..]);

    if rank == 0 {
        root.scatter_into_root(&a[..], &mut local_a[..]);
    } else {
        root.scatter_into(&mut local_a[..]);
    }

    // Loop i-k-j yang dioptimasi untuk Cache RAM
    for i in 0..local_n {
        for k in 0..n {
            let r = local_a[i * n + k];
            for j in 0..n {
                local_c[i * n + j] += r * b[k * n + j];
            }
        }
    }

    // Mengumpulkan kembali hasil dari tiap prosesor
    if rank == 0 {
        root.gather_into_root(&local_c[..], &mut c[..]);
        println!("Waktu Matriks (MPI Rust 4 Proses): {:?}", start.elapsed());
    } else {
        root.gather_into(&local_c[..]);
    }
}
