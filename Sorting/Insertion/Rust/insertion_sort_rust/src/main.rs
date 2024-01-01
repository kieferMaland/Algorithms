// Import the 'env' module for working with environment variables and command line arguments.
use std::env;
// Import 'Rng' trait to allow the use of methods that generate random numbers.
use rand::Rng;
// Import 'Instant' for measuring time durations.
use std::time::Instant;

// Define a function for the insertion sort algorithm that operates on a mutable vector of i32.
fn insertion_sort(arr: &mut Vec<i32>) {
    // Iterate over the elements of the vector starting from the second element.
    for i in 1..arr.len() {
        // 'key' is the value currently being compared. Use 'let' to bind 'key' to the value of arr[i].
        let key = arr[i];
        // 'j' is the position where 'key' will be inserted. It is mutable so it can be decremented.
        let mut j = i;
        // Loop to move elements that are greater than 'key' to one position ahead of their current position.
        while j > 0 && arr[j - 1] > key {
            // Move the value at 'j-1' up one position. Mutable access to 'arr' is required.
            arr[j] = arr[j - 1];
            // Decrement 'j' to find the correct position to insert 'key'.
            j -= 1;
        }
        // Insert 'key' into the vector at the correct position.
        arr[j] = key;
    }
}

// The 'main' function serves as the entry point for the program.
fn main() {
    // Collect command line arguments into a vector of strings.
    let args: Vec<String> = env::args().collect();
    // Parse the second argument as the size for the array. 'expect' will panic if the argument cannot be parsed to an integer.
    let size: usize = args[1].parse().expect("Please provide the array size as an integer.");

    // Instantiate a random number generator specific to the current thread.
    let mut rng = rand::thread_rng();
    // Create a vector of random numbers using a closure that generates a number for each element in the given range.
    let mut numbers: Vec<i32> = (0..size).map(|_| rng.gen_range(0..1000)).collect();

    // Check if a third argument is present and equals "print".
    if args.len() > 2 && args[2] == "print" {
        // Print the unsorted vector to the console using the debug formatter, denoted by '{:?}'.
        println!("Initial array: {:?}", numbers);
    }

    // Record the current time.
    let now = Instant::now();

    // Perform the insertion sort on the vector of numbers.
    insertion_sort(&mut numbers);

    // Calculate the elapsed time since 'now' was recorded.
    let elapsed = now.elapsed();
    // Print the elapsed time using the debug formatter.
    if args.len() > 2 && args[2] == "print"{
			println!("Elapsed: {:.2?}", elapsed);
		}
		else {
			println!("{:.10}", elapsed.as_secs_f64());
		}

    // Check again if "print" was passed as an argument.
    if args.len() > 2 && args[2] == "print" {
        // Print the sorted vector to the console.
        println!("Sorted array: {:?}", numbers);
    }
}
