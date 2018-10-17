use std::io;
use std::cmp::Ordering;

fn main() {
    // I don't check errors since we are in a contest.
    // Moreover, using the crate text_io can reduce
    // all this code to a simple read!(), but it's not
    // available during contests.
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let n = line.trim().parse::<i32>().unwrap();

    // I could have used a standard if construction, but
    // where is the fun in that? ;)
    println!("{}", match 42.cmp(&n) {
        Ordering::Greater => "More",
        Ordering::Less => "Less",
        Ordering::Equal => "Bingo!",
    });
}

