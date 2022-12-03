use std::fs;

fn main() {
  println!("RESULT: {}", solve_puzzle("./input2.txt"));
}

fn solve_puzzle(file: &str) -> i32 {
  let mut calories: Vec<i32> = Vec::new();

  match fs::read_to_string(file) {
    Ok(result) => {
      let mut accumulated: i32 = 0;
      for line in result.lines() {
        if line.is_empty() {
          calories.push(accumulated);
          accumulated = 0;
          continue;
        }
        let my_int: i32 = line.parse().unwrap();
        accumulated += my_int;
      }
      calories.sort();
      return calories.pop().unwrap() + calories.pop().unwrap() + calories.pop().unwrap();
    }
    Err(e) => panic!("{}", e),
  }
}
