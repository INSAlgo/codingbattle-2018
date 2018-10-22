use std::char;
use std::io;
use std::collections::HashMap;

fn main() {
    // Input: start
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let mut number = line.trim().to_string();

    // Input: n
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let n = line.trim().parse::<i32>().unwrap();

    let mut todo_rename = HashMap::new();

    // n steps
    let mut i = 0;
    while i < n {
        number = next(&number);

        if let Some(idx) = todo_rename.get(&number).cloned() {
            let diff = i - idx;
            let skip = (n - i - 1) / diff;
            i += skip * diff + 1;
        } else {
            todo_rename.insert(number.clone(), i);
            i += 1;
        }
    }

    println!("{}", number);
}

fn next(number: &String) -> String {
    let mut count = [0; 10];
    for c in number.chars() {
        count[c.to_digit(10).unwrap() as usize] += 1;
    }

    let mut chars = String::new();
    for (i, n) in count.iter().enumerate() {
        if *n > 0 {
            chars.push(char::from_digit(*n as u32, 10).unwrap());
            chars.push(char::from_digit(i as u32, 10).unwrap());
        }
    }
    chars
}
