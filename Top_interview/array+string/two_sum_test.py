import two_sum

ans = two_sum.Solution()


def test_two_sum():
    assert ans.two_sum([2, 7, 11, 15], 9) == [0, 1]
    assert ans.two_sum([3, 2, 4], 6) == [1, 2]
    assert ans.two_sum([3, 3], 6) == [0, 1]


def test_two_sum_n():
    assert ans.two_sum_N([2, 7, 11, 15], 9) == [0, 1]
    assert ans.two_sum_N([3, 2, 4], 6) == [1, 2]
    assert ans.two_sum_N([3, 3], 6) == [0, 1]
    assert ans.two_sum_N([0, 4, 3, 0], 0) == [0, 3]


def test_two_sum_sorted():
    assert ans.two_sum_sorted([2, 7, 11, 15], 9) == [1, 2]
    assert ans.two_sum_sorted([2, 3, 4], 6) == [1, 3]
    assert ans.two_sum_sorted([3, 3], 6) == [1, 2]
