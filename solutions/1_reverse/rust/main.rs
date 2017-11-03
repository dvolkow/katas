fn main() {
    use std::io;

    let mut input = String::new();
    match io::stdin().read_line(&mut input) {
        Ok(n) => {
            input.remove(n-1);
            let reversed: String = input.chars().rev().collect(); 
            println!("{}", reversed);
        }
        Err(error) => println!("error: {}", error),
    }
}
