// Given a string s, find the length of the longest
// substring
// without repeating characters.

#include <vector>
#include <string>

int lengthOfLongestSubstring(std::string s)
{
    int n = s.size();
    int maxLength = 0;
    std::vector<int> charIndex(128, -1);
    int left = 0;

    for (int right = 0; right < n; ++right)
    {
        if (charIndex[s[right]] >= left)
        {
            left = charIndex[s[right]] + 1;
        }
        charIndex[s[right]] = right;
        maxLength = std::max(maxLength, right - left + 1);
    }

    return maxLength;
}
