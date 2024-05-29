// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
// and removing all non-alphanumeric characters, it reads the same forward and backward.
// Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool isPalindrome(string s)
{
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); }); // give a string in lower case
    // remove all non-alphanumeric characters
    string tmp = s;
    int j = 0;

    for (int i = 0; s[i] != '\0'; ++i)
    {
        if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            tmp[j] = s[i];
            ++j;
        }
    }
    tmp.erase(j, tmp.size() - 1);
    s = tmp;

    // check if it is a palindrome
    int i = 0;
    j = s.size() - 1;
    bool flag = true;
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            flag = false;
        }
        ++i;
        --j;
    }
    return flag;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    isPalindrome(s);
}
