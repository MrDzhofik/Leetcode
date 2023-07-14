#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
  map<int, int> counts;
  set<int> occur;
  for (int i : arr) {
    if (counts.count(i) > 0) {
      counts[i]++;
    } else {
      counts.insert({i, 1});
    }
  }
  map<int, int>::iterator it = counts.begin();
  for (int i = 0; it != counts.end(); it++, i++) {
    occur.insert(it->second);
  }
  int set_size = occur.size();
  int map_size = counts.size();
  return set_size == map_size;
}

int main() {
  vector<int> f = {1, 2, 2, 1, 1, 3};
  cout << uniqueOccurrences(f) << endl;
  return 0;
}