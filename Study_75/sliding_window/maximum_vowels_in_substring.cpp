// Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

#include <iostream>
#include <set>
#include <string>

using namespace std;

int maxVowels(string s, int k)
{
  set<char> vowels = {'a', 'e', 'o', 'i', 'u'};
  int size = s.size();
  int i;
  int curr_vow = 0;
  int max_vow = 0;
  for (i = 0; i < k; i++)
  {
    if (vowels.count(s[i]))
    {
      curr_vow++;
    }
    max_vow = curr_vow > max_vow ? curr_vow : max_vow;
  }
  for (; i < size; i++)
  {
    if (vowels.count(s[i - k]))
    {
      curr_vow--;
    }
    if (vowels.count(s[i]))
    {
      curr_vow++;
    }
    max_vow = curr_vow > max_vow ? curr_vow : max_vow;
  }
  return max_vow;
}

int main()
{
  string s = "abciiidef";
  string f = "leetcode";
  cout << maxVowels(s, 3) << endl;
  cout << maxVowels(f, 3) << endl;
  return 0;
}