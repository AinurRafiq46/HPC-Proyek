use mpi::traits::*;
use std::time::Instant;

fn main() {
    let universe = mpi::initialize().unwrap();
    let world = universe.world();
    let size = world.size() as usize;
    let rank = world.rank();

    let n = 200_000_000;
    let local_n = n / size;

    let a = if rank == 0 { vec![1u32; n] } else { vec![] };
    let b = if rank == 0 { vec![2u32; n] } else { vec![] };
    let mut c = if rank == 0 { vec![0u32; n] } else { vec![] };

    let mut local_a = vec![0u32; local_n];
    let mut local_b = vec![0u32; local_n];
    let mut local_c = vec![0u32; local_n];

    let root = world.process_at_rank(0);
    let start = Instant::now();

    if rank == 0 {
        root.scatter_into_root(&a[..], &mut local_a[..]);
        root.scatter_into_root(&b[..], &mut local_b[..]);
    } else {
        root.scatter_into(&mut local_a[..]);
        root.scatter_into(&mut local_b[..]);
    }

    for i in 0..local_n {
        local_c[i] = local_a[i] + local_b[i];
    }

    if rank == 0 {
        root.gather_into_root(&local_c[..], &mut c[..]);
        println!("Waktu Vektor (MPI Rust 4 Proses): {:?}", start.elapsed());
    } else {
        root.gather_into(&local_c[..]);
    }
}
