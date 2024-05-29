// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
// The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

// Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

// 1. Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
// 2. Return k.

#include <vector>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int size = nums.size();
    int k = size - 1;
    int i = 0;
    while (i <= k)
    {
        if (nums[i] == val)
        {
            while (nums[k] == val and k != i)
            {
                --k;
            }
            int temp = nums[k];
            nums[k] = nums[i];
            nums[i] = temp;
            --k;
        }
        ++i;
    }
    return k + 1;
}

int main()
{
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    removeElement(nums, val);
    return 0;
}
