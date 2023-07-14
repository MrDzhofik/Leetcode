#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool closeStrings(string word1, string word2) {
  map<char, int> w1;
  map<char, int> w2;
  set<char> wd1;
  set<char> wd2;
  int size1 = word1.size();
  int size2 = word2.size();
  if (size1 != size2) {
    return false;
  }
  for (char i : word1) {
    wd1.insert(i);
    if (w1.count(i) == 0) {
      w1.insert({i, 1});
    } else {
      w1[i]++;
    }
  }
  for (char i : word2) {
    wd2.insert(i);
    if (w2.count(i) == 0) {
      w2.insert({i, 1});
    } else {
      w2[i]++;
    }
  }
  if (wd1 != wd2) {
    return false;
  }
  vector<int> freq1;
  vector<int> freq2;
  map<char, int>::iterator it;
  for (it = w1.begin(); it != w1.end(); it++) {
    freq1.push_back(it->second);
  }
  for (it = w2.begin(); it != w2.end(); it++) {
    freq2.push_back(it->second);
  }
  sort(freq1.begin(), freq1.end());
  sort(freq2.begin(), freq2.end());
  return freq1 == freq2;
}

int main() {
  string word1 = "aabccc";
  string word2 = "ccbaaa";
  cout << closeStrings(word1, word2) << endl;
}