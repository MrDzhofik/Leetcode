// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none)
// of the characters without disturbing the relative positions of the remaining characters.
// (i.e., "ace" is a subsequence of "abcde" while "aec" is not)

#include <string>

bool isSubsequence(std::string s, std::string t)
{
    int size1 = s.size();
    int size2 = t.size();
    int i = 0;
    for (int j = 0; i < size1, j < size2; ++j)
    {
        if (s[i] == t[j])
        {
            ++i;
        }
    }
    if (i == size1)
    {
        return true;
    }
    return false;
}

int main()
{
    std::string s = "abc";
    std::string t = "ajfjjbldksfevc";
    isSubsequence(s, t);
}
