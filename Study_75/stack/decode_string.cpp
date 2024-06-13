// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

// The test cases are generated so that the length of the output will never exceed 105.

#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

std::string decodeString(std::string s)
{
    std::stack<int> counts;          // Стек для хранения количества повторений
    std::stack<std::string> results; // Стек для хранения промежуточных результатов
    std::string result;              // Текущий результат
    int i = 0;                       // Индекс для прохода по строке

    while (i < s.length())
    {
        if (isdigit(s[i]))
        {
            int count = 0;
            while (isdigit(s[i]))
            {
                count = count * 10 + (s[i] - '0');
                i++;
            }
            counts.push(count);
        }
        else if (s[i] == '[')
        {
            results.push(result);
            result.clear();
            i++;
        }
        else if (s[i] == ']')
        {
            std::string temp = result;
            result = results.top();
            results.pop();
            int repeat = counts.top();
            counts.pop();
            while (repeat-- > 0)
            {
                result += temp;
            }
            i++;
        }
        else
        {
            result += s[i];
            i++;
        }
    }

    return result;
}

int main()
{
    std::string s = "abc3[cd]xyz"; // mistake
    std::string f = "3[a2[c]]";
    std::string t = "2[abc]3[cd]ef";
    std::cout << decodeString(s) << std::endl;
    std::cout << decodeString(f) << std::endl;
    std::cout << decodeString(t) << std::endl;

    return 0;
}
