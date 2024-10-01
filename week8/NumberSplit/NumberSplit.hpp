#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class NumberSplit {
 public:
  int longestSequence(int start) {
    return longestSequenceHelper(to_string(start));
  }

 private:
  unordered_map<string, int> memo;

  int longestSequenceHelper(const string& numStr) {
    // Base case
    if (numStr.size() == 1) {
      return 1;
    }

    // Check if result is already computed
    if (memo.find(numStr) != memo.end()) {
      return memo[numStr];
    }

    int maxLength = 0;

    // Try all possible splits
    for (int i = 1; i < numStr.size(); i++) {
      // Split into two parts (string)
      for (int j = i + 1; j <= numStr.size(); j++) {
        string part1Str = numStr.substr(0, i);
        string part2Str = numStr.substr(i, j - i);

        // Avoid empty parts
        if (part2Str.empty()) {
          continue;
        }

        // Convert parts to integers, ensuring to handle leading zeros
        int part1 = stoi(part1Str);
        int part2 = stoi(part2Str);

        int product = part1 * part2;

        // If j has not reached the end, consider part3
        if (j < numStr.size()) {
          int part3 = stoi(numStr.substr(j));
          product *= part3;  // Multiply by the third part
        }

        // Recursively calculate the longest sequence for the product
        maxLength =
            max(maxLength, 1 + longestSequenceHelper(to_string(product)));
      }
    }

    // Store result in memo and return
    memo[numStr] = maxLength;
    return maxLength;
  }
};
