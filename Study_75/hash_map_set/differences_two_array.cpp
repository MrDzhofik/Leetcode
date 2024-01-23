// Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

//     answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
//     answer[1] is a list of all distinct integers in nums2 which are not present in nums1.

// Note that the integers in the lists may be returned in any order.

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
  int size1 = nums1.size();
  int size2 = nums2.size();
  set<int> n1;
  set<int> n2;
  for (int i = 0; i < size1; i++)
  {
    if (count(nums2.begin(), nums2.end(), nums1[i]) == 0)
    {
      n1.insert(nums1[i]);
    }
  }
  for (int i = 0; i < size2; i++)
  {
    if (count(nums1.begin(), nums1.end(), nums2[i]) == 0)
    {
      n2.insert(nums2[i]);
    }
  }
  set<int>::iterator it;
  vector<int> nm1, nm2;
  vector<vector<int>> ans;
  for (it = n1.begin(); it != n1.end(); it++)
  {
    nm1.push_back(*it);
  }
  for (it = n2.begin(); it != n2.end(); it++)
  {
    nm2.push_back(*it);
  }
  ans.push_back(nm1);
  ans.push_back(nm2);
  return ans;
}

int main()
{
  vector<int> f = {1, 2, 3};
  vector<int> s = {2, 4, 6};
  findDifference(f, s);
}