# Given an array of positive integers nums and a positive integer target,
# return the minimal length of a whose sum is greater than or equal to target.
# If there is no such subarray, return 0 instead.
from typing import List


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left = 0
        curr_sum = 0
        min_len = float('inf')

        for right, elem in enumerate(nums):
            curr_sum += elem

            while curr_sum >= target:
                min_len = min(min_len, right - left + 1)
                curr_sum -= nums[left]
                left += 1

        return 0 if min_len == float('inf') else min_len
