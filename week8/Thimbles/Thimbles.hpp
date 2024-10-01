#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Thimbles {
 public:
  int thimbleWithBall(vector<string> swaps) {
    // Ball starts under the first thimble
    int ballPosition = 1;

    // Process each swap
    for (string swap : swaps) {
      int thimble1 = swap[0] - '0';  // Convert char to int
      int thimble2 = swap[2] - '0';

      if (ballPosition == thimble1) {
        ballPosition = thimble2;
      } else if (ballPosition == thimble2) {
        ballPosition = thimble1;
      }
    }

    return ballPosition;
  }
};