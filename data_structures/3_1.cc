// Victor Guerra <vguerra@gmail.com>
// 20141031

#include <cstdlib>
#include <iostream>
#include <string>
#include <stack>
#include <utility>

uint32_t scan_parens(std::string str) {
  std::stack<uint16_t> ctrl_parens;
  for (uint16_t pos = 1; pos <= str.length(); ++pos) {
    char c = str[pos - 1];
    switch (c) {
      case '(' : 
        ctrl_parens.push(pos);
        break;
      case ')' : 
        if (!ctrl_parens.empty()) {
          ctrl_parens.pop();
        } else {
          return pos;
        }
        break;
    }
  }
  if (!ctrl_parens.empty()) {
    return ctrl_parens.top();
  }
  return 0;
}

int main() {
  std::string line;
  while (std::getline(std::cin, line)) {
    std::cout << scan_parens(line) << "\n";
  }
  return EXIT_SUCCESS;
}
