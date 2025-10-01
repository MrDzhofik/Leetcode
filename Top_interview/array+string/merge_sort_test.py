import merge_sort

ans = merge_sort.Solution()


def test_merging():
    ans.merge([1, 2, 3, 0, 0, 0], 3, [2, 5, 6], 3)
    assert ans.num1 == [1, 2, 2, 3, 5, 6]
    ans.merge([1], 1, [], 0)
    assert ans.num1 == [1]
    ans.merge([2, 0], 1, [1], 1)
    assert ans.num1 == [1, 2]
    ans.merge([1, 5, 6, 0, 0, 0], 3, [2, 3, 7], 3)
    print("Hehe")
    assert ans.num1 == [1, 2, 3, 5, 6, 7]
