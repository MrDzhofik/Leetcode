// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

#include <vector>

using namespace std;

//  В лоб
void shift(vector<int> &nums)
{
    int curr = nums[0];
    int size = nums.size();
    int temp = 0;
    if (size == 1)
    {
        return;
    }
    for (int i = 0; i < size - 1; ++i)
    {
        temp = nums[i + 1];
        nums[i + 1] = curr;
        curr = temp;
    }
    nums[0] = temp;
}

void rotate(vector<int> &nums, int k)
{
    int size = nums.size();
    if (k < size)
    {
        vector<int> part1;
        int i = 0;
        for (i = 0; i < size - k; ++i)
        {
            part1.push_back(nums[i]);
        }
        vector<int> part2;

        for (; i < size; ++i)
        {
            part2.push_back(nums[i]);
        }

        i = 0;

        for (int j = 0; j < part2.size(); ++j, ++i)
        {
            nums[i] = part2[i];
        }
        for (int j = 0; j < part1.size(); ++j, ++i)
        {
            nums[i] = part1[j];
        }
    }
    else
    {
        for (int i = 0; i < k; ++i)
        {
            shift(nums);
        }
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums, 3);
}
