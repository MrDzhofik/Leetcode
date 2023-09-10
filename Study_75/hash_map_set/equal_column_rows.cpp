#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int equalPairs(vector<vector<int>> &grid) {
  map<string, int> col;
  int n = grid.size();
  int ans = 0;
  string str;
  string curr = "";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      curr += to_string(grid[i][j]);
      curr += "_";
    }
    str = curr;
    curr = "";
    col[str]++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      curr += to_string(grid[j][i]);
      curr += "_";
    }
    str = curr;
    curr = "";
    if (col.find(str) != col.end()) {
      ans += col[str];
    }
  }
  return ans;
}

int main() {
  vector<vector<int>> f = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
  vector<vector<int>> s = {
      {3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
  vector<vector<int>> t = {{11, 1}, {1, 11}};
  cout << equalPairs(f) << endl;
  cout << equalPairs(s) << endl;
  cout << equalPairs(t) << endl;
  return 0;
}