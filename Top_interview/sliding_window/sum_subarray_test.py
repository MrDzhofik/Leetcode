import sum_subarray

ans = sum_subarray.Solution()


def test_sum_subarray():
    assert ans.minSubArrayLen(7, [2, 3, 1, 2, 4, 3]) == 2
    assert ans.minSubArrayLen(4, [1, 4, 4]) == 1
    assert ans.minSubArrayLen(11, [1, 1, 1]) == 0
    assert ans.minSubArrayLen(11, [1, 2, 3, 4, 5]) == 3
    assert ans.minSubArrayLen(1, [5, 6, 8, 9]) == 1
