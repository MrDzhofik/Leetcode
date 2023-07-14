#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
  int size = flowerbed.size();
  int place = size / 2 + size % 2;
  int count = std::count(flowerbed.begin(), flowerbed.end(), 0);
  for (int i = 0; i < size; i++) {
    if (flowerbed[i] == 0) {
      if ((i - 1 < 0) && (i + 1 <= size - 1)) {
        if (flowerbed[i + 1] == 1) {
          count--;
        } else {
          flowerbed[i] = 1;
        }
      } else if ((i + 1 > size - 1) && (i - 1 >= 0)) {
        if (flowerbed[i - 1] == 1) {
          count--;
        } else {
          flowerbed[i] = 1;
        }
      } else if ((i - 1 >= 0) && (i + 1 <= size - 1)) {
        if ((flowerbed[i + 1] != 0) || (flowerbed[i - 1] != 0)) {
          count--;
        } else {
          flowerbed[i] = 1;
        }
      }
    }
  }
  return count >= n;
}

int main() {
  vector<int> f = {0};
  cout << canPlaceFlowers(f, 1);
}