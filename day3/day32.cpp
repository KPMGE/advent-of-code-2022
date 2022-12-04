#include <cctype>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int get_letter_weight(char letter);
char find_common_letter(std::vector<std::string> &vec);
int solve_puzzle(std::vector<std::string> &lines);
std::vector<std::string> read_input(std::string file_path);

int main() {
  std::vector<std::string> lines = read_input("input.txt");
  std::cout << "RESULT: " << solve_puzzle(lines);
}

int get_letter_weight(char letter) {
  if (std::isupper(letter)) {
    return int(letter)  - 38;
  }
  return int(letter) - 96;
}

char find_common_letter(std::vector<std::string> &vec) {
  std::cout << "Size: " << vec.size() << "\n";
  std::cout << "str1: " << vec[0] << "\n";
  std::cout << "str1: " << vec[1] << "\n";
  std::cout << "str1: " << vec[2] << "\n";

  for (int i = 0; i < vec[0].length(); i++) {
    for (int j = 0; j < vec[1].length(); j++) {
      for (int k = 0; k < vec[2].length(); k++) {
        if (vec[0][i] == vec[1][j] && vec[0][i] == vec[2][k]) {
          std::cout << "COMMON: " << vec[0][i];
          return vec[0][i];
        }
      }
    }
  }

  return -1;
}

int solve_puzzle(std::vector<std::string> &lines) {
  int sum = 0;
  std::vector<std::string> vec;

  for (int i = 0; i < lines.size() + 1; i++) {
    if (i != 0 && i % 3 == 0) {
      char l = find_common_letter(vec);
      std::cout << "recurrent: " << l << "(" << get_letter_weight(l) << ")"<< std::endl;
      sum += get_letter_weight(l);
      vec.clear();
    }
    vec.push_back(lines[i]);
  }
  return sum;
}

std::vector<std::string> read_input(std::string file_path) {
  std::fstream file;
  file.open(file_path, std::ios::in);

  if (!file) {
    std::cerr << "Could not open file!";
    exit(1);
  }

  std::vector<std::string> lines;
  std::string line;
  while(std::getline(file, line)) {
    lines.push_back(line);
  }

  file.close();

  return lines;
}
