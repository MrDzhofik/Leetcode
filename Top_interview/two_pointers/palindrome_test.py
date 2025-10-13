import palindrome

ans = palindrome.Solution()


def test_success():
    assert ans.isPalindrome("A man, a plan, a canal: Panama") is True
    assert ans.isPalindrome("race a car") is False
    assert ans.isPalindrome(" ") is True
    assert ans.isPalindrome("0P") is False
