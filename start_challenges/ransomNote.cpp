#include <stdlib.h>

#include <iostream>

bool canConstruct(std::string ransomNote, std::string magazine) {
  int size1 = ransomNote.size(), size2 = magazine.size();
  if (size1 > size2) {
    return false;
  }
  int count = 0;
  for (int i = 0; i < size1; i++) {
    for (int j = 0; j < size2; j++) {
      if ((ransomNote[i] == magazine[j]) && (ransomNote[i] != '_')) {
        count++;
        ransomNote[i] = magazine[j] = '_';
      }
    }
  }
  if (size1 == count) {
    return true;
  }
  return false;
}

int main() {
  std::string first = "aab";
  std::string sec = "baa";
  std::cout << canConstruct(first, sec);
}
