# Given an array of integers nums and an integer target, return indices of
# the two numbers such that they add up to target.

# You may assume that each input would have exactly one solution, and you
# may not use the same element twice.

# You can return the answer in any order.
from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        ans = []
        left = 0
        size = len(nums)
        right = 1
        while left < size - 1:
            if nums[left] + nums[right] == target:
                ans.append(left)
                ans.append(right)
                left = size + 1
            right += 1
            if right >= size:
                left += 1
                right = left + 1
        return ans
