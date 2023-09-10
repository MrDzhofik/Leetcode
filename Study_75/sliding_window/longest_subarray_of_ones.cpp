#include <iostream>
#include <vector>

// Given a binary array nums, you should delete one element from it.

// Return the size of the longest non-empty subarray containing only 1's in the
// resulting array. Return 0 if there is no such subarray.

using namespace std;

int longestSubarray(vector<int>& nums) {
  int k = 1;
  int ans = 0;
  int size = nums.size();
  int curr_one = 0;
  int zero = 0;
  int i = 0;
  for (; i < size; i++) {  // find the first suitable subbaray
    if (zero > k) {
      break;
    }
    if (nums[i] == 0) {  // if we get zero, we delete it
      zero++;
      curr_one--;
    }
    curr_one++;
  }
  ans = ans < curr_one ? curr_one : ans;
  // move to previous element
  i--;
  if (nums[i] == 0) {
    zero--;
  } else {
    curr_one--;
  }
  for (; i < size; i++) {
    if (nums[i] == 0) {
      zero++;
    } else {
      curr_one++;
    }
    if (zero > k) {  // if count of zero greater than one, we move our subarray
      if (nums[i - ans - 1] ==
          0) {  // if we have zero in start of subbaray, we move last one
        zero--;
      } else {
        curr_one--;
      }
    }
    ans = ans < curr_one ? curr_one : ans;  // ans will be maximum
  }
  if (ans == size) {  // if there are no zeros
    ans--;            // we have to delete one element
  }
  return ans;
}

int main() {
  vector<int> f = {1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1};
  cout << longestSubarray(f) << endl;
  vector<int> s = {1, 1, 0, 1};
  cout << longestSubarray(s) << endl;
  vector<int> t = {0, 1, 1, 1, 0, 1, 1, 0, 1};
  cout << longestSubarray(t) << endl;
}