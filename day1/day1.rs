use std::fs;

fn main() {
  println!("{}", solve_puzzle("./input.txt"));
}

fn solve_puzzle(file: &str) -> i32 {
  let mut max = 0;
  match fs::read_to_string(file) {
    Ok(result) => {
      let mut accumulated: i32 = 0;
      for line in result.lines() {
        if line.is_empty() {
          if max < accumulated {
            max = accumulated;
          }
          accumulated = 0;
          continue;
        }
        let my_int: i32 = line.parse().unwrap();
        accumulated += my_int;
      }
      return max;
    }
    Err(e) => panic!("{}", e),
  }
}
