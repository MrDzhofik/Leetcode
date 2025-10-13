# A phrase is a palindrome if, after converting all uppercase letters
# into lowercase letters and removing all non-alphanumeric characters,
# it reads the same forward and backward. Alphanumeric characters include
# letters and numbers.

# Given a string s, return true if it is a palindrome, or false otherwise.


class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        new_s = ""
        flag = True
        for letter in s:
            if letter.isalpha() or letter.isdigit():
                new_s += letter

        left = 0
        right = len(new_s) - 1

        while left <= right:
            if new_s[left] != new_s[right]:
                flag = False
            left += 1
            right -= 1

        return flag
