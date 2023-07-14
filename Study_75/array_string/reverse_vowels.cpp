#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string reverseVowels(string s) {
  vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  vector<int> indexes;
  int size = s.size();
  for (int i = 0; i < size; i++) {
    if ((std::find(vowels.begin(), vowels.end(), s[i]) != vowels.end()) &&
        (std::find(indexes.begin(), indexes.end(), i) == indexes.end())) {
      for (int j = size - 1; j > i; j--) {
        if ((std::find(vowels.begin(), vowels.end(), s[j]) != vowels.end()) &&
            ((std::find(indexes.begin(), indexes.end(), j)) == indexes.end())) {
          char temp = s[i];
          s[i] = s[j];
          s[j] = temp;
          indexes.push_back(i);
          indexes.push_back(j);
          break;
        }
      }
    }
  }
  return s;
}

int main() {
  string f{"aA"};
  string s{"leetcode"};
  cout << reverseVowels(f) << endl;
  cout << reverseVowels(s) << endl;
}
