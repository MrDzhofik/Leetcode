// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times.0
// You may assume that the majority element always exists in the array.

//  Follow-up: Could you solve the problem in linear time and in O(1) space?

#include <vector>
#include <algorithm>

using namespace std;

int majorityElement(vector<int> &nums)
{
    std::sort(nums.begin(), nums.end());
    int size = nums.size();
    int count = 1;
    int ans = 0;
    for (int i = 1; i < size; ++i)
    {
        if (nums[i] == nums[i - 1])
        {
            ++count;
        }
        else
        {
            if (count > size / 2)
            {
                ans = nums[i - 1];
            }
            count = 1;
        }
    }
    if (count > size / 2)
    {
        ans = nums[size - 1];
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 2, 3};
    int count = majorityElement(nums);
}
