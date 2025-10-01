import two_sum

ans = two_sum.Solution()


def test_success():
    assert ans.twoSum([2, 7, 11, 15], 9) == [0, 1]
    assert ans.twoSum([3, 2, 4], 6) == [1, 2]
    assert ans.twoSum([3, 3], 6) == [0, 1]
