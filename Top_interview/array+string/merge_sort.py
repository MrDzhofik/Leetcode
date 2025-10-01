# You are given two integer arrays nums1 and nums2, sorted in non-decreasing
# order,
# and two integers m and n, representing the number of elements in nums1
# and nums2 respectively.

# Merge nums1 and nums2 into a single array sorted in non-decreasing order.

# The final sorted array should not be returned by the function, but instead
# be stored inside the array nums1.
# To accommodate this, nums1 has a length of m + n, where the first m elements
# denote the elements
# that should be merged, and the last n elements are set to 0 and should be
# ignored. nums2 has a length of n.

from typing import List


class Solution:
    def __init__(self):
        self.num1 = []

    def merge(self,  nums1: List[int], m: int,
              nums2: List[int], n: int) -> None:
        first_idx = m - 1
        second_idx = n - 1
        final_idx = n + m - 1
        while final_idx >= 0:
            if first_idx < 0:
                nums1[final_idx] = nums2[second_idx]
                second_idx -= 1
            elif second_idx < 0 or nums1[first_idx] > nums2[second_idx]:
                nums1[final_idx] = nums1[first_idx]
                first_idx -= 1
            else:
                nums1[final_idx] = nums2[second_idx]
                second_idx -= 1
            final_idx -= 1
        self.num1 = nums1
