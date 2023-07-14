#include <iostream>

using namespace std;

string mergeAlternately(string word1, string word2) {
  int size1 = word1.size();
  int size2 = word2.size();
  int size = size1 > size2 ? size2 : size1;
  int i = 0;
  std::cout << size;
  string ans;
  for (i = 0; i < size; i++) {
    std::cout << i;
    ans += word1[i];
    ans += word2[i];
  }
  std::cout << i;
  if (size1 > size2) {
    for (int j = i; j < size1; j++) {
      ans += word1[j];
    }
  }
  if (size2 > size1) {
    for (int j = i; j < size2; j++) {
      ans += word2[j];
    }
  }
  return ans;
}

int main() {
  string f = {"abc"};
  string s = {"pqr"};
  std::cout << mergeAlternately(f, s);
}