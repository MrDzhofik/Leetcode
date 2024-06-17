// Given an integer array hours representing times in hours, return an integer denoting the number of pairs i,
// j where i < j and hours[i] + hours[j] forms a complete day.

// A complete day is defined as a time duration that is an exact multiple of 24 hours.

// For example, 1 day is 24 hours, 2 days is 48 hours, 3 days is 72 hours, and so on.

#include <vector>
#include <unordered_map>

int countCompleteDayPairs(std::vector<int> &hours)
{
    int size = hours.size();
    int days = 0;
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if ((hours[i] + hours[j]) % 24 == 0)
            {
                days += 1;
            }
        }
    }
    return days;
}

long long countCompleteDayPairs(std::vector<int> &hours)
{
    std::unordered_map<int, int> remainder_count;
    long long days = 0;

    for (int hour : hours)
    {
        int remainder = hour % 24;
        int complement = (24 - remainder) % 24;

        if (remainder_count.find(complement) != remainder_count.end())
        {
            days += remainder_count[complement];
        }

        remainder_count[remainder]++;
    }

    return days;
}
