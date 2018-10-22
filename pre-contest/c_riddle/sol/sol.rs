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

    // We create a map to detect cycles.
    // Hint: go have a look into Rust's FAQ about the implementation of
    // this HashMap.
    let mut cycle_detection = HashMap::new();

    // n steps
    let mut i = 0;
    while i < n {
        number = next(&number);

        // Check if the number has already been met, which would mean
        // that there is a cycle. Good news!
        if let Some(idx) = cycle_detection.get(&number).cloned() {
            // We have to determine the length of our jump.
            // Indeed, we know that in exactly `i - idx` steps, we'll end up with
            // the same number, so why bother? We have to be careful though not to
            // to make a jump too long, because otherwise the output number
            // would be wrong.
            // If we knew that cycles are of "reasonable" length, we could store
            // the sequence of seen numbers in order to be able to return the right
            // number using a simple subtraction. But optimization is led by benchmarks,
            // and this implementation is fast enough.
            let diff = i - idx;
            let skip = (n - i - 1) / diff;
            i += skip * diff + 1;
        } else {
            // Here, no cycle. Just add this number to the map and increase i by 1.
            cycle_detection.insert(number.clone(), i);
            i += 1;
        }
    }

    // We have a result! \o\ /o/
    println!("{}", number);
}

/// Generate the next number is the sequence.
fn next(number: &String) -> String {
    // Count occurrences of each digits in the current number.
    // Note: a Vec isn't needed here since we know the length at compilation time.
    let mut count = [0; 10];
    for c in number.chars() {
        count[c.to_digit(10).unwrap() as usize] += 1;
    }

    // Create the new number by just going through the counter.
    let mut chars = String::new();
    for (i, n) in count.iter().enumerate() {
        if *n > 0 {
            chars.push(char::from_digit(*n as u32, 10).unwrap());
            chars.push(char::from_digit(i as u32, 10).unwrap());
        }
    }
    chars
}
