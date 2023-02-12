use rand::Rng;

fn main() {
    let mut circle = 0;
    let mut cartioid = 0;
    let mut rng = rand::thread_rng();

    for _ in 0..2000 {
        let a = rng.gen_range(-1.0..1.0);
        let b = rng.gen_range(-1.0..1.0);
        let s = a * a + b * b;
        if s < 1.0 {
            circle += 1;
        }
        if s * s + a * s - 0.25 * b * b < 0.0 {
            cartioid += 1;
        }
        println!("{:.30}", cartioid as f64 / circle as f64);
    }
}
