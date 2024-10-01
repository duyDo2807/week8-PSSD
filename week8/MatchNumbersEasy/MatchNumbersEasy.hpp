#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class MatchNumbersEasy {
 public:
  std::string maxNumber(std::vector<int> matches, int n) {
    // Initialize DP array with impossible values for comparisons
    std::vector<std::string> dp(n + 1, "");

    // Initialize dp[0] as an empty string because no matches yield no number
    dp[0] = "";

    // Fill dp array with the best possible numbers
    for (int i = 0; i <= n; ++i) {
      for (int digit = 0; digit < matches.size(); ++digit) {
        int matchCount = matches[digit];
        if (i >= matchCount) {
          std::string candidate = dp[i - matchCount] + std::to_string(digit);

          // Ensure that leading zeros are not allowed unless it's the only
          // option
          if (!dp[i - matchCount].empty() || digit != 0) {
            if (candidate.size() > dp[i].size() ||
                (candidate.size() == dp[i].size() && candidate > dp[i])) {
              dp[i] = candidate;
            }
          }
        }
      }
    }

    // If no number could be formed, return "0"
    if (dp[n].empty()) {
      return "0";
    }

    return dp[n];
  }
};