// Given an array of positive integers nums and a positive integer target, return the minimal length of a
// subarray
// whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.

// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1

// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0

#include <vector>

int minSubArrayLen(int target, std::vector<int> &nums)
{
    int i = 0, j = 0;
    int curr_sum = nums[0];
    int minLen = 100001;
    int size = nums.size();
    while (j < size - 1)
    {
        if (curr_sum < target && ++j != size)
        {
            curr_sum += nums[j];
        }
        else if (curr_sum >= target)
        {
            if (j - i + 1 < minLen)
            {
                minLen = j - i + 1;
            }
            curr_sum -= nums[i++];
        }
    }
    return (minLen != 100001) ? minLen : 0;
}

int main()
{
    std::vector<int> nums = {1, 1, 1, 1, 1};
    int target = 7;
    int k = minSubArrayLen(target, nums);
    return 0;
}
