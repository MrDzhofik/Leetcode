// There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

// You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

#include <iostream>
#include <vector>

using namespace std;

int largestAltitude(vector<int> &gain)
{
  int max_altitude = 0;
  int altitude = gain[0];
  int size = gain.size();
  for (int i = 1; i < size; i++)
  {
    altitude = gain[i] + altitude;
    max_altitude = max_altitude >= altitude ? max_altitude : altitude;
  }
  return max_altitude;
}

int main()
{
  vector<int> f = {-5, 1, 5, 0, -7};
  cout << largestAltitude(f);
  return 0;
}