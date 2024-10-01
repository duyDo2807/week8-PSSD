#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class ColorfulRabbits {
 public:
  int getMinimum(vector<int> replies) {
    unordered_map<int, int> countMap;

    // Count occurrences of each reply
    for (int reply : replies) {
      countMap[reply]++;
    }

    int totalRabbits = 0;

    // Calculate minimum number of rabbits for each unique reply
    for (const auto& entry : countMap) {
      int k = entry.first;
      int c = entry.second;
      // Calculate the number of groups needed
      int groups = ceil(static_cast<double>(c) / (k + 1));
      // Each group has (k + 1) rabbits
      totalRabbits += groups * (k + 1);
    }

    return totalRabbits;
  }
};