// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
  vector<int> ans;
  int size = nums.size();
  int zeros = 0;
  int multiply = 1;
  for (int i = 0; i < size; i++)
  {
    if (nums[i] != 0)
    {
      multiply *= nums[i];
    }
    else
    {
      zeros++;
    }
  }
  if (zeros > 1)
  {
    for (int i = 0; i < size; i++)
    {
      nums[i] = 0;
    }
  }
  if (zeros == 1)
  {
    for (int i = 0; i < size; i++)
    {
      if (nums[i] == 0)
      {
        nums[i] = multiply;
      }
      else
      {
        nums[i] = 0;
      }
    }
  }
  if (zeros == 0)
  {
    for (int i = 0; i < size; i++)
    {
      nums[i] = multiply / nums[i];
    }
  }
  return nums;
}

int main()
{
  vector<int> m = {1, 2, 3, 4};
  m = productExceptSelf(m);
  for (int i = 0; i < m.size(); i++)
  {
    cout << m[i] << endl;
  }
  return 0;
}