#include <iostream>
#include <string>

class Solution {
 public:
  char symbols[8] = {'I', 'V', 'X', 'L', 'C', 'D', 'M', '\0'};
  int values[7] = {1, 5, 10, 50, 100, 500, 1000};
  int find_index(char sym) {
    for (int i = 0; i < 8; i++) {
      if (symbols[i] == sym) {
        return i;
      }
    }
  }
  int romanToInt(std::string s) {
    int ans = 0;
    int curr = 0;
    for (int i = 0; i < s.size() - 1; i++) {
      curr = values[find_index(s[i])];
      if (curr >= values[find_index(s[i + 1])]) {
        ans += curr;
      } else {
        ans -= curr;
      }
    }
    ans += values[find_index(s[s.size() - 1])];
    return ans;
  }
};

int main() {
  Solution arr;
  std::cout << arr.romanToInt("MM") << std::endl;       // 2000
  std::cout << arr.romanToInt("XXI") << std::endl;      // 21
  std::cout << arr.romanToInt("MCMXC") << std::endl;    // 1990
  std::cout << arr.romanToInt("MDCLXVI") << std::endl;  // 1666
  std::cout << arr.romanToInt("MMVIII") << std::endl;   // 2008
}