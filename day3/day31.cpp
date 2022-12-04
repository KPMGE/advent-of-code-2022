#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int get_letter_weight(char letter);
char find_recurrent_letter(std::string &str);
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

char find_recurrent_letter(std::string &str) {
  for (int i = 0; i < str.length() / 2; i++) {
    for (int j = str.length() / 2; j < str.length(); j++) {
      if (str[i] == str[j]) return str[i];
    }
  }

  std::cout << "not found!";
  return -1;
}

int solve_puzzle(std::vector<std::string> &lines) {
  int sum = 0;
  for (int i = 0; i < lines.size(); i++) {
    char l = find_recurrent_letter(lines[i]);
    sum += get_letter_weight(l);
    std::cout << "recurrent: " << l << "(" << get_letter_weight(l) << ")"<< std::endl;
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
