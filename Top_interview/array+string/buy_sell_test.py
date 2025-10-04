import buy_sell

ans = buy_sell.Solution()


def test_success():
    assert ans.maxProfit([7, 1, 5, 3, 6, 4]) == 5
    assert ans.maxProfit([7, 6, 4, 3, 1]) == 0
