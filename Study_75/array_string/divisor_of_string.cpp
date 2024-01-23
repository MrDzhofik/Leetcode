// For two strings s and t, we say "t divides s" if and only if s = t + ... + t
// (i.e., t is concatenated with itself one or more times).
// Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

#include <iostream>

using namespace std;

string gcdOfStrings(string str1, string str2)
{
  string max_st;
  string st;
  int max_size = 0;
  int size1 = str1.size();
  int size2 = str2.size();
  int size = size1 > size2 ? size2 : size1;
  int curr_size = 0;
  if (str1 + str2 != str2 + str1)
  {
    return "";
  }
  for (int i = 0; i < size; i++)
  {
    if (str1[i] == str2[i])
    {
      st += str1[i];
      curr_size += 1;
      if ((curr_size > max_size) && !(size1 % curr_size) &&
          !(size2 % curr_size))
      {
        max_st = st;
        max_size = curr_size;
      }
    }
    else
    {
      curr_size = 0;
      st = "";
      max_st = "";
    }
  }
  if (size2 > size1)
  {
    str1 = str2;
    size1 = size2;
  }
  st = "";
  for (int i = size; i < size + max_size; i++)
  {
    st += str1[i];
  }
  if (st != max_st)
  {
    max_st = "";
  }
  return max_st;
}

int main()
{
  string str1 = {"AABBAABBAA"};
  string str2 = {"AABB"};
  cout << gcdOfStrings(str1, str2) << endl;
  return 0;
}