#include <iostream>
#include <string>
#include <vector>

using namespace std;

void remove_extra_spaces(string& input, string& output, int& size) {
  int inputIndex = 0;
  int outputIndex = 0;
  while (inputIndex != size) {
    output += input[inputIndex];

    if (input[inputIndex] == ' ') {
      while (input[inputIndex + 1] == ' ') {
        // skip over any extra spaces
        inputIndex++;
      }
    }

    outputIndex++;
    inputIndex++;
  }
  size = outputIndex;
}
void remove_start_finish_spaces(string& input, string& output, int& size) {
  int inputIndex = 0;
  int outputIndex = 0;
  int finIndex = size - 1;
  while (input[inputIndex] == ' ') {
    inputIndex++;
    size--;
  }
  while (input[finIndex] == ' ') {
    finIndex--;
    size--;
  }
  int index = inputIndex;
  for (int i = 0; i < size; i++) {
    output += input[index];
    index++;
  }
}
string reverseWords(string s) {
  string f;
  int size = s.size();
  remove_start_finish_spaces(s, f, size);
  string rs;
  remove_extra_spaces(f, rs, size);
  string ans;
  vector<string> words;
  string st = "";
  for (int i = 0; i < size; i++) {
    st += rs[i];
    if (rs[i + 1] == ' ' || i + 1 == size) {
      i++;
      words.push_back(st);
      st = "";
    }
  }
  int vec_size = words.size();
  for (int i = vec_size - 1; i >= 0; i--) {
    ans += words[i];
    if (i != 0) {
      ans += ' ';
    }
  }
  return ans;
}

int main() {
  string s = {"   hello world  "};
  string f = {" the sky is blue "};
  string t = {" a good   example "};
  int size = s.size();
  cout << reverseWords(s) << endl;
  cout << reverseWords(f) << endl;
  cout << reverseWords(t) << endl;
}