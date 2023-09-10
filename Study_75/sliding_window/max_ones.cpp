#include <iostream>
#include <vector>

using namespace std;

int longestOnes(vector<int>& nums, int k) {
  int ans = 0;
  int size = nums.size();
  int curr_one = 0;
  int zero = 0;
  int i = 0;
  for (; zero <= k, i < size; i++) {
    if (nums[i] == 0) {
      zero++;
    }
    curr_one++;
  }
  curr_one--;
  i--;
  zero--;
  ans = ans < curr_one ? curr_one : ans;
  for (; i < size; i++) {
    if (nums[i] == 0) {
      zero++;
    }
    if (zero > k) {
      if (nums[i - ans] == 0) {
        zero--;
      }
    } else {
      curr_one++;
    }
    ans = ans < curr_one ? curr_one : ans;
  }
  return ans;
}

int main() {
  vector<int> f = {1, 1, 1, 1};
  cout << longestOnes(f, 4) << endl;
}