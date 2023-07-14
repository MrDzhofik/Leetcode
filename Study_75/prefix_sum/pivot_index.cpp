#include <iostream>
#include <vector>

using namespace std;

int pivotIndex(vector<int>& nums) {
  int size = nums.size();
  int right_sum = 0;
  int left_sum = 0;
  int pivot = -1;
  for (int i = 0; i < size; i++) {
    right_sum += nums[i];
  }
  for (int i = 0; i < size; i++) {
    right_sum -= nums[i];
    if (left_sum == right_sum) {
      pivot = i;
    }
    left_sum += nums[i];
  }
  return pivot;
}

int main() {
  vector<int> f = {-1, -1, 0, 0, -1, -1};
  cout << pivotIndex(f);
  return 0;
}