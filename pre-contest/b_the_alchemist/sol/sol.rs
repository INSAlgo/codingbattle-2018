use std::io;
use std::f32;
use std::cmp;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();

    let v: Vec<i32> = line.trim()
        .split(' ')
        .map(|x| x.parse::<i32>().unwrap())
        .collect();
    let (p, l, g) = (v[0], v[1], v[2]);

    let max_x = cmp::min((g as f32).sqrt().ceil() as i32, p);

    let mut counter = 0;
    for x in 0..max_x {
        for y in 0..l {
            let r = x * x + y + x * y;
            if r == g {
                counter += 1;
            } else if r > g {
                break;
            }
        }
    }

    println!("{}", counter);
}

