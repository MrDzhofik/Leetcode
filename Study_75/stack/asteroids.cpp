// We are given an array asteroids of integers representing asteroids in a row.
// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode.
//  Two asteroids moving in the same direction will never meet.

#include <iostream>
#include <stack>
#include <vector>
#include <cmath>

std::vector<int> asteroidCollision(std::vector<int> &asteroids)
{
    std::stack<int> st;
    std::vector<int> temp;
    std::vector<int> result;
    int size = asteroids.size();
    int top = 0;
    st.push(asteroids[0]);
    for (int i = 1; i < size; ++i)
    {
        top = st.size() > 0 ? st.top() : 0;
        if (top > 0 && asteroids[i] < 0)
        {
            bool flag = true;
            int curr = std::abs(asteroids[i]);
            while (st.size() != 0 && flag)
            {
                top = st.top();
                if (top > 0 && asteroids[i] < 0)
                {
                    top = std::abs(top);
                    if (top < curr)
                    {
                        st.pop();
                    }
                    else if (top == curr)
                    {
                        st.pop();
                        flag = false;
                    }
                    else
                    {
                        flag = false;
                    }
                }
                else
                {
                    flag = false;
                    st.push(asteroids[i]);
                }
            }
            if (flag)
            {
                st.push(asteroids[i]);
            }
        }
        else
        {
            st.push(asteroids[i]);
        }
    }

    int sizet = st.size();

    for (int i = 0; i < sizet; ++i)
    {
        temp.push_back(st.top());
        st.pop();
    }

    for (int i = temp.size() - 1; i >= 0; --i)
    {
        result.push_back(temp[i]);
    }

    return result;
}

int main()
{
    std::vector<int> asteroids = {1, -1, -2, -2};

    asteroids = asteroidCollision(asteroids);

    int size = asteroids.size();

    for (int i = 0; i < size; ++i)
    {
        std::cout << asteroids[i] << ' ';
    }

    std::cout << std::endl;

    return 0;
}