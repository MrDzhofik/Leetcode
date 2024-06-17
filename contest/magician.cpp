// A magician has various spells.

// You are given an array power, where each element represents the damage of a spell. Multiple spells can have the same damage value.

// It is a known fact that if a magician decides to cast a spell with a damage of power[i], they cannot cast any spell with a damage of power[i] - 2, power[i] - 1, power[i] + 1, or power[i] + 2.

// Each spell can be cast only once.

// Return the maximum possible total damage that a magician can cast.

#include <vector>
#include <algorithm>
#include <unordered_map>

long long maxDamage(std::vector<int> &power)
{
    std::sort(power.begin(), power.end());
    int n = power.size();

    std::unordered_map<int, long long> dp;
    long long max_damage = 0;

    for (int i = 0; i < n; ++i)
    {
        int current_power = power[i];
        long long current_damage = current_power;

        // Проверка предыдущих допустимых значений (current_power - 3 и меньше)
        if (dp.find(current_power - 3) != dp.end())
        {
            current_damage += dp[current_power - 3];
        }
        else if (dp.find(current_power - 2) != dp.end())
        {
            current_damage = std::max(current_damage, dp[current_power - 2] + current_power);
        }
        else if (dp.find(current_power - 1) != dp.end())
        {
            current_damage = std::max(current_damage, dp[current_power - 1] + current_power);
        }

        dp[current_power] = std::max(dp[current_power], current_damage);
        max_damage = std::max(max_damage, dp[current_power]);
    }

    return max_damage;
}
