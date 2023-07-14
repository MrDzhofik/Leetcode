#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& nums, int size) {
  int temp;
  int step;
  int k;
  for (int i = 0; i < size - 1; i++) {
    if (nums[i] == 0) {
      step = 1;
      k = i;
      for (int j = i; j < size - 1; j++) {
        if (k + step < size && nums[k + step] != 0) {
          temp = nums[k];
          nums[k] = nums[k + step];
          nums[k + step] = temp;
          k++;
        } else {
          step++;
        }
      }
    }
  }
}

void moveZeroes(vector<int>& nums) {
  int size = nums.size();
  bool flag = false;
  int count = std::count(nums.begin(), nums.end(), 0);
  int j;
  if (size > 1) {
    swap(nums, size);
  }
}

int main() {
  vector<int> f = {0, 1, 0, 3, 12};
  vector<int> s = {0, 0, 1};
  moveZeroes(f);
  moveZeroes(s);
  for (int i = 0; i < f.size(); i++) {
    cout << f[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < s.size(); i++) {
    cout << s[i] << " ";
  }
  cout << endl;
}