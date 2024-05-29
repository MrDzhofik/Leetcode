// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

// The test cases are generated so that the length of the output will never exceed 105.

#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

void write_word(std::string &word, std::string &result)
{
    int word_size = word.size();
    for (int j = 0; j < word_size; ++j)
    {
        result += word[j];
    }
    word.erase();
}

std::string operator*(std::string word, int repeat)
{
    std::string word_2 = word;
    for (int i = 1; i < repeat; ++i)
    {
        word += word_2;
    }
    return word;
}

std::string decodeString(std::string s)
{
    std::stack<char> st{};
    std::string result{};
    char sym = ' ';
    int size = s.size();
    int count = 0;
    std::string word{};
    std::string word_2{};
    int repeat = 0;
    for (int i = 0; i < size; ++i)
    {
        st.push(s[i]);
    }

    while (st.size() != 0)
    {
        sym = st.top();
        st.pop();
        if (repeat != 0)
        {
            word = word * repeat;
            repeat = 0;
        }
        if (count == 0 && (sym > 57 || sym < 48))
        {
            if (word.empty() && sym != ']')
            {
                word = sym;
            }
            write_word(word, result);
            repeat = 0;
        }
        if (sym == ']')
        {
            ++count;
        }

        else if (sym == '[')
        {
            --count;
        }
        else if (sym <= 57 && sym >= 48)
        {
            int pow = 0;
            repeat += sym - 48;
            if (st.size() != 0)
            {
                sym = st.top();
            }
            while (sym <= 57 && sym >= 48 && st.size() != 0)
            {
                sym = st.top();
                ++pow;
                repeat += (sym - 48) * (10 * pow);
                st.pop();
            }
        }
        else if (count != 0)
        {
            word += sym;
        }
    }
    word = word * repeat;
    write_word(word, result);
    int word_size = result.size();
    char tmp = ' ';
    for (int i = 0; i < word_size / 2; ++i)
    {
        tmp = result[i];
        result[i] = result[word_size - 1 - i];
        result[word_size - 1 - i] = tmp;
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