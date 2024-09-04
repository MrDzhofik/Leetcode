// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R

// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);

#include <string>
#include <vector>

std::string convert(std::string s, int numRows)
{
    int size = s.size();
    if (numRows == 1 || numRows >= size)
    {
        return s;
    }

    int index = 0, d = 1;
    vector<vector<char>> rows(numRows);

    for (char c : s)
    {
        rows[index].push_back(c);
        if (index == 0)
        {
            d = 1;
        }
        else if (index == numRows - 1)
        {
            d = -1;
        }
        index += d;
    }

    string result;
    for (const auto &row : rows)
    {
        for (char c : row)
        {
            result += c;
        }
    }

    return result;
}
