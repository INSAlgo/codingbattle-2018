use std::io;

fn main() {
    let b = read_int();
    let t = read_int();
    let n = read_int();

    if 2 * b + 3 * t <= n {
        println!("LOOT!");
    } else {
        println!("RHUM!");
    }
}

fn read_int() -> i32 {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line.trim().parse().unwrap()
}
