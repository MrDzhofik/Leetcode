# Given an array of integers nums and an integer target, return indices of
# the two numbers such that they add up to target.

# You may assume that each input would have exactly one solution, and you
# may not use the same element twice.

# You can return the answer in any order.
from typing import List


class Solution:
    # simple
    def two_sum(self, nums: List[int], target: int) -> List[int]:
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

    # hashmap
    def two_sum_N(self, nums: List[int], target: int) -> List[int]:
        ans = []
        dct = {}
        size = len(nums)
        for i in range(size):
            if dct.get(target - nums[i]) is None:
                dct[nums[i]] = i
            else:
                ans.append(dct.get(target - nums[i]))
                ans.append(i)

        return ans

    # two pointers
    def two_sum_sorted(self, numbers: List[int], target: int) -> List[int]:
        size = len(numbers)
        left = 0
        right = size - 1
        ans = []
        flag = False
        while left < right and not flag:
            curr = numbers[left] + numbers[right]
            if curr > target:
                right -= 1
            elif curr < target:
                left += 1
            else:
                ans.append(left + 1)
                ans.append(right + 1)
                flag = True

        return ans
