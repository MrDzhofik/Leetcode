// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i],
// you can jump to any nums[i + j] where:

//     0 <= j <= nums[i] and
//     i + j < n

// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

#include <vector>

int jump(std::vector<int> &nums)
{
    int n = size(nums);
    std::vector<int> dp(n, 10001);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
        for (int jumpLen = 1; jumpLen <= nums[i]; jumpLen++)
            dp[i] = std::min(dp[i], 1 + dp[std::min(n - 1, i + jumpLen)]);
    return dp[0];
}

int main()
{
    std::vector<int> nums = {2, 3, 1, 1, 4};
    int k = jump(nums);
    return k;
}
