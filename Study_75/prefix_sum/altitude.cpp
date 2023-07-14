#include <iostream>
#include <vector>

using namespace std;

int largestAltitude(vector<int>& gain) {
  int max_altitude = 0;
  int altitude = gain[0];
  int size = gain.size();
  for (int i = 1; i < size; i++) {
    altitude = gain[i] + altitude;
    max_altitude = max_altitude >= altitude ? max_altitude : altitude;
  }
  return max_altitude;
}

int main() {
  vector<int> f = {-5, 1, 5, 0, -7};
  cout << largestAltitude(f);
  return 0;
}