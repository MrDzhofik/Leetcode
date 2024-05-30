// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place
// such that each unique element appears only once. The relative order of the elements should be kept the same.
// Then return the number of unique elements in nums.

// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

// 1.Change the array nums such that the first k elements of nums contain the unique elements in the order
//   they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
// 2.Return k.

#include <vector>

int removeDuplicates(std::vector<int> &nums)
{
    int k = nums.size() - 1;
    for (int i = 1; i <= k; ++i)
    {
        if (nums[i] == nums[i - 1])
        {
            for (int j = i; j < k; ++j)
            {
                int tmp = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = tmp;
            }
            --k;
            --i;
        }
    }
    return k + 1;
}

int main()
{
    std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int size = removeDuplicates(nums);
}
